/*
  #. [ 백준_11403 경로 찾기 Silver I ]

  #. 문제
     가중치 없는 방향 그래프 G가 주어졌을 때, 모든 정점 (i, j)에 대해서, i에서 j로 가는 경로가 있는지 없는지 구하는 프로그램을 작성하시오.

  #. 입력
     첫째 줄에 정점의 개수 N (1 ≤ N ≤ 100)이 주어진다.
     둘째 줄부터 N개 줄에는 그래프의 인접 행렬이 주어진다.
     i번째 줄의 j번째 숫자가 1인 경우에는 i에서 j로 가는 간선이 존재한다는 뜻이고, 0인 경우는 없다는 뜻이다.
     i번째 줄의 i번째 숫자는 항상 0이다.

  #. 출력
     총 N개의 줄에 걸쳐서 문제의 정답을 인접행렬 형식으로 출력한다.
     정점 i에서 j로 가는 경로가 있으면 i번째 줄의 j번째 숫자를 1로, 없으면 0으로 출력해야 한다.

  #. 예제 입력 1
     3
     0 1 0
     0 0 1
     1 0 0

  #. 예제 출력 1
     1 1 1
     1 1 1
     1 1 1

  #. 예제 입력 2
     7
     0 0 0 1 0 0 0
     0 0 0 0 0 0 1
     0 0 0 0 0 0 0
     0 0 0 0 1 1 0
     1 0 0 0 0 0 0
     0 0 0 0 0 0 1
     0 0 1 0 0 0 0

  #. 예제 출력 2
     1 0 1 1 1 1 1
     0 0 1 0 0 0 1
     0 0 0 0 0 0 0
     1 0 1 1 1 1 1
     1 0 1 1 1 1 1
     0 0 1 0 0 0 1
     0 0 1 0 0 0 0
*/

#include <iostream>
using namespace std;

int n;
int map[100][100];
int path[100][100];

void dfs(int i, int j)
{
    if (path[i][j] == true)
        return;

    path[i][j] = 1;
    for (int k = 0; k < n; k++)
    {
        if (map[j][k] == 1 && path[i][k] == false)
            dfs(i, k);
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            dfs(i, j);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << path[i][j];
        cout << "\n";
    }

    return 0;
}