// 0X01강의 연습문제 2번 문제의 시간복잡도 개선 O(n2) --> o(n)

#include <iostream>
#include <vector>
using namespace std;

vector<int> v(101, 0);
int func2(int arr[3], int N)
{
	/*
	for (int i = 0; i < N; i++)
		v[arr[i]]++;
	*/

	for (int i = 0; i < v.size(); i++)
	{
		//cout << v[i] << " ";
		//if ((v[i] == 1 && (v[100 - i] == 1)) || (v[i] == 2 && (v[100 - i] == 2)))
		if(v[100 - arr[i]] == 1)
			return 1;
		v[arr[i]] = 1;
	}
	return 0;
}

int main()
{
	int arr[] = {4, 13, 63, 87};
	cout << func2(arr, 4) << "\n";

	return 0;
}