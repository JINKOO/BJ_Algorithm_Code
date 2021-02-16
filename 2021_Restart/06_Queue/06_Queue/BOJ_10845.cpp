// https://www.acmicpc.net/problem/10845
// 배열을 사용한 풀이

#include <iostream>
#include <string>
using namespace std;

// 배열을 이용한 풀이에서는 push할 수 있는 갯수보다 크게 잡으면 된다.
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
	// 배열의 크기를 충분히 잡아놓았기 때문에 push연산 시 따로 예외처리 안해도 된다.
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