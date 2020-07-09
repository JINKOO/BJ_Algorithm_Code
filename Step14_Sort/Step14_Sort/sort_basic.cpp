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
   '���� ���� ���Ҹ� ã��, �� ���� ���ҿ� swap�Ѵ�.'
   �ð����⵵ O(n * n)
*/
void selection_sort(vector<int> v)
{
	int min;    //�ּڰ��� ã�� ���� ����
	int index;  //�ּڰ��� ��ġ�� index���� ����(���߿� i��°�� ��� swap)
	for (int i = 0; i < v.size(); i++)
	{
		min = 9999;
		//�� �ܰ迡�� j ~ ������ �� �ּڰ��� ã�´�.
		//�� �ܰ� ���� ��, 0 ~ i��°������ ���� ����.
		for (int j = i; j < v.size(); j++)
		{
			if (min > v[j])
			{
				min = v[j];
				index = j;
			}
		}
		//�ش� �ּڰ��� �տ� �ִ� ���ҿ� swap
		swap(v[i], v[index]);
	}
	print(v);
}

/*
   '�ٷ� ���� ���ҿ� ���Ͽ� �� ū ���� �ڷ� ������.'

   - ���� ����������, ���� ���� �˰���.
   - ���� ���İ� �ð� ���⵵�� ������, ���� ���� �ð��� �� ������.
     ���� ������ �ּڰ��� ã�� swap�ѹ� ����,
	 ���� ������ �ٷ� ���̶� swap �Ź� �����ϹǷ�
*/
void bubble_sort(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size() -1 - i; j++)
		{
			//�ٷ� �� ���ҿ� ��.
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
			}
		}
		//�ѹ��� �ݺ��� ������, ���ʿ� ���� ū���� ��������.
	}
	print(v);
}

/*
  '������ ���ĵǾ��ִٰ� �����ϰ�, �� ���ڸ� '������ ��ġ'�� �����Ѵ�.
  - ������ ���Ļ��� ����.
  - ����, ����, ���� �� ���� ȿ�����̴�.
    ����, ������ �̹� ������ �Ǿ��־, ���� �ݺ��� �����Ѵ�.
  - ���� ���ĵ� ���, ���� ������ ���а� �ȴ�.

*/
void insertion_sort(vector<int> v)
{
	for (int i = 1; i < v.size(); i++)
	{
		int j = i;
		//������ ���ĵǾ��ִ� ���¸� ������ �� ����,
		//�� �ڽź��� ���� �� ���� ��ġ�� ���Ե� ��ġ�̴�. 
		while (j > 0 && v[j] < v[j - 1])
		{
			swap(v[j], v[j - 1]);
			j--;
		}
	}
	print(v);
}

//���� ������ �̷������ ���� ����ϱ�.
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