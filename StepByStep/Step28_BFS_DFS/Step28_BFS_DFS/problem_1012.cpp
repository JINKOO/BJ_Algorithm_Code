/*
  #. [ 유기농 배추 ]
  
  #. 문제
     차세대 영농인 한나는 강원도 고랭지에서 유기농 배추를 재배하기로 하였다. 
     농약을 쓰지 않고 배추를 재배하려면 배추를 해충으로부터 보호하는 것이 중요하기 때문에, 
     한나는 해충 방지에 효과적인 배추흰지렁이를 구입하기로 결심한다. 
     이 지렁이는 배추근처에 서식하며 해충을 잡아 먹음으로써 배추를 보호한다. 
     특히, 어떤 배추에 배추흰지렁이가 한 마리라도 살고 있으면 이 지렁이는 인접한 다른 배추로 이동할 수 있어, 
     그 배추들 역시 해충으로부터 보호받을 수 있다.
     (한 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우에 서로 인접해있다고 간주한다)
     
     한나가 배추를 재배하는 땅은 고르지 못해서 배추를 군데군데 심어놓았다. 
     배추들이 모여있는 곳에는 배추흰지렁이가 한 마리만 있으면 되므로 서로 인접해있는 배추들이 
     몇 군데에 퍼져있는지 조사하면 총 몇 마리의 지렁이가 필요한지 알 수 있다.

     예를 들어 배추밭이 아래와 같이 구성되어 있으면 최소 5마리의 배추흰지렁이가 필요하다.
     (0은 배추가 심어져 있지 않은 땅이고, 1은 배추가 심어져 있는 땅을 나타낸다.)

        1	1	0	0	0	0	0	0	0	0
        0	1	0	0	0	0	0	0	0	0
        0  	0	0	0	1	0	0	0	0	0
        0	0	0	0	1	0	0	0	0	0
        0	0	1	1	0	0	0	1	1	1
        0	0	0	0	1	0	0	1	1	1
        
  #. 입력
     입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 
     그 다음 줄부터 각각의 테스트 케이스에 대해 첫째 줄에는 배추를 심은 배추밭의 가로길이 
     M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50), 그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다. 그 다음 K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다.

  #. 출력
     각 테스트 케이스에 대해 필요한 최소의 배추흰지렁이 마리 수를 출력한다.

  #. 예제 입력 1 
     2
     10 8 17
     0 0
     1 0
     1 1
     4 2
     4 3
     4 5
     2 4
     3 4
     7 4
     8 4
     9 4
     7 5
     8 5
     9 5
     7 6
     8 6
     9 6
     10 10 1
     5 5
  #. 예제 출력 1 
     5
     1
  
  #. 예제 입력 2 
     1
     5 3 6
     0 2
     1 2
     2 2
     3 2
     4 2
     4 0
  #. 예제 출력 2 
     2
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[50][50];
int check[50][50];

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,-1,0,1 };

void dfs(int i, int j, int n, int m)
{
    //0. 이미 방문한 배추이면 return
    if (check[i][j])
        return;

    //1. 현재 배추 위치 방문처리.
    check[i][j] = true;

    //2. 현재 배추 위치에서 상하좌우로 배추있나 탐색시작.
    for (int k = 0; k < 4; k++)
    {
        //3. 상하좌우 탐색 위한 현재인덱스 이용하여 조정.
        int next_i = i + di[k];
        int next_j = j + dj[k];

        //4. 조정한 위치가 map[n][m]배열 범위 안에 있고, 
        if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m)
        {
            //5. 조정한 위치에 배추가 존재하며, 아직 방문하지 않은 배추의 위치이면,
            if (map[next_i][next_j] == 1 && check[next_i][next_j] == false)
                //6. 이 위치에서 또 다시 상하좌우 탐색 시작.
                dfs(next_i, next_j, n, m);
        }
    }
}

void bfs(int i, int j, int n, int m)
{
    //0. 위치 정보를 활용해야 하므로 pair사용.
    queue<pair<int, int>> q;

    //1. 우선 처음 발견된 배추 위치 큐에 삽입하고 방문처리.
    q.push(make_pair(i, j));
    check[i][j] = true;

    while (!q.empty())
    {
        //2. 큐에서 하나 꺼내고,
        pair<int, int> p = q.front();
        q.pop();

        //3. 꺼낸 p에서 상하좌우 탐색.
        for (int k = 0; k < 4; k++)
        {
            int next_i = p.first + di[k];
            int next_j = p.second + dj[k];

            //4. 상하좌우 위치가 map[n][m]범위 안에 존재하고,
            if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m)
            {
                //5. 배추가 존재하는 위치이며, 방문하지 않은 위치이면
                if (map[next_i][next_j] == 1 && check[next_i][next_j] == false)
                {
                    //6. 해당 위치 큐에 삽입하고, 방문처리
                    q.push(make_pair(next_i, next_j));
                    check[next_i][next_j] = true;
                }
            }
        }
    }
}

void init(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            map[i][j] = 0;
            check[i][j] = false;
        }
    }
}
void printResult(vector<int> &answer)
{
    for (int i : answer)
        cout << i << "\n";
}

int main()
{
    int T;
    cin >> T;

    vector<int> answer;
    
    for (int i = 0; i < T; i++)
    {
        int n, m, k;
        cin >> n >> m >> k;
        
        //1. 흰 지렁이 최소의 개수 count
        int count = 0;
        
        //2. 한 번의 T수행하면, 다시 map[][], check[][]초기화 해야한다.
        init(n, m);

        //3. 배추 지도 초기화
        for (int j = 0; j < k; j++)
        {
            int num1, num2;
            cin >> num1 >> num2;
            //3.1 배추가 존재하는 위치 
            map[num1][num2] = 1;
        }

        //4. 실질적인 탐색 준비
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                //5. 배추가 존재하는 위치이며, 아직 탐색하지 않은 지점이면,
                if (map[y][x] == 1 && check[y][x] == false)
                {
                    //6. 흰지렁이 1마리 추가
                    count++;
                    //7. 현재 배추위치에서 상하좌우에 또 다른 배추 있나 탐색 시작.
                    //dfs(y, x, n, m);
                    bfs(y, x, n, m);
                }
            }
        }
        //8. 탐색 끝내면 흰지렁이 마리 수 push
        answer.push_back(count);
    }

    printResult(answer);

    return 0;
}