//https://www.acmicpc.net/problem/1158
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main()
{
	// 0. ����� �ӵ� ����Ű��
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 1. �Է� �ޱ�
	int N, K;
	cin >> N >> K;

	// 2. list�� ����� ����� �����Ѵ�.
	list<int> L;

	for (int i = 1; i <= N; i++)
		L.push_back(i);

	while (!L.empty())
	{	
		if (L.size() == N)
			cout << "<";
		for (int i = 0; i < K - 1; i++)
		{
			L.push_back(*(L.begin()));
			L.pop_front();
		}

		cout << *(L.begin());
		
		if (L.size() == 1)
			cout << ">";
		else
			cout << ", ";
		
		L.pop_front();
	}

	return 0;
}