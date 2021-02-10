//https://www.acmicpc.net/problem/11328

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<int> v1(26, 0);
vector<int> v2(26, 0);

bool check_is_strfry(string& s1, string& s2)
{
	for (int i = 0; i < s1.length(); i++)
		v1[s1[i] - 'a']++;

	for (int i = 0; i < s2.length(); i++)
		v2[s2[i] - 'a']++;

	bool flag = true;
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i] != v2[i])
		{
			flag = false;
			break;
		}
	}

	return flag == true ? true : false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;

		if (check_is_strfry(s1, s2))
			cout << "Possible" << "\n";
		else
			cout << "Impossible" << "\n";

		fill(v1.begin(), v1.end(), 0);
		fill(v2.begin(), v2.end(), 0);
	}
	
	return 0;
}