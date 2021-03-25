// https://www.acmicpc.net/problem/1074

#include <iostream>
using namespace std;

/*
   #. 수학적 귀납법

   1. N = 1일 때, r행 c열의 순서를 구할 수 있다.
   2. N = k일 때, r행 c열의 순서를 구할 수 있다고 가정.

   3. N = k + 1일 때, r행 c열의 순서를 구할 수 있다. 이때 N = k일때를 사용한다.

*/

int z_order(int r, int c, int n)
{
	if (n == 0)
		return 0;

	int half = pow(2, n - 1);
	//cout << half << "\n";
	// 1번 지역의 사각형인 경우
	if (r < half && c < half)
		return z_order(r, c, n - 1);

	// 2번 지역의 사각형인 경우
	else if (r < half && c >= half)
		return half * half + z_order(r, half - c, n - 1);

	// 3번 지역의 사각형인 경우
	else if (half <= r && c < half)
		return 2 * half * half + z_order(r - half, c, n - 1);

	// 4번 지역의 사각형인 경우
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