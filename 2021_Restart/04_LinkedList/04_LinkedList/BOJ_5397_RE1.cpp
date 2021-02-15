#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	int TC;
	cin >> TC;

	while (TC > 0)
	{
		string word;
		cin >> word;

		list<char> L;
		list<char>::iterator t = L.begin();

		for (int i = 0; i < word.length(); i++)
		{
			//cout << word[i] << "\n";
			//cout << "before :: " << L.size() << "\n";	
			if (word[i] == '<' && t != L.begin())
				t--;
			else if (word[i] == '>' && t != L.end())
				t++;
			else if (word[i] == '-' && t != L.begin())
				t = L.erase(--t);
			else if(word[i] != '>' && word[i] != '<' && word[i] != '-')
				L.insert(t, word[i]);
			//cout << "after :: " << L.size() << "\n";
		}

		for (auto t : L)
			cout << t;
		cout << "\n";

		TC--;
	}

	return 0;
}















