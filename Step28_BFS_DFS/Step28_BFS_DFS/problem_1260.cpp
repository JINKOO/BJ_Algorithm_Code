/*
  #. [ DFS와 BFS ]
  
  #. 문제
     그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
     단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 
     더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

  #. 입력
     첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 
     다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 
     어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

  #. 출력
     첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. 
     V부터 방문된 점을 순서대로 출력하면 된다.

  #. 예제 입력 1 
     4 5 1
     1 2
     1 3
     1 4
     2 4
     3 4
  #. 예제 출력 1 
     1 2 4 3
     1 2 3 4
  
  #. 예제 입력 2 
     5 5 3
     5 4
     5 2
     1 2
     3 4
     3 1
  #. 예제 출력 2 
     3 1 2 5 4
     3 1 4 2 5
  
  #. 예제 입력 3 
     1000 1 1000
     999 1000
  #. 예제 출력 3 
     1000 999
     1000 999
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v_data[1001];
int arr_data[1001][1001];
int check[1001];
int check2[1001];

void dfs(int start, int n)
{
    if (check2[start])
        return;
    check2[start] = true;

    cout << start << " ";
    for (int i = 1; i <= n; i++)
    {
        if (arr_data[start][i] != 0 && check2[i] != 1)
            dfs(i, n);
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    check[start] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        //인접 노드 중 작은값 부터 탐색하니까 정렬
        sort(v_data[x].begin(), v_data[x].end());
        for (int i = 0; i < v_data[x].size(); i++)
        {
            int y = v_data[x][i];
            if (!check[y])
            {
                q.push(y);
                check[y] = true;
            }
        }
    }  
}

/*
  그래프의 연결 정보를 이차원 배열로 선언하면
  '인접한 노드가 여러개인 경우 작은 수부터 방문한다.'라는 조건 있을 시
  따로 비교나 정렬을 하지 않아도 된다.
  노드의 data를 index로 사용하기 때문에 반복문을 사용하면 어짜피 작은 값부터 탐색한다. 
*/
void bfs(int start, int n)
{
    //0. 큐 선언
    queue<int> q;
    //1. start노드 삽입
    q.push(start);
    //2. 방문한 start노드는 방문처리
    check[start] = true;

    while (!q.empty())
    {
        //3. 인접한 노드를 탐색하기 위해 큐에서 꺼낸다.
        int x = q.front();
        //3.1 큐에서 꺼내고 꺼낸 노드는 출력하고, 
        q.pop();
        cout << x << " ";

        //4. 꺼낸 노드의 인접 노드 중 작은 값부터 탐색 시작.
        for (int i = 1; i <= n; i++)
        {
            //5. 인접 노드이고, 방문하지 않은 노드이면,
            if (arr_data[x][i] != 0 && check[i] != 1)
            {
                //6. 큐에 삽입하고
                q.push(i);
                //7. 방문 처리
                check[i] = true;
            }
        }
    }
}

int main()
{
    int n, m, v;
    cin >> n >> m >> v;
    
    //vector사용 방식.
   /* for (int i = 0; i < m; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        v_data[num1].push_back(num2);
        v_data[num2].push_back(num1);
    }*/

    //그래프 연결 정보를 이차원 배열로 사용한 방식.
    for (int i = 0; i < m; i++)
    {
        int num1,num2;
        cin >> num1 >> num2;
        arr_data[num1][num2] = arr_data[num2][num1] = 1;
    }

    dfs(v, n);
    cout << "\n";
    bfs(v, n);
    
    return 0;
}