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
int SIZE = 1000000;

int main()
{
    //에라토스테네스의 채를 사용한다.
    int m, n;
    std::cin >> m >> n;

    //1 ~ 1,000,000숫자에 대하여 true로 초기회
    bool* num_arr = new bool[SIZE + 1];
    
    num_arr[1] = false;
    for (int i = 2; i <= SIZE; i++)
        num_arr[i] = true;

    for (int i = 2; i * i <= SIZE; i++)
    {
        if (num_arr[i])
        {
            for (int j = i * i; j <= SIZE; j += i)
                num_arr[j] = false;
        }
    }

    for (int i = m; i <= n; i++)
    {
        if (num_arr[i])
            std::cout << i << "\n";
    }

    return 0;
}