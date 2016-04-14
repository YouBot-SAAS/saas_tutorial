#include "../include/joy_teleop.h"

JoyTeleop::JoyTeleop() : nh_(""), nh_local_("~") {
  joy_sub_ = nh_.subscribe("joy", 10, &JoyTeleop::joyCallback, this);
  vel_pub_ = nh_.advertise<geometry_msgs::Twist>("cmd_vel", 10);

  nh_local_.param<double>("linear_gain", k_v_, 2.0);
  nh_local_.param<double>("angular_gain", k_w_, 2.0);

  ros::spin();
}

void JoyTeleop::joyCallback(const sensor_msgs::Joy::ConstPtr& joy_msg) {
  geometry_msgs::Twist msg;
  msg.linear.x = k_v_ * joy_msg->axes[1];
  msg.linear.y = k_v_ * joy_msg->axes[2];
  msg.angular.z = k_w_ * joy_msg->axes[0];

  vel_pub_.publish(msg);
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "joy_teleop");
  JoyTeleop J;
  return 0;
}
