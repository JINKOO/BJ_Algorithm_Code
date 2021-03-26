// https://www.acmicpc.net/problem/1463
// 1로 나누기 (DP, or BFS)

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
	dp[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		if (i % 2 == 0 && i % 3 == 0)
			dp[i] = min(dp[i / 2], dp[i / 3]) + 1;
		else if (i % 2 == 0)
			dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
		else if (i % 3 == 0)
			dp[i] = min(dp[i - 1], dp[i / 3]) + 1;
		else
			dp[i] = dp[i - 1] + 1;
	}

	cout << dp[N] << "\n";

	return 0;
}