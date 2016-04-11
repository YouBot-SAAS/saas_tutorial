#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Twist.h>

class JoyTeleop {
public:
  JoyTeleop();

private:
  void joyCallback(const sensor_msgs::Joy::ConstPtr& joy_msg);

  ros::NodeHandle nh_;
  ros::NodeHandle nh_local_;

  ros::Subscriber joy_sub_;
  ros::Publisher vel_pub_;

  double k_v_;
  double k_w_;
};
