#include <cv_pkg/Cluster.hpp>
int main(int argc, char **argv)
{
  ros::init(argc, argv, "cluster");     // 노드 이름 초기화
  ros::NodeHandle nh;                  // ROS 시스템과 통신을 위한 노드 핸들

  cluster cl;
  
  cl.test();
}

