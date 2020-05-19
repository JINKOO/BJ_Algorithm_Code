/*
  #. [ 1로 만들기 분류 ] - Silver III

  #. 문제
     정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
     
     1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
     2. X가 2로 나누어 떨어지면, 2로 나눈다.
     3. 1을 뺀다.
     
     정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 
     연산을 사용하는 횟수의 최솟값을 출력하시오.

  #. 입력
     첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 정수 N이 주어진다.

  #. 출력
     첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

  #. 예제 입력 1 
     2
     예제 출력 1 
     1

  #. 예제 입력 2 
     10
     예제 출력 2 
     3
  
  #. 힌트
     10의 경우에 10 -> 9 -> 3 -> 1 로 3번 만에 만들 수 있다.
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