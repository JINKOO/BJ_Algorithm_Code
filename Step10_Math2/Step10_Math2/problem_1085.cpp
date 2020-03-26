/*
  #. 문제 1085 :: 직사각형에서 탈출 

  #. 문제
     한수는 지금 (x, y)에 있다. 직사각형의 왼쪽 아래 꼭짓점은 (0, 0)에 있고, 오른쪽 위 꼭짓점은 (w, h)에 있다. 
     직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.

  #. 입력
     첫째 줄에 x y w h가 주어진다. w와 h는 1,000보다 작거나 같은 자연수이고, x는 1보다 크거나 같고, 
     w-1보다 작거나 같은 자연수이고, y는 1보다 크거나 같고, h-1보다 작거나 같은 자연수이다.

  #. 출력
     첫째 줄에 문제의 정답을 출력한다.

  #. 예제 입력 1 >> 6 2 10 3
     예제 출력 1 >> 1
*/

#include <iostream>

struct Point
{
    int x;
    int y;
};

int main()
{
    int x, y, w, h;
    std::cin >> x >> y >> w >> h;

    Point input_point;
    input_point.x = x;
    input_point.y = y;

    Point pivot_point[4];
    pivot_point[0].x = x;
    pivot_point[0].y = 0;

    pivot_point[1].x = x;
    pivot_point[1].y = h;

    pivot_point[2].x = 0;
    pivot_point[2].y = y;

    pivot_point[3].x = w;
    pivot_point[3].y = y;

    int min = pow(pivot_point[0].x - input_point.x, 2) + pow(pivot_point[0].y - input_point.y, 2);
    for (int i = 1; i < 4; i++)
    {
        int distance = pow(pivot_point[i].x - input_point.x, 2) + pow(pivot_point[i].y - input_point.y, 2);
        if (min <= distance)
            min = distance;
    }

    std::cout << min << "\n";
    return 0;
}