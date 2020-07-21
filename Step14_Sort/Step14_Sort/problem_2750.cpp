/*
  #. 2750 [수 정렬하기] 
  
  #. 문제
     N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
     
  #. 입력
     첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 
     이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

  #. 출력
     첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

  #. 예제 입력 1 
     5
     5 2 3 4 1
  #. 예제 출력 1 
     1
     2
     3
     4
     5
*/

/*
  #. 풀이법.
     - 여기서는 n이 1000이하이다.
       버블, 선택, 삽입, 퀵 sort 모두 가능하다.
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
