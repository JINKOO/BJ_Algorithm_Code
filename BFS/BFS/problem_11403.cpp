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

/*
  #. 나의 풀이법.
     - bfs로 풀기위하여, queue를 사용하는 것까지...
     - 이후, 방향그래프에서 i -> k, k -> j이면 i->j로 가는 경로가 존재한다는 것을 어떻게 표현할지..
  
  #. 여기서는 방문표시를 하지 않는다.
     - check라는 방문표시 대신에, 경로가 있냐 없느냐를 나타내는 정보가 필요하다. -> path
     - bfs(i, j)에서 매개변수 i를 사용해야 한다.


*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> v(100, vector<int>(100, 0));
vector<vector<int>> path(100, vector<int>(100, false));
queue<pair<int, int>> q;


//a->b로 가는 경우가 존재하다는 뜻이다.
//이 때, bfs를 수행하면서, b에서 갈 수 있는 경로를 탐색한다.
//b에서 갈 수 있는 경로가 존재하면, 그 경로는 a에서도 갈 수 있다.
void bfs(int a, int b)
{
    queue<pair<int, int>> q;

    q.push(make_pair(a, b));
    path[a][b] = true;

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        //b->에서 갈 수 있는 지점들을 탐색한다.
        for (int i = 0; i < n; i++)
        {
            //b-> 에서 갈 수 있는 지점들이 존재하면, a->에서도 경로가 존재한다.
            if (v[curr.second][i] == 1 && path[a][i] == false)
            {
                //a->b,b->c이면, a->c로 경로가 존재한다.
                path[a][i] = true;
                
                //c->에서 갈 수 있는 경로 탐색하기 위해, 큐에 삽입.
                q.push(make_pair(curr.second, i));
            }
        }

    }
}

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 1 && path[i][j] == false)
                bfs(i, j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << path[i][j] << " ";
        cout << "\n";
    }

    return 0;
}