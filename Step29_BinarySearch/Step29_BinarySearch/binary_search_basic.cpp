#include <iostream>
#include <algorithm>
using namespace std;

bool my_binary_search(int* arr, int s, int e, int key)
{
	if (s > e)
		return false;

	int mid = (s + e) / 2;

	if (arr[mid] == key)
		return true;
	else if (arr[mid] < key)
		return my_binary_search(arr, mid + 1, e, key);
	else
		return my_binary_search(arr, s, mid - 1, key);
}

int main()
{
	int arr[6] = { 9,5,1,34,2,6 };
	//이분 탐색은 '오름차순으로 정렬되어있어야 한다.'
	sort(arr, arr + 6);

	cout << my_binary_search(arr, 0, 5, 23) << "\n";
	cout << my_binary_search(arr, 0, 5, 9) << "\n";


	//라이브러리 사용.
	return 0;
}