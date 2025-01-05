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
    std::string path = "/home/hyun/ros_5_week/src/cv_pkg/src/fruit-png/";
    // std::string input_image[20] = {"바나나1.png", "바나나2.png", "yellow.jpeg", "보라.png", "포도2.png"};
    std::string input_image[22] = {};

    cv::Mat image; // 이미지
    int k = 3;  // 클러스터 수
    uchar b[3] = {};
    uchar g[3] = {};
    uchar r[3] = {};
    int number = 0;
    int num_1 = 0, num_2 = 0, num_3 = 0;
    int F_num_1 = 0, F_num_2 = 0, F_num_3 = 0;
    bool falg_p = false;
    cv::Vec3b mean[22];
    cv::Vec3b current_centroids[3] = {};
    cv::Vec3b past_centroids[3] = {};
    cv::Vec3b data_1[22] = {};
    cv::Vec3b data_2[22] = {};
    cv::Vec3b data_3[22] = {};
   
public:
    cluster(/* args */);
    ~cluster();

    void ImageRead();
    void FindCentroid();
    void FirstCentroids();
    void IamgeAverage(cv::Mat image);
    void Clustring(cv::Vec3b mean);
    double getDistance(const cv::Vec3b& p1, const cv::Vec3b& p2);
    bool flag_p = false;
    void NewCentroid();
    void RunClustering();
};

#endif