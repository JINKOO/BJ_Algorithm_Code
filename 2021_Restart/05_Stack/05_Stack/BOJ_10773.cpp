// https://www.acmicpc.net/problem/10773

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int answer = 0;
	int N;
	cin >> N;

	stack<int> s;
	while (N--)
	{
		int price;
		cin >> price;

		if (price == 0 && !s.empty())
			s.pop();
		else
			s.push(price);
	}

	while (!s.empty())
	{
		answer += s.top();
		s.pop();
	}

	cout << answer << "\n";

	return 0;
}