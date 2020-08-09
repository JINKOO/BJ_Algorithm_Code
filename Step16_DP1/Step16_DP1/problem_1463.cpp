/*
   #. [ ����_1463�� 1�� ����� ] Silver III
   
   #. ����
      ���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.

      - X�� 3���� ������ ��������, 3���� ������.
      - X�� 2�� ������ ��������, 2�� ������.
      - 1�� ����.
      
      ���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�. ������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.
      
   #. �Է�
      ù° �ٿ� 1���� ũ�ų� ����, 10�� 6�º��� �۰ų� ���� ���� N�� �־�����.
   
   #. ���
      ù° �ٿ� ������ �ϴ� Ƚ���� �ּڰ��� ����Ѵ�.
      
   #. ���� �Է� 1 
      2
      ���� ��� 1 
      1
 
   #. ���� �Է� 2 
      10
      ���� ��� 2 
      3
      
   #. ��Ʈ
      10�� ��쿡 10 -> 9 -> 3 -> 1 �� 3�� ���� ���� �� �ִ�.
*/

#include <iostream>
using namespace std;

int dp[1000001];

int getMin(int num1, int num2)
{
    return num1 < num2 ? num1 : num2;
}

int solution(int n)
{
    int answer = 0;
    //
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= n; i++)
    {
        if (i % 2 == 0 && i % 3 == 0)
            dp[i] = getMin(dp[i / 2], dp[i / 3]) + 1;
        else if (i % 2 == 0)
            dp[i] = getMin(dp[i - 1], dp[i / 2]) + 1;
        else if (i % 3 == 0)
            dp[i] = getMin(dp[i - 1], dp[i / 3]) + 1;
        else
            dp[i] = dp[i - 1] + 1;
    }
    answer = dp[n];
    //
    return answer;
}

int main()
{
    int n;
    cin >> n;

    cout << solution(n) << "\n";

    return 0;
}