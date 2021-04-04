// https://www.acmicpc.net/problem/2504
// ��ȣ�� ��

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    // 0. ����� �ӵ� ���
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. ���ڿ� �Է�
    string str;
    cin >> str;

    // 2. stack ����
    stack<char> stk;

    // 3. ����� (), []�� ���� ����ϱ� ���� ����
    int answer = 0;
    int temp = 1;

    // 4. ���ڿ��� ���̴� 30�����̹Ƿ� ���.
    for (int i = 0; i < str.length(); i++)
    {
        // stack�� ������� ������, ��ȣ�� ����
        if (!stk.empty())
        {
            if (stk.top() == '(' && str[i] == ')')
            {
                // ������ ��ȣ�� ( �̾��ٸ�, ������� ����ؾ��Ѵ�. (()())�� ���, ( ���� ù ��°()�� ������ ����� �����ؾ��Ѵ�.
                if (str[i - 1] == '(')
                    answer += temp;

                // �ϴ� ��ȣ���� ������ pop
                stk.pop();
                
                // temp�� �ٽ� 2�� �����ش�. ��? pop()�� �ϸ� �ش� ��ȣ���� ���Ǿ���, �й� ��Ģ�� ���� ��������Ѵ�. (()[]�� ���� ���ذ� ������
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

        // stack�� ����ִٸ� �ϴ� ���� ��ȣ�� ������ stk�� �����ؾ��Ѵ�.
        stk.push(str[i]);

        // temp ����
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