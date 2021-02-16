// https://www.acmicpc.net/problem/2164

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	// 1. queue����
	queue<int> q;

	// 2. queue�� 1 ~ N���� ����.
	for (int i = 1; i <= N; i++)
		q.push(i);

	// 3. ó�� �� ���� ����
	q.pop();

	// 4. queue�� size == 1�� �� ����
	while (!q.empty() && q.size() > 1)
	{
		// 4.1 �� �� ���� �ڷ� �ű��
		q.push(q.front());
		q.pop();

		// 4.2 �� ���� ���� pop();
		q.pop();
	}

	if (q.empty())
		cout << 1 << "\n";
	else 
		cout << q.front() << "\n";

	return 0;
}