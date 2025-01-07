#include <cv_pkg/Cluster.hpp>

bool ClassifyImage(cv_pkg::ImageClassify::Request  &req, cv_pkg::ImageClassify::Response &res)
{
   ROS_INFO("Received request with image path: %s", req.image_path.c_str());
    // 이미지 로드
    cv::Mat classify_image = cv::imread(req.image_path);
    if(classify_image.empty()) 
    {
        ROS_ERROR("Failed to load image");
        return false;
    }

    cluster cl;
    // TestImageAverage의 결과를 받아서 서비스 응답으로 전달
    std::string result = cl.TestIamgeAverage(classify_image);

     // 결과를 Response 메시지에 저장
    res.fruit_type = result;  // result 필드 이름은 srv 파일 정의에 맞게 수정

    return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "cluster");     // 노드 이름 초기화
  ros::NodeHandle nh;                  // ROS 시스템과 통신을 위한 노드 핸들

  cluster cl;

  cl.ImageRead();


  ros::ServiceServer service = nh.advertiseService("fruit_classify", ClassifyImage);

  ROS_INFO("Ready to ImageClassify.");
  ros::spin();
   
  return 0;
}

