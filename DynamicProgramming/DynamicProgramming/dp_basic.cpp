/*
  [ Dynamic Programming(DP), 동적 계획법 ]

  #. 하나의 문제는 단 한번만 푼다! with Memoization

  #. 단순 분할 정복의 단점(같은 문제를 여러 번 푸는 것)을 해결
     피보나치 수열을 단순 분할 정복으로 해결하면 동일한 문제를 여러번 해결하는 비효율성 발생
     50번째 값을 구할 때 계산 수 최소 >= 2의 50제곱
      but 분할 정복에서 정렬(quick, merge sort)는 단점을 보이지 않는다.

  #. DP가정
     1. 큰 문제는 작은 문제로 나눌 수 있다.
     2. 작은 문제의 solution은 큰 문제에서도 동일하다.(with memoization)
 
  #. DP를 사용하면 O(n)으로 줄일 수 있다.

  
  #. 좁은 의미의 DP는 Memoization과 구별된다.
      - Memoization에서는 recursion이 기본(top-down방식)
     
     넓은 의미로 DP는 Memoization을 포함한다.
      - bottom-up방식을 선호한다. recursion은 많은 overhead.

*/

#include <iostream>
using namespace std;

long long d[100];

long long fibonacci(long long x)
{
    if (x == 1) return 1;
    if (x == 2) return 1;
    if (d[x] != 0) return d[x];
    return d[x] = fibonacci(x - 1) + fibonacci(x - 2);
}

int main()
{
    cout << fibonacci(50) << "\n";
}












