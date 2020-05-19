/*
  #. [ 2133번 - 타일 채우기 ] Silver II

  #. 문제
     3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

  #. 입력
     첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.

  #. 출력
     첫째 줄에 경우의 수를 출력한다.

  #. 예제 입력 1 
     2
  #. 예제 출력 1 
     3
*/


#include <iostream>
using namespace std;

int dp[31];

int solution(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;
    if (n == 2)
        return 3;
    if (dp[n] != 0)
        return dp[n];

    if (n % 2 == 0)
    {
        int result = 3 * solution(n - 2);
        for (int i = 4; i <= n; i+=2)
            result += 2 * solution(n - i);
        return dp[n] = result;
    }
    else
        return dp[n] = 0;
}

int main()
{
    int n;
    cin >> n;
    cout << solution(n) << "\n";

    return 0;
}