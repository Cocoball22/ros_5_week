#include "ros/ros.h"
#include "cv_pkg/ImageClassify.h"
#include <filesystem>
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "fruit_classify_client");
  

  std::string test_path = "/home/hyun/ros_5_week/src/cv_pkg/src/test/";
  std::string test_image[13] = {};
  int n = 0;
  

  std::filesystem::directory_iterator itr(test_path);

    while (itr != std::filesystem::end(itr)) 
    {
      const std::filesystem::directory_entry& entry = *itr;
      // std::cout << entry.path() << std::endl;
      test_image[n] = entry.path();
      // std::cout << test_image[n] << std::endl;
      n++; 
      itr++;
    }

  ros::NodeHandle nh;
  ros::ServiceClient client = nh.serviceClient<cv_pkg::ImageClassify>("fruit_classify");
  cv_pkg::ImageClassify srv;

  while (ros::ok())
  {
   char name[100];
   std::cout << "\n사용 가능한 이미지 목록:" << std::endl;
    for(int i = 0; i < n; i++) 
    {
      std::cout << i + 1 << ". " << test_image[i] << std::endl;
    }

    printf("\n확인할 이미지를 적어주세요 (종료하려면 'q' 입력): ");
    scanf("%s", name);
    
    // 종료 조건
    if(name[0] == 'q' || name[0] == 'Q') 
    {
      ROS_INFO("프로그램을 종료합니다.");
      break;
    }


  // 입력받은 이미지 이름으로 서비스 호출
  std::string target_image = test_path + std::string(name);

  srv.request.image_path = target_image;

  if (client.call(srv))
  {
     ROS_INFO("Image: %s is %s", target_image.c_str(), srv.response.fruit_type.c_str());
  }
  else
  {
    ROS_ERROR("Failed to process image");
    continue;
  }

  ros::spinOnce();  // 콜백 처리를 위해 필요
  
  }
  
  return 0;
}