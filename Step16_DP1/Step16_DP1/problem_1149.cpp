/*
  #. [ RGB�Ÿ� ] ���� �̿ϼ��ڵ�

  #. ����
     RGB�Ÿ����� ���� N�� �ִ�. �Ÿ��� �������� ��Ÿ�� �� �ְ�, 1�� ������ N�� ���� ������� �ִ�.
     ���� ����, �ʷ�, �Ķ� �� �ϳ��� ������ ĥ�ؾ� �Ѵ�. 
     ������ ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� �־����� ��, �Ʒ� ��Ģ�� �����ϸ鼭 ��� ���� ĥ�ϴ� ����� �ּڰ��� ���غ���.
     
     1�� ���� ���� 2�� ���� ���� ���� �ʾƾ� �Ѵ�.
     N�� ���� ���� N-1�� ���� ���� ���� �ʾƾ� �Ѵ�.
     i(2 �� i �� N-1)�� ���� ���� i-1��, i+1�� ���� ���� ���� �ʾƾ� �Ѵ�.

  #. �Է�
     ù° �ٿ� ���� �� N(2 �� N �� 1,000)�� �־�����. 
     ��° �ٺ��� N���� �ٿ��� �� ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� 1�� ������ �� �ٿ� �ϳ��� �־�����. 
     ���� ĥ�ϴ� ����� 1,000���� �۰ų� ���� �ڿ����̴�.

  #. ���
     ù° �ٿ� ��� ���� ĥ�ϴ� ����� �ּڰ��� ����Ѵ�.

  #. ���� �Է� 1 
     3
     26 40 83
     49 60 57
     13 89 99
     ���� ��� 1 
     96
*/

#include <iostream>
#include <vector>
using namespace std;

int dp [1001][3];
vector<vector<int>> v(1001, vector<int> (3));

int getMin(int num1, int num2)
{
    return num1 < num2 ? num1 : num2;
}

int solution(int n)
{
    /*if (n == 1)
    {
        colored_index = getMinFirst(v[n-1]);
        return v[n-1][colored_index];
    }
    
    if (dp[n] != 0)
        return dp[n];
    else
        return dp[n] = solution(n - 1) + getMin(v[n - 1], colored_index);*/

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    int i;
    for (i = 1; i <= n; i++)
    {
        dp[i][0] = getMin(dp[i-1][1], dp[i-1][2]) + v[i][0];
        dp[i][1] = getMin(dp[i-1][0], dp[i-1][2]) + v[i][1];
        dp[i][2] = getMin(dp[i-1][0], dp[i-1][1]) + v[i][2];
    }

    return getMin(getMin(dp[n][0], dp[n][1]), dp[n][2]);
}

int main()
{

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    cout << solution(n) << "\n";

    return 0;
}











