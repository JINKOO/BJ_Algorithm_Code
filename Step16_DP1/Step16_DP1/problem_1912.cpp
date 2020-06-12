/*
  #. [ 연속합 ]
  
  #. 문제
     n개의 정수로 이루어진 임의의 수열이 주어진다. 
     우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 
     단, 수는 한 개 이상 선택해야 한다.

     예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 
     여기서 정답은 12+21인 33이 정답이 된다.

  #. 입력
     첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 
     수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

  #. 출력
     첫째 줄에 답을 출력한다.
     
  #. 예제 입력 1 
     10
     10 -4 3 1 5 6 -35 12 21 -1
  #. 예제 출력 1 
     33

  #. 예제 입력 2 
     10
     2 1 -4 3 4 -4 6 5 -5 1
  #. 예제 출력 2 
     14

  #. 예제 입력 3 
     5
     -1 -2 -3 -4 -5
  #. 예제 출력 3 
    -1
*/
#include <iostream>
using namespace std;

int dp[100001];
int cost[100001];

int getMax(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

int solution(int n)
{
    /*
     dp[i] = dp[i-1] + cost[i]이지만
     현재 전까지의 합이 현재 cost[i]보다 작으면
     cost[i]부터 다시 합하여 간다. 
     이후 이전의 max와 비교하여 더 큰 값이 정답.
    */
    dp[1] = cost[1];
    int max = dp[1];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = getMax(dp[i-1] + cost[i], cost[i]);
        max = getMax(max, dp[i]);
    }
    return max;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    cout << solution(n) << "\n";

    return 0;
}











