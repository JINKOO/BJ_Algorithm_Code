/*
  #. [ 2��n Ÿ�ϸ� 2 ] - Silver III

  #. ����
     2��n ���簢���� 1��2, 2��1�� 2��2 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
     �Ʒ� �׸��� 2��17 ���簢���� ä�� �Ѱ��� ���̴�.
  
  #. �Է�
     ù° �ٿ� n�� �־�����. (1 �� n �� 1,000)

  #. ���
     ù° �ٿ� 2��n ũ���� ���簢���� ä��� ����� ���� 10,007�� ���� �������� ����Ѵ�.

  #. ���� �Է� 1 
     2
     ���� ��� 1 
     3
  #. ���� �Է� 2 
     8
     ���� ��� 2 
     171
  #. ���� �Է� 3 
     12
     ���� ��� 3 
     2731
*/
#include <iostream>
using namespace std;

int dp[1001];

int solution(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 3;
    if (dp[n] != 0)
        return dp[n];
    return dp[n] = (solution(n - 1) + 2 * solution(n - 2)) % 10007;
}

int main()
{
    int n;
    cin >> n;

    cout << solution(n) << "\n";
    return 0;
}