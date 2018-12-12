#include "ros/ros.h"
#include "std_msgs/Int8.h"
#include <sound_play/sound_play.h>
#include <unistd.h>
int sound = -1;
void soundCallback(const std_msgs::Int8::ConstPtr& msg)
{
	ROS_INFO("Sound Callback");
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
	 sound_play::SoundClient sc;
	while (ros::ok())
	{
	ros::spinOnce();
	sleep(0.2);
		switch(sound)
		{
		case(0):
			{
				sc.playWave("/home/ros/miniproject_ws/src/bookish_carnival/src/cricket.wav");
     		while(sound == 0 && ros::ok())
					{
						sleep(0.1);
						ros::spinOnce();
					}
			}
		case(1):
			{
				sc.playWave("/home/ros/miniproject_ws/src/bookish_carnival/src/Yee.wav");
				while(sound == 1 && ros::ok())
					{
						sleep(0.1);
						ros::spinOnce();
					}
			}
		case(2):
			{
				sc.playWave("/home/ros/miniproject_ws/src/bookish_carnival/src/reverse.wav");
				while(sound == 2 && ros::ok())
					{
						sleep(0.1);
						ros::spinOnce();
					}
			}
		case(3):
			{
				sc.playWave("/home/ros/miniproject_ws/src/bookish_carnival/src/nani.wav");
				while(sound == 3 && ros::ok())
					{
						sleep(0.1);
						ros::spinOnce();
					}
			}
		}

	}
  return 0;
}
