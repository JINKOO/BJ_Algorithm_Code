/*
  #. [ 2��n Ÿ�ϸ� �з� ] - Silver III

  #. ����
     2��n ũ���� ���簢���� 1��2, 2��1 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
     �Ʒ� �׸��� 2��5 ũ���� ���簢���� ä�� �� ���� ����� ���̴�.
  
  #. �Է�
     ù° �ٿ� n�� �־�����. (1 �� n �� 1,000)

  #. ���
     ù° �ٿ� 2��n ũ���� ���簢���� ä��� ����� ���� 10,007�� ���� �������� ����Ѵ�.

  #. ���� �Է� 1 
     2
     ���� ��� 1 
     2

  #. ���� �Է� 2 
     9
     ���� ��� 2 
     55
*/

#include <iostream>
using namespace std;

int dp[1001];

int solution(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (dp[n] != 0)
        return dp[n];
    return dp[n] = (solution(n - 1) + solution(n - 2)) % 10007;
}

void printResult(int answer)
{
    cout << answer << "\n";
}

int main()
{
    int n;
    cin >> n;
    
    printResult(solution(n));
    cout << dp[4] << "\n";
    return 0;
}