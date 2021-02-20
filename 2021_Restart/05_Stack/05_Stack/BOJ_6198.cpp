// https://www.acmicpc.net/problem/6198

// 여려움...
// 아직 이해 못함... 2021.02.16

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> buildings(N, 0);
	for (int i = 0; i < N; i++)
		cin >> buildings[i];

	stack<int> s;
	vector<int> temp;
	long long answer = 0;

	for (int i = 0; i < buildings.size(); i++)
	{
		while (!s.empty() && s.top() <= buildings[i])
			s.pop();

		temp.push_back(s.size());
		s.push(buildings[i]);
	}

	for (auto t : temp)
	{
		//cout << t << "\n";
		answer += t;
	}

	cout << answer << "\n";

	return 0;
}