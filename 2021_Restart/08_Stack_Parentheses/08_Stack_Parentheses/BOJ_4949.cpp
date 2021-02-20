// https://www.acmicpc.net/problem/4949

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{

	while (1)
	{
		// 1. 문자열 입력 (종료조건 '.')
		string sentence;
		getline(cin, sentence);

		if (sentence == ".")
			break;

		// 2. stack선언
		stack<char> stk;

		// 3. 엇갈린 쌍을 만나면 더이상 진행안해도 된다. (empty()인데 닫는 괄호가 나오거나, 짝이 안맞는 경우 false)
		bool flag = true;

		// 3. 입력한 문자열 처음부터 읽으면서 괄호쌍 판별
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

		// 4. stack이 empty()이면 yes, 아니면 no를 출력한다.
		if (flag && stk.empty())
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";

	}
	return 0;
}