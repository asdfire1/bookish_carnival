cmake_minimum_required(VERSION 2.8.3)
project(move_turtlesim)

find_package(catkin REQUIRED roscpp turtlesim geometry_msgs)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(dance src/dance.cpp)
target_link_libraries(bookish-carnival
  ${catkin_LIBRARIES}
)

