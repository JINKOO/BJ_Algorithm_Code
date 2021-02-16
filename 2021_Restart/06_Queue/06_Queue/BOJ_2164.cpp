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

	// 1. queue선언
	queue<int> q;

	// 2. queue에 1 ~ N까지 삽입.
	for (int i = 1; i <= N; i++)
		q.push(i);

	// 3. 처음 맨 윗장 버림
	q.pop();

	// 4. queue의 size == 1일 때 까지
	while (!q.empty() && q.size() > 1)
	{
		// 4.1 맨 앞 원소 뒤로 옮기고
		q.push(q.front());
		q.pop();

		// 4.2 그 다음 원소 pop();
		q.pop();
	}

	if (q.empty())
		cout << 1 << "\n";
	else 
		cout << q.front() << "\n";

	return 0;
}