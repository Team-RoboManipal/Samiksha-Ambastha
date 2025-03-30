import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import math
import sys


class DrawLetterD(Node):
    def __init__(self):
        super().__init__('draw_letter_d')

        # ROS2 publishers and subscribers
        self.publisher = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.subscriber = self.create_subscription(Pose, '/turtle1/pose', self.pose_callback, 10)
        self.timer = self.create_timer(0.1, self.control_loop)

        # Initialize variables
        self.pose = None
        self.state = "start"
        self.spawn_x = None
        self.spawn_y = None
        self.start_theta = None
        self.radius = float(sys.argv[1])  # Radius of the semi-circle
        self.angular_speed = float(sys.argv[2])  # Angular speed (rad/s)
        self.linear_speed = self.angular_speed * self.radius  # Linear speed (m/s)
        self.target_angle = math.pi  # Target angle for the semi-circle (180 degrees)
        self.angle_covered = 0.0  # Tracks the angle covered for the semi-circle
        self.distance_tol = 0.1  # Distance tolerance to determine arrival at the spawn point

    def pose_callback(self, data):
        self.pose = data
        if self.state == "start" and self.spawn_x is None:
            # Save the spawn position and initial orientation
            self.spawn_x = data.x
            self.spawn_y = data.y
            self.start_theta = data.theta
            self.state = "draw_semi_circle"
            self.get_logger().info(f"Spawn point: x={self.spawn_x}, y={self.spawn_y}, theta={self.start_theta}")

    def control_loop(self):
        vel_msg = Twist()

        if self.state == "draw_semi_circle":
            # Move in a semi-circle
            vel_msg.linear.x = self.linear_speed
            vel_msg.angular.z = self.angular_speed
            self.angle_covered += abs(self.angular_speed * 0.1)  # Update the angle covered

            if self.angle_covered >= self.target_angle:
                # Stop the semi-circle motion
                vel_msg.linear.x = 0.0
                vel_msg.angular.z = 0.0
                self.state = "return_to_spawn"
                self.get_logger().info("Semi-circle complete. Returning to spawn.")

        elif self.state == "return_to_spawn":
            # Compute distance and angle to spawn point
            distance = math.sqrt((self.spawn_x - self.pose.x)**2 + (self.spawn_y - self.pose.y)**2)
            theta = math.atan2((self.spawn_y - self.pose.y), (self.spawn_x - self.pose.x))
            angular_tol = 0.1
            distance_tol = 0.1
            angle_error = theta - self.pose.theta

            if abs(angle_error) > angular_tol:
                # Rotate to face the spawn point
                vel_msg.angular.z = angle_error
                vel_msg.linear.x = 0.0
            else:
                if distance > distance_tol:
                    # Move towards the spawn point
                    vel_msg.linear.x = min(distance * 0.5, 1.0)  # Scale linear speed
                    vel_msg.angular.z = 0.0
                else:
                    # Stop at the spawn point
                    vel_msg.linear.x = 0.0
                    vel_msg.angular.z = 0.0
                    self.state = "done"
                    self.get_logger().info("Goal reached! D is completed.")

        self.publisher.publish(vel_msg)


def main(args=None):
    rclpy.init(args=args)

    node = DrawLetterD()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
