cmake_minimum_required(VERSION 3.8)
project(learning_tf2_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(turtlesim REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(message_filters REQUIRED)

# Add executables and dependencies
add_executable(static_turtle_tf2_broadcaster src/static_turtle_tf2_broadcaster.cpp)
ament_target_dependencies(static_turtle_tf2_broadcaster geometry_msgs rclcpp tf2 tf2_ros)

add_executable(turtle_tf2_broadcaster src/turtle_tf2_broadcaster.cpp)
ament_target_dependencies(turtle_tf2_broadcaster geometry_msgs rclcpp tf2 tf2_ros turtlesim)

add_executable(turtle_tf2_listener src/turtle_tf2_listener.cpp)
ament_target_dependencies(turtle_tf2_listener geometry_msgs rclcpp tf2 tf2_ros turtlesim)

add_executable(fixed_frame_tf2_broadcaster src/fixed_frame_tf2_broadcaster.cpp)
ament_target_dependencies(fixed_frame_tf2_broadcaster geometry_msgs rclcpp tf2_ros)

add_executable(turtle_tf2_listener_time src/turtle_tf2_listener_time.cpp)
ament_target_dependencies(turtle_tf2_listener_time geometry_msgs rclcpp tf2 tf2_ros turtlesim)
target_link_libraries(turtle_tf2_listener_time tf2_geometry_msgs::tf2_geometry_msgs)

add_executable(turtle_tf2_listener_travel src/turtle_tf2_listener_travel.cpp)
ament_target_dependencies(turtle_tf2_listener_travel geometry_msgs rclcpp tf2 tf2_ros turtlesim)
target_link_libraries(turtle_tf2_listener_travel tf2_geometry_msgs::tf2_geometry_msgs)

add_executable(turtle_tf2_message_filter src/turtle_tf2_message_filter.cpp)
ament_target_dependencies(
  turtle_tf2_message_filter
  geometry_msgs
  message_filters
  rclcpp
  tf2
  tf2_geometry_msgs
  tf2_ros
)

# Check if tf2_geometry_msgs.hpp exists
if(TARGET tf2_geometry_msgs::tf2_geometry_msgs)
  get_target_property(_include_dirs tf2_geometry_msgs::tf2_geometry_msgs INTERFACE_INCLUDE_DIRECTORIES)
else()
  set(_include_dirs ${tf2_geometry_msgs_INCLUDE_DIRS})
endif()

find_file(TF2_CPP_HEADERS
  NAMES tf2_geometry_msgs.hpp
  PATHS ${_include_dirs}
  NO_CACHE
  PATH_SUFFIXES tf2_geometry_msgs
)

if(EXISTS ${TF2_CPP_HEADERS})
  target_compile_definitions(turtle_tf2_message_filter PUBLIC -DTF2_CPP_HEADERS)
endif()

# Install targets
install(TARGETS
  static_turtle_tf2_broadcaster
  turtle_tf2_broadcaster
  turtle_tf2_listener
  fixed_frame_tf2_broadcaster
  turtle_tf2_listener_time
  turtle_tf2_listener_travel
  turtle_tf2_message_filter
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

# If configuration files exist
# install(DIRECTORY config
#   DESTINATION share/${PROJECT_NAME})

# Add testing dependencies
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)  # Skip copyright check
  set(ament_cmake_cpplint_FOUND TRUE)  # Skip cpplint check
  ament_lint_auto_find_test_dependencies()
endif()

# Mark the package for ament
ament_package()
