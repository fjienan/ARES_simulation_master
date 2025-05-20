cmake_minimum_required(VERSION 3.8)
project(test_serial)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ares_comm REQUIRED)

add_executable(test_serial 
  src/test_serial.cpp
)

add_executable(test_frame 
  src/test_frame.cpp
)



# ament_target_dependencies(test_serial rclcpp ares_comm)

target_link_libraries(test_serial
  ares_comm::ares_comm_lib  # 使用命名空间目标
  ${rclcpp_LIBRARIES}
)

target_link_libraries(test_frame
  ares_comm::ares_comm_lib  # 使用命名空间目标
  ${rclcpp_LIBRARIES}
)

target_include_directories(test_serial PRIVATE
  ${ares_comm_INCLUDE_DIRS}
)
# message(111111111111 "${ares_comm_INCLUDE_DIRS}")

target_include_directories(test_frame PRIVATE
  ${ares_comm_INCLUDE_DIRS}
)

# 关键修复1：显式链接目标库
target_link_libraries(test_serial
  ares_comm::ares_comm_lib  # 使用命名空间目标
  ${rclcpp_LIBRARIES}
)

target_link_libraries(test_frame
  ares_comm::ares_comm_lib  # 使用命名空间目标
  ${rclcpp_LIBRARIES}
)


# 关键修复2：传递包含目录
target_include_directories(test_serial PRIVATE
  ${ares_comm_INCLUDE_DIRS}
)

# 关键修复2：传递包含目录
target_include_directories(test_frame PRIVATE
  ${ares_comm_INCLUDE_DIRS}
)

# 声明依赖
ament_target_dependencies(test_serial
  rclcpp
  ares_comm
)

ament_target_dependencies(test_frame
  rclcpp
  ares_comm
)

# 安装可执行文件
install(TARGETS test_serial
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS test_frame
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
