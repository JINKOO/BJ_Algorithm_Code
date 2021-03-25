// https://www.acmicpc.net/problem/1629

#include <iostream>
using namespace std;

/*
   1. b�� 21���� �� �� �ֱ� ������ a�� �ѹ��� ���ϸ� �ð��ʰ�...

   2. 'a^n * a^n = a^2n' �� �̿�.

   3. ������ �ͳ��� ���.

      3.1 �츮�� a^1�� ���� �� �ִ�.  -- > base condition�� �ȴ�.
	  3.2 a^k�� ���� �� �ִٰ� ����.

	  3.3 a^2k, a^(2k + 1)�� ���� �� �ִ�. --> �츮�� ����ؾ��� �κ�.
	      a^2k = a^k * a*2k;
		  a^(2k + 1) = a^2k * a;

    4. ��� ������������ ��� Ż������!. Ȯ���� �߿�. 
	   �ͳ������� ��������, �ȴٴ� Ȯ������ �о������.

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