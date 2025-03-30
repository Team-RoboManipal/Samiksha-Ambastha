cmake_minimum_required(VERSION 3.5)

# Set the project name to match the package name
project(task_controller_cpp)

# Find the required packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)


# Include directories (if you have any custom headers)
include_directories(include)

# Add your executables
add_executable(talker src/publisher_member_function.cpp)  # Publisher executable
add_executable(listener src/subscriber_member_function.cpp)  # Subscriber executable
add_executable(server_doc src/service_doc.cpp)
add_executable(client_doc src/client_doc.cpp)
add_executable(chatNode1 src/chat_first.cpp)
add_executable(chatNode2 src/chat_second.cpp)
add_executable(control src/control_turtle.cpp)
add_executable(circle src/circle_turtle.cpp)
add_executable(letter src/letter_turtle.cpp)
ament_target_dependencies(server_doc rclcpp example_interfaces)
ament_target_dependencies(client_doc rclcpp example_interfaces)
ament_target_dependencies(control rclcpp geometry_msgs turtlesim)
ament_target_dependencies(circle rclcpp geometry_msgs turtlesim)
ament_target_dependencies(letter rclcpp geometry_msgs turtlesim)
# Link against the required libraries
ament_target_dependencies(talker rclcpp std_msgs)  # Link dependencies for talker
ament_target_dependencies(listener rclcpp std_msgs)  # Link dependencies for listener
ament_target_dependencies(chatNode1 rclcpp std_msgs)
ament_target_dependencies(chatNode2 rclcpp std_msgs)

# Install the executables
install(TARGETS
  talker
  listener
  server_doc
  client_doc
  chatNode1
  chatNode2
  control
  circle
  letter
  DESTINATION lib/${PROJECT_NAME}
)

# Call ament package
ament_package()
