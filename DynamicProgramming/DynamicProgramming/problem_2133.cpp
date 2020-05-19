/*
  #. [ 2133�� - Ÿ�� ä��� ] Silver II

  #. ����
     3��N ũ���� ���� 2��1, 1��2 ũ���� Ÿ�Ϸ� ä��� ����� ���� ���غ���.

  #. �Է�
     ù° �ٿ� N(1 �� N �� 30)�� �־�����.

  #. ���
     ù° �ٿ� ����� ���� ����Ѵ�.

  #. ���� �Է� 1 
     2
  #. ���� ��� 1 
     3
*/


#include <iostream>
using namespace std;

int dp[31];

int solution(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;
    if (n == 2)
        return 3;
    if (dp[n] != 0)
        return dp[n];

    if (n % 2 == 0)
    {
        int result = 3 * solution(n - 2);
        for (int i = 4; i <= n; i+=2)
            result += 2 * solution(n - i);
        return dp[n] = result;
    }
    else
        return dp[n] = 0;
}

int main()
{
    int n;
    cin >> n;
    cout << solution(n) << "\n";

    return 0;
}