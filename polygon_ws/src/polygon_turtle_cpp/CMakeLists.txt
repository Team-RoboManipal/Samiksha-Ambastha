cmake_minimum_required(VERSION 3.8)
project(polygon_turtle_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(custom_interfaces REQUIRED)  
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)

add_executable(draw_server src/polygon_server.cpp)
add_executable(draw_client src/polygon_client.cpp)


ament_target_dependencies(draw_server rclcpp geometry_msgs turtlesim custom_interfaces)
ament_target_dependencies(draw_client rclcpp geometry_msgs turtlesim custom_interfaces)


target_link_libraries(draw_server rclcpp::rclcpp)
target_link_libraries(draw_client rclcpp::rclcpp)


install(TARGETS
  draw_client
  draw_server
  DESTINATION lib/${PROJECT_NAME}
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

