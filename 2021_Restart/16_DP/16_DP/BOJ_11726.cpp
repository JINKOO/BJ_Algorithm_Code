// https://www.acmicpc.net/problem/11726
// 2 X n 타일링

#include <iostream>
#include <vector>
using namespace std;

const int MX = 1001;
const int MOD = 10007;
int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	// 1. N입력
	int N;
	cin >> N;

	// 2. dp[k] = 2 * k의 타일을 채우는 방법의 수
	vector<int> dp(MX, 0);

	// 3. 초기값 설정
	dp[1] = 1;
	dp[2] = 2;

	// 4. 점화식 계산 (본인은 N=5까지의 경우의 수를 직접 세어봄)
	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;

	cout << dp[N] << "\n";

	return 0;
}
