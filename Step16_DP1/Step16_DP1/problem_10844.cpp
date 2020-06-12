/*
  #. [ ���� ��� �� ]
  
  #. ����
     45656�̶� ���� ����.
	 �� ���� ������ ��� �ڸ����� ���̰� 1�� ����. �̷� ���� ��� ����� �Ѵ�.
	 �����̴� ���� ���̰� N�� ��� ���� �� �� �ִ��� �ñ�������.
	 
	 N�� �־��� ��, ���̰� N�� ��� ���� �� �� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. (0���� �����ϴ� ���� ����.)

  #. �Է� 
     ù° �ٿ� N�� �־�����. N�� 1���� ũ�ų� ����, 100���� �۰ų� ���� �ڿ����̴�.

  #. ���
     ù° �ٿ� ������ 1,000,000,000���� ���� �������� ����Ѵ�.

  #. ���� �Է� 1 
     1
  #. ���� ��� 1 
     9

  #. ���� �Է� 2 
     2
  #. ���� ��� 2 
     17
*/

#include <iostream>
using namespace std;

#define MOD 1000000000
long long dp[101][11];

long long solution(int n)
{
    long long answer = 0;

    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    dp[1][0] = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j + 1] % MOD;
            else if (j == 9)
                dp[i][j] = dp[i - 1][j - 1] % MOD;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }

    for (int i = 0; i <= 9; i++)
        answer += dp[n][i];

    return answer % MOD;
}

int main() 
{
	int n;
	cin >> n;

	cout << solution(n) << "\n";

	return 0;
}