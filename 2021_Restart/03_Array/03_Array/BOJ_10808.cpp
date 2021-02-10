//https://www.acmicpc.net/problem/10808
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string word;
	getline(cin, word);

	vector<int> alphabet(26, 0);
	//int alphabet[26];
	//fill(alphabet, alphabet + 26, 0);

	for (int i = 0; i < word.length(); i++)
		alphabet[word[i] - 'a']++;

	for (int e:alphabet)
		cout << e << " ";

	return 0;
}