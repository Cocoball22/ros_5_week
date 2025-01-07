#ifndef CLUSTER_h
#define CLUSTER_h

#include <ros/ros.h>			// ROS 기본 헤더 파일
#include "opencv2/opencv.hpp"
#include <iostream>
#include <random>
#include <filesystem>
#include "cv_pkg/ImageClassify.h"

class cluster
{
private:
    std::string path = "/home/hyun/ros_5_week/src/cv_pkg/src/fruit-png/";
    std::string test_path = "/home/hyun/ros_5_week/src/cv_pkg/src/test/";
    // std::string input_image[20] = {"바나나1.png", "바나나2.png", "yellow.jpeg", "보라.png", "포도2.png"};
    std::string input_image[33] = {};
    std::string test_image[13] = {};
    int n = 0;
    cv::Mat image; // 이미지
    int k = 3;  // 클러스터 수
    uchar b[3] = {};
    uchar g[3] = {};
    uchar r[3] = {};
    int number = 0, bun = 0, input = 0;
    int num_1 = 0, num_2 = 0, num_3 = 0;
    bool flag_p = false;
    
    cv::Vec3b mean[33];
    cv::Vec3b current_centroids[3] = {};
    cv::Vec3b past_centroids[3] = {};
    cv::Vec3b data_1[33] = {};
    cv::Vec3b data_2[33] = {};
    cv::Vec3b data_3[33] = {};
    std::string name_1[33] = {};
    std::string name_2[33] = {};
    std::string name_3[33] = {};
public:
    cluster(/* args */);
    ~cluster();
    
    void ImageRead();
    void FindCentroid();
    void FirstCentroids();
    void IamgeAverage(cv::Mat image);
    void Clustring(cv::Vec3b mean);
    double getDistance(const cv::Vec3b& p1, const cv::Vec3b& p2);
    std::string TestIamgeAverage(cv::Mat image);
    void Test();
    std::string classification(cv::Vec3b mean);
};

#endif