// https://www.acmicpc.net/problem/10845
// STL queue를 사용한 풀이

#include <iostream>
#include <queue>
using namespace std;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	queue<int> q;

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
			if (!q.empty())
			{
				cout << q.front() << "\n";
				q.pop();
			}
			else
				cout << -1 << "\n";
		}
		else if (operation == "size")
			cout << q.size() << "\n";
		else if (operation == "empty")
			cout << q.empty() << "\n";
		else if (operation == "front")
		{
			if (!q.empty())
				cout << q.front() << "\n";
			else
				cout << -1 << "\n";
		}
		else if (operation == "back")
		{
			if (!q.empty())
				cout << q.back() << "\n";
			else
				cout << -1 << "\n";
		}
	}
	return 0;
}