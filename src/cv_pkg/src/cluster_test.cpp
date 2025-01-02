#include <cv_pkg/cv_pkg_node.hpp>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "cluster_test");     // 노드 이름 초기화
  ros::NodeHandle nh;                  // ROS 시스템과 통신을 위한 노드 핸들
    
    std::string imagePath = "../fruit/바나나1.jpeg";
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);

    if (image.empty()) 
    {
        std::cerr << "Failed to load image at: " << imagePath << std::endl;
        return -1;
    }

    // 이미지 정보 출력
    std::cout << "Image Size: " << image.cols << "x" << image.rows << std::endl;

    cv::imshow("Loaded Image", image);
    cv::Mat src = cv::imread("$(find)");

    // 메르센 트위스터 기반의 RNG 생성
    cv::RNG rng(cv::getTickCount());  // 초기 시드 값 설정 (Tick Count 사용)

    // 1. 정수 난수 생성
    int randomInt = rng.uniform(0, 100);  // 0에서 99 사이의 정수 난수 생성
    std::cout << "Random Integer: " << randomInt << std::endl;

    // 2. 실수 난수 생성
    double randomDouble = rng.uniform(0.0, 1.0);  // 0.0에서 1.0 사이의 실수 난수 생성
    std::cout << "Random Double: " << randomDouble << std::endl;

    // 3. 정규 분포 난수 생성
    double randomGaussian = rng.gaussian(1.0);  // 평균 0, 표준편차 1.0의 정규 분포 난수 생성
    std::cout << "Random Gaussian: " << randomGaussian << std::endl;

    // 4. 난수를 이용한 이미지 생성 (255 범위의 픽셀 값으로 채우기)
    cv::Mat randomImage(300, 300, CV_8UC1);  // 300x300 크기의 흑백 이미지
    rng.fill(randomImage, cv::RNG::UNIFORM, 0, 255);  // 0~255 범위의 난수로 채우기
    cv::imshow("Random Image", randomImage);

    cv::waitKey(0);
    return 0;
}