/*
  #. [ 백준_15651번 N과 M (3) ]Silver III

  #. 문제
     자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
     - 1부터 N까지 자연수 중에서 M개를 고른 수열
     - 같은 수를 여러 번 골라도 된다.
     
  #. 입력
     첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 7)
     
  #. 출력
     한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 
     각 수열은 공백으로 구분해서 출력해야 한다.
     수열은 사전 순으로 증가하는 순서로 출력해야 한다.

  #. 예제 입력 1 
     3 1
     예제 출력 1 
     1
     2
     3
     
  #. 예제 입력 2 
     4 2
  #. 예제 출력 2 
     1 1
     1 2
     1 3
     1 4
     2 1
     2 2
     2 3
     2 4
     3 1
     3 2
     3 3
     3 4
     4 1
     4 2
     4 3
     4 4
*/

#include <iostream>
#include <vector>
using namespace std;

int n, m;
int cost[8];

vector<int> v;

void dfs(int count)
{
    if (count == m)
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }

    //각 수열에서 원소가 중복가능하므로, 지금까지 사용했던 check[]배열은 필요없다.
    //단순히 vector에 삽입하고, dfs후 다시 삭제해주기만 하면 된다.
    for (int i = 1; i <= n; i++)
    {
        v.push_back(cost[i]);
        dfs(count + 1);
        v.pop_back();
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cost[i] = i;

    dfs(0);

    return 0;
}