/*
  #. [ 토마토 ]
  
  #. 문제
     철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 
     토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다. 
     
     창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 
     보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 
     하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 
     대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 
     철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.
     
     토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 
     며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 
     단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

  #. 입력
     첫 줄에는 상자의 크기를 나타내는 두 정수 M, N이 주어진다. 
     M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M,N ≤ 1,000 이다. 
     둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 
     즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 
     하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 
     정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다. 

  #. 출력
     여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 
     만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 
     토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.

  #. 예제 입력 1 
     6 4
     0 0 0 0 0 0
     0 0 0 0 0 0
     0 0 0 0 0 0
     0 0 0 0 0 1
  #. 예제 출력 1 
     8

  #. 예제 입력 2 
     6 4
     0 -1 0 0 0 0
     -1 0 0 0 0 0
     0 0 0 0 0 0
     0 0 0 0 0 1
  #. 예제 출력 2 
     -1

  #. 예제 입력 3 
     6 4
     1 -1 0 0 0 0
     0 -1 0 0 0 0
     0 0 0 0 -1 0
     0 0 0 0 -1 1
  #. 예제 출력 3 
     6

  #.예제 입력 4 
    5 5
    -1 1 0 0 0
    0 -1 -1 -1 0
    0 -1 -1 -1 0
    0 -1 -1 -1 0
    0 0 0 0 0
  #. 예제 출력 4 
    14
    
  #. 예제 입력 5 
     2 2
     1 -1
     -1 1
  #. 예제 출력 5 
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
    
    //0. 첫 번째 요소 삽입하고 방문 처리.
    q.push(first_location);
    for (int i = 0; i < first_location.size(); i++)
        check[first_location[i].first][first_location[i].second] = true;

    while (!q.empty())
    {
        //1. queue에서 꺼내고 각 위치에서 상하 좌우 탐색
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













