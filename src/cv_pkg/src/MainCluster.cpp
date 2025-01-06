#include <cv_pkg/Cluster.hpp>

bool add(cv_pkg::AddTwoInts::Request  &req, cv_pkg::AddTwoInts::Response &res)
{
    res.sum = req.a + req.b;
    ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: [%ld]", (long int)res.sum);
    return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "cluster");     // 노드 이름 초기화
  ros::NodeHandle nh;                  // ROS 시스템과 통신을 위한 노드 핸들

  cluster cl;

  cl.ImageRead();
  cl.Test();

  ros::ServiceServer service = nh.advertiseService("add_two_ints", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();
   
  return 0;
}

