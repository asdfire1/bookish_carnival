#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Int8.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "dance");
  ros::NodeHandle nh;
  ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/navi", 10); //Setting up publisher for velocities
  ros::Publisher sound_pub = nh.advertise<std_msgs::Int8>("sound", 10); //Setting up publisher used by player node
  geometry_msgs::Twist msg;
  std_msgs::Int8 msgb;
  ROS_INFO("Starting Dance Node");

  srand (time(NULL));
  int mode = 0;
  msgb.data = 0; //Publishing data for return / idle
  sound_pub.publish(msgb);
  sleep(7);
  
  int t = 0;

  while(ros::ok())
    {
      mode = rand() % 4 + 0;
      t = rand() %20 + 6;
      switch(mode)
        {
          case 0:
          //Going forward
              ROS_INFO("Going Forward");
              msg.linear.x = 0.2;
              msg.angular.z = 0.0;
              msgb.data = 1; //Publishing data for going forward
              sound_pub.publish(msgb);

              for (int i=0 ; i<t; i++)
                {
                  cmd_vel_pub.publish(msg);
                  ros::Duration(0.2).sleep();
                }
              ROS_INFO("Returning");
              msgb.data = 0; //Publishing data for return / idle
              sound_pub.publish(msgb);
              msg.linear.x = -0.2; //Returning to initial position
              msg.angular.z = 0.0;

              for (int i=0 ; i<t; i++)
                {
                  cmd_vel_pub.publish(msg);
                  ros::Duration(0.2).sleep();
                }
              break;
          
          case 1:
          //Spin direction 1
              ROS_INFO("Spinning CCW");
              msg.linear.x = 0.0;
              msg.angular.z = 2.0;
              msgb.data = 3; // Publishing data for spin
              sound_pub.publish(msgb);
              for (int i=0 ; i<t; i++)
                {
                  cmd_vel_pub.publish(msg);
                  ros::Duration(0.2).sleep();
                }
              msgb.data = 0; //Publishing data for return / idle
              sound_pub.publish(msgb);
          
              break;
          
          case 2:
          //Going backwards
              ROS_INFO("Going Backwards");
              msg.linear.x = -0.2;
              msg.angular.z = 0.0;
              msgb.data = 2; //Publishing data for going backwards
              sound_pub.publish(msgb);
              for (int i=0 ; i<t; i++)
                {
                  cmd_vel_pub.publish(msg);
                  ros::Duration(0.2).sleep();
                }
              ROS_INFO("Returning");
              msgb.data = 0; //Publishing data for return / idle
              sound_pub.publish(msgb);
              msg.linear.x = 0.2; //Returning to initial position
              msg.angular.z = 0.0;
              for (int i=0 ; i<t; i++)
                {
                  cmd_vel_pub.publish(msg);
                  ros::Duration(0.2).sleep();
                }
              
              break;
          
          case 3:
          //Spin direction 2
              ROS_INFO("Spinning CW");
              msg.linear.x = 0.0;
              msg.angular.z = -2.0;
              msgb.data = 3; // Publishing data for spin
              sound_pub.publish(msgb);
              for (int i=0 ; i<t; i++)
                {
                  cmd_vel_pub.publish(msg);
                  ros::Duration(0.2).sleep();
                }
              msgb.data = 0; //Publishing data for return / idle
              sound_pub.publish(msgb);
              
              break;
        }
    }

  return 0;
}
