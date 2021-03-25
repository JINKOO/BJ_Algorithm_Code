#include <iostream>
using namespace std;

// ��ʹ� ������ �ͳ������� Ǯ���Ѵ�. (�� ���̶�� Ȯ��!!!!!)

/*
  1. 1�� ��� �� �� �ִ�.
  2. k, k-1, ... 1�� ��� �����ϴٰ� ����.

  3. fun(k + 1)�� k + 1���, �� func(k)�ϸ� ����.

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
   1. 1�� ���� ���� �� �ִ�.
   2. k ~ 1������ ���� ���� �� �ִٰ� ����.

   3. func(k + 1) �� k + 1�� func(k)�� ���ϸ� �����Ѵ�.

*/
int get_total(int n)
{
	if (n == 1)
		return 1;
	return n + get_total(n - 1);
}

int main()
{

	//1. n ~ 1������ ���� ���.
	print_num(10);

	cout << "\n";

	//2. n ~ 1������ �� ���.
	int total = get_total(10);
	cout << total << "\n";

	return 0;
}