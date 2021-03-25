// https://www.acmicpc.net/problem/2178
// BFS 유형 2 :: 최단거리를 구하는 문제

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

string board[101];
int dis[101][101];

int N, M;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void bfs()
{
	queue<pair<int, int>> Q;

	// 1. 시작점 삽입 및 방문처리
	Q.push(make_pair(0, 0));

	dis[0][0] = 0;

	while (!Q.empty())
	{
		pair<int, int> curr = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = curr.X + dx[dir];
			int ny = curr.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] != '1' || dis[nx][ny] > -1) continue;

			dis[nx][ny] = dis[curr.X][curr.Y] + 1;
			Q.push(make_pair(nx, ny));
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 1. 입력 받기
	cin >> N >> M;

	// 2. board배열 초기화
	for (int i = 0; i < N; i++)
		cin >> board[i];

	for (int i = 0; i < N; i++)
		fill(dis[i], dis[i] + M, -1);

	bfs();

	cout << dis[N - 1][M - 1] + 1 << "\n";

	return 0;
}