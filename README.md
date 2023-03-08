# turtlebot3-humble
ROS2 humbleでturtlebot3を使ったシミュレーションをできるようにするためのリポジトリ

# 動作環境
- OS: Ubuntu 22.04.1 LTS
- ROS2: humble

# 使用方法
- Setup
    - Clone
        ```
        git clone --recursive git@github.com:makotoyoshigoe/turtlebot3_humble.git
        ```
    - Build
        ```
        rosdep update
	    rosdep install -y -r -i --from-paths src --ignore-src --rosdistro $ROS_DISTRO
        colcon build --symlink-install
        ```
- Navigation
    1. シミュレータの起動
        ```
        source ~/turtlebot3_humble/install/setup.bash
        ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py 
        ```
    2.  ナビゲーションの実行
        ```
        source ~/turtlebot3_humble/install/setup.bash
        ros2 launch turtlebot3_navigation2 navigation2.launch.py use_sim_time:=true
        ```
