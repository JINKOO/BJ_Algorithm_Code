// https://www.acmicpc.net/problem/10845
// �迭�� ����� Ǯ��

#include <iostream>
#include <string>
using namespace std;

// �迭�� �̿��� Ǯ�̿����� push�� �� �ִ� �������� ũ�� ������ �ȴ�.
const int MX = 10005;
int dat[MX];
int head = 0, tail = 0;

bool empty()
{
	if (tail == head)
		return 1;
	else
		return 0;
}

void push(int val)
{
	// �迭�� ũ�⸦ ����� ��Ƴ��ұ� ������ push���� �� ���� ����ó�� ���ص� �ȴ�.
	dat[tail++] = val;
}

void pop()
{
	if (empty())
	{
		cout << -1 << "\n";
		return;
	}
	cout << dat[head] << "\n";
	head++;
}

int size()
{
	return tail - head;
}

int front()
{
	if (empty())
		return -1;
	else
		return dat[head];
}

int back()
{
	if (empty())
		return -1;
	else
		return dat[tail - 1];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	while (N--)
	{
		string operation;
		cin >> operation;

		if (operation == "push")
		{
			int val;
			cin >> val;
			push(val);
		}
		else if (operation == "pop")
			pop();
		else if (operation == "size")
			cout << size() << "\n";
		else if (operation == "empty")
			cout << empty() << "\n";
		else if (operation == "front")
			cout << front() << "\n";
		else if (operation == "back")
			cout << back() << "\n";
	}

	return 0;
}