// https://www.acmicpc.net/problem/9012
// 괄호

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // 1. testcase 입력 받기
    int T;
    cin >> T;

    while (T--)
    {
        // 2. stack
        stack<char> stk;

        // 3. 괄호 입력 받기
        string str;
        cin >> str;

        for (const auto& t : str)
        {
            if (!stk.empty() && stk.top() == '(' && t == ')')
            {
                stk.pop();
                continue;
            }

            stk.push(t);
        }

        if (stk.empty())
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";

    }

    return 0;
}