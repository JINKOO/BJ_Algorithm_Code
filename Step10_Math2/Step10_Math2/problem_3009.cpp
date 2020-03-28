/*
  #. 문제 3009 :: 네 번째 점 

  #. 문제
     세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한 네 번째 점을 찾는 프로그램을 작성하시오.

  #. 입력
     세 점의 좌표가 한 줄에 하나씩 주어진다. 좌표는 1보다 크거나 같고, 1000보다 작거나 같은 정수이다.

  #. 출력
     직사각형의 네 번째 점의 좌표를 출력한다.

  #. 예제 입력 1 >>  30 20
                    10 10
                    10 20
     예제 출력 1 <<  30 10

*/

#include <iostream>
struct Point
{
    int x;
    int y;
};

int main()
{
    //1. 구조체 배열 선언
    Point p[3];

    //2. 4번째 직사각형 좌표 변수 초기화
    int last_x = 0, last_y = 0;

    //3. 직사각형 1~3번째 좌표값 입력 받기
    for (int i = 0; i < 3; i++)
    {
        int x, y;
        std::cin >> x >> y;
        p[i].x = x;
        p[i].y = y;
    }

    /*4. 각 축에 평행한 직사각형 이려면,
      4개의 좌표에서 각각 2개씩 좌표값이 같아야 한다.*/

    //4.1 4번째 x좌표 구하기
    if (p[0].x == p[1].x)
        last_x = p[2].x;
    else if (p[0].x == p[2].x)
        last_x = p[1].x;
    else if (p[1].x == p[2].x)
        last_x = p[0].x;

    //4.2 4번째 y좌표 구하기.
    if (p[0].y == p[1].y)
        last_y = p[2].y;
    else if (p[0].y == p[2].y)
        last_y = p[1].y;
    else if (p[1].y == p[2].y)
        last_y = p[0].y;

    //5. 5번째 결과 출력
    std::cout << last_x << " " << last_y << "\n";

    return 0;
}