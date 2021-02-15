//acmicpc.net/problem/5397

#include <iostream>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;

int TC;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	list<char> L;
	
	while (TC > 0)
	{
		string input;
		cin >> input;

		L.clear();
		auto t = L.begin();

		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == '<' && t != L.begin()) t--;
			else if (input[i] == '>' && t != L.end()) t++;
			else if (input[i] == '-' && t != L.begin())
				t = L.erase(--t);
			else if (input[i] != '>' && input[i] != '<' && input[i] != '-')
				L.insert(t, input[i]);
		}

		for (auto i : L)
			cout << i;
		cout << "\n";
		
		TC--;
	}

	return 0;
}