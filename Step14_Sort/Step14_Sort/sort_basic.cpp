#include <iostream>
#include <vector>
using namespace std;

void swap(int &num1, int &num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void print(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
}

/*
   '가장 작은 원소를 찾아, 맨 앞의 원소와 swap한다.'
   시간복잡도 O(n * n)
*/
void selection_sort(vector<int> v)
{
	int min;    //최솟값을 찾기 위한 변수
	int index;  //최솟값이 위치한 index저장 변수(나중에 i번째와 얘와 swap)
	for (int i = 0; i < v.size(); i++)
	{
		min = 9999;
		//각 단계에서 j ~ 끝까지 중 최솟값을 찾는다.
		//각 단계 수행 후, 0 ~ i번째까지는 정렬 상태.
		for (int j = i; j < v.size(); j++)
		{
			if (min > v[j])
			{
				min = v[j];
				index = j;
			}
		}
		//해당 최솟값을 앞에 있는 원소와 swap
		swap(v[i], v[index]);
	}
	print(v);
}

/*
   '바로 옆의 원소와 비교하여 더 큰 값을 뒤로 보낸다.'

   - 가장 간단하지만, 가장 느린 알고리즘.
   - 선택 정렬과 시간 복잡도는 같지만, 실제 수행 시간은 더 느리다.
     선택 정렬은 최솟값을 찾고 swap한번 수행,
	 버블 정렬은 바로 옆이랑 swap 매번 수행하므로
*/
void bubble_sort(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size() -1 - i; j++)
		{
			//바로 옆 원소와 비교.
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
			}
		}
		//한번의 반복이 끝나면, 뒤쪽에 가장 큰값이 보내진다.
	}
	print(v);
}

/*
  '왼쪽은 정렬되어있다고 가정하고, 각 숫자를 '적절한 위치'에 삽입한다.
  - 왼쪽은 정렬상태 유지.
  - 버블, 선택, 삽입 중 가장 효율적이다.
    버블, 선택은 이미 정렬이 되어있어도, 안쪽 반복문 진입한다.
  - 거의 정렬된 경우, 삽입 정렬은 깡패가 된다.

*/
void insertion_sort(vector<int> v)
{
	for (int i = 1; i < v.size(); i++)
	{
		int j = i;
		//왼쪽이 정렬되어있는 상태를 만났을 때 까지,
		//즉 자신보다 작은 값 다음 위치가 삽입될 위치이다. 
		while (j > 0 && v[j] < v[j - 1])
		{
			swap(v[j], v[j - 1]);
			j--;
		}
	}
	print(v);
}

//삽입 정렬이 이루어지는 과정 출력하기.
void insertion_sort_quiz()
{
	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		v.push_back(num);
		if (i == 0)
			continue;

		int j = i;
		while (j > 0 && v[j] < v[j - 1])
		{
			swap(v[j], v[j - 1]);
			j--;
		}

		print(v);
	}
}

vector<int> v2 = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
void quick_sort(vector<int> &v, int start, int end)
{
	if (start >= end)
		return;

	int pivot = start;
	int i = pivot + 1;
	int j = end;

	while (i <= j)
	{
		while (i <= end && v[i] <= v[pivot])
			i++;
		
		while (j > start && v[j] >= v[pivot])
			j--;

		if (i > j)
			swap(v[pivot], v[j]);

		else
			swap(v[i], v[j]);
	}

	quick_sort(v, start, j-1);
	quick_sort(v, j + 1, end);
}

int main()
{
	vector<int> v = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	selection_sort(v);
	bubble_sort(v);
	insertion_sort(v);
	print(v2);
	quick_sort(v2, 0, v2.size() - 1);
	print(v2);

	//insertion_sort_quiz();

	return 0;
}