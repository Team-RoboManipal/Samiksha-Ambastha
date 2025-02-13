cmake_minimum_required(VERSION 3.8)
project(rviz_plugin_tutorial_msgs)

# Compiler options for GCC and Clang
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)  # Ensure std_msgs is found
find_package(rosidl_default_generators REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(pluginlib REQUIRED)
find_package(rviz_common REQUIRED)
find_package(Qt5 REQUIRED Core Widgets)
find_package(rviz_rendering REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)  # Ensure the include directory is used
qt5_wrap_cpp(MOC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/rviz_plugin_tutorial/point_display.hpp)


# Define the plugin library
add_library(point_display src/point_display.cpp ${MOC_FILES})
target_include_directories(point_display PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(point_display
  pluginlib
  rviz_common
  rviz_rendering
)

# Install directives
install(TARGETS point_display
        EXPORT export_rviz_plugin_tutorial
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)
install(DIRECTORY include/
        DESTINATION include
)
install(FILES rviz_common_plugins.xml
        DESTINATION share/${PROJECT_NAME}
)

ament_export_include_directories(include)
ament_export_targets(export_rviz_plugin_tutorial)
pluginlib_export_plugin_description_file(rviz_common rviz_common_plugins.xml)

target_link_libraries(point_display
  Qt5::Core
  Qt5::Widgets
  rviz_common::rviz_common
  rviz_rendering::rviz_rendering
)

# Generate ROS 2 interfaces
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Point2D.msg"  # Specify your message files here
  DEPENDENCIES std_msgs  # Declare std_msgs as a dependency
)

# Export the generated interfaces
ament_export_dependencies(rosidl_default_runtime)
ament_export_dependencies(std_msgs)  # Export std_msgs as a dependency

# Call ament package
ament_package()
