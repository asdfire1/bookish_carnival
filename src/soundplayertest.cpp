#include "ros/ros.h"
#include <sound_play/sound_play.h>
#include <unistd.h>

 int main(int argc, char **argv)
 {
   ros::init(argc, argv, "sound_play_test");

   ros::NodeHandle nh;
   sound_play::SoundClient sc;

   sleep(1);

   while(nh.ok())
   {
     sc.say("Hello world!");
     sleep(2);
     sc.playWave("/home/ros/Yee.wav");
     sleep(2);

  }
	return 0;
}
