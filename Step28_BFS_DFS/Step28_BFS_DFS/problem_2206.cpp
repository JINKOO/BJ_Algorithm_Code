/*
  #. [ 벽 부수고 이동하기 ]
  
  #. 문제
     N×M의 행렬로 표현되는 맵이 있다. 
	 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 
	 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 
	 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.
	 
	 만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 
	 벽을 한 개 까지 부수고 이동하여도 된다.
	 
	 맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

  #. 입력
     첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 
	 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

  #. 출력
     첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.

  #. 예제 입력 1 
     6 4
	 0100
	 1110
	 1000
	 0000
	 0111
	 0000
  #. 예제 출력 1 
     15

  #. 예제 입력 2 
     4 4
	 0111
	 1111
	 1111
	 1110
  #. 예제 출력 2 
    -1
*/
#include <iostream>
#include <string>
#include <queue>;
using namespace std;

string map[1000];
int check[2][1000][1000];

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, -1, 0, 1 };

void print(int N, int M)
{
	//test출력
	//1. 0번째 level :: 각 위치에서 벽을 뚫고 오지 않았을 경우 경로 수
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << check[0][i][j] << " ";
		}
		cout << "\n";
	}

	//1. 2번째 level :: 각 위치에서 벽을 뚫고 오는 경우 경로 수
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << check[1][i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
}


int bfs(int n, int m)
{
	int answer = 0;
	queue<pair<bool, pair<int, int>>> q;

	q.push(make_pair(false, make_pair(0, 0)));
	check[0][0][0] = 1;
	check[1][0][0] = 1;

	while (!q.empty())
	{
		pair<bool, pair<int, int>> current = q.front();
		q.pop();

		bool crashed = current.first;
		int curr_i = current.second.first;
		int curr_j = current.second.second;

		if (curr_i == n - 1 && curr_j == m - 1)
			return check[crashed][curr_i][curr_j];
		
		for (int k = 0; k < 4; k++)
		{
			int next_i = curr_i + di[k];
			int next_j = curr_j + dj[k];

			if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m)
			{
				//1. 탐색할 위치가 벽이고, 아직 벽 뿌신적 없는 경우.
				if (map[next_i][next_j] == '1' && !crashed)
				{
					check[crashed + 1][next_i][next_j] = check[crashed][curr_i][curr_j] + 1;
					q.push(make_pair(crashed + 1, make_pair(next_i, next_j)));
				}
				//2. 탐색할 위치가 빈 공간이고, 아직 탐색하지 않은 경로인 경우
				 if (map[next_i][next_j] == '0' && check[crashed][next_i][next_j] == 0)
				{
					check[crashed][next_i][next_j] = check[crashed][curr_i][curr_j] + 1;
					q.push(make_pair(crashed, make_pair(next_i, next_j)));
				}
			}
		}
	}
	return -1;
}


int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> map[i];

	cout << bfs(N, M) << "\n";

	//print(N, M);
	
	return 0;
}