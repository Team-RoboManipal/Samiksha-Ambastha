I am getting an error : 
make[2]: *** No rule to make target '/home/samiksha/ros2_ws2/src/rviz_plugin_tutorial_msgs/include/rviz_plugin_tutorial/point_display.hpp', needed by 'include/rviz_plugin_tutorial/moc_point_display.cpp'.  Stop.
gmake[1]: *** [CMakeFiles/Makefile2:193: CMakeFiles/point_display.dir/all] Error 2
 while building the rviz_plugin_tutorial_msgs and rviz_panel_tutorial packages that it cannot find the point_display.hpp header file 
 but i have added it in the Home/ros2_ws2/src/rviz_plugin_tutorial_msgs/include/rviz_plugin_tutorial_msgs.
  
polygon_ws - python and cpp code for drawing a polygon using server and client.

ros2_ws - 
        task_controller - python codes to draw a circle,letter , move to a goal and polygon using publisher and  subscriber and implementation of server,client, publisher subscriber codes given in the documentation
        task_controller_cpp= c++ codes of chatbot, circle,letter,moving to a goal and documentation implementation of server client , publisher and subscriber
        
