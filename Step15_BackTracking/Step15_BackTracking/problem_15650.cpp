/*
   #. [ 백준_15650번 N과 M (2) ] Silver III
   
   #. 문제
      자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
       - 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
       - 고른 수열은 오름차순이어야 한다.
      
   #. 입력
      첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
      
   #. 출력
      한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
      중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
      
   #. 수열은 사전 순으로 증가하는 순서로 출력해야 한다.
   
   #. 예제 입력 1 
      3 1
   #. 예제 출력 1 
      1
      2
      3
      
   #. 예제 입력 2 
      4 2
      예제 출력 2 
      1 2
      1 3
      1 4
      2 3
      2 4
      3 4
      
   #. 예제 입력 3 
      4 4
      예제 출력 3 
      1 2 3 4
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, m;

int cost[9];
bool check[9];

void dfs(int index, int count)
{
    if (count == m)
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = index; i <= n; i++)
    {
        if (check[i] == false)
        {
            check[i] = true;
            v.push_back(cost[i]);
            dfs(i + 1, count + 1);
            check[i] = false;
            v.pop_back();
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cost[i] = i;

    dfs(1, 0);

    return 0;
}