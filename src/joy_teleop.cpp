#include "../include/joy_teleop.h"

JoyTeleop::JoyTeleop() : nh_("") {
  joy_sub_ = nh_.subscribe("joy", 10, &JoyTeleop::joyCallback, this);
  vel_pub_ = nh_.advertise<geometry_msgs::Twist>("velocity", 10);

  ros::spin();
}

void JoyTeleop::joyCallback(const sensor_msgs::Joy::ConstPtr& joy_msg) {
  geometry_msgs::Twist msg;
  msg.linear.x = 2.0 * joy_msg->axes[1];
  msg.angular.z = 2.0 * joy_msg->axes[0];

  vel_pub_.publish(msg);
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "joy_teleop");
  JoyTeleop J;
  return 0;
}
