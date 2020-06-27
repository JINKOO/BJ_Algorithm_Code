/*
  #. [ �丶�� ]
  
  #. ����
     ö���� �丶�� ���忡���� �丶�並 �����ϴ� ū â�� ������ �ִ�. 
     �丶��� �Ʒ��� �׸��� ���� ���� ��� ������ ĭ�� �ϳ��� �־ â�� �����Ѵ�. 
     
     â�� �����Ǵ� �丶��� �߿��� �� ���� �͵� ������, ���� ���� ���� �丶��鵵 ���� �� �ִ�. 
     ���� �� �Ϸ簡 ������, ���� �丶����� ������ ���� �ִ� ���� ���� �丶����� ���� �丶���� ������ �޾� �Ͱ� �ȴ�. 
     �ϳ��� �丶���� ������ ���� ����, ������, ��, �� �� ���⿡ �ִ� �丶�並 �ǹ��Ѵ�. 
     �밢�� ���⿡ �ִ� �丶��鿡�Դ� ������ ���� ���ϸ�, �丶�䰡 ȥ�� ������ �ʹ� ���� ���ٰ� �����Ѵ�. 
     ö���� â�� ������ �丶����� ��ĥ�� ������ �� �Ͱ� �Ǵ���, �� �ּ� �ϼ��� �˰� �;� �Ѵ�.
     
     �丶�並 â�� �����ϴ� ���ڸ���� ���ڵ��� ũ��� ���� �丶���� ���� ���� �丶����� ������ �־����� ��, 
     ��ĥ�� ������ �丶����� ��� �ʹ���, �� �ּ� �ϼ��� ���ϴ� ���α׷��� �ۼ��϶�. 
     ��, ������ �Ϻ� ĭ���� �丶�䰡 ������� ���� ���� �ִ�.

  #. �Է�
     ù �ٿ��� ������ ũ�⸦ ��Ÿ���� �� ���� M, N�� �־�����. 
     M�� ������ ���� ĭ�� ��, N�� ������ ���� ĭ�� ���� ��Ÿ����. ��, 2 �� M,N �� 1,000 �̴�. 
     ��° �ٺ��ʹ� �ϳ��� ���ڿ� ����� �丶����� ������ �־�����. 
     ��, ��° �ٺ��� N���� �ٿ��� ���ڿ� ��� �丶���� ������ �־�����. 
     �ϳ��� �ٿ��� ���� �����ٿ� ����ִ� �丶���� ���°� M���� ������ �־�����. 
     ���� 1�� ���� �丶��, ���� 0�� ���� ���� �丶��, ���� -1�� �丶�䰡 ������� ���� ĭ�� ��Ÿ����. 

  #. ���
     �������� �丶�䰡 ��� ���� �������� �ּ� ��¥�� ����ؾ� �Ѵ�. 
     ����, ����� ������ ��� �丶�䰡 �;��ִ� �����̸� 0�� ����ؾ� �ϰ�, 
     �丶�䰡 ��� ������ ���ϴ� ��Ȳ�̸� -1�� ����ؾ� �Ѵ�.

  #. ���� �Է� 1 
     6 4
     0 0 0 0 0 0
     0 0 0 0 0 0
     0 0 0 0 0 0
     0 0 0 0 0 1
  #. ���� ��� 1 
     8

  #. ���� �Է� 2 
     6 4
     0 -1 0 0 0 0
     -1 0 0 0 0 0
     0 0 0 0 0 0
     0 0 0 0 0 1
  #. ���� ��� 2 
     -1

  #. ���� �Է� 3 
     6 4
     1 -1 0 0 0 0
     0 -1 0 0 0 0
     0 0 0 0 -1 0
     0 0 0 0 -1 1
  #. ���� ��� 3 
     6

  #.���� �Է� 4 
    5 5
    -1 1 0 0 0
    0 -1 -1 -1 0
    0 -1 -1 -1 0
    0 -1 -1 -1 0
    0 0 0 0 0
  #. ���� ��� 4 
    14
    
  #. ���� �Է� 5 
     2 2
     1 -1
     -1 1
  #. ���� ��� 5 
     0
*/

#include <iostream>
#include <queue>
using namespace std;

int tomato[1000][1000];
int check[1000][1000];

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0,-1, 0, 1 };

int bfs(vector<pair<int, int>> first_location, int n, int m)
{
    int answer = 0;
    queue<vector<pair<int, int>>> q;
    
    //0. ù ��° ��� �����ϰ� �湮 ó��.
    q.push(first_location);
    for (int i = 0; i < first_location.size(); i++)
        check[first_location[i].first][first_location[i].second] = true;

    while (!q.empty())
    {
        //1. queue���� ������ �� ��ġ���� ���� �¿� Ž��
        vector<pair<int, int>> v = q.front();
        q.pop();

        vector<pair<int, int>> one_day_ripe_tomato; 
        bool isRipe = false;
        for (int i = 0; i < v.size(); i++)
        {
            for (int k = 0; k < 4; k++)
            {
                int next_i = v[i].first + di[k];
                int next_j = v[i].second + dj[k];

                if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m)
                {
                    if (tomato[next_i][next_j] == 0 && check[next_i][next_j] == false)
                    {
                        tomato[next_i][next_j] = 1;
                        check[next_i][next_j] = true;
                        isRipe = true;
                        one_day_ripe_tomato.push_back(make_pair(next_i, next_j));
                    }
                }
            }
        }
        if (one_day_ripe_tomato.size() != 0)
            q.push(one_day_ripe_tomato);
        if (isRipe)
            answer++;
    }
    return answer;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<pair<int, int>> first_tomato_location;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
                first_tomato_location.push_back(make_pair(i, j));
        }
    }

    int result = bfs(first_tomato_location, n, m);
    bool isAllRipe = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tomato[i][j] == 0)
            {
                isAllRipe = false;
                break;
            }
        }
    }

    if (isAllRipe)
        cout << result << "\n";
    else
        cout << -1 << "\n";

    return 0;
}













