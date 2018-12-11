#include "ros/ros.h"
#include "std_msgs/Int8.h"
int sound=-1;
void soundCallback(const std_msgs::Int8::ConstPtr& msg)
{
  sound = msg->data;
  ROS_DEBUG("Playing sound: [%s]", sound);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "subscriber");

  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("sound", 10, soundCallback);
  while(ros::ok())
  {
  ros::spin();
  ROS_INFO("Playing sound: ", sound);
  }
  return 0;
}
