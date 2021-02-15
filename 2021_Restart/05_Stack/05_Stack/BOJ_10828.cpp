//https://www.acmicpc.net/problem/10828

#include <iostream>
using namespace std;

const int MX = 10005;
int dat[MX];
int pos = 0;

void push(int val);
void pop();
bool isFull();
bool isEmpty();
int size();
int top();

void push(int val)
{
	if (isFull())
		return;
	// 삽입 후 pos증가
	dat[pos++] = val;
}

void pop()
{
	if (isEmpty())
	{
		cout << -1 << "\n";
		return;
	}
	cout << top() << "\n";
	pos--;
}

int size()
{
	return pos;
}

bool isFull()
{
	return pos == 10000 ? 1 : 0;
}

bool isEmpty()
{
	return pos == 0 ? 1 : 0;
}

int top()
{
	return isEmpty() ? -1 : dat[pos - 1];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	while (N > 0)
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
			cout << isEmpty() << "\n";
		else if (operation == "top")
			cout << top() << "\n";
		N--;
	}
	return 0;
}