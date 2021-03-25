// https://www.acmicpc.net/problem/17478

#include <iostream>
using namespace std;

/*
   1. N = 1�� ��, �ش� ������ ��� �� �� �ִ�.

   2. N = k�� ��, k, k-1, ... 1������ ��� �� �� �ִ�.

   3. N = k + 1�� ��, N=K�� �̿��ؼ� ����� �� �ִ�.

*/

void chat_bot(int count, int n)
{
	string temp = "";
	for (int i = 0; i < count * 4; i++)
		temp += "_";

	cout << temp + "\"����Լ��� ������?\"" << "\n";

	if (count == n)
	{
		cout << temp + "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << "\n";
		cout << temp + "��� �亯�Ͽ���." << "\n";
		return;
	}

	cout << temp + "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << "\n";
	cout << temp + "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << "\n";
	cout << temp + "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << "\n";

	chat_bot(count + 1, n);
	cout << temp + "��� �亯�Ͽ���." << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << "\n";

	chat_bot(0, N);

	return 0;
}