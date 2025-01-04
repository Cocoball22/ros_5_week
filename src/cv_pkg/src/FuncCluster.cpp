#include <cv_pkg/Cluster.hpp>

cluster::cluster(/* args */)
{
 step1();
}
cluster::~cluster()
{
}

void cluster::test()
{
  printf("start\n");

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

   for(; number < 22; number++)
   {
    image = cv::imread(input_image[number], cv::IMREAD_COLOR);
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
  
  // 1부터 255까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
  std::uniform_int_distribution<int> dist_b(0, 255);
  std::uniform_int_distribution<int> dist_g(0, 255);
  std::uniform_int_distribution<int> dist_r(0, 255);

  for(int i = 0; i < k; i++)
    { 
      // int y = dist_y(gen);
      b[i] = dist_b(gen);
      g[i] = dist_g(gen);
      r[i] = dist_r(gen);
      current_centroids[i] = {b[i], g[i], r[i]};
      past_centroids[i] = current_centroids[i]; // 이전 값 저장
      std::cout << "current_centroids:" << current_centroids[i] << std::endl;
      // std::cout << "past_centroids:" << past_centroids[i] << std::endl;
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
  std::cout << "image average: " <<  mean << std::endl;
  step3(mean);
}

void cluster::step3(cv::Vec3b mean) 
{
  double distance[3] = {};

  for(int k = 0; k < 3; k++)
  {
    std::cout << "current_centroids: " << current_centroids[k] << std::endl;
    distance[k] = getDistance(mean, current_centroids[k]);
  }
  std::cout <<"distance: " << distance[0] << " " << distance[1] << " " << distance[2] << std::endl;
  double min =  distance[0] < distance[1] ? (distance[0] < distance[2] ? distance[0] : distance[2]) : (distance[1] < distance[2] ? distance[1] : distance[2]);
  // printf("min: %f \n", distance[0] < distance[1] ? (distance[0] < distance[2] ? distance[0] : distance[2]) : (distance[1] < distance[2] ? distance[1] : distance[2]));
  printf("min: %f \n", min);

  if(distance[0] == min)
  {
    data_1[num_1] = mean;
    num_1++;
  }
  else if(distance[1] == min)
  {
    data_2[num_2] = mean;
    num_2++;
  }
  else if(distance[2] == min)
  {
    data_3[num_3] = mean;
    num_3++;
  }
  else
  {
    std::cout << "error" << std::endl;
  }
  std::cout << "num_1: " << num_1 << " "  << "num_2: " << num_2  << " " << "num_3: " << num_3 << " " << std::endl;
}


double cluster::getDistance(const cv::Vec3b& p1, const cv::Vec3b& p2) 
{
  return std::sqrt(std::pow(p1[0] - p2[0], 2) + std::pow(p1[1] - p2[1], 2) + std::pow(p1[2] - p2[2], 2));
}

void::cluster::test2()
{
  cv::Vec3i sum_data_1;
  cv::Vec3i avg_data_1;
  for(int i = 0; i<num_1; i++)
  {
    std::cout << "data_1: " << data_1[i] << std::endl;
    sum_data_1 = sum_data_1 + (cv::Vec3i)data_1[i];
  }
  for(int i = 0; i<num_2; i++)
  {
    std::cout << "data_2: " << data_2[i] << std::endl;
  }
  for(int i = 0; i<num_3; i++)
  {
    std::cout << "data_3: " << data_3[i] << std::endl;
  }
  std::cout << "sum_centroid_1: " << sum_data_1 << std::endl;
  
  if(num_1 > 0)
  {
    avg_data_1 = sum_data_1 / num_1;
    std::cout << "avg_data_1: " << avg_data_1 << std::endl;
  }
  
}

// void::cluster::test2()
// {
//   // std::filesystem::path p(path+"바나나1.png");

//   // std::cout << "내 현재 경로 : " << std::filesystem::current_path() << std::endl;
//   // std::cout << "Does " << p << " exist? [" << std::boolalpha
//   //           << std::filesystem::exists(p) << "]" << std::endl;
//   // std::cout << "Is " << p << " file? [" << std::filesystem::is_regular_file(p)
//   //           << "]" << std::endl;
//   // std::cout << "Is " << p << " directory? [" << std::filesystem::is_directory(p)
//   //           << "]" << std::endl;

//   // std::cout << "상대 경로 : " << p.relative_path() << std::endl;

  

// }