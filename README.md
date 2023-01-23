# About this package
This package allows you to simulate turtlebot3 in ROS2(humble).

# Enviroment
- OS: Ubuntu 22.04.1 LTS
- ROS2: humble

# How to use
- Setup
    - Clone
        ```
        git clone --recursive https://github.com/makotoyoshigoe/turtlebot3_humble.git
        ```
    - Build
        ```
        rosdep update
        rosdep install -y -r -i --from-paths src --ignore-src--rosdistro $ROS_DISTRO
        colcon build --symlink-install
        ```
- Navigation
    - First terminal: Launch gazebo
        ```
        source ~/turtlebot3_humble/install/setup.bash
        ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py 
        ```
    - Second terminal: Launch navigation stack
        ```
        source ~/turtlebot3_humble/install/setup.bash
        ros2 launch turtlebot3_navigation2 navigation2.launch.py use_sim_time:=true
        ```