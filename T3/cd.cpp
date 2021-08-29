#include <iostream>
#include <cmath>
#include <random>

using std::cout;
using std::endl;


class Point {
int x, y;
 public:
  Point(int pos_x, int pos_y){
    x = pos_x; y = pos_y;
  }

  int getx(){return x;}
  int gety(){return y;}
};


class Geometry {
 public:
  Geometry() {
    num_points = 0;
  }

  void AddPoint(Point &point) {
    point_array[num_points++] = new Point(point.getx(), point.gety());

  }

  // 모든 점들 간의 거리를 출력하는 함수 입니다.
  void PrintDistance();

  // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
  // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
  // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
  // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
  void PrintNumMeets();

private:
  // 점 100 개를 보관하는 배열.
  Point* point_array[100];
  int num_points;
};

void Geometry::PrintDistance()
{
  double total=0;
  for(int i=0 ; i<num_points-1; i++)
  {
    for(int j=i+1; j<num_points; j++)
    {
      int x1 = point_array[i]->getx(); int x2 = point_array[j]->getx();
      int y1 = point_array[i]->gety(); int y2 = point_array[j]->gety();
      total += sqrt(pow((x1-x2),2) + pow((y1-y2),2));
    } 
  }
  cout<< "거리의 총합 : " << total << " 입니다." << endl;
}

int main()
{
  // 시드 값을 얻기 위한 random_device 생성
    std::random_device rd;

    // random_device를 통해 난수 생성 엔진을 초기화
    std::mt19937 gen(rd());

    // 0부터 99까지 균등하게 나타나는 난수 열을 생성하기 위해 균등 분포 정의
    std::uniform_int_distribution<int> dis(0, 99);

    // point 개수
    const int NUM_OF_POINT = 8;

    Geometry geometry;
    
    for (int i = 0; i < NUM_OF_POINT; i++) {
        std::cout << "난수 : " << dis(gen) <<", " << dis(gen) <<std::endl;
        Point point(dis(gen), dis(gen));
        geometry.AddPoint(point);
    }
    geometry.PrintDistance();
    return 0;
}