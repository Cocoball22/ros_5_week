#include <ros/ros.h>			// ROS 기본 헤더 파일
#include "std_msgs/String.h"
#include "opencv2/opencv.hpp"
int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");     // 노드 이름 초기화
  ros::NodeHandle nh;                  // ROS 시스템과 통신을 위한 노드 핸들
  
  // 퍼블리셔 선언
  //// test_pkg에 정의된 test_msg 메시지 메시지 파일을 이용함
  //// 만약 표준 메시지를 사용한다면 그에 맞게 사용해야 함. (예) <std_msgs::String>
  //// 토픽 이름: chatter, 큐 사이즈: 100개
  ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("say_hello_world", 100);

  // 루프 주기를 10hz로 설정. 1초에 10번 루프를 돌며 메시지를 송신함.
  ros::Rate loop_rate(10);
  int count = 0;			// 코드 내에서 사용할 변수 선언

  while (ros::ok())			// 종료 전까지 계속 반복 수행함
  {
    std_msgs::String msg;		// 메시지 변수 선언
    std::stringstream ss;
    ss << "hello world" << count;
    msg.data  = ss.str();

    ROS_INFO("send msg = %s", msg.data.c_str());

    chatter_pub.publish(msg);	// 메시지를 퍼블리시함(토픽으로 전송)
    ros::spinOnce();
    loop_rate.sleep();		// 정해준 주기만큼 일시정지(sleep)
    ++count;
  }

  return 0;
}