#include <iostream>
using namespace std;

int N, S;
int numbers[20];
bool check[20];
int answer = 0;

void dfs(int index, int sum)
{
	//cost의 모든 원소를 돌았다면 return
	if (index == N)
		return;

	//부분 수열의 합, 즉 현재원소까지의 합이 S이면,
	if (sum + numbers[index] == S)
		answer++;

	//현재 원소 합하지 않는 경우,
	dfs(index + 1, sum);
	//현재 원소 합하는 경우
	dfs(index + 1, sum + numbers[index]);
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> numbers[i];

	dfs(0, 0);

	cout << answer << "\n";

	return 0;
}