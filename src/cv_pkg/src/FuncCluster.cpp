#include <cv_pkg/Cluster.hpp>

cluster::cluster(/* args */)
{
 
}
cluster::~cluster()
{
}

void cluster::test()
{
  printf("start\n");
   for(; number < 20; number++)
   {
    image = cv::imread(input_image[number], cv::IMREAD_COLOR);
    step1();
    step2(image);
   }
   printf("finish\n");

}

// 초기 중심점 설정 랜덤 centroids
void cluster::step1()
{
  // 시드값을 얻기 위한 random_device 생성.
  std::random_device rd;

  // random_device를 통해 난수 생성 엔진을 초기화 한다.
  std::mt19937 gen(rd());

  // std::mt19937 mt((unsigned int)time(NULL)); // 시드값 123
  
  // 1부터 500까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
  std::uniform_int_distribution<int> dist_b(0, 254);
  std::uniform_int_distribution<int> dist_g(0, 254);
  std::uniform_int_distribution<int> dist_r(0, 254);

  cv::Vec3b centroids;

  for(int i = 0; i < k; i++)
  {
    // int y = dist_y(gen);
    uchar b = dist_b(gen);
    uchar g = dist_g(gen);
    uchar r = dist_r(gen);
    centroids = {b, g, r};
    // printf("%d, %d, %d\n",centroids[0],centroids[1],centroids[2]);
  }
  
}

// 데이터를 군집에 할당
void cluster::step2(cv::Mat image)
{ 
  unsigned int sum_b = 0, sum_g = 0, sum_r = 0;
  uchar avg_b, avg_g, avg_r;
  int count;
  cv::Vec3b mean;
  for(int row = 0; row < image.rows; row++)
  {
    uchar* pointer_row = image.ptr<uchar>(row); 
    for(int col =0; col < image.cols; col++)
    {

      uchar b = pointer_row[col * 3 + 0];
      uchar g = pointer_row[col * 3 + 1];
      uchar r = pointer_row[col * 3 + 2];

      if(b > 240 && g > 240 && r > 240)
      {
        continue;
      }
      sum_b = sum_b + b;
      sum_g = sum_g + g;
      sum_r = sum_r + r;
      count++;
    }
  }
  avg_b = sum_b/count;
  avg_g = sum_g/count;
  avg_r = sum_r/count;

  // printf("%d,%d,%d\n",sum_b, sum_g, sum_r);
  
  mean = {avg_b, avg_g, avg_r};
  std::cout <<  mean << std::endl;
  step3(mean);
}

void cluster::step3(cv::Vec3b mean) {
    // 노란색 범위
    cv::Vec3b lower_yellow(0, 128, 128);
    cv::Vec3b upper_yellow(50, 255, 255);

    // 보라색 범위 (예시로 설정)
    cv::Vec3b lower_purple(64, 0, 64);
    cv::Vec3b upper_purple(150, 150, 255);

    // mean 값이 노란색 범위에 포함되는지 확인
    if ((mean[0] >= lower_yellow[0] && mean[0] <= upper_yellow[0]) &&
        (mean[1] >= lower_yellow[1] && mean[1] <= upper_yellow[1]) &&
        (mean[2] >= lower_yellow[2] && mean[2] <= upper_yellow[2])) 
    {
        std::cout << "yellow" << std::endl;
        yellow_data[number] = input_image[number];
        std::cout << yellow_data[number] << std::endl;
    }
    // mean 값이 보라색 범위에 포함되는지 확인
    else if ((mean[0] >= lower_purple[0] && mean[0] <= upper_purple[0]) &&
             (mean[1] >= lower_purple[1] && mean[1] <= upper_purple[1]) &&
             (mean[2] >= lower_purple[2] && mean[2] <= upper_purple[2])) 
    {
        std::cout << "purple" << std::endl;
        purple_data[number] = input_image[number];
        std::cout << purple_data[number] << std::endl;
    } 
    else 
    {
        std::cout << "Color not detected" << std::endl;
    }
}


double getDistance(const cv::Vec3b& p1, const cv::Vec3b& p2) 
{
  return std::sqrt(std::pow(p1[0] - p2[0], 2) + std::pow(p1[1] - p2[1], 2) + std::pow(p1[2] - p2[2], 2));
}

void::cluster::test2()
{
  // std::filesystem::path p(path+"바나나1.png");

  // std::cout << "내 현재 경로 : " << std::filesystem::current_path() << std::endl;
  // std::cout << "Does " << p << " exist? [" << std::boolalpha
  //           << std::filesystem::exists(p) << "]" << std::endl;
  // std::cout << "Is " << p << " file? [" << std::filesystem::is_regular_file(p)
  //           << "]" << std::endl;
  // std::cout << "Is " << p << " directory? [" << std::filesystem::is_directory(p)
  //           << "]" << std::endl;

  // std::cout << "상대 경로 : " << p.relative_path() << std::endl;

  int n = 0;
  std::filesystem::directory_iterator itr(path);
  while (itr != std::filesystem::end(itr)) 
  {
    const std::filesystem::directory_entry& entry = *itr;
    std::cout << entry.path() << std::endl;
    input_image[n] = entry.path();
    n++; 
    itr++;
  }

}