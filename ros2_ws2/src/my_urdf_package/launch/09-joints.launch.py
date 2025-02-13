from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    pkg_name = 'urdf_sim_tutorial'  # Change to your actual package name
    config_path = os.path.join(
        get_package_share_directory(pkg_name), 'config', 'ros2_controllers.yaml'
    )

    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true', description='Use simulation (Gazebo) clock'),
        
        # Start the Controller Manager
        Node(
            package='controller_manager',
            executable='ros2_control_node',
            parameters=[config_path],
            output='screen',
        ),

        # Load & Start the Joint State Broadcaster
        ExecuteProcess(
            cmd=['ros2', 'control', 'load_controller', '--set-state', 'start', 'joint_state_broadcaster'],
            output='screen'
        ),
         ExecuteProcess(
            cmd=['ros2', 'control', 'load_controller', '--set-state', 'start', 'head_controller'],
            output='screen'
        ),
    ])
