# velocity_integrator.py
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, Point
from visualization_msgs.msg import Marker
from rclpy.duration import Duration
import math

class VelocityIntegrator(Node):
    def __init__(self):
        super().__init__('velocity_integrator')
        
        self.subscription = self.create_subscription(
            Twist,
            '/ally/robot1/cmd_vel',
            self.vel_callback,
            10)
        
        self.marker_pub = self.create_publisher(Marker, '/predicted_trajectory', 10)
        
        # 轨迹配置
        self.marker = Marker()
        self.marker.header.frame_id = "base_link"  # 确保与车体坐标系一致
        self.marker.ns = "predicted_path"
        self.marker.id = 0
        self.marker.type = Marker.LINE_STRIP      # 必须为 LINE_STRIP
        self.marker.action = Marker.ADD
        self.marker.scale.x = 0.05               # 线宽增加到5cm
        self.marker.color.a = 1.0                # 透明度必须为1
        self.marker.color.r = 0.0
        self.marker.color.g = 1.0
        self.marker.color.b = 0.0
        self.marker.pose.orientation.w = 1.0
        self.marker.lifetime = Duration(seconds=2).to_msg()  # 显示持续时间
        
        # 运动参数
        self.current_v = 0.0
        self.current_omega = 0.0
        self.wheelbase = 0.5  # 假设车辆轴距为0.5米

    def vel_callback(self, msg):
        self.current_v = msg.linear.x
        self.current_omega = msg.angular.z
        self.generate_trajectory()

    def generate_trajectory(self):
        self.marker.points = []
        prediction_time = 3.0  # 增加预测时间到3秒
        time_step = 0.1
        steps = int(prediction_time / time_step)
        
        x = 0.0
        y = 0.0
        theta = 0.0
        
        for _ in range(steps + 1):
            # 数值积分（阿克曼转向模型）
            if abs(self.current_omega) > 1e-6:
                # 计算转向半径
                radius = self.current_v / self.current_omega
                beta = math.atan(self.wheelbase / radius)  # 转向角
            else:
                beta = 0.0
            
            dx = self.current_v * math.cos(theta) * time_step
            dy = self.current_v * math.sin(theta) * time_step
            dtheta = (self.current_v * math.tan(beta) / self.wheelbase) * time_step
            
            x += dx
            y += dy
            theta += dtheta
            
            point = Point()
            point.x = x + self.wheelbase  # 车头偏移（假设车头在轴距前方）
            point.y = y
            point.z = 0.0
            self.marker.points.append(point)
            
            # 调试输出
            self.get_logger().info(f"Generated point: ({point.x:.2f}, {point.y:.2f})")

        self.marker.header.stamp = self.get_clock().now().to_msg()
        self.marker_pub.publish(self.marker)
        self.get_logger().info(f"Published {len(self.marker.points)} trajectory points")

def main(args=None):
    rclpy.init(args=args)
    node = VelocityIntegrator()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()