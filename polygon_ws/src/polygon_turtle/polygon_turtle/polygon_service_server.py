from custom_interfaces.srv import PolygonServer
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import math

class DrawPolygonServer(Node):
    def __init__(self):
        super().__init__('draw_polygon_server')
        self.publisher = self.create_publisher(Twist, 'turtle1/cmd_vel', 10)
        self.subscriber = self.create_subscription(Pose, 'turtle1/pose', self.pose_callback, 10)

        self.pose = None
        self.state = "idle"
        self.sides = 0
        self.side_length = 0.0
        self.linear_speed = 0.5  
        self.target_angle_increment = 0.0
        self.target_angle = 0.0
        self.sides_drawn = 0
        self.spawn_x = None
        self.spawn_y = None

        self.srv = self.create_service(PolygonServer, 'draw_polygon', self.handle_polygon_request)
        self.timer = self.create_timer(0.1, self.control_loop)

    def pose_callback(self, data):
        self.pose = data

    def handle_polygon_request(self, request, response):
        self.sides = request.sides
        self.side_length = request.side_length
        

        self.linear_speed = min(0.5, self.side_length / 2) 
        self.target_angle_increment = 2 * math.pi / self.sides

        self.state = "start"
        self.sides_drawn = 0
        self.spawn_x = None
        self.spawn_y = None

        self.get_logger().info(f"Received request: {self.sides} sides, {self.side_length}")

        response.success = True
        response.message = "Polygon drawing started."
        return response

    def control_loop(self):
        if self.pose is None:
            return

        vel_msg = Twist()
        

        if self.state == "start" and self.pose is not None and self.spawn_x is None:
            self.spawn_x = self.pose.x
            self.spawn_y = self.pose.y
            self.target_angle = self.pose.theta
            self.state = "draw_polygon"

        if self.state == "draw_polygon":
            distance = math.sqrt((self.pose.x - self.spawn_x) ** 2 + (self.pose.y - self.spawn_y) ** 2)
            vel_msg.linear.x = self.linear_speed

            if distance >= self.side_length:
                vel_msg.linear.x = 0.0
                self.sides_drawn += 1

                if self.sides_drawn >= self.sides:
                    self.state = "done"
                else:
                    self.state = "rotate"
                    self.spawn_x = self.pose.x
                    self.spawn_y = self.pose.y
                    self.target_angle += self.target_angle_increment

            self.publisher.publish(vel_msg)

        elif self.state == "rotate":
            angle_error = self.target_angle - self.pose.theta
            angle_error = math.atan2(math.sin(self.target_angle - self.pose.theta), math.cos(self.target_angle - self.pose.theta))

            if abs(angle_error) < 0.1:
                vel_msg.angular.z = 0.0
                self.state = "draw_polygon"
            else:
                angular_speed=2.0
                vel_msg.angular.z = angular_speed if angle_error > 0 else -angular_speed

            self.publisher.publish(vel_msg)

        elif self.state == "done":
            vel_msg.linear.x = 0.0
            vel_msg.angular.z = 0.0
            self.publisher.publish(vel_msg)

def main(args=None):
    rclpy.init(args=args)
    node = DrawPolygonServer()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

