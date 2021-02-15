// https://www.acmicpc.net/problem/10828
// STL stack을 활용한  풀이

#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	while (N > 0)
	{
		string operation;
		cin >> operation;

		if (operation == "push")
		{
			int val;
			cin >> val;
			s.push(val);
		}
		else if (operation == "pop")
		{
			if (!s.empty())
			{
				cout << s.top() << "\n";
				s.pop();
			}
			else
				cout << -1 << "\n";
		}
		else if (operation == "size")
		{
			cout << s.size() << "\n";
		}
		else if (operation == "empty")
		{
			if (s.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (operation == "top")
		{
			if (!s.empty())
				cout << s.top() << "\n";
			else
				cout << -1 << "\n";
		}
		N--;
	}

	return 0;
}