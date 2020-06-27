/*
  #. [ 토마토_7576 ]
  
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

/*
   #. 접근법
   - 최소의 시간을 구하는 것 ~= 최단 경로 문제 ==> BFS로 푼다.
   - BFS로 푼다는 것은 알았음.
   - but여기서 핵심은, 최초의 시작 위치가 1개가 아니라, 1개 이상이라는 것이다.
     queue에서 한 번 꺼낼 때, 꺼낸 위치가 1개이상일 수 있고, 이 위치'들'에서 상하좌우 탐색 각각 해야한다.
     지금까지의 문제에서는 시작 점이 1개였다.
     즉, 
     1. 시작 점이 1개이상일 때의 처리와, 
     2. 해당 위치들에서 상하좌우 탐색하는 것을 어떻게 구현할지가 
     관건이었다.

     기본적인 BFS뼈대는 같다.
*/
int bfs(vector<pair<int, int>> first_location, int n, int m)
{
    int answer = 0;
    /*
      0. 시작점이 1개 이상일 경우, 각 위치에서 동시에 상하좌우를 탐색하여 
         '하루'동안 익어진 토마토 위치를 저장 해야한다. 
         이 '하루'는 한 cycle이 되고, 
         '하루'동안 익어진 토마토의 위치는 1개 이상이기 때문에 queue를 다음과 같이 생성한다. 
    */
    queue<vector<pair<int, int>>> q;
    
    //1. 첫 번째 시작 위치 queue에 삽입하고, 방문처리
    q.push(first_location);
    for (int i = 0; i < first_location.size(); i++)
        check[first_location[i].first][first_location[i].second] = true;

    while (!q.empty())
    {
        /*
          2. queue에서 하나의 vector하나 꺼낸다.
             여기서 하나의 vector에는 하루 동안 익어진 1개 이상의 토마토 위치가 저장 되어 있다.
        */
        vector<pair<int, int>> v = q.front();
        q.pop();

        // 3. '하루' 동안 익어진 토마토들의 위치를 삽입 할 vector선언. 이후 이 vector를 queue에 삽입한다.
        vector<pair<int, int>> one_day_ripe_tomato; 

        // 4. '하루' 동안 익어진 토마토들이 있는지 체크. 있다면 answer++된다. 
        bool isRipe = false;

        // 5. queue에서 꺼낸, vector안에 있는 각 토마토 위치에서 각각 탐색해야 한다.
        for (int i = 0; i < v.size(); i++)
        {
            for (int k = 0; k < 4; k++)
            {
                //5.1 위치 갱신 하고,
                int next_i = v[i].first + di[k];
                int next_j = v[i].second + dj[k];

                //5.2 각 상하 좌우로 갱신한 위치가 범위 안에 있고,
                if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m)
                {
                    //5.3 그 위치가 덜익은 토마토이고, 방문하지 않은 위치이면,
                    if (tomato[next_i][next_j] == 0 && check[next_i][next_j] == false)
                    {
                        //5.4 토마토를 익은 토마토로 변경하고,
                        tomato[next_i][next_j] = 1;
                        //5.5 방문 처리,
                        check[next_i][next_j] = true;
                        //5.6 익은 토마토로 변경된 위치가 있으므로 true로 바꾸고,
                        isRipe = true;
                        //5.7 익은 토마토로 변경된 위치를 vector에 삽입한다. 이후 queue에 삽입 할 것임.
                        one_day_ripe_tomato.push_back(make_pair(next_i, next_j));
                    }
                }
            }
        }
        //6. 하루 동안, 익어진 토마토가 1개라도 존재한다면, queue에 삽입한다.
        if (one_day_ripe_tomato.size() != 0)
            q.push(one_day_ripe_tomato);

        //7. 하루 동안, 익어진 토마토가 1개라도 존재한다면 일수++.
        if (isRipe)
            answer++;
    }

    return answer;
}

int main()
{
    int m, n;
    cin >> m >> n;

    //0. 토마토가 1인 좌표를 vector를 사용하여 삽입한다.(익은 토마토 위치가 1개 이상 일 수 있기 때문)
    vector<pair<int, int>> first_tomato_location;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //0.1 입력 받고,
            cin >> tomato[i][j];
            //0.2 익은 토마토가 있는 위치는 first_tomato_location에 삽입.
            if (tomato[i][j] == 1)
                first_tomato_location.push_back(make_pair(i, j));
        }
    }

    //1. bfs시작 위치'들'이 저장된 vector 넘긴다.
    //BFS수행.
    int result = bfs(first_tomato_location, n, m);
    
    //2. 모두 익었다면, 비어 있는 곳 -1을 제외한 모든 곳이 1이어야 한다.
    bool isAllRipe = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //2.1 한 곳이라도 덜 익은 토마토가 존재한다면, 벽에 가로막힌 부분이 있다는 것임.
            if (tomato[i][j] == 0)
            {
                isAllRipe = false;
                break;
            }
        }
    }

    //3. 정답 출력.
    if (isAllRipe)
        cout << result << "\n";
    else
        cout << -1 << "\n";

    return 0;
}