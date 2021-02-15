// https://www.acmicpc.net/problem/2493
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int find_index(int val, vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == val)
			return i;
	}
	return -1;
}

int main()
{
	int N;
	cin >> N;

	vector<int> v(N, 0);
	stack<int> s;
	stack<int> result;

	// 0. ������ ���� �Է¹ޱ�
	for (int i = 0; i < N; i++)
		cin >> v[i];

	//1. stack�� ������ ���� �����Ѵ�.
	for (auto t : v)
		s.push(t);

	//2. ������ v���� �Ųٷ� Ž���ϸ� stack�� ��ȸ�Ѵ�.
	while (!s.empty())
	{
		int curr_height = s.top();
		//cout << curr_height << "\n";
		int j = find_index(curr_height, v) - 1;
		//cout << j << "\n";
		while(j >= 0 && curr_height > v[j])
		{
			j--;
		}
		if (j >= 0)
			result.push(j + 1);
		else
			result.push(0);

		s.pop();
	}

	while (!result.empty())
	{
		cout << result.top() << " ";
		result.pop();
	}
	cout << "\n";

	return 0;
}