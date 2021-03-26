#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
   #. 코딩테스트에서는 무조건 sort()를 써라.
      오름차순, 내림차순, 커스텀 정렬기준 가능

	  pair, tuple을 사용할 때에는 자동으로 앞 원소부터 대소비교해준다.

   #. sort 사용 시 주의 할점
      1. 커스텀 정렬 사용 시, 두 값이 같은 경우는 false처리를 해주자
	     
	  2. string등의 객체, STL인자 를 파라미터로 넘길 때에는 반드시 const, reference!!
*/

// 정렬기준 5로 나눈 나머지순으로(오름차순), 나머지가 같다면, 오름차순
bool cmp(const int& a, const int& b)
{
	// 5로 나눈 나머지가 같지 않다면, 나머지가 큰 순으로 정렬
	if (a % 5 != b % 5) return a % 5 < b % 5;

	// 나머지가 같다면, 큰 수부터
	return a > b;
}

int main()
{

	vector<int> v = { 1,2,3,4,5,6,7 };

	sort(v.begin(), v.end(), cmp);

	for (const auto& t : v)
		cout << t << " ";
	cout << "\n";

	return 0;
}