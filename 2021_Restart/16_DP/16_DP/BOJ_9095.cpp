// https://www.acmicpc.net/problem/9095
// 1, 2, 3 ¥ı«œ±‚

#include <iostream>
#include <vector>
using namespace std;

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	int TC;
	cin >> TC;

	vector<int> dp(11, 0);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 11; i++)
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

	while (TC--)
	{
		int N;
		cin >> N;

		cout << dp[N] << "\n";
	}


	return 0; 
}