/*
  #. [ 쉬운 계단 수 ]

  #. 문제
     45656이란 수를 보자.
     이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.
     세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.

     N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

  #. 입력
     첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

  #. 출력
     첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

  #. 예제 입력 1
     1
  #. 예제 출력 1
     9

  #. 예제 입력 2
     2
  #. 예제 출력 2
     17
*/

#include <iostream>
using namespace std;

typedef long long ll;
ll dp[101][11];
int MOD = 1000000000;

int solution(int n)
{
    ll answer = 0;

    //1. base case
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    //2. bottom-up방식
    /*
      N, j  0 1 2 3 4 5 6 7 8 9
      1     0 1 1 1 1 1 1 1 1 1
      2     1 1 2 2 2 2 2 2 2 1 
      3     1 3 3 3 3 3 3 3 3 2

      ex) N = 2일 때,
          첫째 자리가 0인 경우 십의 자리에 올 수 있는 수 : 1     10 
          첫째 자리가 1인 경우 십의 자리에 올 수 있는 수 : 2     21
          첫째 자리가 2인 경우 십의 자리에 올 수 있는 수 : 1,3   12, 23
          첫째 자리가 9인 경우 십의 자리에 올 수 있는 수 : 8     89

      ex) N = 3일 때,
          첫째 자리가 0인 경우 십의 자리에 올 수 있는 수 : 1     10
                         이후 백의 자리에 올 수 있는 수 : 2     210
          첫째 자리가 1인 경우 십의 자리에 올 수 있는 수 : 2     21
                         이후 백의 자리에 올 수 있는 수 : 1,3   101, 121, 321 (십의 자리가 2인 경우 + 십의 자리1인 경우)
          첫째 자리가 2인 경우 십의 자리에 올 수 있는 수 : 1,3   12, 32
                         이후 백의 자리에 올 수 있는 수 : 2, 4  212, 232, 432
          첫째 자리가 3인 경우 십의 자리에 올 수 있는 수 : 2,4   23, 43
                         이후 백의 자리에 올 수 있는 수 : 1,3,5 123, 323, 343, 543 (십의 자리 2인 경우 + 십의 자리 4인 경우)
          첫째 자리가 9인 경우 십의 자리에 올 수 있는 수 : 8    89
                         이후 백의 자리에 올 수 있는 수 : 7,9  789, 989 
          .
          .
          . 

          즉, 
          1. 현재 첫째 자리가 0인 경우      = 전 단계의 첫째 자리가 1인 경우
          2. 현재 첫째 자리가 9인 경우      = 전 단계의 첫째 자리가 8인 경우
          3. 현재 첫째 자리가 i(1~8)인 경우 = 전 단계의 첫째 자리가 i-1인 경우 + i+1인 경우
    */
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
        //여기서도 %하는 이유는 숫자가 너무 커질 수 있기 때문
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















