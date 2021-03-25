// https://www.acmicpc.net/problem/1926
// 그림

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int n, m;
int board[501][501];
int vis[501][501];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

vector<int> pictures;

int bfs(int x, int y)
{
	int count = 0;

	queue<pair<int, int>> Q;

	vis[x][y] = 1;
	Q.push(make_pair(x, y));

	while (!Q.empty())
	{
		pair<int, int> curr = Q.front();
		Q.pop();

		count++;

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = curr.X + dx[dir];
			int ny = curr.Y + dy[dir];

			if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
			if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;

			vis[nx][ny] = 1;
			Q.push(make_pair(nx, ny));
		}
	}

	return count;
}

int main()
{

	// 0. 입출력 속도 향상
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 1. n, m입력 받기
	cin >> n >> m;

	int biggest_picture = 0;

	// 2. 좌표값 입력
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];
	}

	// 3. 시작점이 여러개 이므로, 시작점을 찾고 거기서 BFS수행.
	for (int x = 1; x <= n; x++)
	{
		for (int y = 1; y <= m; y++)
		{
			if (vis[x][y] == 0 && board[x][y] == 1)
			{
				int count = bfs(x, y);
				pictures.push_back(count);
			}
		}
	}

	if(pictures.size())
		biggest_picture = *max_element(pictures.begin(), pictures.end());

	cout << pictures.size() << "\n";
	cout << biggest_picture << "\n";

	return 0;
}
