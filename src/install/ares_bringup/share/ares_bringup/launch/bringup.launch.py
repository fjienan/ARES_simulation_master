from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

def generate_launch_description():
    
    simulation_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('simulation_bringup'),
                'launch/my_robot.launch.py'
            ])
        ])
    )

    trajectory_visualizer = Node(
        package = 'visualizer',
        executable ='trajectory_visualizer',
        name = 'trajectory_visualizer_node',
    )

    return LaunchDescription([
        simulation_launch,
        trajectory_visualizer,
    ])
