/*
  [ Dynamic Programming(DP), ���� ��ȹ�� ]

  #. �ϳ��� ������ �� �ѹ��� Ǭ��! with Memoization

  #. �ܼ� ���� ������ ����(���� ������ ���� �� Ǫ�� ��)�� �ذ�
     �Ǻ���ġ ������ �ܼ� ���� �������� �ذ��ϸ� ������ ������ ������ �ذ��ϴ� ��ȿ���� �߻�
     50��° ���� ���� �� ��� �� �ּ� >= 2�� 50����
      but ���� �������� ����(quick, merge sort)�� ������ ������ �ʴ´�.

  #. DP����
     1. ū ������ ���� ������ ���� �� �ִ�.
     2. ���� ������ solution�� ū ���������� �����ϴ�.(with memoization)
 
  #. DP�� ����ϸ� O(n)���� ���� �� �ִ�.

  
  #. ���� �ǹ��� DP�� Memoization�� �����ȴ�.
      - Memoization������ recursion�� �⺻(top-down���)
     
     ���� �ǹ̷� DP�� Memoization�� �����Ѵ�.
      - bottom-up����� ��ȣ�Ѵ�. recursion�� ���� overhead.

*/

#include <iostream>
using namespace std;

long long d[100];

long long fibonacci(long long x)
{
    if (x == 1) return 1;
    if (x == 2) return 1;
    if (d[x] != 0) return d[x];
    return d[x] = fibonacci(x - 1) + fibonacci(x - 2);
}

int main()
{
    cout << fibonacci(50) << "\n";
}












