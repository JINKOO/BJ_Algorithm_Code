/*
���� ���� 2577��
�� ���� �ڿ��� A, B, C�� �־��� �� A��B��C�� ����� ����� 0���� 9���� ������ ���ڰ� �� ���� ���������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ��� A = 150, B = 266, C = 427 �̶��
A �� B �� C = 150 �� 266 �� 427 = 17037300 �� �ǰ�,
����� ��� 17037300 ���� 0�� 3��, 1�� 1��, 3�� 2��, 7�� 2�� ������.
*/
#include<iostream>
using namespace std;

int main()
{
	//�Է� �ޱ�
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;

	int result = a * b * c;
	int num_array[10] = { 0, };

	while (result != 0)
	{
		int num = result % 10;
		num_array[num]++;
		result = result / 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << num_array[i] << "\n";
	}

	return 0;
}
