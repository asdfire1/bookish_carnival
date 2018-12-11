cmake_minimum_required(VERSION 2.8.3)
project(bookish_carnival)

find_package(catkin REQUIRED roscpp turtlesim geometry_msgs)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)


add_executable(bookish_carnival src/dance.cpp)
target_link_libraries(bookish_carnival
  ${catkin_LIBRARIES}
)
add_executable(subscriber src/subscribertest.cpp)
target_link_libraries(subscriber
  ${catkin_LIBRARIES}
)
