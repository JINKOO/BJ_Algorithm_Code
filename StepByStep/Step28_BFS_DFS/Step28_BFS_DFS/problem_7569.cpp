/*
  #. [ 토마토 ]
  
  #. 문제
     철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 
     토마토는 아래의 그림과 같이 격자모양 상자의 칸에 하나씩 넣은 다음, 
     상자들을 수직으로 쌓아 올려서 창고에 보관한다.
     
     창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 
     보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 
     하나의 토마토에 인접한 곳은 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향에 있는 토마토를 의미한다. 
     대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 
     철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지 그 최소 일수를 알고 싶어 한다.


  #. 토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 
     며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 
     단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

  #. 입력
     첫 줄에는 상자의 크기를 나타내는 두 정수 M, N과 쌓아올려지는 상자의 수를 나타내는 H가 주어진다. 
     M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 
     단, 2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100 이다. 
     둘째 줄부터는 가장 밑의 상자부터 가장 위의 상자까지에 저장된 토마토들의 정보가 주어진다. 
     즉, 둘째 줄부터 N개의 줄에는 하나의 상자에 담긴 토마토의 정보가 주어진다. 
     각 줄에는 상자 가로줄에 들어있는 토마토들의 상태가 M개의 정수로 주어진다. 
     정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다. 
     이러한 N개의 줄이 H번 반복하여 주어진다.

  #. 출력
     여러분은 토마토가 모두 익을 때까지 최소 며칠이 걸리는지를 계산해서 출력해야 한다. 
     만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 
     토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.

  #. 예제 입력 1 
     5 3 1
     0 -1 0 0 0
     -1 -1 0 1 1
     0 0 0 1 1
  #. 예제 출력 1 
    -1

  #. 예제 입력 2 
     5 3 2
     0 0 0 0 0
     0 0 0 0 0
     0 0 0 0 0
     0 0 0 0 0
     0 0 1 0 0
     0 0 0 0 0
  #. 예제 출력 2 
     4

  #. 예제 입력 3 
     4 3 2
     1 1 1 1
     1 1 1 1
     1 1 1 1
     1 1 1 1
     -1 -1 -1 -1
     1 1 1 -1
  #. 예제 출력 3 
     0
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int tomato[100][100][100];
int check[100][100][100];

//3차원 배열이므로 다음과 같이 이동 방향을 생성해야한다.
//같은 level에서의 상,하,좌,우 + level간 이동 위, 아래
int dh[6] = {-1, 1, 0, 0, 0, 0};
int di[6] = { 0, 0, -1, 0, 1, 0 };
int dj[6] = { 0, 0, 0, -1, 0, 1 };

int bfs(vector<pair<int, pair<int, int>>> first_loc, int h, int n, int m)
{
    int answer = 0;
    /*
      0. 하루 단위로 익은 토마토의 위치(1개 이상) 구분하기 위하여 다음과 같이 queue를 생성.
         여기서는 3차원 배열이므로 다음과 같이 queue안의 vector를 사용한다.
    */
    queue<vector<pair<int, pair<int, int>>>> q;
    
    //1. 첫번째 시작 위치'들' queue에 삽입 후 방문처리.
    q.push(first_loc);
    for (int i = 0; i < first_loc.size(); i++)
        check[first_loc[i].first][first_loc[i].second.first][first_loc[i].second.second] = true;


    //2. 실질적인 탐색 시작
    while (!q.empty())
    {
        //3. queue에서 vector하나 꺼내고, 이 vector에는 하루 동안 익은 토마토로 상태가 변한 좌표들이 들어있다.
        vector<pair<int, pair<int, int>>> v = q.front();
        q.pop();

        /*
          4. 하루 동안 상태가 변한 토마토들(익은 토마토로 변경된 토마토)의 좌표 저장 변수.
             이 후, 이 vector를 queue에 삽입.
             이 vector에 들어있는 좌표들은 하루가 지나면, 그 좌표들을 기준으로 상,하,좌,우,위,아래 탐색하게 된다.
        */
        vector<pair<int, pair<int, int>>> oneday_ripe_tomato;
        for (int i = 0; i < v.size(); i++)
        {
            //4.1 queue에서 꺼낸 v[i]에 들어있는 좌표(현재까지 익은 토마토 좌표)에서 상,하,좌,우,위,아래 탐색.
            for (int k = 0; k < 6; k++)
            {
                int next_h = v[i].first + dh[k];
                int next_i = v[i].second.first + di[k];
                int next_j = v[i].second.second + dj[k];

                //4.2 탐색할 좌표 값들이 tomato[h][i][j]범위 안에 존재하고,
                if (next_h >= 0 && next_h < h && next_i >= 0 && next_i < n && next_j >= 0 && next_j < m)
                {
                    //4.3 탐색한 좌표 위치에 덜익은 토마토가 존재하며, 아직 방문하지 않은 곳이면,
                    if (tomato[next_h][next_i][next_j] == 0 && check[next_h][next_i][next_j] == false)
                    {
                        //4.4 익은 토마토로 상태 변경,
                        tomato[next_h][next_i][next_j] = 1;
                        //4.5 해당 위치 방문처리,
                        check[next_h][next_i][next_j] = true;
                        //4.6 하루 동안 익은 토마토로 변경 된 좌표들 vector에 삽입한다. 이후 queue에 삽입.
                        oneday_ripe_tomato.push_back(make_pair(next_h, make_pair(next_i, next_j)));
                    }
                }
            }
        }
        //5. 하루 동안 익은 토마토가 1개라도 존재한다면,
        if (oneday_ripe_tomato.size() != 0)
        {
            /* 
              5.1 queue에 삽입.
                  현재 vector에 들어있는 좌표들이 다시 덜 익은 토마토를 탐색하게 된다.
            */
            cout << oneday_ripe_tomato[0].first << " " << oneday_ripe_tomato[0].second.first << " " << oneday_ripe_tomato[0].second.second << "\n";
            q.push(oneday_ripe_tomato);

            //5.2 하루 동안 상태가 변한 토마토가 존재하므로 일수 증가시킨다.
            answer++;
        }
    }
    //
    return answer;
}

// bfs수행 후 모든 토마토가 익었는 지 확인.
bool isAllRipe(int h, int n, int m)
{
    bool allRipe = true;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (tomato[i][j][k] == 0)
                    return allRipe = false;
            }
        }
    }

    return allRipe;
}

int main()
{
    int m, n, h;
    cin >> m >> n >> h;

    //0. 첫 번째 익은 토마토들이 있는 위치 저장 vector.
    vector<pair<int, pair<int, int>>> first_loc;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                //1. 입력 받고, 익은 토마토가 있는 위치이면 vector에 삽입.
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1)
                    first_loc.push_back(make_pair(i, make_pair(j, k)));
            }
        }
    }

    int answer = 0;
    //2. 익은 토마토가 존재 할 때만 bfs수행한다.
    if (first_loc.size() != 0)
    {
        //2.1 bfs수행하고
        int total_day = bfs(first_loc, h, n, m);

        //2.2 bfs수행 후 모든 토마토가 익었는지 check한다.
        if (isAllRipe(h, n, m))
            //2.3 모두 익은 토마토가 되었다면, 
            answer = total_day;
        else
            //2.4 bfs를 수행하였지만, 익지 않은 토마토가 존재하면(벽에 가로막혀 있는 토마토 확률높다.)
            answer = -1;
    }
    //3. 애초에 익은 토마토가 존재하지 않으면, -1
    else
        answer = -1;

    cout << answer << "\n";

    return 0;
}