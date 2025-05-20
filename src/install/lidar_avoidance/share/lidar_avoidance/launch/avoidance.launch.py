import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_dir = get_package_share_directory('lidar_avoidance')

    avoidance_node = Node(
        package='lidar_avoidance',
        executable= 'lidar_avoidance',
        name = 'avoidance_node',
    )

    return LaunchDescription([
        avoidance_node
    ])