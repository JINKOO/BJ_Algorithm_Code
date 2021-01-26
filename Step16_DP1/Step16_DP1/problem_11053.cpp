/*
   #. [ 백준_11053번 가장 긴 증가하는 부분 수열 ] Silver II
   
   #. 문제
      수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
	  예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
	  
   #. 입력
      - 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
	  - 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

   #. 출력
      첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
	  
   #. 예제 입력 1 
      6
	  10 20 10 30 20 50
   #. 예제 출력 1 
      4
*/

/*
   #. 나의 풀이법.
      - cost[0]값을 max로 잡고, cost[]를 반복하면서 더 큰값이 나오면 dp[i]를 1로 갱신하고
	    dp[i] = getMax(max, dp[i-1]) + 1 라는 점화식으로 풀었다.
	    잘못된 접근이었다.
   
   #. 풀이법 (구글링 도움)
      - cost에서 cost[i]보다 작은 값들만 탐색한다.
	  - 작은 값들만 탐색하면서 dp[]중 가장 큰 값을 찾는다.
	    점화식 : dp[i] = max + 1;
*/
#include <iostream>
#include <vector>
using namespace std;

int dp[1001];
int cost[1001];

int solution(int n)
{
	int answer = 0;
	dp[0] = 0;
	
	//cost[i]일 때, dp[i]는 i까지 중 cost[i]보다 작은 값만 찾고, 이 중 가장 큰 dp값을 찾는다.
	//이후 dp[i] = max + 1;
	for (int i = 1; i <= n; i++)
	{
		int max_dp = 0;
		for (int j = 1; j <= i; j++)
		{
			if (cost[i] > cost[j])
			{
				if (max_dp < dp[j])
					max_dp = dp[j];
			}
		}
		dp[i] = max_dp + 1;
	}

	
	for (int i = 0; i <= n; i++)
	{
		cout << dp[i] << " ";
		if (answer < dp[i])
			answer = dp[i];
	}

	return answer;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}

	cout << solution(n) << "\n";

	return 0;
}