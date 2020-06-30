/*
  #. [ �� �μ��� �̵��ϱ� ]
  
  #. ����
     N��M�� ��ķ� ǥ���Ǵ� ���� �ִ�. 
	 �ʿ��� 0�� �̵��� �� �ִ� ���� ��Ÿ����, 1�� �̵��� �� ���� ���� �ִ� ���� ��Ÿ����. 
	 ����� (1, 1)���� (N, M)�� ��ġ���� �̵��Ϸ� �ϴµ�, �̶� �ִ� ��η� �̵��Ϸ� �Ѵ�. 
	 �ִܰ�δ� �ʿ��� ���� ���� ������ ĭ�� ������ ��θ� ���ϴµ�, �̶� �����ϴ� ĭ�� ������ ĭ�� �����ؼ� ����.
	 
	 ���࿡ �̵��ϴ� ���߿� �� ���� ���� �μ��� �̵��ϴ� ���� �� �� ��ΰ� ª�����ٸ�, 
	 ���� �� �� ���� �μ��� �̵��Ͽ��� �ȴ�.
	 
	 ���� �־����� ��, �ִ� ��θ� ���� ���� ���α׷��� �ۼ��Ͻÿ�.

  #. �Է�
     ù° �ٿ� N(1 �� N �� 1,000), M(1 �� M �� 1,000)�� �־�����. 
	 ���� N���� �ٿ� M���� ���ڷ� ���� �־�����. (1, 1)�� (N, M)�� �׻� 0�̶�� ��������.

  #. ���
     ù° �ٿ� �ִ� �Ÿ��� ����Ѵ�. �Ұ����� ���� -1�� ����Ѵ�.

  #. ���� �Է� 1 
     6 4
	 0100
	 1110
	 1000
	 0000
	 0111
	 0000
  #. ���� ��� 1 
     15

  #. ���� �Է� 2 
     4 4
	 0111
	 1111
	 1111
	 1110
  #. ���� ��� 2 
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
	//test���
	//1. 0��° level :: �� ��ġ���� ���� �հ� ���� �ʾ��� ��� ��� ��
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << check[0][i][j] << " ";
		}
		cout << "\n";
	}

	//1. 2��° level :: �� ��ġ���� ���� �հ� ���� ��� ��� ��
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
				//1. Ž���� ��ġ�� ���̰�, ���� �� �ѽ��� ���� ���.
				if (map[next_i][next_j] == '1' && !crashed)
				{
					check[crashed + 1][next_i][next_j] = check[crashed][curr_i][curr_j] + 1;
					q.push(make_pair(crashed + 1, make_pair(next_i, next_j)));
				}
				//2. Ž���� ��ġ�� �� �����̰�, ���� Ž������ ���� ����� ���
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