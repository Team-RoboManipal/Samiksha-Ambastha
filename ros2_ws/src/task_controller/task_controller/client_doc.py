from example_interfaces.srv import AddTwoInts
import rclpy
from rclpy.node import Node
import sys

class ClientDoc(Node):
  def __init__(self):
    super().__init__('client_node')
    self.client=self.create_client(AddTwoInts,'add_two_ints')
    while not self.client.wait_for_service(timeout_sec=1.0):
      self.get_logger().info('service not available.waiting ....')
    self.request = AddTwoInts.Request()
  def send_request(self,a,b):
    self.request.a=a
    self.request.b=b
    return self.client.call_async(self.request)

def main():
  rclpy.init()
  client_node=ClientDoc()
  future= client_node.send_request(int(sys.argv[1]),int(sys.argv[2]))
  rclpy.spin_until_future_complete(client_node,future)
  if future.result() is not None:

        response = future.result()

        client_node.get_logger().info('Result of two numbers: a: %d and b: %d is: %d' % (int(sys.argv[1]), int(sys.argv[2]), response.sum))

  else:

        client_node.get_logger().error('Exception while calling service: %r' % future.exception())
  client_node.destroy_node()
  rclpy.shutdown()

if __name__=='__main__':
  main()
