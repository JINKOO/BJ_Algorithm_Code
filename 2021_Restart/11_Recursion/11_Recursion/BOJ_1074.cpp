// https://www.acmicpc.net/problem/1074

#include <iostream>
using namespace std;

/*
   #. ������ �ͳ���

   1. N = 1�� ��, r�� c���� ������ ���� �� �ִ�.
   2. N = k�� ��, r�� c���� ������ ���� �� �ִٰ� ����.

   3. N = k + 1�� ��, r�� c���� ������ ���� �� �ִ�. �̶� N = k�϶��� ����Ѵ�.

*/

int z_order(int r, int c, int n)
{
	if (n == 0)
		return 0;

	int half = pow(2, n - 1);
	//cout << half << "\n";
	// 1�� ������ �簢���� ���
	if (r < half && c < half)
		return z_order(r, c, n - 1);

	// 2�� ������ �簢���� ���
	else if (r < half && c >= half)
		return half * half + z_order(r, half - c, n - 1);

	// 3�� ������ �簢���� ���
	else if (half <= r && c < half)
		return 2 * half * half + z_order(r - half, c, n - 1);

	// 4�� ������ �簢���� ���
	else if (half <= r && half <= c)
		return 3 * half * half + z_order(r - half, c - half, n - 1);
}

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, r, c;
	cin >> N >> r >> c;

	cout << z_order(r, c, N) << "\n";

	return 0;
}