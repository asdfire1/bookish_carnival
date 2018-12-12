#include <ros.h>
#include <sound_play/sound_play.h>
#include <unistd.h>
void sleepok(int t, ros::NodeHandle &nh)
{
  if (nh.ok())
                sleep(t);
 }
 int main(int argc, char **argv)
 {
   ros::init(argc, argv, "sound_play_test");

   ros::NodeHandle nh;
   sound_play::SoundClient sc;

   sleepok(1, nh);

   while(nh.ok())
   {
     sc.say("Hello world!");
     sleepok(2, nh);
     sc.playWave("/usr/share/xemacs21/xemacs-packages/etc/sounds/boing.wav");
     sleepok(2, nh);

  }
	return 0;
}
