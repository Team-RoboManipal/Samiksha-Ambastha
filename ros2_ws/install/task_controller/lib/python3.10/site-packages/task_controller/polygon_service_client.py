import rclpy
from custom_interfaces.srv import PolygonServer
from rclpy.node import Node

class DrawPolygonClient(Node):
  def __init__(self):
    super().__init__('draw_polygon_client')
    self.client = self.create_client(PolygonServer, 'draw_polygon')

  def send_request(self, sides, side_length, angular_speed):
        request = PolygonServer.Request()
        request.sides = sides
        request.side_length = side_length
        request.angular_speed = angular_speed

        # Wait until the service is available
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')

        future = self.client.call_async(request)
        future.add_done_callback(self.callback)

  def callback(self, future):
        response = future.result()
        self.get_logger().info(f"Response: Success={response.success}, Message: {response.message}")

def main(args=None):
    rclpy.init(args=args)
    node = DrawPolygonClient()
    node.send_request(4, 2.0, 0.5)  # Example: draw a square with side length 2 and angular speed 0.5 rad/s
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()