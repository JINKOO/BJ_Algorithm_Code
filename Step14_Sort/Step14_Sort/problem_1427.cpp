/*
  #. [ 1427_��Ʈ �λ��̵� Silver V]

  #. ����
     �迭�� �����ϴ� ���� ����. ���� �־�����, �� ���� �� �ڸ����� ������������ �����غ���.

  #. �Է�
    ù° �ٿ� �����ϰ����ϴ� �� N�� �־�����. N�� 1,000,000,000���� �۰ų� ���� �ڿ����̴�.

  #. ���
     ù° �ٿ� �ڸ����� ������������ ������ ���� ����Ѵ�.

  #. ���� �Է� 1 
     2143
  #. ���� ��� 1 
     4321
*/

/* 
   #. quick_sort�� Ǯ�� �ð��ʰ� ����.
      �� �˰��� ���̺귯�� ����.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool myCompare(char c1, char c2)
{
    return c1 > c2;
}

void swap(char& c1, char& c2)
{
    char temp = c1;
    c1 = c2;
    c2 = temp;
}

void quick_sort(string &s, int start, int end)
{
    if (start >= end)
        return;

    int pivot = start;
    int i = start + 1;
    int j = end;

    //�������� ���� �� ����
    while (i <= j)
    {
        //
        while (i <= end && s[pivot] < s[i])
            i++;
        while (j > start && s[pivot] > s[j])
            j--;

        if (i > j)
            swap(s[pivot], s[j]);
        else
            swap(s[i], s[j]);
    }

    quick_sort(s, start, j - 1);
    quick_sort(s, j + 1, end);
}

int main()
{
    string number;
    cin >> number;

    sort(number.begin(), number.end(), myCompare);
    //quick_sort(number, 0, number.length() - 1);
    cout << number << "\n";

    return 0;
}