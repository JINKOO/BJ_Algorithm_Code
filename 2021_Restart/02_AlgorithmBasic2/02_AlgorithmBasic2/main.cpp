#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
  1. STL�� parameter�� �ѱ� ������ �ݵ�� reference�� �ѱ��.
     �Ʒ��� ���� ����� O(1)�� ���������, �Ķ���Ϳ��� vector�� �����ϹǷ� O(n)�� �ð��� �ɸ���.
*/
bool cmp1(vector<int> v1, vector<int> v2, int idx)
{
	return v1[idx] > v2[idx];
}

bool cmp2(vector<int>& v1, vector<int>& v2, int idx)
{
	return v1[idx] > v2[idx];
}

int main()
{
	// 2. ǥ�� �����
	// �ַ� cin��  cout�� ����� ���̴�.
	// ���� �����ϴ� string�Է¹ޱ�.
	string s;
	getline(cin, s);

	//cin, cout�� ��������� ���� �ð��ʰ��� �������� ������ ���ۤ���.
	ios::sync_with_stdio(0);
	cin.tie(0);

	return 0;
}