/*
  #. [ 1�� ����� �з� ] - Silver III

  #. ����
     ���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.
     
     1. X�� 3���� ������ ��������, 3���� ������.
     2. X�� 2�� ������ ��������, 2�� ������.
     3. 1�� ����.
     
     ���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�. 
     ������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.

  #. �Է�
     ù° �ٿ� 1���� ũ�ų� ����, 106���� �۰ų� ���� ���� N�� �־�����.

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
#include <vector>
using namespace std;

int dp[100001] = {0,1,1};

int getMin(int num1, int num2)
{
    return num1 <= num2 ? num1 : num2;
}

void solution(int val)
{
    /*if (val == 1)
        return 0;
    if (val == 2)
        return 1;
    if (dp[val] != 0)
        return dp[val];*/

    int result = 0;
    for (int i = 3; i <= val; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
            dp[i] = getMin(dp[i], dp[i / 2] + 1);
    }
    cout << dp[val] << "\n";
}

void printResult(int answer)
{
    cout << answer << "\n";
}

int main()
{
    int n;
    cin >> n;
    solution(n);
    //printResult(solution(n));

    return 0;
}