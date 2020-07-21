/*
  #. [ 백준 10814_나이순 정렬  Silver V ]

  #. 문제
     온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다. 
     이때, 회원들을 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.

  #. 입력
     첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)
     둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다. 
     - 나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고, 
     - 이름은 알파벳 대소문자로 이루어져 있고, 길이가 100보다 작거나 같은 문자열이다. 
     입력은 가입한 순서로 주어진다.

  #. 출력
     첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 
     나이가 같으면 가입한 순으로 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.

  #. 예제 입력 1 
     3
     21 Junkyu
     21 Dohyun
     20 Sunyoung
  #. 예제 출력 1 
     20 Sunyoung
     21 Junkyu
     21 Dohyun
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//solution 1
bool myCompare(pair<pair<int, string>, int> &p1, pair<pair<int, string>, int> &p2)
{
    //나이가 같다면 ==> 먼저 기입한 순(오름차순이 된다.)
    if (p1.first.first == p2.first.first)
        return p1.second < p2.second;
    return p1.first.first < p2.first.first;
}

void init(vector<pair<pair<int, string>, int>>& v, int& n)
{
    for(int i = 0; i < n; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        v.push_back(make_pair(make_pair(age, name), i));
    }
}

void print(vector<pair<pair<int, string>, int>>& v)
{
    for (pair<pair<int, string>, int> p : v)
        cout << p.first.first << " " << p.first.second << "\n";
}


//===========================================================================//

//solutin 2
bool myCompare2(const pair<int, string> &p1, const pair<int, string> &p2)
{
    //stable_sort를 사용하므로, 순서가 유지된다.
    //문제에서 순서는 기입한 순서이므로 나이 순 오름차순만 비교하면 된다.
    return p1.first < p2.first;
}

void init(vector<pair<int, string>>& v, int& n)
{
    for (int i = 0; i < n; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        v.push_back(make_pair(age, name));
    }
}

void print(vector<pair<int, string>>& v)
{
    for (pair<int, string> p : v)
        cout << p.first << " " << p.second << "\n";
}

int main()
{
    int N;
    cin >> N;

    //1. sort() 사용.
    /*
    vector<pair<pair<int, string>, int>> v;
    
    init(v, N);
    sort(v.begin(), v.end(), myCompare);
    print(v);
    */

    //2. stable_sort() 사용.
    /*
      stable_sort()사용할 때, compare함수 파라미터에 레퍼런스만 붙이면 안됨.
      const 키워드를 추가하고 &붙이거나, &붙이지 않아야한다.
    */
    vector<pair<int, string>> v;
    init(v, N);
    stable_sort(v.begin(), v.end(), myCompare2);
    print(v);

    return 0;
}