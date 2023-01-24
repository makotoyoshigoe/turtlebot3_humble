import launch
from ament_index_python.packages import get_package_share_directory
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os

def generate_launch_description():
    os.environ['TURTLEBOT3_MODEL'] = "burger"
    gazebo_launch_share_dir = get_package_share_directory("turtlebot3_gazebo")
    nav2_launch_share_dir = get_package_share_directory("turtlebot3_navigation2")
    print(gazebo_launch_share_dir, nav2_launch_share_dir)

    gazebo_launch = launch.actions.IncludeLaunchDescription(
        PythonLaunchDescriptionSource([gazebo_launch_share_dir + "/launch/turtlebot3_world.launch.py"])
    )

    # nav2_launch = launch.actions.IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource([nav2_launch_share_dir + "/launch/turtlebot3_navigation2.launch.py"])
    #     # launch_arguments={
    #     #     "use_sim_time": "true"
    #     # }.items()
    # )
    return launch.LaunchDescription([gazebo_launch])