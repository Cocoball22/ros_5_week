#ifndef CLUSTER_h
#define CLUSTER_h

#include <ros/ros.h>			// ROS 기본 헤더 파일
#include "opencv2/opencv.hpp"
#include <iostream>
#include <random>
#include <filesystem>

class cluster
{
private:
    std::string path = "/home/cona/catkin_ws/src/cv_pkg/src/fruit-png/";
    // std::string input_image[20] = {"바나나1.png", "바나나2.png", "yellow.jpeg", "보라.png", "포도2.png"};
    std::string input_image[20] = {};
    std::string yellow_data[10] = {};
    std::string purple_data[10] = {};
    std::string red_data[10] = {};
    cv::Mat image; // 이미지
    int k = 3;  // 클러스터 수
    int number = 0;
    bool c = true;
    std::vector<cv::Vec3b> centroids;  // 클러스터 중심점
    cv::Vec3b mean;
public:
    cluster(/* args */);
    ~cluster();

    void test();
    void test2();
    void step1();
    void step2(cv::Mat image);
    void step3(cv::Vec3b mean);
};

#endif