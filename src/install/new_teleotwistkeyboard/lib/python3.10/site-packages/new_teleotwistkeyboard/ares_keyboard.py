import sys
import threading
import geometry_msgs.msg
import rclpy

if sys.platform == 'win32':
    import msvcrt
else:
    import termios
    import tty
    import fcntl
    import os

msg = """
This node takes keypresses from the keyboard and publishes them
as Twist/TwistStamped messages. It works best with a US keyboard layout.
---------------------------
Moving around:
   u    i    o
   j    k    l
   m    ,    .

For Holonomic mode (strafing), hold down the shift key:
---------------------------
   U    I    O
   J    K    L
   M    <    >

t : up (+z)
b : down (-z)

anything else : stop

q/z : increase/decrease max speeds by 10%
w/x : increase/decrease only linear speed by 10%
e/c : increase/decrease only angular speed by 10%

CTRL-C to quit
"""

moveBindings = {
    'i': (1, 0, 0, 0),
    'o': (1, 0, 0, -1),
    'j': (0, 0, 0, 1),
    'l': (0, 0, 0, -1),
    'u': (1, 0, 0, 1),
    ',': (-1, 0, 0, 0),
    '.': (-1, 0, 0, 1),
    'm': (-1, 0, 0, -1),
    'O': (1, -1, 0, 0),
    'I': (1, 0, 0, 0),
    'J': (0, 1, 0, 0),
    'L': (0, -1, 0, 0),
    'U': (1, 1, 0, 0),
    '<': (-1, 0, 0, 0),
    '>': (-1, -1, 0, 0),
    'M': (-1, 1, 0, 0),
    't': (0, 0, 1, 0),
    'b': (0, 0, -1, 0),
}

speedBindings = {
    'q': (1.1, 1.1),
    'z': (.9, .9),
    'w': (1.1, 1),
    'x': (.9, 1),
    'e': (1, 1.1),
    'c': (1, .9),
}

class TeleopTwistKeyboard:
    def __init__(self, node):
        self.node = node
        self.pub = self.node.create_publisher(geometry_msgs.msg.Twist, 'cmd_vel', 10)

        # 速度参数（恢复原版命名）
        self.speed = 0.5    # 原版 speed 变量
        self.turn = 1.0     # 原版 turn 变量
        self.linear_accel = 0.5
        self.angular_accel = 1.0

        # 状态变量
        self.target_linear_x = 0.0
        self.target_angular_z = 0.0
        self.current_linear_x = 0.0
        self.current_angular_z = 0.0

        self.timer = self.node.create_timer(0.1, self.update_speed)

    def update_speed(self):
        dt = 0.1
        # 线速度更新（保持原版 x 变量逻辑）
        if self.target_linear_x > self.current_linear_x:
            self.current_linear_x = min(
                self.current_linear_x + self.linear_accel * dt, 
                self.target_linear_x
            )
        else:
            self.current_linear_x = max(
                self.current_linear_x - self.linear_accel * dt, 
                self.target_linear_x
            )

        # 角速度更新（保持原版 th 变量逻辑）
        if self.target_angular_z > self.current_angular_z:
            self.current_angular_z = min(
                self.current_angular_z + self.angular_accel * dt,
                self.target_angular_z
            )
        else:
            self.current_angular_z = max(
                self.current_angular_z - self.angular_accel * dt,
                self.target_angular_z
            )

        # 发布消息（恢复原版 twist 结构）
        twist = geometry_msgs.msg.Twist()
        twist.linear.x = self.current_linear_x * self.speed
        twist.angular.z = self.current_angular_z * self.turn
        self.pub.publish(twist)

def getKey(settings):
    if sys.platform == 'win32':
        return msvcrt.getwch()
    else:
        try:
            return sys.stdin.read(1)
        except IOError:
            return ''

def saveTerminalSettings():
    if sys.platform == 'win32':
        return None
    fd = sys.stdin.fileno()
    old_attr = termios.tcgetattr(fd)
    old_flags = fcntl.fcntl(fd, fcntl.F_GETFL)
    tty.setraw(fd)
    fcntl.fcntl(fd, fcntl.F_SETFL, old_flags | os.O_NONBLOCK)
    return (old_attr, old_flags)

def restoreTerminalSettings(old_settings):
    if sys.platform != 'win32' and old_settings:
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_settings[0])
        fcntl.fcntl(sys.stdin, fcntl.F_SETFL, old_settings[1])

def vels(speed, turn):
    # 严格保持原版输出格式
    return 'currently:\tspeed %s\tturn %s ' % (round(speed, 1), round(turn, 1))

def main():
    settings = saveTerminalSettings()
    rclpy.init()
    
    try:
        node = rclpy.create_node('teleop_twist_keyboard')
        teleop = TeleopTwistKeyboard(node)
        
        # 恢复原版参数处理
        stamped = node.declare_parameter('stamped', False).value
        frame_id = node.declare_parameter('frame_id', '').value
        if not stamped and frame_id:
            raise ValueError("'frame_id' requires 'stamped' to be True")

        # 原版消息输出
        print(msg)
        print(vels(teleop.speed, teleop.turn))
        
        status = 0
        while rclpy.ok():
            key = getKey(settings)
            if key:
                # 原版按键处理逻辑
                if key in moveBindings:
                    direction = moveBindings[key]
                    teleop.target_linear_x = direction[0]
                    teleop.target_angular_z = direction[3]
                elif key in speedBindings:
                    factor = speedBindings[key]
                    teleop.speed *= factor[0]
                    teleop.turn *= factor[1]
                    print(vels(teleop.speed, teleop.turn))
                    status = (status + 1) % 15
                    if status == 0:
                        print(msg)
                elif key == '\x03':  # CTRL-C
                    break

    finally:
        if rclpy.ok():
            # 原版清理逻辑
            twist = geometry_msgs.msg.Twist()
            teleop.pub.publish(twist)
            node.destroy_node()
            rclpy.shutdown()
        restoreTerminalSettings(settings)

if __name__ == '__main__':
    main()