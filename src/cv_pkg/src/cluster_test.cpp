#include <cv_pkg/cv_pkg_node.hpp>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "cluster_test");     // 노드 이름 초기화
  ros::NodeHandle nh;                  // ROS 시스템과 통신을 위한 노드 핸들
    
    std::string imagePath = "/home/cona/catkin_ws/src/cv_pkg/src/fruit-png/바나나10.png";
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);

    if (image.empty()) 
    {
        std::cerr << "Failed to load image at: " << imagePath << std::endl;
        return -1;
    }

    // 이미지 정보 출력
    std::cout << "Image Size: " << image.cols << "x" << image.rows << std::endl;


    cv::namedWindow("image");
    cv::imshow("image", image);

    // 메르센 트위스터 기반의 RNG 생성
    cv::RNG rng(cv::getTickCount());  // 초기 시드 값 설정 (Tick Count 사용)

    // 1. 정수 난수 생성
    int centroid_1 = rng.uniform(0, 100);  // 0에서 99 사이의 정수 난수 생성
    int centroid_2 = rng.uniform(0, 100);  // 0에서 99 사이의 정수 난수 생성
    int centroid_3 = rng.uniform(0, 100);  // 0에서 99 사이의 정수 난수 생성
    std::cout << "centroid: " << centroid_1 << " " << centroid_2 <<  " " << centroid_3 << std::endl;

    cv::waitKey(0);
    return 0;
}