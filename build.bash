#!/bin/bash
rosdep update
rosdep install -y -r -i --from-paths src --ignore-src --rosdistro $ROS_DISTRO
colcon build --symlink-install
