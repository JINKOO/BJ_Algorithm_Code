// https://www.acmicpc.net/problem/2493
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 시간 초과 코드
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

	// 0. 기지국 높이 입력받기
	for (int i = 0; i < N; i++)
		cin >> v[i];

	//1. stack에 기지국 높이 삽입한다.
	for (auto t : v)
		s.push(t);

	//2. 기지국 v에서 거꾸로 탐색하며 stack을 순회한다.
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

	// 0. stack를 선언하는데 pair형의 원소로 한다. pair<heigth, index>
	stack<pair<int, int>> s;

	for (int i = 0; i < N; i++)
	{
		// 1. 수신탑의 높이를 입력받는다.
		int curr_height;
		cin >> curr_height;

		// 2. stack이 empty가 아닐 때까지 '현재 들어온 수신탑의 높이'보다 큰 수신탑을 찾는다.
		while (!s.empty())
		{
			// 2.1 curr_height보다 높은 수신탑을 찾으면, 해당 수신탑의 index출력하고 break한다.
			if (curr_height < s.top().first)
			{
				cout << s.top().second << "\n";
				break;
			}
			s.pop();
		}

		// 3. stack이 empty라면, 수신할 수 있는 수신탑이 없다는 의미이다. 따라서 0출력
		if (s.empty())
			cout << 0 << "\n";

		// 4. stack에 push한다.
		s.push(make_pair(curr_height, i + 1));
	}

	return 0;
}