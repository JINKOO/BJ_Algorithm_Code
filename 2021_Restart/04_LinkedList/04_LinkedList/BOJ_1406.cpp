//https://www.acmicpc.net/problem/1406

#include <iostream>
#include <string>
#include <list>
using namespace std;

string word;
int TC;

list<char> L;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> word;
	cin >> TC;
	cin.ignore();

	for (int i = 0; i < word.length(); i++)
		L.push_back(word[i]);

	list<char>::iterator t = L.end();

	for (int i = 0; i < TC; i++) 
	{
		string order;
		getline(cin, order);

		if (order.at(0) == 'L')
		{
			if (t != L.begin())
				t--;
		}
		else if (order.at(0) == 'D')
		{
			if (t != L.end())
				t++;
		}
		else if (order.at(0) == 'B')
		{
			if (t != L.begin())
			{
				t = L.erase(--t);
			}
		}
		else if (order.at(0) == 'P')
		{
			const char c = order.at(2);
			L.insert(t, c);
		}
	}

	for (auto i : L)
		cout << i;
	cout << "\n";

	return 0;
}