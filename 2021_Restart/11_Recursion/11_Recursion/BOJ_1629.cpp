// https://www.acmicpc.net/problem/1629

#include <iostream>
using namespace std;

/*
   1. b가 21억이 될 수 있기 때문에 a에 한번씩 곱하면 시간초과...

   2. 'a^n * a^n = a^2n' 을 이용.

   3. 수학적 귀납법 사용.

      3.1 우리는 a^1을 구할 수 있다.  -- > base condition이 된다.
	  3.2 a^k를 구할 수 있다고 가정.

	  3.3 a^2k, a^(2k + 1)을 구할 수 있다. --> 우리가 계산해야할 부분.
	      a^2k = a^k * a*2k;
		  a^(2k + 1) = a^2k * a;

    4. 재귀 절자지향적인 사고 탈피하자!. 확신이 중요. 
	   귀납법으로 보였으면, 된다는 확신으로 밀어붙이자.

*/
using ll = long long;
int solution(ll a, ll b, ll c)
{
	// base condition
	if (b == 1)
		return a % c;

	ll result = solution(a, b / 2, c);
	result = result * result % c;

	if (b % 2 == 0)
		return result;
	return result * a % c;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll A, B, C;
	cin >> A >> B >> C;

	ll answer = solution(A, B, C);
	cout << answer << "\n";

	return 0;
}