import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import sys
import math

class DrawCircle(Node):
    def __init__(self):
        super().__init__('circle_drawer')
        self.publisher = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.subscriber = self.create_subscription(Pose, '/turtle1/pose', self.pose_callback, 10)
        self.timer = self.create_timer(0.1, self.draw_circle)

        # Initialize variables
        self.pose = None
        self.radius = float(sys.argv[1]) 
        self.angular_speed = float(sys.argv[2])
        self.linear_speed = self.angular_speed * self.radius

        self.get_logger().info(f"Drawing a circle with radius {self.radius} m")

    def pose_callback(self, data):
        self.pose = data

    def draw_circle(self):
        vel_msg = Twist()
        vel_msg.linear.x = self.linear_speed  
        vel_msg.angular.z = self.angular_speed  

        self.publisher.publish(vel_msg)

        # Log debug info
        self.get_logger().info(f"Linear Speed: {vel_msg.linear.x:.2f}, Angular Speed: {vel_msg.angular.z:.2f}")

def main(args=None):
    rclpy.init(args=args)

    node = DrawCircle()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
