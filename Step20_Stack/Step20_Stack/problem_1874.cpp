#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> result(n);
	for (int i = 0; i < n; i++)
	{
		arr.push_back(i + 1);
		cin >> result[i];
	}

	stack<int> s;
	for (int i = 0; i < arr.size(); i++)
	{
		s.push(arr[i]);
		if (s.top() == result[i])
			s.pop();
	}

	return 0;
}