#! /usr/bin/bash
ros2 daemon stop && export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp && ros2 daemon start
colcon build && . install/setup.bash && ros2 launch simulator launcher.launch.py