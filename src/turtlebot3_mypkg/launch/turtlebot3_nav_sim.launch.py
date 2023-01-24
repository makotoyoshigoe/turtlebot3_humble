import launch
from ament_index_python.packages import get_package_share_directory
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os

def generate_launch_description():
    os.environ['TURTLEBOT3_MODEL'] = 'burger'
    gazebo_launch_share_dir = os.path.join(get_package_share_directory('turtlebot3_gazebo'), 'launch', 'turtlebot3_world.launch.py')
    nav2_launch_share_dir = os.path.join(get_package_share_directory('turtlebot3_navigation2'), 'launch', 'navigation2.launch.py')

    gazebo_launch = launch.actions.IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(gazebo_launch_share_dir)
        )
    )

    nav2_launch = launch.actions.IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(nav2_launch_share_dir)
        ), 
        launch_arguments={
            'use_sim_time': 'true'
        }.items()
    )
    
    ld = launch.LaunchDescription()
    ld.add_action(nav2_launch)
    ld.add_action(gazebo_launch)
    
    return ld