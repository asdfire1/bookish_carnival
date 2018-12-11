#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/TeleportAbsolute.h"

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "bookish_carnival");

  ros::NodeHandle nh;
  ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

  ros::Duration(1.0).sleep();

  geometry_msgs::Twist msg;
  msg.linear.x = 1.0;
  cmd_vel_pub.publish(msg);

  ros::Duration(1.0).sleep();

  msg.linear.x = 0.0;
  msg.angular.z = 1.0;
  cmd_vel_pub.publish(msg);

  ros::Duration(1.0).sleep();

  ros::ServiceClient client = nh.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");

  ros::Duration(1.0).sleep();

  turtlesim::TeleportAbsolute srv;
  srv.request.x = 1.0;
  srv.request.y = 10.0;
  client.call(srv);

  ros::spin();

  return 0;
}
