/*
   #. [ ����_9251�� LCS ] Gold V
   
   #. ����
      LCS(Longest Common Subsequence, ���� ���� �κ� ����)������ �� ������ �־����� ��, 
      ����� �κ� ������ �Ǵ� ���� �� ���� �� ���� ã�� �����̴�.
      ���� ���, ACAYKP�� CAPCAK�� LCS�� ACAK�� �ȴ�.
      
   #. �Է�
      ù° �ٰ� ��° �ٿ� �� ���ڿ��� �־�����. ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� ������, 
      �ִ� 1000���ڷ� �̷���� �ִ�.
      
   #. ���
      ù° �ٿ� �Է����� �־��� �� ���ڿ��� LCS�� ���̸� ����Ѵ�.
      
   #. ���� �Է� 1 
      ACAYKP
      CAPCAK
   #. ���� ��� 1 
      4
*/

/*
   #. Ǯ�̹�.
      - 2���� �迭�� dp�� �����. ���ڿ��� ���� + 1��ŭ
      
          A C A Y K P 
        0 0 0 0 0 0 0
      C 0 0 1 1 1 1 1
      A 0 1 1 2 2 2 2
      P 0 1 1 2 2 2 3   
      C 0 1 2 2 2 2 3
      A 0 1 2 3 3 3 3
      K 0 1 2 3 3 4 4

      - ���� �ݺ����� ���鼭, ���� ���� �����̸�, ���� �밢�� + 1
                          ���� �ٸ� �����̸�, max(����, ����)�̴�.
      -  [C, P]�ǹ� :: CAPC, ACAYK�� LCS / CAP, ACAYKP�� LCS �� �ִ��� 3�̴�. CAP
*/
#include <string>
#include <iostream>
using namespace std;

int dp[1001][1001];

int getMax(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

int solution(string &str1, string &str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++) {
            if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = getMax(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n1][n2];
}

int main()
{
    string str1;
    string str2;

    cin >> str1 >> str2;

    cout << solution(str1, str2) << "\n";

    return 0;
}