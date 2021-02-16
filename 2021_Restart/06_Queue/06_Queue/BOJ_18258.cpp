// https://www.acmicpc.net/problem/18258

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 1. N입력 받기
	int N;
	cin >> N;

	// 2. queue선언
	queue <int> q;

	// 3. 명령어 처리
	while (N--)
	{
		string operation;
		cin >> operation;

		if (operation == "push")
		{
			int val;
			cin >> val;
			q.push(val);
		}
		else if (operation == "pop")
		{
			if (q.empty())
				cout << -1 << "\n";
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (operation == "size")
			cout << q.size() << "\n";
		else if (operation == "empty")
			cout << q.empty() << "\n";
		else if (operation == "front")
		{
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.front() << "\n";
		}
		else if (operation == "back")
		{
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.back() << "\n";
		}
	}

	return 0;
}