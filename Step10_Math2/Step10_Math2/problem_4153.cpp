/*
  #. 문제 4153 :: 직각삼각형

  #. 문제
     과거 이집트인들은 각 변들의 길이가 3, 4, 5인 삼각형이 직각 삼각형인것을 알아냈다.
     주어진 세변의 길이로 삼각형이 직각인지 아닌지 구분하시오.

  #. 입력
     입력은 여러개의 테스트케이스로 주어지며 마지막줄에는 0 0 0이 입력된다.
     각 테스트케이스는 모두 30,000보다 작은 양의 정수로 주어지며, 각 입력은 변의 길이를 의미한다.

  #. 출력
     각 입력에 대해 직각 삼각형이 맞다면 "right", 아니라면 "wrong"을 출력한다.

  #. 예제 입력 1 >> 6 8 10
                   25 52 60
                   5 12 13
                   0 0 0
  #. 예제 출력 1 << right
                   wrong
                   right
*/

#include <iostream>

void findMidMin(int& mid, int& min, int num2, int num3)
{
    mid = num2 > num3 ? num2 : num3;
    min = num2 < num3 ? num2 : num3;
}

int main()
{
    while (1)
    {
        int x = 0, y = 0, z = 0;
        std::cin >> x >> y >> z;

        if (x == 0 && y == 0 && z == 0)
            break;

        int max = 0, mid = 0, min = 0;
        if (x > y && x > z)
        {
            max = x;
            findMidMin(mid, min, y, z);
        }

        else if (y > x && y > z)
        {
            max = y;
            findMidMin(mid, min, x, z);
        }

        else if (z > x && z > y)
        {
            max = z;
            findMidMin(mid, min, x, y);
        }

        std::cout << max << ">" << mid << ">" << min << "\n";

        if ((max * max) == (mid * mid) + (min * min))
            std::cout << "right" << "\n";
        else
            std::cout << "wrong" << "\n";
    }
    return 0;
}