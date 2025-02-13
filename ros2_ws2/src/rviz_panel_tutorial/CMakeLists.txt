cmake_minimum_required(VERSION 3.8)
project(rviz_panel_tutorial)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
cmake_minimum_required(VERSION 3.8)
project(rviz_panel_tutorial)

# Compiler flags
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(pluginlib REQUIRED)
find_package(rviz_common REQUIRED)
find_package(Qt5 REQUIRED Core Widgets)

set(CMAKE_AUTOMOC ON)  # Enable Qt MOC
set(CMAKE_INCLUDE_CURRENT_DIR ON)

qt5_wrap_cpp(MOC_FILES
  include/rviz_panel_tutorial/demo_panel.hpp
)

add_library(demo_panel src/demo_panel.cpp ${MOC_FILES})

target_include_directories(demo_panel PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(demo_panel
  pluginlib
  rviz_common
)

install(TARGETS demo_panel
  EXPORT export_rviz_panel_tutorial
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
ament_export_targets(export_rviz_panel_tutorial)
pluginlib_export_plugin_description_file(rviz_common rviz_common_plugins.xml)

ament_package()

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
