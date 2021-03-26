// https://www.acmicpc.net/problem/12852
// 1로 만들기 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MX = 1000001;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> dp(MX, 0);
	vector<int> prev(MX, 0);

	dp[1] = 0;
	prev[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		if (i % 2 == 0 && i % 3 == 0)
		{
			dp[i] = min(dp[i / 2], dp[i / 3]) + 1;
			prev[i] = (dp[i / 2] <= dp[i / 3]) ? i / 2 : i / 3;
		}

		else if (i % 2 == 0)
		{
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
			prev[i] = (dp[i / 2] <= dp[i - 1]) ? i / 2 : i - 1;
		}

		else if (i % 3 == 0)
		{
			dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
			prev[i] = (dp[i / 3] <= dp[i - 1]) ? i / 3 : i - 1;
		}
		
		else
		{
			dp[i] = dp[i - 1] + 1;
			prev[i] = i - 1;
		}
	}

	cout << dp[N] << "\n";
	
	while (N)
	{
		int curr = N;
		cout << curr << " ";
		if (curr == 1)
			break;
		N = prev[curr];
	}
	
	return 0;
}
