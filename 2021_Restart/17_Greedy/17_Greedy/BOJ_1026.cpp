// https://www.acmicpc.net/problem/1026
// º¸¹°

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> A(N, 0);
	vector<int> B(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	int answer = 0;
	for (int i = 0; i < A.size(); i++)
		answer += (A[i] * B[i]);
	
	cout << answer << "\n";

	return 0;
}