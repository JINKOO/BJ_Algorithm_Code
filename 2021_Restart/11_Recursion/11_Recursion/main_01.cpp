#include <iostream>
using namespace std;

// 재귀는 무조건 귀납법으로 풀이한다. (될 것이라는 확신!!!!!)

/*
  1. 1을 출력 할 수 있다.
  2. k, k-1, ... 1을 출력 가능하다고 가정.

  3. fun(k + 1)은 k + 1출력, 후 func(k)하면 성립.

*/
void print_num(int n)
{
	// base condition
	if (n == 0)
		return;

	cout << n << " ";
	print_num(n - 1);
}

/*
   1. 1의 합을 구할 수 있다.
   2. k ~ 1까지의 합을 구할 수 있다고 가정.

   3. func(k + 1) 은 k + 1과 func(k)를 더하면 성립한다.

*/
int get_total(int n)
{
	if (n == 1)
		return 1;
	return n + get_total(n - 1);
}

int main()
{

	//1. n ~ 1까지의 숫자 출력.
	print_num(10);

	cout << "\n";

	//2. n ~ 1까지의 합 출력.
	int total = get_total(10);
	cout << total << "\n";

	return 0;
}