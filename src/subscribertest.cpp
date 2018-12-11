#include "ros/ros.h"
#include "std_msgs/Int8.h"
int sound = -1;
void soundCallback(const std_msgs::Int8::ConstPtr& msg)
{
	ROS_INFO("Void function starts");
  sound = msg->data;
  ROS_INFO("Playing sound: %d", sound);
}

int main(int argc, char **argv)
{
	ROS_INFO("starting up");
  	ros::init(argc, argv, "subscriber");
 	ros::NodeHandle nh;
  	ros::Subscriber sub = nh.subscribe("sound", 10, soundCallback);
	ROS_INFO("starting loop", sound);
	ros::spin();
	// sound is a global variable that can now be used anywhere
  return 0;
}
