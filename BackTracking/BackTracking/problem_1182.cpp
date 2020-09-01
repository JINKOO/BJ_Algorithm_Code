#include <iostream>
using namespace std;

int N, S;
int numbers[20];
bool check[20];
int answer = 0;

void dfs(int index, int sum)
{
	//cost�� ��� ���Ҹ� ���Ҵٸ� return
	if (index == N)
		return;

	//�κ� ������ ��, �� ������ұ����� ���� S�̸�,
	if (sum + numbers[index] == S)
		answer++;

	//���� ���� ������ �ʴ� ���,
	dfs(index + 1, sum);
	//���� ���� ���ϴ� ���
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