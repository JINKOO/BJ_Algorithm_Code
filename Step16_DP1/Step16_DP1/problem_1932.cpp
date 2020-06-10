#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[501][501];
int cost[501][501];

int getMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

int solution(int n)
{
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			cin >> cost[i][j];
	}
	
	int max = 0;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i == 1)
				dp[i][j] = dp[i - 1][1] + cost[i][j];
			else if (i == j)
				dp[i][j] = dp[i - 1][j - 1] + cost[i][j];
			else
				dp[i][j] = getMax(dp[i - 1][j - 1] + cost[i][j], dp[i - 1][j] + cost[i][j]);
			
			max = getMax(max, dp[i][j]);
		}
	}

	return max;
}

int main()
{
	int n;
	cin >> n;

	cout << solution(n) << "\n";
	return 0;
}