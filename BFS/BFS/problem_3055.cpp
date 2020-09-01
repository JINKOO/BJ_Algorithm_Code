/*
   #. [ 백준_3055번 탈출 ] 분류 Gold V
   
   #. 문제
      사악한 암흑의 군주 이민혁은 드디어 마법 구슬을 손에 넣었고, 그 능력을 실험해보기 위해 근처의 티떱숲에 홍수를 일으키려고 한다. 
      이 숲에는 고슴도치가 한 마리 살고 있다. 고슴도치는 제일 친한 친구인 비버의 굴로 가능한 빨리 도망가 홍수를 피하려고 한다.
      
      티떱숲의 지도는 R행 C열로 이루어져 있다. 비어있는 곳은 '.'로 표시되어 있고, 물이 차있는 지역은 '*', 돌은 'X'로 표시되어 있다. 
      비버의 굴은 'D'로, 고슴도치의 위치는 'S'로 나타내어져 있다.
      
      매 분마다 고슴도치는 현재 있는 칸과 인접한 네 칸 중 하나로 이동할 수 있다. 
      (위, 아래, 오른쪽, 왼쪽) 물도 매 분마다 비어있는 칸으로 확장한다. 
      물이 있는 칸과 인접해있는 비어있는 칸(적어도 한 변을 공유)은 물이 차게 된다. 
      물과 고슴도치는 돌을 통과할 수 없다. 
      또, 고슴도치는 물로 차있는 구역으로 이동할 수 없고, 물도 비버의 소굴로 이동할 수 없다.
      
      티떱숲의 지도가 주어졌을 때, 고슴도치가 안전하게 비버의 굴로 이동하기 위해 필요한 최소 시간을 구하는 프로그램을 작성하시오.
      고슴도치는 물이 찰 예정인 칸으로 이동할 수 없다. 즉, 다음 시간에 물이 찰 예정인 칸으로 고슴도치는 이동할 수 없다. 
      이동할 수 있으면 고슴도치가 물에 빠지기 때문이다. 
      
   #. 입력
      첫째 줄에 50보다 작거나 같은 자연수 R과 C가 주어진다.
      다음 R개 줄에는 티떱숲의 지도가 주어지며, 문제에서 설명한 문자만 주어진다. 'D'와 'S'는 하나씩만 주어진다.
      
   #. 출력
      첫째 줄에 고슴도치가 비버의 굴로 이동할 수 있는 가장 빠른 시간을 출력한다. 
      만약, 안전하게 비버의 굴로 이동할 수 없다면, "KAKTUS"를 출력한다.
      
   #. 예제 입력 1 
      3 3
      D.*
      ...
      .S.
   #. 예제 출력 1 
      3

   #. 예제 입력 2 
      3 3
      D.*
      ...
      ..S
   #. 예제 출력 2 
      KAKTUS
      
   #. 예제 입력 3 
      3 6
      D...*.
      .X.X..
      ....S.
   #. 예제 출력 3 
      6
      
   #. 예제 입력 4 
      5 4
      .D.*
      ....
      ..X.
      S.*.
      ....
   #. 예제 출력 4 
      4
*/

/*
  #. 풀이법.
     - 물이 매 시간 마다 퍼지는 것을 bfs하고, 이후 고슴도치가 갈 수 있는 길을 bfs한다.
*/

#include <iostream>
#include <queue>
using namespace std;

int R, C;
char map[50][50];
int water_map[50][50];
bool check[50][50];

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, -1, 0, 1 };

void water_bfs(vector<pair<int, int>> water_start)
{
    //1. water_map초기화
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            //999로 초기화하는 이유 : 고슴도치가 갈 수 있는 길을 물이 차있는 곳인지와, 다음번 물이 찰곳인지 계산하는데
            //0으로 초기화하면, D자리에 고슴도치가 이동할 수 없다. 최대한 높은 숫자로 설정해야 한다.
            water_map[i][j] = 999;
    }

    //2. 물이 여러군데에서 시작할 수 있으니 다음과 같이 큐를 정의한다.
    queue<vector<pair<int, int>>> q;

    //2.1 큐에 시작지점 vector push하고, 방문처리하고, 물의 시작 시점을 0으로 set한다.
    q.push(water_start);
    for (int i = 0; i < water_start.size(); i++)
    {
        pair<int, int> p = water_start[i];
        cout << p.first << p.second << "\n";
        check[p.first][p.second] = true;
        water_map[p.first][p.second] = 0;
    }

    while (!q.empty())
    {
        vector<pair<int, int>> curr = q.front();
        q.pop();

        vector<pair<int, int>> next;
        for (int i = 0; i < curr.size(); i++)
        {
            pair<int, int> curr_p = curr[i];
            
            for (int k = 0; k < 4; k++)
            {
                int ni = curr_p.first + di[k];
                int nj = curr_p.second + dj[k];
                
                if (0 <= ni && ni < R && 0 <= nj && nj < C)
                {
                    //다음 번 위치가 '길'이고, 아직 방문하지 않은 곳이면,
                    if (map[ni][nj] == '.' && !check[ni][nj])
                    {
                        check[ni][nj] = true;
                        //최단 거리 기록
                        water_map[ni][nj] = water_map[curr_p.first][curr_p.second] + 1;
                        next.push_back(make_pair(ni, nj));
                    }
                }
            }
        }
        if (next.size() != 0)
            q.push(next);
    }
}

int hedgehog_bfs(int start_i, int start_j, int end_i, int end_j)
{
    //좌표값, 해당 좌표까지의 고슴도치가 갈 수 있는 최단 경로 수
    queue<pair<pair<int, int>, int>> q;

    q.push(make_pair(make_pair(start_i, start_j), 0));
    check[start_i][start_j] = true;

    while (!q.empty())
    {
        pair<pair<int, int>, int> curr = q.front();
        pair<int, int> curr_p = curr.first;
        int record = curr.second;

        q.pop();

        //D에 도달 하면 return한다.
        if (curr_p.first == end_i && curr_p.second == end_j)
            return record;

        for (int k = 0; k < 4; k++)
        {
            int ni = curr_p.first + di[k];
            int nj = curr_p.second + dj[k];

            if (0 <= ni && ni < R && 0 <= nj && nj < C)
            {
                //다음 위치가 벽이 아니고, 방문하지 않은 곳이며, 물이 차지 않고 바로 다음 시간에도 물이 차지 않는 곳이면,
                if (map[ni][nj] != 'X' && !check[ni][nj] && record + 1 < water_map[ni][nj])
                {
                    check[ni][nj] = true;
                    q.push(make_pair(make_pair(ni, nj), record + 1));
                }
            }
        }
    }
    return -1;
}

int main()
{
    int answer = 0;

    cin >> R >> C;
    
    //1.1 물이 시작되는 지점은 여려곳 일 수 있기 때문에 초기 시작점들을 저장하는 vector.
    vector<pair<int, int>> water_start;

    //1.2 고슴도치의 시작점, 끝점.
    int start_i, start_j, end_i, end_j;

    //1.3 map입력 받기
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == '*')
                water_start.push_back(make_pair(i, j));
            else if (map[i][j] == 'S')
            {
                start_i = i;
                start_j = j;
            }
            else if (map[i][j] == 'D')
            {
                end_i = i;
                end_j = j;
            }
        }
    }

    //2. 물이 퍼지는 bfs를 먼저 수행한다.
    water_bfs(water_start);
    /*for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << water_map[i][j] << " ";
        cout << "\n";
    }*/
    memset(check, false, sizeof(check));

    //3. 고슴도치가 이동하는 bfs를 수행한다.
    answer = hedgehog_bfs(start_i, start_j, end_i, end_j);

    if (answer != -1)
        cout << answer << "\n";
    else
        cout << "KAKTUS" << "\n";

    return 0;
}