import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/samiksha/second_ros2_ws/src/urdf_tutorial_r2d2/install/urdf_tutorial_r2d2'
