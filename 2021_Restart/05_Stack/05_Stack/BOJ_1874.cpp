#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	// 0. ����� �ӵ� ����
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	stack<int> s;
	vector<char> v;
	vector<int> num_arr(N, 0);

	for (int i = 0; i < N; i++)
		cin >> num_arr[i];


	for (int i = 1, j = 0; i <= N; i++)
	{
		// 1. 1���� ���ʴ�� stack�� �����Ѵ�.
		s.push(i);
		v.push_back('+');

		// 2. s.top()�� ���� ������ ���Ұ� ������ pop()�Ѵ�.
		while (!s.empty() && s.top() == num_arr[j])
		{
			s.pop();
			v.push_back('-');
			j++;
		}
	}

	// 3. stack�� empty�̸� ������ ���� �� �ִ� ���̴�.
	if (!s.empty()) 
		cout << "NO" << "\n";
	else
	{
		for (auto t : v)
			cout << t << "\n";
	}

	return 0;
}