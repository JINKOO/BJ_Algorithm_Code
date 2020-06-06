/*
  #. [ RGB거리 ] 아직 미완성코드

  #. 문제
     RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
     집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 
     각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.
     
     1번 집의 색은 2번 집의 색과 같지 않아야 한다.
     N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
     i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

  #. 입력
     첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 
     둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 
     집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

  #. 출력
     첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.

  #. 예제 입력 1 
     3
     26 40 83
     49 60 57
     13 89 99
     예제 출력 1 
     96
*/

#include <iostream>
#include <vector>
using namespace std;

int dp [1001][3];
vector<vector<int>> v(1001, vector<int> (3));

int getMin(int num1, int num2)
{
    return num1 < num2 ? num1 : num2;
}

int solution(int n)
{
    /*if (n == 1)
    {
        colored_index = getMinFirst(v[n-1]);
        return v[n-1][colored_index];
    }
    
    if (dp[n] != 0)
        return dp[n];
    else
        return dp[n] = solution(n - 1) + getMin(v[n - 1], colored_index);*/

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    int i;
    for (i = 1; i <= n; i++)
    {
        dp[i][0] = getMin(dp[i-1][1], dp[i-1][2]) + v[i][0];
        dp[i][1] = getMin(dp[i-1][0], dp[i-1][2]) + v[i][1];
        dp[i][2] = getMin(dp[i-1][0], dp[i-1][1]) + v[i][2];
    }

    return getMin(getMin(dp[n][0], dp[n][1]), dp[n][2]);
}

int main()
{

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    cout << solution(n) << "\n";

    return 0;
}











