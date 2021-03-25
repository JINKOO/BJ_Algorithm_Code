// https://www.acmicpc.net/problem/15649
// N°ú M(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MX = 9;
vector<int> v(MX, 0);
vector<bool> is_used(MX, false);

void back_tracking(int N, int M, int k)
{
	if (k == M)
	{
		for (int i = 0; i < M; i++)
			cout << v[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!is_used[i])
		{
			v[k] = i;
			is_used[i] = true;
			back_tracking(N, M, k + 1);
			is_used[i] = false;
		}
	}
}

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	//back_tracking(N, M, 0);
	vector<int> permu(N, 1);
	for (int i = 0; i < M; i++)
		permu[i] = 0;
	
	vector<vector<int>> answer;

	do
	{
		vector<int> temp;
		for (int i = 0; i < permu.size(); i++)
		{
			if (permu[i] == 0)
				temp.push_back(i + 1);
		}
		do
		{
			answer.push_back(temp);
		} while (next_permutation(temp.begin(), temp.end()));
	} while (next_permutation(permu.begin(), permu.end()));

	sort(answer.begin(), answer.end());

	for (const auto& t : answer)
	{
		for (const auto& p : t)
			cout << p << " ";
		cout << "\n";
	}

	return 0;
}