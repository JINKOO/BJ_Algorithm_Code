// https://www.acmicpc.net/problem/11729

#include <iostream>
using namespace std;

/*
    �ͳ���
	1. �츮�� ���� 1���� ���ϴ� ������� �ű� �� �ִ�.
	2. �츮�� ���� k���� ���ϴ� ������� �ű� �� �ִٰ� ����.

	3. ���� k+1���� ���ϴ� ������� �ű� �� �ִ�. k+1��° �ű� ��, k�� �ű� �� �����Ƿ�.
*/
void hanoi(int from, int to, int n)
{
	if (n == 1)
	{
		cout << from << " " << to << "\n";
		return;
	}

	// 1 ~ n-1��° ������ �ű��.
	hanoi(from, 6 - from - to, n - 1);

	// n��° ������ �ű��.
	cout << from << " " << to << "\n";
	
	// 1 ~ n-1������ �ű��.
	hanoi(6 - from - to, to, n - 1);
}

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	cout << (1<<N) - 1 << "\n";

	hanoi(1, 3, N);


	return 0;
}