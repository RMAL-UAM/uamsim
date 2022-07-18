
## publish a Twist
ros2 topic pub -r 1 /uam/twist geometry_msgs/Twist  '{linear:  {x: 0.1, y: 0.0, z: 0.0}, angular: {x: 0.0,y: 0.0,z: 0.0}}'

ros2 daemon stop && ros2 daemon start

ros2 topic pub -r 1 /uam/pose geometry_msgs/PoseStamped  '{pose: {position:  {x: 0.0, y: 0.0, z: 0.0}, orientation: {w: 1.0,x: 0.0,y: 0.0,z: 0.0}}}'


    <joint name='prop_shaft1' type='revolute'>
      <pose relative_to='base_link'>0.098035 -0.358168 0.191641 0 0 -0.351202</pose>
      <parent>base_link</parent>
      <child>prop1</child>
      <axis>
        <xyz>0 0 1</xyz>
        <limit>
          <lower>-1e+16</lower>
          <upper>1e+16</upper>
        </limit>
        <dynamics>
          <spring_reference>0</spring_reference>
          <spring_stiffness>0</spring_stiffness>
        </dynamics>
      </axis>
    </joint>
    <link name='prop1'>
      <pose relative_to='prop_shaft1'>0 0 0 0 -0 0</pose>
      <inertial>
        <pose>-0 0 0.06985 0 -0 0</pose>
        <mass>10</mass>
        <inertia>
          <ixx>1.6806</ixx>
          <ixy>-3.627e-05</ixy>
          <ixz>-7.8723e-13</ixz>
          <iyy>1.6805</iyy>
          <iyz>1.4484e-12</iyz>
          <izz>3.1026</izz>
        </inertia>
      </inertial>
      <collision name='prop1_collision'>
        <pose>0 0 0 0 -0 0</pose>
        <geometry>
          <mesh>
            <scale>1 1 1</scale>
            <uri>model://uamv1_description/meshes/prop1.STL</uri>
          </mesh>
        </geometry>
        <surface>
          <friction>
            <torsional>
              <coefficient>
                0.1
              </coefficient>
            </torsional>
          </friction>
        </surface>
      </collision>
      <visual name='prop1_visual'>
        <pose>0 0 0 0 -0 0</pose>
        <geometry>
          <mesh>
            <scale>1 1 1</scale>
            <uri>model://uamv1_description/meshes/prop1.STL</uri>
          </mesh>
        </geometry>
      </visual>
    </link>
    <joint name='prop_shaft2' type='revolute'>
      <pose relative_to='base_link'>-0.244429 -0.256213 0.191641 0 -0 2.21259</pose>
      <parent>base_link</parent>
      <child>prop2</child>
      <axis>
        <xyz>0 0 1</xyz>
        <limit>
          <lower>-1e+16</lower>
          <upper>1e+16</upper>
        </limit>
        <dynamics>
          <spring_reference>0</spring_reference>
          <spring_stiffness>0</spring_stiffness>
        </dynamics>
      </axis>
    </joint>
    <link name='prop2'>
      <pose relative_to='prop_shaft2'>0 0 0 0 -0 0</pose>
      <inertial>
        <pose>-0 0 0.06985 0 -0 0</pose>
        <mass>10</mass>
        <inertia>
          <ixx>1.6806</ixx>
          <ixy>-3.627e-05</ixy>
          <ixz>-7.8305e-13</ixz>
          <iyy>1.6805</iyy>
          <iyz>1.4496e-12</iyz>
          <izz>3.1026</izz>
        </inertia>
      </inertial>
      <collision name='prop2_collision'>
        <pose>0 0 0 0 -0 0</pose>
        <geometry>
          <mesh>
            <scale>1 1 1</scale>
            <uri>model://uamv1_description/meshes/prop2.STL</uri>
          </mesh>
        </geometry>
        <surface>
          <friction>
            <torsional>
              <coefficient>
                0.1
              </coefficient>
            </torsional>
          </friction>
        </surface>
      </collision>
      <visual name='prop2_visual'>
        <pose>0 0 0 0 -0 0</pose>
        <geometry>
          <mesh>
            <scale>1 1 1</scale>
            <uri>model://uamv1_description/meshes/prop2.STL</uri>
          </mesh>
        </geometry>
      </visual>
    </link>
    <joint name='prop_shaft3' type='revolute'>
      <pose relative_to='base_link'>-0.314037 0.087299 0.191761 0 0 -0.351202</pose>
      <parent>base_link</parent>
      <child>prop3</child>
      <axis>
        <xyz>0 0 1</xyz>
        <limit>
          <lower>-1e+16</lower>
          <upper>1e+16</upper>
        </limit>
        <dynamics>
          <spring_reference>0</spring_reference>
          <spring_stiffness>0</spring_stiffness>
        </dynamics>
      </axis>
    </joint>
    <link name='prop3'>
      <pose relative_to='prop_shaft3'>0 0 0 0 -0 0</pose>
      <inertial>
        <pose>-0 0 0.06985 0 -0 0</pose>
        <mass>10</mass>
        <inertia>
          <ixx>1.6806</ixx>
          <ixy>-3.627e-05</ixy>
          <ixz>-7.8727e-13</ixz>
          <iyy>1.6805</iyy>
          <iyz>1.4483e-12</iyz>
          <izz>3.1026</izz>
        </inertia>
      </inertial>
      <collision name='prop3_collision'>
        <pose>0 0 0 0 -0 0</pose>
        <geometry>
          <mesh>
            <scale>1 1 1</scale>
            <uri>model://uamv1_description/meshes/prop3.STL</uri>
          </mesh>
        </geometry>
        <surface>
          <friction>
            <torsional>
              <coefficient>
                0.1
              </coefficient>
            </torsional>
          </friction>
        </surface>
      </collision>
      <visual name='prop3_visual'>
        <pose>0 0 0 0 -0 0</pose>
        <geometry>
          <mesh>
            <scale>1 1 1</scale>
            <uri>model://uamv1_description/meshes/prop3.STL</uri>
          </mesh>
        </geometry>
      </visual>
    </link>
    <joint name='prop_shaft4' type='revolute'>
      <pose relative_to='base_link'>-0.067864 0.336864 0.191641 0 0 -0.351202</pose>
      <parent>base_link</parent>
      <child>prop4</child>
      <axis>
        <xyz>0 0 1</xyz>
        <limit>
          <lower>-1e+16</lower>
          <upper>1e+16</upper>
        </limit>
        <dynamics>
          <spring_reference>0</spring_reference>
          <spring_stiffness>0</spring_stiffness>
        </dynamics>
      </axis>
    </joint>
    <link name='prop4'>
      <pose relative_to='prop_shaft4'>0 0 0 0 -0 0</pose>
      <inertial>
        <pose>-0 0 0.06985 0 -0 0</pose>
        <mass>10</mass>
        <inertia>
          <ixx>1.6806</ixx>
          <ixy>-3.627e-05</ixy>
          <ixz>-7.8726e-13</ixz>
          <iyy>1.6805</iyy>
          <iyz>1.4483e-12</iyz>
          <izz>3.1026</izz>
        </inertia>
      </inertial>
      <collision name='prop4_collision'>
        <pose>0 0 0 0 -0 0</pose>
        <geometry>
          <mesh>
            <scale>1 1 1</scale>
            <uri>model://uamv1_description/meshes/prop4.STL</uri>
          </mesh>
        </geometry>
        <surface>
          <friction>
            <torsional>
              <coefficient>
                0.1
              </coefficient>
            </torsional>
          </friction>
        </surface>
      </collision>
      <visual name='prop4_visual'>
        <pose>0 0 0 0 -0 0</pose>
        <geometry>
          <mesh>
            <scale>1 1 1</scale>
            <uri>model://uamv1_description/meshes/prop4.STL</uri>
          </mesh>
        </geometry>
      </visual>
    </link>
    <joint name='prop_shaft5' type='revolute'>
      <pose relative_to='base_link'>0.2746 0.234909 0.191641 0 0 -0.351202</pose>
      <parent>base_link</parent>
      <child>prop5</child>
      <axis>
        <xyz>0 0 1</xyz>
        <limit>
          <lower>-1e+16</lower>
          <upper>1e+16</upper>
        </limit>
        <dynamics>
          <spring_reference>0</spring_reference>
          <spring_stiffness>0</spring_stiffness>
        </dynamics>
      </axis>
    </joint>
    <link name='prop5'>
      <pose relative_to='prop_shaft5'>0 0 0 0 -0 0</pose>
      <inertial>
        <pose>-0 0 0.06985 0 -0 0</pose>
        <mass>10</mass>
        <inertia>
          <ixx>1.6806</ixx>
          <ixy>-3.627e-05</ixy>
          <ixz>-7.8728e-13</ixz>
          <iyy>1.6805</iyy>
          <iyz>1.4483e-12</iyz>
          <izz>3.1026</izz>
        </inertia>
      </inertial>
      <collision name='prop5_collision'>
        <pose>0 0 0 0 -0 0</pose>
        <geometry>
          <mesh>
            <scale>1 1 1</scale>
            <uri>model://uamv1_description/meshes/prop5.STL</uri>
          </mesh>
        </geometry>
        <surface>
          <friction>
            <torsional>
              <coefficient>
                0.1
              </coefficient>
            </torsional>
          </friction>
        </surface>
      </collision>
      <visual name='prop5_visual'>
        <pose>0 0 0 0 -0 0</pose>
        <geometry>
          <mesh>
            <scale>1 1 1</scale>
            <uri>model://uamv1_description/meshes/prop5.STL</uri>
          </mesh>
        </geometry>
      </visual>
    </link>
    <joint name='prop_shaft6' type='revolute'>
      <pose relative_to='base_link'>0.34419 -0.108662 0.191761 0 0 -0.351202</pose>
      <parent>base_link</parent>
      <child>prop6</child>
      <axis>
        <xyz>0 0 1</xyz>
        <limit>
          <lower>-1e+16</lower>
          <upper>1e+16</upper>
        </limit>
        <dynamics>
          <spring_reference>0</spring_reference>
          <spring_stiffness>0</spring_stiffness>
        </dynamics>
      </axis>
    </joint>
    <link name='prop6'>
      <pose relative_to='prop_shaft6'>0 0 0 0 -0 0</pose>
      <inertial>
        <pose>-0 0 0.06985 0 -0 0</pose>
        <mass>10</mass>
        <inertia>
          <ixx>1.6806</ixx>
          <ixy>-3.627e-05</ixy>
          <ixz>-7.8726e-13</ixz>
          <iyy>1.6805</iyy>
          <iyz>1.4483e-12</iyz>
          <izz>3.1026</izz>
        </inertia>
      </inertial>
      <collision name='prop6_collision'>
        <pose>0 0 0 0 -0 0</pose>
        <geometry>
          <mesh>
            <scale>1 1 1</scale>
            <uri>model://uamv1_description/meshes/prop6.STL</uri>
          </mesh>
        </geometry>
        <surface>
          <friction>
            <torsional>
              <coefficient>
                0.1
              </coefficient>
            </torsional>
          </friction>
        </surface>
      </collision>
      <visual name='prop6_visual'>
        <pose>0 0 0 0 -0 0</pose>
        <geometry>
          <mesh>
            <scale>1 1 1</scale>
            <uri>model://uamv1_description/meshes/prop6.STL</uri>
          </mesh>
        </geometry>
      </visual>
    </link>