#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
  1. STL을 parameter로 넘길 때에는 반드시 reference로 넘긴다.
     아래와 같은 방식은 O(1)을 기대했지만, 파라미터에서 vector를 복사하므로 O(n)의 시간이 걸린다.
*/
bool cmp1(vector<int> v1, vector<int> v2, int idx)
{
	return v1[idx] > v2[idx];
}

bool cmp2(vector<int>& v1, vector<int>& v2, int idx)
{
	return v1[idx] > v2[idx];
}

int main()
{
	// 2. 표준 입출력
	// 주로 cin과  cout을 사용할 것이다.
	// 공백 포함하는 string입력받기.
	string s;
	getline(cin, s);

	//cin, cout은 입축력으로 인한 시간초과를 막기위해 다음을 사요앟ㄴ다.
	ios::sync_with_stdio(0);
	cin.tie(0);

	return 0;
}