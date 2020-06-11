/*
  #. [ 이친수 ]
  #. 문제
     0과 1로만 이루어진 수를 이진수라 한다. 이러한 이진수 중 특별한 성질을 갖는 것들이 있는데, 
	 이들을 이친수(pinary number)라 한다. 이친수는 다음의 성질을 만족한다.
	 
	 - 이친수는 0으로 시작하지 않는다.
	 - 이친수에서는 1이 두 번 연속으로 나타나지 않는다. 즉, 11을 부분 문자열로 갖지 않는다.
	 - 예를 들면 1, 10, 100, 101, 1000, 1001 등이 이친수가 된다. 
	   하지만 0010101이나 101101은 각각 1, 2번 규칙에 위배되므로 이친수가 아니다.

	 N(1 ≤ N ≤ 90)이 주어졌을 때, N자리 이친수의 개수를 구하는 프로그램을 작성하시오.

  #. 입력
     첫째 줄에 N이 주어진다.

  #. 출력
     첫째 줄에 N자리 이친수의 개수를 출력한다.

  #. 예제 입력 1 
     3
  #. 예제 출력 1 
     2
*/
#include <iostream>
using namespace std;

long long dp[91];

long long solution(int n)
{

	/*dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 2] + dp[i - 1];

	return dp[n];*/
	
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (dp[n] != 0)
		return dp[n];
	else
		return dp[n] = solution(n - 2) + solution(n - 1);
}

int main()
{
	int n;
	cin >> n;

	cout << solution(n) << "\n";

	return 0;
}