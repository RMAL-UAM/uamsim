#! /usr/bin/bash
export GAZEBO_PLUGIN_PATH=GAZEBO_PLUGIN_PATH:/home/willcmc/uamsim/build/simulator
ros2 daemon stop && export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp && ros2 daemon start
colcon build && . install/setup.bash && ros2 launch simulator launcher.launch.py