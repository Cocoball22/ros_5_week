#include <cv_pkg/Cluster.hpp>

cluster::cluster(/* args */)
{
 FirstCentroids();
}
cluster::~cluster()
{
}

void cluster::ImageRead()
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

  // 반복 시작
  while (ros::ok() && !flag_p)
  {
    // 1. 현재 중심점 저장
    for(int i = 0; i < k; i++)
    {
      past_centroids[i] = current_centroids[i];
    }

    // 2. 클러스터링 및 횟수 초기화
    number = 0;
    num_1 = 0; num_2 = 0; num_3 = 0;
    for(; number < 33; number++)
    {
      image = cv::imread(input_image[number], cv::IMREAD_COLOR);
      IamgeAverage(image);
    }
    
    // 3. 새로운 중심점 계산
    FindCentroid();

    bun++;
    std::cout << "bunsu: " << bun << std::endl;
    
    // 4. 이전 중심점이랑 현재 중심점 비교
    if(past_centroids[0] == current_centroids[0] && past_centroids[1] == current_centroids[1] && past_centroids[2] == current_centroids[2])
    {
      flag_p = true;  // 같으면 끝내기
    }

    // 다르면 계속 반복
  }
  printf("finish\n");
}

// 초기 중심점 설정 랜덤 centroids
void cluster::FirstCentroids()
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
      std::cout << "current[" << i << "]: " << current_centroids[i] << std::endl;
      past_centroids[i] = current_centroids[i]; // 이전 값 저장
    }

  // ---------------test--------------------------- 
  // b[0] =  0, g[0] = 0, r[0] = 255;
  // b[1] =  128, g[1] = 0, r[0] = 128;
  // b[2] =  0, g[2] = 255, r[2] = 255;

  // for(int i = 0; i < k; i++)
  //   { 
  //     current_centroids[i] = {b[i], g[i], r[i]};
  //     past_centroids[i] = current_centroids[i]; // 이전 값 저장
  //     std::cout << "current[" << i << "]: " << current_centroids[i] << std::endl;
  //   }
}

// 이미지 평균
void cluster::IamgeAverage(cv::Mat image)
{ 
  unsigned int sum_b = 0, sum_g = 0, sum_r = 0;
  uchar avg_b, avg_g, avg_r;
  int count = 0, cnt = 0;

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
  std::cout << input_image[number] << std::endl;
  mean[cnt] = {avg_b, avg_g, avg_r};
  std::cout << "image average: " <<  mean[cnt] << std::endl;
  Clustring(mean[cnt]);
  cnt++;
}

// 모든것이 끝난 뒤에 분류한 클러스터링
void cluster::Clustring(cv::Vec3b mean) 
{
  double distance[3] = {};

  for(int k = 0; k < 3; k++)
  {
    std::cout << "current_centroids: " << current_centroids[k] << std::endl;
    distance[k] = getDistance(mean, current_centroids[k]);
  }
  std::cout <<"distance: " << distance[0] << " " << distance[1] << " " << distance[2] << std::endl;
  double min =  distance[0] < distance[1] ? (distance[0] < distance[2] ? distance[0] : distance[2]) : (distance[1] < distance[2] ? distance[1] : distance[2]);
 
  printf("min: %f \n", min);

  if(distance[0] == min)
  {
    data_1[num_1] = mean;
    name_1[num_1] = input_image[number];
    num_1++;
    
  }
  if(distance[1] == min)
  {
    data_2[num_2] = mean;
    name_2[num_2] = input_image[number];
    num_2++;
    
  }
  if(distance[2] == min)
  {
    data_3[num_3] = mean;
    name_3[num_3] = input_image[number];
    num_3++;
   
  }
  std::cout << "num_1: " << num_1 << " "  << "num_2: " << num_2  << " " << "num_3: " << num_3 << " " << std::endl;

}


double cluster::getDistance(const cv::Vec3b& p1, const cv::Vec3b& p2) 
{
  return std::sqrt(std::pow(p1[0] - p2[0], 2) + std::pow(p1[1] - p2[1], 2) + std::pow(p1[2] - p2[2], 2));
}

void cluster::FindCentroid()
{
  cv::Vec3i sum_data_1, sum_data_2, sum_data_3;
  cv::Vec3i avg_data_1, avg_data_2, avg_data_3;
  for(int i = 0; i< num_1; i++)
  {
    std::cout << "data_1: " << data_1[i] << " " << name_1[i] << std::endl;
    sum_data_1 = sum_data_1 + (cv::Vec3i)data_1[i];
  }
  for(int i = 0; i< num_2; i++)
  {
    std::cout << "data_2: " << data_2[i] << " " << name_2[i] << std::endl;
    sum_data_2 = sum_data_2 + (cv::Vec3i)data_2[i];
  }
  for(int i = 0; i< num_3; i++)
  {
    std::cout << "data_3: " << data_3[i] << " " << name_3[i] << std::endl;
    sum_data_3 = sum_data_3 + (cv::Vec3i)data_3[i];
  }
  std::cout << "sum_data_1: " << sum_data_1 << std::endl;
  std::cout << "sum_data_2: " << sum_data_2 << std::endl;
  std::cout << "sum_data_3: " << sum_data_3 << std::endl;

  // num_1은 카운트 수
  if(num_1 > 0)
  {
    avg_data_1 = sum_data_1 / num_1;
    current_centroids[0] = (cv::Vec3b)avg_data_1;
    std::cout << "avg_data_1: " << avg_data_1 << std::endl;
  }
  if(num_2 > 0)
  {
    avg_data_2 = sum_data_2 / num_2;
    current_centroids[1] = (cv::Vec3b)avg_data_2;
    std::cout << "avg_data_2: " << avg_data_2 << std::endl;
  }
  if(num_3 > 0)
  {
    avg_data_3 = sum_data_3 / num_3;
    current_centroids[2] = (cv::Vec3b)avg_data_3;
    std::cout << "avg_data_3: " << avg_data_3 << std::endl;
  }

  std::cout << "now: " << current_centroids[0] << current_centroids[1] << current_centroids[2] << std::endl;
  std::cout << "past: " << past_centroids[0] << past_centroids[1] << past_centroids[2] << std::endl; 
}

void cluster::Test()
{
    int n = 0;
    std::filesystem::directory_iterator itr(test_path);

    while (itr != std::filesystem::end(itr)) 
    {
      const std::filesystem::directory_entry& entry = *itr;
      std::cout << entry.path() << std::endl;
      test_image[n] = entry.path();
      n++; 
      itr++;
    }

    // std::cout << test_image[1] << std::endl;

    printf("테스트 이미지의 번호를 입력: ");
    scanf("%d", &input);
    // printf("%d \n",input);

    // 2. 클러스터링 및 횟수 초기화

    image = cv::imread(test_image[input], cv::IMREAD_COLOR);
    TestIamgeAverage(image);
   
}

// 이미지 평균
std::string cluster::TestIamgeAverage(cv::Mat image)
{ 
  unsigned int sum_b = 0, sum_g = 0, sum_r = 0;
  uchar avg_b, avg_g, avg_r;
  int count = 0;

  for(int row = 0; row < image.rows; row++)
  {
    uchar* pointer_row = image.ptr<uchar>(row); 
    for(int col =0; col < image.cols; col++)
    {

      uchar b = pointer_row[col * 3 + 0];
      uchar g = pointer_row[col * 3 + 1];
      uchar r = pointer_row[col * 3 + 2];

      // if((b > 102 && b <160) && (g > 102 && g <160 )&& (r > 102 && r <160))
      // {
      //   continue;
      // }

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
  
  mean[input] = {avg_b, avg_g, avg_r};
  std::cout << "image average: " <<  mean[input] << std::endl;
  return classification(mean[input]);
}

// 분류
// std::string cluster::classification(cv::Vec3b mean) 
// {
//   printf("      \n");
//   std::cout << "classification" << std::endl;

//   double apple_distance[3] = {};
//   double banana_distance[3] = {};
//   double grape_distance[3] = {};
//   double distance[3] = {};

//   double label_distance[3] = {};

//   cv::Vec3b apple(0,0,255); 
//   cv::Vec3b banana(0,255,255); 
//   cv::Vec3b grape(128,0,128); 
//   // printf("%d %d %d\n", apple[0], apple[1], apple[2]);

//   for(int k = 0; k < 3; k++)
//   {
//        apple_distance[k] = getDistance(apple, current_centroids[k]);

//   }
//   for(int k = 0; k < 3; k++)
//   {
//        banana_distance[k] = getDistance(banana, current_centroids[k]);
//   }
//   for(int k = 0; k < 3; k++)
//   {
//        grape_distance[k] = getDistance(grape, current_centroids[k]);
//   }

//   std::cout <<"apple_distance: " << apple_distance[0] << " " << apple_distance[1] << " " << apple_distance[2] << std::endl;
//   std::cout <<"banana_distance: " << banana_distance[0] << " " << banana_distance[1] << " " << banana_distance[2] << std::endl;
//   std::cout <<"grape_distance: " << grape_distance[0] << " " << grape_distance[1] << " " << grape_distance[2] << std::endl;

//   label_distance[0] = apple_distance[0] < apple_distance[1] ? (apple_distance[0] < apple_distance[2] ? apple_distance[0] : apple_distance[2]) : (apple_distance[1] < apple_distance[2] ? apple_distance[1] : apple_distance[2]);
//   label_distance[1] = banana_distance[0] < banana_distance[1] ? (banana_distance[0] < banana_distance[2] ? banana_distance[0] : banana_distance[2]) : (banana_distance[1] < banana_distance[2] ? banana_distance[1] : banana_distance[2]);
//   label_distance[2] = grape_distance[0] < grape_distance[1] ? (grape_distance[0] < grape_distance[2] ? grape_distance[0] : grape_distance[2]) : (grape_distance[1] < grape_distance[2] ? grape_distance[1] : grape_distance[2]);


//   std::cout <<"label_distance: " << label_distance[0] << " " << label_distance[1] << " " << label_distance[2] << std::endl;

//   int apple_n = 0, banana_n = 0, grape_n = 0;

//   for(int k = 0; k < 3; k++)
//   {
//     if(apple_distance[k] == label_distance[0])
//     {
//       apple_n = k;
//     }

//     else if(banana_distance[k] == label_distance[1])
//     {
//       banana_n = k;
//     }

//     else if(grape_distance[k] == label_distance[2])
//     {
//       grape_n = k;
//     }

//   }

//   printf("%d %d %d \n", apple_n, banana_n, grape_n);

//   std::cout << "apple_centroid :" << apple_distance[apple_n] << " " << "banana_distance :" << banana_distance[banana_n] << " " << "grape_distance :" << grape_distance[grape_n] << " " << std::endl;

//   // 선택한 이미지 값과 중심점 값의 차이 중에 가장 작은 값이 과일을 분류 해야하니까
//   for(int k = 0; k < 3; k++)
//   {
//     std::cout << "current_centroids: " << current_centroids[k] << std::endl;
//     distance[k] = getDistance(mean, current_centroids[k]);
//   }

//   std::cout <<"평균 이미지 distance: " << distance[0] << " " << distance[1] << " " << distance[2] << std::endl;

//    // 가장 가까운 중심점 찾기
//   double min = distance[0];
//   int closest_centroid = 0;
  
//   for(int k = 1; k < 3; k++) {
//     if(distance[k] < min) {
//       min = distance[k];
//       closest_centroid = k;
//     }
//   }

//   std::string result;

//   // 가장 가까운 중심점이 어떤 과일에 해당하는지 확인
//   if(closest_centroid == apple_n)
//   {
//     result = "apple";
//     std::cout << "이 이미지는 사과입니다." << std::endl;
//   }
//   else if(closest_centroid == banana_n) 
//   {
//     result = "banana";
//     std::cout << "이 이미지는 바나나입니다." << std::endl;
//   }
//   else if(closest_centroid == grape_n) 
//   {
//     result = "grape";
//     std::cout << "이 이미지는 포도입니다." << std::endl;
//   }

//   return result;
// }

std::string cluster::classification(cv::Vec3b mean) 
{
    // 각 centroid의 특성 파악
    int centroid_label[3]; // 0:포도, 1:바나나, 2:사과

    for(int i = 0; i < 3; i++) 
    {
        // BGR 값 중 가장 큰 값을 찾아서 라벨링
        if(current_centroids[i][2] > current_centroids[i][1] && current_centroids[i][2] > current_centroids[i][0]) 
        {
            centroid_label[i] = 2; // R이 가장 크면 사과
        }
        else if(current_centroids[i][1] > current_centroids[i][2] && current_centroids[i][1] > current_centroids[i][0]) 
        {
            centroid_label[i] = 1; // G가 가장 크면 바나나
        }
        else 
        {
            centroid_label[i] = 0; // B가 가장 크면 포도
        }
    }

    // 입력 이미지와 가장 가까운 centroid 찾기
    double min_distance = getDistance(mean, current_centroids[0]);
    int closest_centroid = 0;

    for(int i = 1; i < 3; i++) 
    {
        double dist = getDistance(mean, current_centroids[i]);
        if(dist < min_distance) 
        {
            min_distance = dist;
            closest_centroid = i;
        }
    }

    // 결과 반환
    std::string result;
    switch(centroid_label[closest_centroid]) 
    {
        case 0:
            result = "grape";
            std::cout << "이 이미지는 포도입니다." << std::endl;
            break;
        case 1:
            result = "banana";
            std::cout << "이 이미지는 바나나입니다." << std::endl;
            break;
        case 2:
            result = "apple";
            std::cout << "이 이미지는 사과입니다." << std::endl;
            break;
    }

    return result;
}