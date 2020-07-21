/*
  #. BFS(Breath First Search)
     BFS자체는 별 의미가 없다. 이 방법을 적용시키는 것이 중요

  #. 탐색 기법 중 하나이다. 
     - 너비 우선의 맹목적인 탐색
     - 최단 경로를 보장할 때 사용

  #. Queue와 함께 사용한다.
     - startNode를 큐에 집어 넣는 것에서 시작한다.
     - 이후 그래프에서는 방문 처리가 중요!

  #. 동작 원리
     - 큐에서 노드를 하나 꺼낸다.
     - 꺼낸 노드와 인접 노드 중 방문하지 않은 노드를 방문하고 큐에 삽입한다.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//노드 방문 체크
int check[8];
int check2[8];
//그래프 연결 관계 정보
vector<int> v[8];          

void bfs(int startNode)
{
    queue<int> q;
    
    //1. startNode queue에 삽입 후 방문 체크
    q.push(startNode);
    check[startNode] = true;
    
    while (!q.empty())
    {
        //2. 큐에서 꺼냄(꺼냈다는 의미는 탐색 완료)
        int data = q.front();
        q.pop();
        cout << data << " ";
        for (int i = 0; i < v[data].size(); i++)
        {
            int y = v[data][i];
            //3. 방문하지 않은 노드이 큐에 삽입하고 방문 처리.
            if (!check[y])
            {
                q.push(y);
                check[y] = true;
            }
        }
    }
    cout << "\n";
}

void dfs(int start)
{
    if (check2[start])
        return;

    check2[start] = true;
    cout << start << " ";

    for (int i = 0; i < v[start].size(); i++)
    {
        dfs(v[start][i]);
    }

}

int main()
{
    //graph연결 정보
    v[1].push_back(2);
    v[2].push_back(1);

    v[1].push_back(3);
    v[3].push_back(1);

    v[2].push_back(3);
    v[3].push_back(2);

    v[2].push_back(4);
    v[4].push_back(2);
    
    v[2].push_back(5);
    v[5].push_back(2);

    v[3].push_back(6);
    v[6].push_back(3);

    v[3].push_back(7);
    v[7].push_back(3);

    v[4].push_back(5);
    v[5].push_back(4);

    v[6].push_back(7);
    v[7].push_back(6);

    bfs(1);
    dfs(1);

    return 0;
}