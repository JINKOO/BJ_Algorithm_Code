#include <iostream>
using namespace std;

int N, S;
int numbers[20];
bool check[20];
int answer = 0;

void dfs(int index, int sum)
{
	if (sum == S)
	{
		answer++;
		return;
	}

	for (int i = index; i < N; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			dfs(i + 1, sum + numbers[i]);
			check[i] = false;
		}
	}

}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> numbers[i];

	for (int i = 0; i < N; i++)
	{
		dfs(i, 0);
		memset(check, false, sizeof(check));
	}

	cout << answer << "\n";

	return 0;
}