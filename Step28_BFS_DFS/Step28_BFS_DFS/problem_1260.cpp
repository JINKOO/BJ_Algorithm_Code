/*
  #. [ DFS�� BFS ]
  
  #. ����
     �׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
     ��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�, 
     �� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. ���� ��ȣ�� 1������ N�������̴�.

  #. �Է�
     ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), Ž���� ������ ������ ��ȣ V�� �־�����. 
     ���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����. 
     � �� ���� ���̿� ���� ���� ������ ���� �� �ִ�. �Է����� �־����� ������ ������̴�.

  #. ���
     ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�. 
     V���� �湮�� ���� ������� ����ϸ� �ȴ�.

  #. ���� �Է� 1 
     4 5 1
     1 2
     1 3
     1 4
     2 4
     3 4
  #. ���� ��� 1 
     1 2 4 3
     1 2 3 4
  
  #. ���� �Է� 2 
     5 5 3
     5 4
     5 2
     1 2
     3 4
     3 1
  #. ���� ��� 2 
     3 1 2 5 4
     3 1 4 2 5
  
  #. ���� �Է� 3 
     1000 1 1000
     999 1000
  #. ���� ��� 3 
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
        //���� ��� �� ������ ���� Ž���ϴϱ� ����
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
  �׷����� ���� ������ ������ �迭�� �����ϸ�
  '������ ��尡 �������� ��� ���� ������ �湮�Ѵ�.'��� ���� ���� ��
  ���� �񱳳� ������ ���� �ʾƵ� �ȴ�.
  ����� data�� index�� ����ϱ� ������ �ݺ����� ����ϸ� ��¥�� ���� ������ Ž���Ѵ�. 
*/
void bfs(int start, int n)
{
    //0. ť ����
    queue<int> q;
    //1. start��� ����
    q.push(start);
    //2. �湮�� start���� �湮ó��
    check[start] = true;

    while (!q.empty())
    {
        //3. ������ ��带 Ž���ϱ� ���� ť���� ������.
        int x = q.front();
        //3.1 ť���� ������ ���� ���� ����ϰ�, 
        q.pop();
        cout << x << " ";

        //4. ���� ����� ���� ��� �� ���� ������ Ž�� ����.
        for (int i = 1; i <= n; i++)
        {
            //5. ���� ����̰�, �湮���� ���� ����̸�,
            if (arr_data[x][i] != 0 && check[i] != 1)
            {
                //6. ť�� �����ϰ�
                q.push(i);
                //7. �湮 ó��
                check[i] = true;
            }
        }
    }
}

int main()
{
    int n, m, v;
    cin >> n >> m >> v;
    
    //vector��� ���.
   /* for (int i = 0; i < m; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        v_data[num1].push_back(num2);
        v_data[num2].push_back(num1);
    }*/

    //�׷��� ���� ������ ������ �迭�� ����� ���.
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