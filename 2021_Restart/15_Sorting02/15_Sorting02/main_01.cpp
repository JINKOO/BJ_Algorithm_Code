#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
   #. �ڵ��׽�Ʈ������ ������ sort()�� ���.
      ��������, ��������, Ŀ���� ���ı��� ����

	  pair, tuple�� ����� ������ �ڵ����� �� ���Һ��� ��Һ����ش�.

   #. sort ��� �� ���� ����
      1. Ŀ���� ���� ��� ��, �� ���� ���� ���� falseó���� ������
	     
	  2. string���� ��ü, STL���� �� �Ķ���ͷ� �ѱ� ������ �ݵ�� const, reference!!
*/

// ���ı��� 5�� ���� ������������(��������), �������� ���ٸ�, ��������
bool cmp(const int& a, const int& b)
{
	// 5�� ���� �������� ���� �ʴٸ�, �������� ū ������ ����
	if (a % 5 != b % 5) return a % 5 < b % 5;

	// �������� ���ٸ�, ū ������
	return a > b;
}

int main()
{

	vector<int> v = { 1,2,3,4,5,6,7 };

	sort(v.begin(), v.end(), cmp);

	for (const auto& t : v)
		cout << t << " ";
	cout << "\n";

	return 0;
}