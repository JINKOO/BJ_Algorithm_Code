//https://www.acmicpc.net/problem/2577

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v(10, 0);
	int A, B, C;
	cin >> A >> B >> C;

	string s = to_string(A * B * C);
	
	cout << s << "\n";
	for (int i = 0; i < s.length(); i++)
		v[s[i] - '0']++;

	for (int e : v)
		cout << e << "\n";

	return 0;
}