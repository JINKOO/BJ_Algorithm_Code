// https://www.acmicpc.net/problem/2493
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// �ð� �ʰ� �ڵ�
/*
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
*/

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	// 0. stack�� �����ϴµ� pair���� ���ҷ� �Ѵ�. pair<heigth, index>
	stack<pair<int, int>> s;

	for (int i = 0; i < N; i++)
	{
		// 1. ����ž�� ���̸� �Է¹޴´�.
		int curr_height;
		cin >> curr_height;

		// 2. stack�� empty�� �ƴ� ������ '���� ���� ����ž�� ����'���� ū ����ž�� ã�´�.
		while (!s.empty())
		{
			// 2.1 curr_height���� ���� ����ž�� ã����, �ش� ����ž�� index����ϰ� break�Ѵ�.
			if (curr_height < s.top().first)
			{
				cout << s.top().second << "\n";
				break;
			}
			s.pop();
		}

		// 3. stack�� empty���, ������ �� �ִ� ����ž�� ���ٴ� �ǹ��̴�. ���� 0���
		if (s.empty())
			cout << 0 << "\n";

		// 4. stack�� push�Ѵ�.
		s.push(make_pair(curr_height, i + 1));
	}

	return 0;
}