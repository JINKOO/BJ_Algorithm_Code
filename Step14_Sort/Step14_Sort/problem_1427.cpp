/*
  #. [ 1427_소트 인사이드 Silver V]

  #. 문제
     배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.

  #. 입력
    첫째 줄에 정렬하고자하는 수 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.

  #. 출력
     첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.

  #. 예제 입력 1 
     2143
  #. 예제 출력 1 
     4321
*/

/* 
   #. quick_sort로 풀면 시간초과 난다.
      걍 알고리즘 라이브러리 쓰자.
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

    //엇갈리지 않을 때 까지
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