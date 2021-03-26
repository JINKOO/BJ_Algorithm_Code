// https://www.acmicpc.net/problem/9012
// ��ȣ

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // 1. testcase �Է� �ޱ�
    int T;
    cin >> T;

    while (T--)
    {
        // 2. stack
        stack<char> stk;

        // 3. ��ȣ �Է� �ޱ�
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