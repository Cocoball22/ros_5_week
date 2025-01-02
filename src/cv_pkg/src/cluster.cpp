#include <iostream>
#include <ros/ros.h>
#include "opencv2/opencv.hpp"
#include <ctime>

int main(int argc, char **argv)
{    

  ros::init(argc, argv, "cluster");     // 노드 이름 초기화
  ros::NodeHandle nh;                  // ROS 시스템과 통신을 위한 노드 핸들
  
// 컬러 테이블 미리 생성
    cv::Scalar colorTab[] = {   cv::Scalar(0, 0, 255),
                                cv::Scalar(0,255,0),
                                cv::Scalar(255,0,0),
                                };

    cv::Mat img(500, 500, CV_8UC3);
    // 난수 발생기
    cv::RNG rng(time(NULL));

    for (;;) {
        int k, clusterCount = 5;
        int i, sampleCount = 1000;
        cv::Mat points(sampleCount, 1, CV_32FC2), labels;
        clusterCount = MIN(clusterCount, sampleCount);
        cv::Mat centers;

        for (k = 0; k < clusterCount; k++) {
            cv::Point center;
            center.x = rng.uniform(0, img.cols);
            center.y = rng.uniform(0, img.rows);
            cv::Mat pointChunk = points.rowRange(k * sampleCount / clusterCount, k == clusterCount - 1 ? sampleCount : (k + 1) * sampleCount / clusterCount);
            rng.fill(pointChunk, cv::RNG::NORMAL, cv::Scalar(center.x, center.y), cv::Scalar(img.cols * 0.05, img.rows * 0.05));
        }
        cv::randShuffle(points, 1, &rng);

        cv::kmeans(points, clusterCount, labels, cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 10, 1.0),
            3, cv::KMEANS_PP_CENTERS, centers);
        img = cv::Scalar::all(0);
        for (i = 0; i < sampleCount; i++) {
            int clusterIdx = labels.at<int>(i);
            cv::Point ipt = points.at<cv::Point2f>(i);
            cv::circle(img, ipt, 2, colorTab[clusterIdx], -1);
        }

        cv::imshow("clusters", img);
        char key = (char)cv::waitKey();
        if (key == 27 || key == 'q' || key == 'Q')
            break;
    }
    return 0;
}