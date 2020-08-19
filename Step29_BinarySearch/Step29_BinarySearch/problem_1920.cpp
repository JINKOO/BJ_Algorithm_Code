/*
   #. [ 백준_1920번 수 찾기 분류 ] Silver IV
   
   #. 문제
      N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.
      
   #. 입력
      첫째 줄에 자연수 N(1≤N≤100,000)이 주어진다. 
      다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 
      다음 줄에는 M(1≤M≤100,000)이 주어진다. 
      다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 
      모든 정수의 범위는 -2의31승 보다 크거나 같고 2의31승보다 작다.
      
   #. 출력
      M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.
      
   #. 예제 입력 1 
      5
      4 1 5 2 3
      5
      1 3 7 9 5
      예제 출력 1 
      1
      1
      0
      0
      1
*/
/*
   #. 나의 풀이법.
      - 이 문제는 단순 이중 반복문으로 풀 수 없다.
      - 최악의 경우 n = 1,000,000이고 m이 1,000,000이면 연산 횟수는 백만 x 백만이 되기 때문.
      - 이분 탐색을 사용해야 한다. O(log n)
      - 이분 탐색을 정렬이 되어 있을 때 사용해야 한다.

*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[1000000];
int b[1000000];

bool binary_search(int s, int e, int key)
{
    if (s > e)
        return false;
    int mid = (s + e) / 2;

    if (a[mid] == key)
        return true;
    else if (a[mid] < key)
        return binary_search(mid + 1, e, key);
    else
        return binary_search(s, mid - 1, key);
}

int main()
{
    vector<int> answer;

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    //정렬 해야한다.
    sort(a, a + n, less<int>());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        answer.push_back(binary_search(0, n - 1, b[i]));
    }

    for (int i : answer)
        cout << i << "\n";
}