/*
 �� �ڿ��� A�� B�� ���� ��, A%B�� A�� B�� ���� ������ �̴�. ���� ���, 7, 14, 27, 38�� 3���� ���� �������� 1, 2, 0, 2�̴�.

 �� 10���� �Է¹��� ��, �̸� 42�� ���� �������� ���Ѵ�. �� ���� ���� �ٸ� ���� �� �� �ִ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

 �Է� �� :: 39 40 41 42 43 44 82 83 84 85

 ��� �� :: 6
*/

#include<iostream>
using namespace std;
int main()
{
	int input = 0;
	int modular_arr[42] = { 0, };

	for (int i = 0; i < 10; i++)
	{
		cin >> input;
		modular_arr[input % 42] = 1;
	}

	int count = 0;
	for (int i = 0; i < 42; i++)
		count = count + modular_arr[i];

	cout << count << "\n";

	return 0;
}