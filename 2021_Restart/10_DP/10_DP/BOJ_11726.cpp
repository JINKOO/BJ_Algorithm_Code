// https://www.acmicpc.net/problem/11726
// 2 X n Ÿ�ϸ�

#include <iostream>
#include <vector>
using namespace std;

const int MX = 1001;
const int MOD = 10007;
int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	// 1. N�Է�
	int N;
	cin >> N;

	// 2. dp[k] = 2 * k�� Ÿ���� ä��� ����� ��
	vector<int> dp(MX, 0);

	// 3. �ʱⰪ ����
	dp[1] = 1;
	dp[2] = 2;

	// 4. ��ȭ�� ��� (������ N=5������ ����� ���� ���� ���)
	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;

	cout << dp[N] << "\n";

	return 0;
}
