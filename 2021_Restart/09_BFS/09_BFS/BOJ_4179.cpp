// https://www.acmicpc.net/problem/4179
// BFS 유형 4 :: 시작점이 2종류, 즉 BFS를 2번 수행

#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define X first
#define Y second

int R, C;

string maze[1001];
int dis_fire[1001][1001];
int dis_jh[1001][1001];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, -1, 0, 1 };

void fire_bfs(int start_x, int start_y)
{
	queue<pair<int, int>> Q;

	Q.push(make_pair(start_x, start_y));
	dis_fire[start_x][start_y] = 0;

	while (!Q.empty())
	{
		pair<int, int> curr = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = curr.X + dx[dir];
			int ny = curr.Y + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (maze[nx][ny] != '.' || dis_fire[nx][ny] > -1) continue;

			dis_fire[nx][ny] = dis_fire[curr.X][curr.Y] + 1;
			Q.push(make_pair(nx, ny));

		}
	}
}

int jh_bfs(int start_x, int start_y)
{
	int length = 0;
	queue<pair<int, int>> Q;

	Q.push(make_pair(start_x, start_y));
	dis_fire[start_x][start_y] = 0;

	while (!Q.empty())
	{
		pair<int, int> curr = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = curr.X + dx[dir];
			int ny = curr.Y + dy[dir];

			// 여기 들어오면 탈출 성공
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				return dis_jh[curr.X][curr.Y] + 1;
			}
			if (maze[nx][ny] != '.' || ) continue;
			if (dis_fire[nx][ny] > || dis_jh[curr.X][curr.Y] + 1 >= dis_fire[nx][ny]) continue;

			dis_jh[nx][ny] = dis_jh[curr.X][curr.Y] + 1;
			Q.push(make_pair(nx, ny));
		}
	}

	return length;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int result = 0;

	cin >> R >> C;

	int fire_x, fire_y;
	int jh_x, jh_y;

	for (int i = 0; i < R; i++)
	{
		cin >> maze[i];

		for (int j = 0; j < C; j++)
		{
			if (maze[i][j] == '.')
				dis_fire[i][j] = -1;
			else if (maze[i][j] == 'F')
			{
				fire_x = i;
				fire_y = j;
			}
			else if (maze[i][j] == 'J')
			{
				jh_x = i;
				jh_y = j;
			}
		}
	}

	// 1. Fire에 대한 BFS수행
	fire_bfs(fire_x, fire_y);

	// 2. 지훈에 대한 BFS수행
	result = jh_bfs(jh_x, jh_y);

	if (result)
		cout << result + 1 << "\n";
	else
		cout << "IMPOSSIBLE" << "\n";

	return 0;
}