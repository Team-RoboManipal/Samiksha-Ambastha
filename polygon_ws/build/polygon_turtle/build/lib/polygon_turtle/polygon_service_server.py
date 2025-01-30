from custom_interfaces.srv import PolygonServer
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import sys
import math

class DrawPolygonServer(Node):
  def __init__(self):
    super().__init__('draw_polygon_server')
    self.publisher=self.create_publisher(Twist,'turtle1/cmd_vel',10)
    self.subscriber=self.create_subscription(Pose,'turtle1/pose',self.pose_callback,10)

    self.pose = None
    self.state = "start"
    self.sides = int(sys.argv[1])  # Number of sides of the polygon
    self.side_length = float(sys.argv[2])  # Length of each side of the polygon
    self.angular_speed = float(sys.argv[3])  # Angular speed (rad/s)
    self.linear_speed = min(0.5,self.side_length/2) # Fixed linear speed (m/s)
    self.target_angle_increment = 2 * math.pi / self.sides  # External angle (in radians)
    self.target_angle = 0.0  # Initialize target angle
    self.sides_drawn = 0  # Counter for sides drawn
    self.spawn_x = None
    self.spawn_y = None

    self.srv = self.create_service(PolygonServer, 'draw_polygon', self.handle_polygon_request)
    #self.timer = self.create_timer(0.1, self.control_loop)  # Call control_loop every 0.1 seconds

    
  def pose_callback(self, data):
        self.pose = data
        if self.state == "start" and self.spawn_x is None:
            # Save the spawn position and initial orientation
            self.spawn_x = data.x
            self.spawn_y = data.y
            self.target_angle = data.theta  # Set the initial orientation
            self.state = "draw_polygon"
            self.get_logger().info(f"Spawn point: x={self.spawn_x}, y={self.spawn_y}, theta={self.target_angle}")
            self.sides_drawn=0.0
  def control_loop(self):
        if self.pose is None:
            return  # Wait for the pose to be initialized

        vel_msg = Twist()
    
        if self.state == "draw_polygon":
            # Calculate distance traveled from the spawn point
            distance = math.sqrt((self.pose.x - self.spawn_x) ** 2 + (self.pose.y - self.spawn_y) ** 2)
            vel_msg.linear.x = self.linear_speed

            # Move in a straight line for each side of the polygon
            if distance >= self.side_length:
                vel_msg.linear.x = 0.0  # Stop moving forward
                self.sides_drawn += 1
                self.get_logger().info(f"Side {self.sides_drawn} complete. Turning to the next side.")

                # Check if all sides are drawn, if so, stop
                if self.sides_drawn >= self.sides+(self.sides-4):
                    vel_msg.angular.z = 0.0
                    self.state = "done"  # Transition to the done state to stop the turtle
                    self.get_logger().info("Polygon complete. Stopping the turtle.")
                else:
                    #rclpy.spin_once(self, timeout_sec=2)  # Sleep for 1 second
                    self.state = "rotate"  # Change state to rotate
                    self.spawn_x = self.pose.x  # Update spawn point for the next side
                    self.spawn_y = self.pose.y
                    self.target_angle += self.target_angle_increment  # Increment target angle

            self.publisher.publish(vel_msg)  # Publish the velocity message

        elif self.state == "rotate":
            # Calculate the angle error (handling wraparound)
            angle_error = self.target_angle - self.pose.theta

            # Ensure the angle error is between -pi and pi
            angle_error = (angle_error + math.pi) % (2 * math.pi) - math.pi

            # Define tolerance for stopping rotation
            angle_tol = 0.05 # Small tolerance for rotation
            if abs(angle_error) <= angle_tol:
                vel_msg.angular.z = 0.0  # Stop rotating
                #rclpy.spin_once(self, timeout_sec=2)  # Sleep for 1 second
                self.state = "draw_polygon"  # Transition back to drawing
                self.get_logger().info(f"Rotation completed. Starting to draw side {self.sides_drawn + 1}")
            else:
                # Rotate in the correct direction
                vel_msg.angular.z = self.angular_speed if angle_error > 0 else -self.angular_speed
                vel_msg.linear.x = 0.0  # Stop moving forward while rotating

            self.publisher.publish(vel_msg)  # Publish the velocity message

        elif self.state == "done":
            # Stop the turtle
            vel_msg.linear.x = 0.0
            vel_msg.angular.z = 0.0
            self.publisher.publish(vel_msg)        
  def handle_polygon_request(self,request,response):
        self.sides=request.sides
        self.side_length=request.side_length
        self.angular_speed=request.angular_speed

        self.state = "start"
        self.sides_drawn = 0
        self.spawn_x = None
        self.spawn_y = None
        self.get_logger().info(f"Received request to draw polygon with {self.sides} sides, each of length {self.side_length}, and angular speed {self.angular_speed} rad/s")
  
        #self.timer.reset()
        

        # Send response after drawing the polygon
        response.success = True
        response.message = "Polygon drawing complete."
        return response
def main(args=None):
     rclpy.init(args=args)

     node = DrawPolygonServer()
     rclpy.spin(node)

     node.destroy_node()
     rclpy.shutdown()

if __name__ == '__main__':
    main()
 