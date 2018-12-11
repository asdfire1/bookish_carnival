#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "move_circle");

  ros::NodeHandle nh;
  ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 5);

  geometry_msgs::Twist msg;
  msg.linear.x = 0.1;
  msg.angular.z = 1.0;

  for(int; i=0; i<24; i++)
  {
    cmd_vel_pub.publish(msg);
    ros::Duration(0.2).sleep();
  }

  return 0;
}
