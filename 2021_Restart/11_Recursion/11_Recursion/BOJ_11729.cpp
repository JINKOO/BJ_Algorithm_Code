// https://www.acmicpc.net/problem/11729

#include <iostream>
using namespace std;

/*
    귀납법
	1. 우리는 원판 1개를 원하는 기둥으로 옮길 수 있다.
	2. 우리는 원판 k개를 원하는 기둥으로 옮길 수 있다고 가정.

	3. 원판 k+1개를 원하는 기둥으로 옮길 수 있다. k+1번째 옮긴 후, k개 옮길 수 있으므로.
*/
void hanoi(int from, int to, int n)
{
	if (n == 1)
	{
		cout << from << " " << to << "\n";
		return;
	}

	// 1 ~ n-1번째 원판을 옮긴다.
	hanoi(from, 6 - from - to, n - 1);

	// n번째 원판을 옮긴다.
	cout << from << " " << to << "\n";
	
	// 1 ~ n-1원판을 옮긴다.
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