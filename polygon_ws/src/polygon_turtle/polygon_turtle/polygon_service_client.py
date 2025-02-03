import rclpy
import sys  
from custom_interfaces.srv import PolygonServer
from rclpy.node import Node

class DrawPolygonClient(Node):
    def __init__(self):
        super().__init__('draw_polygon_client')
        self.client = self.create_client(PolygonServer, 'draw_polygon')

    def send_request(self, sides, side_length):
        request = PolygonServer.Request()
        request.sides = sides
        request.side_length = side_length
       

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

    if len(sys.argv) != 3:  
        print("Usage: ros2 run polygon_turtle draw_client <sides> <side_length> ")
        sys.exit(1)

    sides = int(sys.argv[1])  
    side_length = float(sys.argv[2])
    

    node.send_request(sides, side_length)  
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

