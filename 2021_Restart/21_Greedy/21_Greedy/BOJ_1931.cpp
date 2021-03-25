// https://www.acmicpc.net/problem/1931
// 회의실 배정

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool my_sort(const pair<int, int>& p1, const pair<int, int>& p2)
{
	if (p1.second != p2.second)
		return p1.second < p2.second;
	return p1.first < p2.first;
}

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int answer = 1;
	vector<pair<int, int>> meetings;

	// 1. 회의실 시작, 끝시간 초기화 하여 meetings에 삽입
	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		meetings.push_back({start, end});
	}

	// 2. 회의실 종료시간 기준 정렬한다.
	sort(meetings.begin(), meetings.end(), my_sort);

	pair<int, int> curr = meetings[0];
	for (int i = 1; i < meetings.size(); i++)
	{
		if (curr.second <= meetings[i].first)
		{
			answer++;
			curr = meetings[i];
		}
	}

	cout << answer << "\n";

	return 0;
}