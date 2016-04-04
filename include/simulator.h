#include <ros/ros.h>
#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/Twist.h>

class Simulator {
public:
  Simulator();

private:
  void velocityCallback(const geometry_msgs::Twist::ConstPtr& vel_msg);

  ros::NodeHandle nh_;
  ros::Subscriber vel_sub_;
  ros::Publisher pose_pub_;

  geometry_msgs::Pose2D pose_;
  geometry_msgs::Twist velocity_;
};
