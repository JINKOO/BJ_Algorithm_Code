// https://www.acmicpc.net/problem/2504
// 괄호의 값

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    // 0. 입출력 속도 향상
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 문자열 입력
    string str;
    cin >> str;

    // 2. stack 선언
    stack<char> stk;

    // 3. 정답과 (), []의 값을 계산하기 위한 변수
    int answer = 0;
    int temp = 1;

    // 4. 문자열의 길이는 30이하이므로 충분.
    for (int i = 0; i < str.length(); i++)
    {
        // stack이 비어있지 않으면, 괄호쌍 연산
        if (!stk.empty())
        {
            if (stk.top() == '(' && str[i] == ')')
            {
                // 직전의 괄호가 ( 이었다면, 결과값을 계산해야한다. (()())의 경우, ( 안의 첫 번째()가 끝나면 결과값 누적해야한다.
                if (str[i - 1] == '(')
                    answer += temp;

                // 일단 괄호쌍이 맞으면 pop
                stk.pop();
                
                // temp를 다시 2로 나눠준다. 왜? pop()을 하면 해당 괄호쌍이 계산되었고, 분배 법칙을 위해 나눠줘야한다. (()[]를 보면 이해가 갈것임
                temp /= 2;
                continue;
            }

            else if (stk.top() == '[' && str[i] == ']')
            {
                if (str[i - 1] == '[')
                    answer += temp;
                stk.pop();
                temp /= 3;
                continue;
            }
        }

        // stack이 비어있다면 일단 여는 괄호는 무조건 stk에 삽입해야한다.
        stk.push(str[i]);

        // temp 조정
        if (str[i] == '(')
            temp *= 2;
        else if (str[i] == '[')
            temp *= 3;
    }

    if (!stk.empty())
        answer = 0;

    cout << answer << "\n";

    return 0;
}