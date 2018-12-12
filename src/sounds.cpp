//Nothing - 0
//Forward - 1
//Back - 2
//Spin - 3
// For now we will just cout instead of playing the sound to make it more sure.

#include "ros/ros.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Int16.h"
#include <sound_play/sound_play.h>
#include <unistd.h>
int sound = -1;
int playtime = 1;
void soundCallback(const std_msgs::Int8::ConstPtr& msg)
{
	ROS_INFO("Sound Callback");
  sound = msg->data;
  ROS_INFO("Playing sound: %d", sound);
}
void playtimeCallback(const std_msgs::Int16::ConstPtr& msg)
{
	ROS_INFO("Playtime callback");
  playtime = msg->data;
	playtime = playtime * 0.2;
	ROS_INFO("Playingtime: %d", playtime);
}
int main(int argc, char **argv)
{
	ROS_INFO("starting up");
  	ros::init(argc, argv, "subscriber");
 	ros::NodeHandle nh;
  	ros::Subscriber sub = nh.subscribe("sound", 10, soundCallback);
		ros::Subscriber subb = nh.subscribe("playtime", 10, playtimeCallback);
	ROS_INFO("starting loop", sound);
	 sound_play::SoundClient sc;
	 int temp = 0;
	while (ros::ok())
	{
	ros::spinOnce();
	sleep(0.2);
		switch(sound)
		{
		case(0):
			{
				sc.playWave("/home/ros/miniproject_ws/src/bookish_carnival/src/cricket.wav");
     		while(sound == 0)
					{
						sleep(0.1);
						ros::spinOnce()
					}
			}
		case(1):
			{
				sc.playWave("/home/ros/miniproject_ws/src/bookish_carnival/src/Yee.wav");
				while(sound == 1)
					{
						sleep(0.1);
						ros::spinOnce()
					}
			}
		case(2):
			{
				sc.playWave("/home/ros/miniproject_ws/src/bookish_carnival/src/reverse.wav");
				while(sound == 2)
					{
						sleep(0.1);
						ros::spinOnce()
					}
			}
		case(3):
			{
				sc.playWave("/home/ros/miniproject_ws/src/bookish_carnival/src/nani.wav");
				while(sound == 3)
					{
						sleep(0.1);
						ros::spinOnce()
					}
			}
		}

	}
  return 0;
}
