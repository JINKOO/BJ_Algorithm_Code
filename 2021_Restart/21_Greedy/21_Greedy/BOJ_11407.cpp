// https://www.acmicpc.net/problem/11047
// µ¿Àü 0

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	int answer = 0;
	stack<int> stk;

	for (int i = 0; i < N; i++)
	{
		int money;
		cin >> money;
		stk.push(money);
	}

	while (!stk.empty())
	{
		if (K / stk.top() != 0)
		{
			answer += K / stk.top();
			K %= stk.top();
		}

		stk.pop();
	}

	cout << answer << "\n";

	return 0;
}