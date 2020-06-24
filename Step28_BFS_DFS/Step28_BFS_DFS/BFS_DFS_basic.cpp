/*
  #. BFS(Breath First Search)
     BFS��ü�� �� �ǹ̰� ����. �� ����� �����Ű�� ���� �߿�

  #. Ž�� ��� �� �ϳ��̴�. 
     - �ʺ� �켱�� �͸����� Ž��
     - �ִ� ��θ� ������ �� ���

  #. Queue�� �Բ� ����Ѵ�.
     - startNode�� ť�� ���� �ִ� �Ϳ��� �����Ѵ�.
     - ���� �׷��������� �湮 ó���� �߿�!

  #. ���� ����
     - ť���� ��带 �ϳ� ������.
     - ���� ���� ���� ��� �� �湮���� ���� ��带 �湮�ϰ� ť�� �����Ѵ�.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//��� �湮 üũ
int check[8];
int check2[8];
//�׷��� ���� ���� ����
vector<int> v[8];          

void bfs(int startNode)
{
    queue<int> q;
    
    //1. startNode queue�� ���� �� �湮 üũ
    q.push(startNode);
    check[startNode] = true;
    
    while (!q.empty())
    {
        //2. ť���� ����(���´ٴ� �ǹ̴� Ž�� �Ϸ�)
        int data = q.front();
        q.pop();
        cout << data << " ";
        for (int i = 0; i < v[data].size(); i++)
        {
            int y = v[data][i];
            //3. �湮���� ���� ����� ť�� �����ϰ� �湮 ó��.
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
    //graph���� ����
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