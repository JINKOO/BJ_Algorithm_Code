// https://www.acmicpc.net/problem/4949

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{

	while (1)
	{
		// 1. ���ڿ� �Է� (�������� '.')
		string sentence;
		getline(cin, sentence);

		if (sentence == ".")
			break;

		// 2. stack����
		stack<char> stk;

		// 3. ������ ���� ������ ���̻� ������ص� �ȴ�. (empty()�ε� �ݴ� ��ȣ�� �����ų�, ¦�� �ȸ´� ��� false)
		bool flag = true;

		// 3. �Է��� ���ڿ� ó������ �����鼭 ��ȣ�� �Ǻ�
		for (char c : sentence)
		{
			if (c == '(' || c == '[')
				stk.push(c);

			else if (c == ')')
			{
				if (!stk.empty() && stk.top() == '(')
					stk.pop();
				else
				{
					flag = false;
					break;
				}
			}

			else if (c == ']')
			{
				if (!stk.empty() && stk.top() == '[')
					stk.pop();
				else
				{
					flag = false;
					break;
				}
			}
		}

		// 4. stack�� empty()�̸� yes, �ƴϸ� no�� ����Ѵ�.
		if (flag && stk.empty())
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";

	}
	return 0;
}