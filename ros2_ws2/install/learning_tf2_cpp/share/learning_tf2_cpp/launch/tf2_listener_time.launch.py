
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
#this launch file is for the using time cpp file
from launch_ros.actions import Node
def generate_launch_description():
    return LaunchDescription([
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            name='sim'
        ),
        Node(
            package='learning_tf2_cpp',
            executable='turtle_tf2_broadcaster',
            name='broadcaster1',
            parameters=[
                {'turtlename': 'turtle1'}
            ]
        ),
DeclareLaunchArgument(
  'target_frame', default_value='turtle1',
            description='Target frame name.'
        ),
Node(
            package='learning_tf2_cpp',
            executable='turtle_tf2_listener_time',
            name='listener_time',
            parameters=[
                {'target_frame': LaunchConfiguration('target_frame')}
            ]
        ),
    ])