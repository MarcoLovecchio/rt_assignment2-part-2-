# ResearchTrack1 Assignment2_part-2
The motion node has been developed following the first ros exercise: the robot move along x until x is higher than 6 or less than 0, then turn in a circular arc by imposing a velocity along z.
The current position of the robot is always updated with the values published on the topic /odom.
The launch file 'gazebo.launch.py' has been modified, in order to launch the new node.

In order to run the code you need to do the following steps:

  Clone the repository inside the src folder of a ros2 workspace:

    git clone https://github.com/MarcoLovecchio/rt_assignment2-part-2-.git assignment2_part2

  Build the workspace

    cd ..
    colcon build

  Go inside the install folder of the worksapce and launch the setup bash file

    cd install
    source local_setup.bash

  Go inside the launch folder of the package:

    cd ..
    cd src/assignment2_part2/launch

  Launch the launch file gazebo.launch.py:

    ros2 launch gazebo.launch.py
