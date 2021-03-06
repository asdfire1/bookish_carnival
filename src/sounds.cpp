#include "ros/ros.h"
#include "std_msgs/Int8.h"
#include <sound_play/sound_play.h>
#include <unistd.h>

int sound = 0;

void soundCallback(const std_msgs::Int8::ConstPtr& msg) //Callback function for subscriber
{
  sound = msg->data;
}

int main(int argc, char **argv) {
	ROS_INFO("Player node starting up");
  ros::init(argc, argv, "player");
 	ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("sound", 10, soundCallback);
	sound_play::SoundClient sc;

	while (ros::ok())
		{
			ros::spinOnce();
			sleep(0.2);
			switch(sound)
				{
					case(0):
					//Idle / return sound
						{
							ROS_INFO("Playing idle/return sound");
							sc.playWave("/home/ros/miniproject_ws/src/bookish_carnival/src/cricket.wav");
     					while(sound == 0 && ros::ok())
								{
									sleep(0.1);
									ros::spinOnce();
								}
						break;
						}
					case(1):
					//Forward sound
						{
							ROS_INFO("Playing forward sound");
							sc.playWave("/home/ros/miniproject_ws/src/bookish_carnival/src/Yee.wav");
							while(sound == 1 && ros::ok())
								{
									sleep(0.1);
									ros::spinOnce();
								}
						break;
						}
					case(2):
					//Backwards sound
						{
							ROS_INFO("Playing backwards sound");
							sc.playWave("/home/ros/miniproject_ws/src/bookish_carnival/src/reverse.wav");
							while(sound == 2 && ros::ok())
								{
									sleep(0.1);
									ros::spinOnce();
								}
						break;
						}
					case(3):
					//Spinning sound
						{
							ROS_INFO("Playing spinning sound");
							sc.playWave("/home/ros/miniproject_ws/src/bookish_carnival/src/nani.wav");
							while(sound == 3 && ros::ok())
								{
									sleep(0.1);
									ros::spinOnce();
								}
						break;
						}
				}

		}
  return 0;
}
