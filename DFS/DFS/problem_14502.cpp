/*
  #. [ 연구소 분류 ]

  #. 문제
     인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다.
     다행히 바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.

     연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다.
     연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다.

     일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다.
     새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.

     예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자.

     2 0 0 0 1 1 0
     0 0 1 0 1 2 0
     0 1 1 0 1 0 0
     0 1 0 0 0 0 0
     0 0 0 0 0 1 1
     0 1 0 0 0 0 0
     0 1 0 0 0 0 0

     이때, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다. 아무런 벽을 세우지 않는다면,
     바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.
     2행 1열, 1행 2열, 4행 6열에 벽을 세운다면 지도의 모양은 아래와 같아지게 된다.

     2 1 0 0 1 1 0
     1 0 1 0 1 2 0
     0 1 1 0 1 0 0
     0 1 0 0 0 1 0
     0 0 0 0 0 1 1
     0 1 0 0 0 0 0
     0 1 0 0 0 0 0

     바이러스가 퍼진 뒤의 모습은 아래와 같아진다.

     2 1 0 0 1 1 2
     1 0 1 0 1 2 2
     0 1 1 0 1 2 2
     0 1 0 0 0 1 2
     0 0 0 0 0 1 1
     0 1 0 0 0 0 0
     0 1 0 0 0 0 0

     벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다. 위의 지도에서 안전 영역의 크기는 27이다.
     연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.

  #. 입력
     첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)
     둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다.
     2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.
     빈 칸의 개수는 3개 이상이다.

  #. 출력
     첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.

  #. 예제 입력 1
     7 7
     2 0 0 0 1 1 0
     0 0 1 0 1 2 0
     0 1 1 0 1 0 0
     0 1 0 0 0 0 0
     0 0 0 0 0 1 1
     0 1 0 0 0 0 0
     0 1 0 0 0 0 0
  #. 예제 출력 1
     27

  #. 예제 입력 2
     4 6
     0 0 0 0 0 0
     1 0 0 0 0 2
     1 1 1 0 0 2
     0 0 0 0 0 2
  #. 예제 출력 2
     9

  #. 예제 입력 3
     8 8
     2 0 0 0 0 0 0 2
     2 0 0 0 0 0 0 2
     2 0 0 0 0 0 0 2
     2 0 0 0 0 0 0 2
     2 0 0 0 0 0 0 2
     0 0 0 0 0 0 0 0
     0 0 0 0 0 0 0 0
     0 0 0 0 0 0 0 0
  #. 예제 출력 3
     3
*/

/*
   #. 나의 접근법
      - 벽 3개 세우는 것을 어떻게 처리해야 할지 생각하지 못함...

   #. 풀이
      - 본 문제는 N, M범위가 <= 8 로 작다.
      --> 모든 경우의 수를 따져가며 + 탐색해야 한다.
          즉, brute force + BFS/DFS문제 였다.
*/

#include <iostream>
using namespace std;

int N, M, answer;
int map[8][8];
int tempMap[8][8];

int check[8][8];

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, -1, 0, 1 };

void mapCopy(int (*temp)[8], int (*origin)[8])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            temp[i][j] = origin[i][j];
    }
}

void dfs(int (*virus)[8], int curr_i, int curr_j)
{
    if (check[curr_i][curr_j] == true)
        return;

    check[curr_i][curr_j] = true;

    for (int k = 0; k < 4; k++)
    {
        int next_i = curr_i + di[k];
        int next_j = curr_j + dj[k];

        if (next_i >= 0 && next_i < N && next_j >= 0 && next_j < M)
        {
            //!= 1이 신의 한수 였다... 초반에 == 0인 경우만 했더니 안됐음..
            if (virus[next_i][next_j] != 1 && check[next_i][next_j] == false)
            {
                virus[next_i][next_j] = 2;
                dfs(virus, next_i, next_j);
            }
        }
    }
}

void print(int(*virus)[8])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << virus[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

int getSafeZone(int(*virus)[8])
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (virus[i][j] == 0)
                count++;
        }
    }
    return count;
}

void makeWall(int count)
{
    if (count == 3)
    {
        int virus[8][8];
        mapCopy(virus, tempMap);
        memset(check, false, sizeof(check));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (virus[i][j] == 2 && check[i][j] == false)
                {
                    dfs(virus, i, j);
                    int result = getSafeZone(virus);
                    if (answer <= result)
                        answer = result;
                }
            }
        }
        return;
    }


    //모든 경우의 수를 찾는 부분,
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tempMap[i][j] == 0)
            {
                tempMap[i][j] = 1;
                makeWall(count + 1);
                tempMap[i][j] = 0;
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
            {
                mapCopy(tempMap, map);
                tempMap[i][j] = 1;
                makeWall(1);
                tempMap[i][j] = 0;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}