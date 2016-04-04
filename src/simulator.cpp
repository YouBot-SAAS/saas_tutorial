#include "../include/simulator.h"

Simulator::Simulator() : nh_("") {

}

int main(int argc, char** argv) {
  ros::init(argc, argv, "simulator");
  Simulator S;
  return 0;
}
