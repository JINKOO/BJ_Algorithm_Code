//https://www.acmicpc.net/problem/1260

#include <iostream>
#include <queue>
using namespace std;

int arr[1001][1001];
bool check[1001];
bool check2[1001];
int N, M, V;


void dfs(int start) {

	if (check[start])
		return;

	check[start] = true;
	
	cout << start << " ";
	for (int i = 1; i <= N; i++) {
		if (arr[start][i] && !check[i])
			dfs(i);
	}
}

void bfs(int start) {

	queue<int> q;

	q.push(start);
	check2[start] = true;

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		cout << front << " ";

		for (int i = 1; i <= N; i++) {
			if (arr[front][i] && !check2[i]) {
				q.push(i);
				check2[i] = true;
			}
		}
	}
}


int main() {

	cin >> N >> M >> V;

	for (int i = 1; i <= M; i++) {
		int num1, num2;
		cin >> num1 >> num2;

		arr[num1][num2] = arr[num2][num1] = 1;

	}

	dfs(V);
	cout << "\n";
	bfs(V);

	return 0;
}