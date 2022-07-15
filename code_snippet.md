
## publish a Twist
ros2 topic pub -r 1 /uam/twist geometry_msgs/Twist  '{linear:  {x: 0.1, y: 0.0, z: 0.0}, angular: {x: 0.0,y: 0.0,z: 0.0}}'

ros2 daemon stop && ros2 daemon start

ros2 topic pub -r 1 /uam/pose geometry_msgs/PoseStamped  '{pose: {position:  {x: 0.0, y: 0.0, z: 0.0}, orientation: {w: 1.0,x: 0.0,y: 0.0,z: 0.0}}}'
