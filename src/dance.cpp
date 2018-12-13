#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Int8.h"
#include <stdlib.h>
#include <time.h>

void init()
{
  geometry_msgs::Twist msg;
  std_msgs::Int8 msgb; 
  ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/navi", 10); //Setting up publisher for velocities
  ros::Publisher sound_pub = nh.advertise<std_msgs::Int8>("sound", 10); //Setting up publisher used by player node
}

void move(float lin=0.0, float ang=0.0) //function for movement
  {
    msg.linear.x = lin;
    msg.angular.z = ang;
  }
  
void publishsound(int data=0)   //function for publishing sound data
  {
    msgb.data = data;  
    sound_pub.publish(msgb);
  }

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "bookish_carnival");
  ros::NodeHandle nh;
  
  init();

  srand (time(NULL));
  int mode = 0;
  msgb.data = 0; //Publishing data for return / idle
  sound_pub.publish(msgb);
  sleep(7);
  
  int t = 0;

  while(ros::ok())
    {
      mode = rand() % 3 + 0;
      t = rand() %20 + 6;
      switch(mode)
        {
          case 0:
          //Going forward
            {
              move(0.2,0.0);
              publishsound(1); //Publishing data for going forward

              for (int i=0 ; i<t; i++)
                {
                  cmd_vel_pub.publish(msg);
                  ros::Duration(0.2).sleep();
                }

              publishsound(0); //Publishing data for return / idle
              move(-0.2,0.0); //Returning to initial position

              for (int i=0 ; i<t; i++)
                {
                  cmd_vel_pub.publish(msg);
                  ros::Duration(0.2).sleep();
                }
            }
          case 1:
          //Spin direction 1
            {
              move(0.0,2.0);
              publishsound(3); // Publishing data for spin
              for (int i=0 ; i<t; i++)
                {
                  cmd_vel_pub.publish(msg);
                  ros::Duration(0.2).sleep();
                }
              publishsound(0); //Publishing data for return / idle
            }
          case 2:
          //Going backwards
            {
              move(-0.2,0.0);
              publishsound(2); //Publishing data for going backwards
              for (int i=0 ; i<t; i++)
                {
                  cmd_vel_pub.publish(msg);
                  ros::Duration(0.2).sleep();
                }
              publishsound(0); //Publishing data for return / idle
              move(0.2,0.0); //Returning to initial position
              for (int i=0 ; i<t; i++)
                {
                  cmd_vel_pub.publish(msg);
                  ros::Duration(0.2).sleep();
                }

            }
          case 3:
          //Spin direction 2
            {
              move(0.0,-0.2);
              publishsound(3); // Publishing data for spin
              for (int i=0 ; i<t; i++)
                {
                  cmd_vel_pub.publish(msg);
                  ros::Duration(0.2).sleep();
                }
              publishsound(0); //Publishing data for return / idle
            }

        }
    }

  return 0;
}
