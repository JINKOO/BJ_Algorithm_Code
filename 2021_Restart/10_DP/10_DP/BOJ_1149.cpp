// https://www.acmicpc.net/problem/1149
// RGB �Ÿ�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MX = 1001;
const int RGB = 3;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 1. N�Է� �ް�
	int N;
	cin >> N;

	vector<vector<int>> houses(MX, vector<int>(RGB, 0));
	vector<vector<int>> dp(MX, vector<int>(RGB, 0));

	// 2. �� ���� paint��� �ʱ�ȭ
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < RGB; j++)
			cin >> houses[i][j];
	}

	// 3. dp���
	for (int i = 1; i <= N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + houses[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + houses[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + houses[i][2];
	}

	int answer = *min_element(dp[N].begin(), dp[N].end());

	cout << answer << "\n";

	return 0;
}