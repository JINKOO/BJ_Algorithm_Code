// https://www.acmicpc.net/problem/7576
// BFS 유형 3 :: 동시 시작 시작점 여러개

#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int tomatos[1001][1001];
int dis[1001][1001];

int M, N;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void bfs()
{
	// 1. 1인 지점 찾아 Q에 삽입하고, 방문처리(여기서는 거리 0으로 set)
	queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tomatos[i][j] == 1)
			{
				Q.push(make_pair(i, j));
				dis[i][j] = 0;
			}
		}
	}

	while (!Q.empty())
	{
		pair<int, int> curr = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = curr.X + dx[dir];
			int ny = curr.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (tomatos[nx][ny] != 0 || dis[nx][ny] > -1) continue;

			tomatos[nx][ny] = 1;
			dis[nx][ny] = dis[curr.X][curr.Y] + 1;

			Q.push(make_pair(nx, ny));
		}
	}
}

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	int answer = 0;
	bool flag = false;

	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tomatos[i][j];
			if (tomatos[i][j] == 0)
				flag = true;
		}
	}

	for (int i = 0; i < N; i++)
		fill(dis[i], dis[i] + M, -1);

	if (!flag)
		answer = 0;
	else
	{
		bool flag = false;

		bfs();

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				
				if (tomatos[i][j] == 0)
				{
					answer = -1;
					flag = true;
					break;
				}

				else if (tomatos[i][j] == 1)
				{
					if (answer <= dis[i][j])
						answer = dis[i][j];
				}
				
			}
			if (flag)
				break;
		}
	}

	cout << answer << "\n";

	return 0;
}