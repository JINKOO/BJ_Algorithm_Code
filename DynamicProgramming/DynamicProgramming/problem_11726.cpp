/*
  #. [ 2×n 타일링 분류 ] - Silver III

  #. 문제
     2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
     아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.
  
  #. 입력
     첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

  #. 출력
     첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

  #. 예제 입력 1 
     2
     예제 출력 1 
     2

  #. 예제 입력 2 
     9
     예제 출력 2 
     55
*/

#include <iostream>
using namespace std;

int dp[1001];

int solution(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (dp[n] != 0)
        return dp[n];
    return dp[n] = (solution(n - 1) + solution(n - 2)) % 10007;
}

void printResult(int answer)
{
    cout << answer << "\n";
}

int main()
{
    int n;
    cin >> n;
    
    printResult(solution(n));
    cout << dp[4] << "\n";
    return 0;
}