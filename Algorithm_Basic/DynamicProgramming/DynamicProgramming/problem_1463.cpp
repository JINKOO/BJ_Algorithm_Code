// https://www.acmicpc.net/problem/1463

#include <iostream>
using namespace std;

int dp[1000001];

int getMin(const int& num1, const int& num2) {
	return num1 < num2 ? num1 : num2;
}

int main() {

	int num;
	cin >> num;

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= num; i++) {

		if (i % 2 == 0 && i % 3 == 0)
			dp[i] = getMin(dp[i/2], dp[i / 3]) + 1;
		else if (i % 2 == 0)
			dp[i] = getMin(dp[i / 2], dp[i - 1]) + 1;
		else if (i % 3 == 0)
			dp[i] = getMin(dp[i / 3], dp[i - 1]) + 1;
		else
			dp[i] = dp[i - 1] + 1;
	}
		
	cout << dp[num] << "\n";

	return 0;
}