// https://www.acmicpc.net/problem/1012

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

vector<int> dx = { -1, 0, 1, 0 };
vector<int> dy = { 0, -1, 0, 1 };

int M, N, K;
vector<vector<int>> vege(50, vector<int>(50, 0));
vector<vector<bool>> check(50, vector<bool>(50, false));

void bfs(int x, int y)
{
	queue<pair<int, int>> Q;

	Q.push(make_pair(x, y));
	check[x][y] = true;

	while (!Q.empty())
	{
		pair<int, int> curr = Q.front();
		Q.pop();

		for (int dir = 0; dir < dx.size(); dir++)
		{
			int nx = curr.X + dx[dir];
			int ny = curr.Y + dy[dir];

			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if (vege[nx][ny] == 1 && check[nx][ny] == false)
				{
					Q.push(make_pair(nx, ny));
					check[nx][ny] = true;
				}
			}
		}
	}
}

// dfs Àç±Í ¹öÀü
void dfs_recursion(int x, int y)
{
	if (check[x][y])
		return;

	check[x][y] = true;

	for (int dir = 0; dir < dx.size(); dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (0 <= nx && nx < N && 0 <= ny && ny < M)
		{
			if (vege[nx][ny] == 1 && check[nx][ny] == false)
				dfs_recursion(nx, ny);
		}
	}
}

void dfs_stack(int x, int y)
{
	stack<pair<int, int>> stk;
	
	stk.push(make_pair(x, y));
	check[x][y] = true;

	while (!stk.empty())
	{
		pair<int, int> curr = stk.top();
		stk.pop();

		for (int dir = 0; dir < dx.size(); dir++)
		{
			int nx = curr.X + dx[dir];
			int ny = curr.Y + dy[dir];
			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if (vege[nx][ny] == 1 && check[nx][ny] == false)
				{
					check[nx][ny] = true;
					stk.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int TC;
	cin >> TC;

	while (TC--)
	{
		int answer = 0;

		cin >> M >> N >> K;

		for (int i = 0; i < K; i++)
		{
			int m, n;
			cin >> m >> n;
			vege[n][m] = 1;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (vege[i][j] == 1 && check[i][j] == false)
				{
					//bfs(i, j);
					//dfs_recursion(i, j);
					dfs_stack(i, j);
					answer++;
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			fill(vege[i].begin(), vege[i].end(), 0);
			fill(check[i].begin(), check[i].end(), false);
		}
		
		cout << answer << "\n";
	}


	return 0;
}