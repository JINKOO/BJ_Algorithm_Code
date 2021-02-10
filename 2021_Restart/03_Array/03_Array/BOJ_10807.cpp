//https://www.acmicpc.net/problem/10807

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, V;
	int answer = 0;

	cin >> N;
	
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	cin >> V;
	for (int e : v)
	{
		if (e == V)
			answer++;
	}

	cout << answer << "\n";

	return 0;
}