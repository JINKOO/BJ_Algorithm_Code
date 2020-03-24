/*
  #. 문제 1929 ::  소수 구하기 

  #. 문제
     M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

  #. 입력
     첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000)

  #. 출력
     한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.

  #. 예제 입력 1 >> 3 16

     예제 출력 1 << 3
                   5
                   7
                   11
                   13
*/

#include <iostream>
int main()
{
    int M, N = 0;
    std::cin >> M >> N;

    for (int num = M; num <= N; num++)
    {
        int divided_number = 1, count = 0;
        while (divided_number <= num)
        {
            if ((num % divided_number) == 0)
                count++;
            divided_number++;
        }
        if (count == 2)
            printf("%d\n", num);
    }
    return 0;
}