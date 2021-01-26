//https://www.acmicpc.net/problem/2667

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int N;
string map[25];
bool check[25][25];

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, -1, 0, 1 };

int bfs(int i, int j) {

	int count = 0;
	queue<pair<int, int>> q;

	q.push(make_pair(i, j));
	check[i][j] = true;

	while (!q.empty()) {

		pair<int, int> p = q.front();
		q.pop();
		count++;
		for (int d = 0; d < 4; d++) {
			int ni = p.first + di[d];
			int nj = p.second + dj[d];

			if (0 <= ni && ni < N && 0 <= nj && nj < N) {
				if (map[ni][nj] == '1' && !check[ni][nj]) {
					q.push(make_pair(ni, nj));
					check[ni][nj] = true;
				}
			}
		}
	}
	return count;
}

int main() {

	vector<int> answer;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> map[i];


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1' && !check[i][j]) {
				int count = bfs(i, j);
				answer.push_back(count);
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << "\n";

	return 0;
}
