// https://www.acmicpc.net/problem/11659
// 구간 합 구하기

#include <iostream>
#include <vector>
using namespace std;

const int MX = 100001;

// 시간초과 코드
// 최악의 경우 100억번 연산 수행
void solution1()
{
	int N, M;
	cin >> N >> M;

	vector<int> nums(MX, 0);

	for (int i = 0; i < N; i++)
		cin >> nums[i];

	while (M--)
	{
		int i, j;
		cin >> i >> j;

		int total = 0;
		for (int k = i - 1; k <= j - 1; k++)
			total += nums[k];

		cout << total << "\n";
	}
}

// Prefix Sum방식 이용 (DP)
// Prefix sum을 문제를 푸는 과정에서 시간복잡도를 줄이는 기법 중 하나
void solution2()
{
	int N, M;
	cin >> N >> M;

	vector<int> nums(MX, 0);
	vector<int> dp(MX, 0);

	// dp[i] = a[0] + a[1] + a[2] + ... + a[i];
	// dp[i] = dp[i - 1] + a[i];
	/*
	   a[i] + a[i + 1] + ... + a[j]
	   = a[1] + a[2] + ... + a[j] - (a[1] + a[2] + ... + a[i-1])
	   = dp[j] - dp[i-1];
	*/

	for (int i = 1; i <= N; i++)
		cin >> nums[i];

	dp[0] = 0;
	dp[1] = nums[1];
	for (int i = 1; i <= N; i++)
		dp[i] = dp[i - 1] + nums[i];

	while (M--)
	{
		int total = 0;

		int i, j;
		cin >> i >> j;

		total = dp[j] - dp[i - 1];

		cout << total << "\n";
	}
}

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	//solution1();
	solution2();

	return 0;
}