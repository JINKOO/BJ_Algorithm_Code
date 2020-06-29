#include <iostream>
#include <queue>
using namespace std;

int map[1000][1000];
int check[1000][1000];

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, -1, 0, 1 };

void bfs(int i, int j, int n, int m)
{
	queue<pair<int, int>> q;

	q.push(make_pair(i, j));
	check[i][j] = true;

	while (!q.empty())
	{
		pair<int, int> current = q.front();
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int next_i = current.first + di[k];
			int next_j = current.second + dj[k];

			if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m)
			{
				if (map[next_i][next_j] == 1)
				{
					
				}

				if (map[next_i][next_j] == 0 && check[next_i][next_j] == false)
				{

				}
			}
				
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				is
			}
		}
	}

	bfs(0, 0, N, M);

	return 0;
}