/*
   #. [ 백준_9251번 LCS ] Gold V
   
   #. 문제
      LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 
      모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
      예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.
      
   #. 입력
      첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 
      최대 1000글자로 이루어져 있다.
      
   #. 출력
      첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.
      
   #. 예제 입력 1 
      ACAYKP
      CAPCAK
   #. 예제 출력 1 
      4
*/

/*
   #. 풀이법.
      - 2차원 배열의 dp를 만든다. 문자열의 길이 + 1만큼
      
          A C A Y K P 
        0 0 0 0 0 0 0
      C 0 0 1 1 1 1 1
      A 0 1 1 2 2 2 2
      P 0 1 1 2 2 2 3   
      C 0 1 2 2 2 2 3
      A 0 1 2 3 3 3 3
      K 0 1 2 3 3 4 4

      - 이중 반복문을 돌면서, 서로 같은 문자이면, 왼쪽 대각선 + 1
                          서로 다른 문자이면, max(왼쪽, 위쪽)이다.
      -  [C, P]의미 :: CAPC, ACAYK의 LCS / CAP, ACAYKP의 LCS 중 최댓값은 3이다. CAP
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