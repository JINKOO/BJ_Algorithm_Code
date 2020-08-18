#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T, n, m;

	cin >> T;
	while (T != 0)
	{
		cin >> n >> m;

		queue<pair<int, int>> q;
		priority_queue<int, vector<int>, less<>> pq;
		int count = 0;
		
		for (int i = 0; i < n; i++)
		{
			int value;
			cin >> value;
			q.push(make_pair(i, value));
			pq.push(value);
		}

		while (!q.empty())
		{
			pair<int, int> p = q.front();
			int number = p.first;
			int priority = p.second;
			q.pop();
			if (pq.top() == priority)
			{
				pq.pop();
				count++;
				if (number == m)
					break;

			}
			else
				q.push(p);
		}

		cout << count << "\n";

		T--;
	}
	return 0;
}