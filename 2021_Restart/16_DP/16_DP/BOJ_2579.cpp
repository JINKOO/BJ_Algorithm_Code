// https://www.acmicpc.net/problem/2579
// 계단 오르기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MX = 301;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> stairs(MX, 0);

	// dp[k][0] :: 현재 연속해서 1개의 계단을 밟고 k번째 계단까지 왔을 때의 최댓값
	// dp[k][1] :: 현재 연속해서 2개의 계단을 밟고 k번째 계단까지 왔을 때의 최댓값
	vector<vector<int>> dp(MX, vector<int>(2, 0));

	for (int i = 1; i <= N; i++)
		cin >> stairs[i];

	dp[1][0] = stairs[1];
	dp[1][1] = stairs[1];
	dp[2][0] = stairs[2];
	//dp[2][1] = stairs[2] + dp[1][0];

	for (int i = 3; i <= N; i++)
	{
		dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + stairs[i];
		dp[i][1] = dp[i - 1][0] + stairs[i];
	}

	cout << max(dp[N][0], dp[N][1]) << "\n";

	return 0;
}