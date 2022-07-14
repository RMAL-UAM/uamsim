# UAM Simulator

Running ROS2 Foxy on 20.04

## Commands

Build image with the name `foxy-uam` and tag `v1`
```
docker build -t foxy-uam:v1  .
```

Run container
```
docker run -it foxy-uam:v1
```

List all images
```
docker image ls
```


## Configuring Display

Run the following on your host terminal
```
xhost +local:
```

Check the output of `echo $DISPLAY` and change it in the Dockerfile.

```
gazebo -s libgazebo_ros_init.so -s libgazebo_ros_factory.so &
```

```
/opt/ros/foxy/lib/gazebo_ros/spawn_entity.py -entity uamv0 -file /home/ubuntu/ros2_ws/install/uamv0_description/share/uamv0_description/urdf/uamv0.urdf --ros-args
```
