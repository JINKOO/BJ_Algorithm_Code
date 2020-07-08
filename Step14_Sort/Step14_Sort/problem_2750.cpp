/*
  #. 2750 [�� �����ϱ�] 
  
  #. ����
     N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
     
  #. �Է�
     ù° �ٿ� ���� ���� N(1 �� N �� 1,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���ڰ� �־�����. 
     �� ���� ������ 1,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

  #. ���
     ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.

  #. ���� �Է� 1 
     5
     5 2 3 4 1
  #. ���� ��� 1 
     1
     2
     3
     4
     5
*/

/*
  #. Ǯ�̹�.
     - ���⼭�� n�� 1000�����̴�.
       ����, ����, ����, �� sort ��� �����ϴ�.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
void swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

}

void quick_sort(vector<int>& v, int start, int end)
{
    if (start >= end)
        return;

    int pivot = start;
    int i = start + 1;
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

    quick_sort(v, start, j - 1);
    quick_sort(v, j + 1, end);
}

void bubble_sort(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size() - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}

void selection_sort(vector<int>& v)
{
    int index, min;
    for (int i = 0; i < v.size(); i++)
    {
        min = 9999;
        for (int j = i; j < v.size(); j++)
        {
            if (min >= v[j])
            {
                min = v[j];
                index = j;
            }
        }
        swap(v[i], v[index]);
    }
}

void insertion_sort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int j = i;
        while (j > 0 && v[j] < v[j - 1])
        {
            swap(v[j], v[j - 1]);
            j--;
        }
    }
}

void print(vector<int>& v)
{
    for(int i : v)
        cout << i << "\n";
}

int main()
{
    int N;
    cin >> N;

    init(N);
    //quick_sort(v, 0, v.size() - 1);
    //bubble_sort(v);
    //selection_sort(v);
    insertion_sort(v);
    print(v);

    return 0;
}
