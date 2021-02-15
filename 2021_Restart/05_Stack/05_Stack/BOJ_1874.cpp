#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	// 0. 입출력 속도 증가
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
		// 1. 1부터 차례대로 stack에 삽입한다.
		s.push(i);
		v.push_back('+');

		// 2. s.top()이 현재 수열의 원소가 같으면 pop()한다.
		while (!s.empty() && s.top() == num_arr[j])
		{
			s.pop();
			v.push_back('-');
			j++;
		}
	}

	// 3. stack이 empty이면 수열을 만들 수 있는 것이다.
	if (!s.empty()) 
		cout << "NO" << "\n";
	else
	{
		for (auto t : v)
			cout << t << "\n";
	}

	return 0;
}