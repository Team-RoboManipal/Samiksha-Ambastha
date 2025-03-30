from example_interfaces.srv import AddTwoInts
import rclpy
from rclpy.node import Node

class ServiceDoc(Node):
  def __init__(self):
    super().__init__('service_node')
    self.service=self.create_service(AddTwoInts,'add_two_ints',self.add_two_ints_callback)
  
  def add_two_ints_callback(self,request,response):
    response.sum=request.a+request.b
    self.get_logger().info('incoming request\na:%d b:%d'%(request.a,request.b))
    return response
    
  
def main():
    rclpy.init()
    service_node=ServiceDoc()
    rclpy.spin(service_node)
    rclpy.shutdown()

if __name__=='__main__':
    main()