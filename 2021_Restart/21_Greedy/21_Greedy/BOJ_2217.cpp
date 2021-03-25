// https://www.acmicpc.net/problem/2217
// ทฮวม

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> w(N, 0);
	for (int i = 0; i < w.size(); i++)
		cin >> w[i];

	sort(w.begin(), w.end(), greater<int>());

	int max_weight = w[0];
	for (int i = 1; i < w.size(); i++)
	{
		max_weight = max(max_weight, w[i] * (i + 1));
	}

	cout << max_weight << "\n";

	return 0;
}