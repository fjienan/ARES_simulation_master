#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import numpy as np
from sklearn.cluster import DBSCAN
from scipy.optimize import minimize, linear_sum_assignment
from geometry_msgs.msg import Twist, PoseStamped
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
from tf_transformations import euler_from_quaternion
from visualization_msgs.msg import Marker  # 确保导入
from scipy.spatial import ConvexHull


class OmniMPCController(Node):
    def __init__(self):
        super().__init__('omni_mpc_controller')
        self.marker_pub = self.create_publisher(Marker, '/obstacles', 10)  # 显式初始化
        self.previous_cluster_count = -1
        self.previous_obstacles = []

        # 声明参数
        self.declare_parameters(namespace='',
            parameters=[
                ('control_rate', 20.0),
                ('max_speed', 2.0),
                ('max_accel', 4.0),
                ('safety_radius', 0.5),
                ('manual_weight', 0.3),
                ('dbscan_eps', 0.3),
                ('dbscan_min_samples', 3)
            ])
        
        # 初始化参数
        self.control_rate = self.get_parameter('control_rate').value
        self.max_speed = self.get_parameter('max_speed').value
        self.manual_weight = self.get_parameter('manual_weight').value
        
        # 车辆状态 (全向轮需要x,y速度)
        self.pose = np.zeros(3)  # x, y, theta
        self.velocity = np.zeros(2)  # vx, vy
        self.obstacles = []
        self.obstacle_clusters = []
        self.goal = None
        self.manual_cmd = np.zeros(2)  # [vx, vy]
        
        # 创建ROS接口
        # self.cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        # self.create_subscription(Odometry, '/odom', self.odom_callback, 10)
        self.create_subscription(LaserScan, '/ally/robot1/scan2', self.laser_callback, 10)
        # self.create_subscription(PoseStamped, '/goal_pose', self.goal_callback, 10)
        # self.create_subscription(Twist, '/manual_cmd', self.manual_callback, 10)
        
        # 控制定时器
        # self.create_timer(1.0/self.control_rate, self.control_cycle)
        
        self.get_logger().info("全向轮MPC控制器已启动")

    def odom_callback(self, msg):
        """处理全向轮里程计数据"""
        # 位置
        self.pose[0] = msg.pose.pose.position.x
        self.pose[1] = msg.pose.pose.position.y
        
        # 航向角
        q = msg.pose.pose.orientation
        self.pose[2] = euler_from_quaternion([q.x, q.y, q.z, q.w])[2]
        
        # 线速度 (全向轮需要x,y方向速度)
        self.velocity[0] = msg.twist.twist.linear.x
        self.velocity[1] = msg.twist.twist.linear.y

    def publish_obstacle_marker(self,center, marker_id):
        """发布障碍物可视化标记"""
        marker = Marker()
        marker.header.frame_id = "base_link"
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = "obstacles"        # 命名空间
        marker.id = marker_id          # 唯一标识符
        marker.type = Marker.CYLINDER
        marker.action = Marker.ADD
        marker.scale.x = 0.8  # 直径
        marker.scale.y = 0.8
        marker.scale.z = 1.0  # 高度
        marker.color.a = 0.5
        marker.color.r = 1.0
        marker.color.g = 0.0
        marker.color.b = 0.0
        marker.pose.position.x = center[0]
        marker.pose.position.y = center[1]
        marker.pose.position.z = 0.5  # 离地高度
        
        # if not hasattr(self, 'marker_pub'):
        self.marker_pub = self.create_publisher(Marker, '/obstacles', 10)

        self.marker_pub.publish(marker)

    def laser_callback(self, msg):
        """处理2D激光雷达数据并生成圆柱障碍物"""
        points = []
        robot_x, robot_y, robot_theta = self.pose

        # 转换为全局坐标系
        for i, r in enumerate(msg.ranges):
            if msg.range_min < r < msg.range_max:
                local_angle = msg.angle_min + i * msg.angle_increment
                global_angle = local_angle + robot_theta
                x = robot_x + r * np.cos(global_angle)
                y = robot_y + r * np.sin(global_angle)
                points.append([x, y])
        
        # 初始化聚类相关变量
        current_cluster_count = 0
        unique_labels = set()
        clusters = []
        self.obstacles = []
        
        # DBSCAN聚类
        if points:
            dbscan = DBSCAN(eps=0.5, min_samples=5)
            clusters = dbscan.fit_predict(points)
            unique_labels = set(clusters)
            unique_labels.discard(-1)  # 移除噪声点
            current_cluster_count = len(unique_labels)
            # 无论是否触发更新条件，都要计算障碍物中心
            for label in unique_labels:
                cluster_points = np.array([points[i] for i, l in enumerate(clusters) if l == label])
                obstacle_center = self.calculate_obstacle_center(cluster_points, robot_x, robot_y)
                self.obstacles.append(obstacle_center)  # 关键！始终填充障碍物列表

        # 位置变化检测（必须在聚类之后）
        position_changed = False
        print(len(self.obstacles))

        if len(self.obstacles) == len(self.previous_obstacles) and len(self.obstacles) > 0:
            
            distances = [np.linalg.norm(new-old) for new, old in zip(self.obstacles, self.previous_obstacles)]
            position_changed = any(d > 0.1 for d in distances)
        # else:
        #     position_changed = current_cluster_count != 0  # 数量变化即视为位置变化

        # 更新条件判断
        if current_cluster_count != self.previous_cluster_count or position_changed:
            # 删除旧标记
            delete_marker = Marker()
            delete_marker.header.frame_id = "base_link"
            delete_marker.header.stamp = self.get_clock().now().to_msg()
            delete_marker.action = Marker.DELETEALL
            delete_marker.ns = "obstacles"
            self.marker_pub.publish(delete_marker)

            # 生成新标记
            if current_cluster_count > 0:
                for idx, obstacle_center in enumerate(self.obstacles):
                    # cluster_points = np.array([points[i] for i, l in enumerate(clusters) if l == label])
                    # obstacle_center = self.calculate_obstacle_center(cluster_points, robot_x, robot_y)
                    # self.obstacles.append(obstacle_center)
                    self.publish_obstacle_marker(obstacle_center, marker_id=idx)

            # 更新状态记录
            self.previous_cluster_count = current_cluster_count
            self.previous_obstacles = self.obstacles.copy()
            self.get_logger().info(f"障碍物数量变化：{self.previous_cluster_count}")  # 修复变量名



    def calculate_obstacle_center(self, cluster_points, robot_x, robot_y):
        """计算位于激光点后方的障碍物中心"""
        # 方法1：射线反向投影法
        # 计算所有点相对于机器人的平均方向
        avg_angle = np.arctan2(
            (cluster_points[:,1]-robot_y).mean(),
            (cluster_points[:,0]-robot_x).mean()
        )
        
        # 计算平均距离并增加安全余量
        avg_distance = np.mean(np.linalg.norm(cluster_points - [robot_x, robot_y], axis=1))
        safety_margin = 0.3  # 根据障碍物半径调整
        
        # 障碍物中心位于射线延长线上（更远离机器人）
        obstacle_center = [
            robot_x + (avg_distance + safety_margin) * np.cos(avg_angle),
            robot_y + (avg_distance + safety_margin) * np.sin(avg_angle)
        ]
# region 凸包法
        # # 方法2：凸包法（更精确但计算量更大）
        # try:
        #     hull = ConvexHull(cluster_points)
        #     farthest_point = cluster_points[hull.vertices][
        #         np.argmax(np.linalg.norm(cluster_points[hull.vertices] - [robot_x, robot_y], axis=1))
        #     ]
            
        #     # 沿法线方向外推
        #     edge_vector = farthest_point - cluster_points[hull.vertices][0]
        #     normal = np.array([-edge_vector[1], edge_vector[0]])
        #     normal /= np.linalg.norm(normal)
            
        #     obstacle_center = farthest_point + 0.4 * normal  # 外推距离根据实际情况调整
        # except:
        #     pass  # 回退到方法1
# endregion
        
        return np.array(obstacle_center)    

    

    def track_obstacles(self):
        """改进的障碍物跟踪算法"""
        # 创建代价矩阵（考虑速度和方向）
        cost_matrix = np.zeros((len(self.obstacle_clusters), len(self.obstacles)))
        for i, prev in enumerate(self.obstacle_clusters):
            for j, curr in enumerate(self.obstacles):
                # 考虑距离和速度一致性
                distance_cost = np.linalg.norm(prev['position'] - curr)
                velocity = prev['velocity'] if 'velocity' in prev else np.zeros(2)
                predicted_pos = prev['position'] + velocity * self.dt
                prediction_cost = np.linalg.norm(predicted_pos - curr)
                cost_matrix[i,j] = 0.7 * prediction_cost + 0.3 * distance_cost
        
        # 匈牙利算法匹配
        row_ind, col_ind = linear_sum_assignment(cost_matrix)
        
        # 更新障碍物信息
        new_clusters = []
        for i, j in zip(row_ind, col_ind):
            prev = self.obstacle_clusters[i]
            curr = self.obstacles[j]
            
            # 计算速度
            velocity = (curr - prev['position']) / self.dt
            
            new_clusters.append({
                'position': curr,
                'velocity': 0.9 * prev['velocity'] + 0.1 * velocity,
                'last_seen': self.get_clock().now().nanoseconds
            })
        
        # 添加新障碍物
        current_time = self.get_clock().now().nanoseconds
        for j in range(len(self.obstacles)):
            if j not in col_ind:
                new_clusters.append({
                    'position': self.obstacles[j],
                    'velocity': np.zeros(2),
                    'last_seen': current_time
                })
        
        # 移除过期障碍物（超过2秒未更新）
        self.obstacle_clusters = [
            o for o in new_clusters 
            if current_time - o['last_seen'] < 2e9
        ]

    def omni_motion_model(self, state, u):
        """全向轮运动模型
        state: [x, y, theta, vx, vy]
        u: [ax, ay] 加速度
        """
        dt = 1.0/self.control_rate
        new_state = np.zeros_like(state)
        
        # 更新速度
        new_state[3] = state[3] + u[0]*dt  # vx
        new_state[4] = state[4] + u[1]*dt  # vy
        
        # 更新位置
        new_state[0] = state[0] + new_state[3]*dt
        new_state[1] = state[1] + new_state[4]*dt
        new_state[2] = state[2]  # 全向轮暂不考虑旋转
        
        return new_state

    def mpc_optimize(self):
        """MPC优化"""
        horizon = 5
        u0 = np.zeros(2 * horizon)
        state = np.append(self.pose, self.velocity)
        
        # 约束条件
        bounds = [(-self.get_parameter('max_accel').value, 
                  self.get_parameter('max_accel').value)] * 2 * horizon
        
        res = minimize(self.mpc_cost, u0, args=(state,),
                    bounds=bounds, method='SLSQP')
        
        return res.x[:2] if res.success else None

    def mpc_cost(self, u, state):
        """MPC代价函数"""
        cost = 0.0
        current_state = state.copy()
        
        for i in range(5):
            # 应用控制量
            accel = u[i*2:i*2+2]
            current_state = self.omni_motion_model(current_state, accel)
            
            # 目标点代价
            if self.goal is not None:
                cost += 1.0 * np.linalg.norm(current_state[:2] - self.goal[:2])
            
            # 障碍物代价
            for obs in self.obstacle_clusters:
                dist = np.linalg.norm(current_state[:2] - obs)
                if dist < self.get_parameter('safety_radius').value:
                    cost += 100 / (dist + 0.1)
            
            # 控制量代价
            cost += 0.1 * np.linalg.norm(accel)**2
        
        return cost

    def fuse_commands(self, auto_cmd):
        """融合手动和自动控制指令"""
        if auto_cmd is None:
            return self.manual_cmd
        
        # 速度限幅
        manual_vx = np.clip(self.manual_cmd[0], -self.max_speed, self.max_speed)
        manual_vy = np.clip(self.manual_cmd[1], -self.max_speed, self.max_speed)
        
        # 加权融合
        fused_vx = (self.manual_weight * manual_vx + 
                   (1-self.manual_weight) * auto_cmd[0])
        fused_vy = (self.manual_weight * manual_vy + 
                   (1-self.manual_weight) * auto_cmd[1])
        
        return np.array([fused_vx, fused_vy])

    def control_cycle(self):
        """主控制循环"""
        if self.goal is None:
            self.get_logger().warn("等待目标点...")
            return
        
        # MPC优化
        auto_cmd = self.mpc_optimize()
        
        # 指令融合
        fused_cmd = self.fuse_commands(auto_cmd)
        
        # 发布控制指令
        cmd = Twist()
        cmd.linear.x = fused_cmd[0]
        cmd.linear.y = fused_cmd[1]
        self.cmd_pub.publish(cmd)

    def goal_callback(self, msg):
        """目标点回调"""
        self.goal = np.array([
            msg.pose.position.x,
            msg.pose.position.y
        ])

    def manual_callback(self, msg):
        """手动控制回调"""
        self.manual_cmd = np.array([msg.linear.x, msg.linear.y])

def main(args=None):
    rclpy.init(args=args)
    controller = OmniMPCController()
    rclpy.spin(controller)
    controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main() 