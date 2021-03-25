// https://www.acmicpc.net/problem/1697
// 숨바꼭질 1차원배열에서의 BFS

#include <iostream>
#include <queue>
using namespace std;

const int MX = 100001;
vector<int> dis(MX, -1);

int bfs(int start, int target)
{
	queue<int> Q;

	Q.push(start);
	dis[start] = 0;

	while (!Q.empty())
	{
		int curr = Q.front();	
		Q.pop();

		if (curr == target)
			return dis[curr];

		vector<int> next = { curr - 1, curr + 1, curr * 2 };
		
		for (const auto& t : next)
		{
			if (0 <= t && t < 100000 && dis[t] == -1)
			{
				dis[t] = dis[curr] + 1;
				Q.push(t);
			}
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int pos_subin, pos_sister;
	cin >> pos_subin >> pos_sister;

	cout << bfs(pos_subin, pos_sister) << "\n";

	return 0;
}