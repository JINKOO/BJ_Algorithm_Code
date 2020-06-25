/*
  #. [ 단지 번호 붙이기 ]
  
  #. 문제
     <그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 
     철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 
     여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 
     대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 
     지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
     
  #. 입력
     첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 
     그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

  #. 출력
     첫 번째 줄에는 총 단지수를 출력하시오. 
     그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

  #. 예제 입력 1 
     7
     0110100
     0110101
     1110101
     0000111
     0100000
     0111110
     0111000
  #. 예제 출력 1 
     3
     7
     8
     9
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

string map[25];
int check[25][25];

int di[] = { -1,0,1,0 };
int dj[] = { 0,1,0,-1 };
int house_count;

/*
  dfs에서는 재귀를 사용하므로 
  house_count를 전역 변수로 설정한다.

  bfs에서는 지역 함수 선언하여 사용해도 된다.

  #. 접근 법(DFS or BFS).
   - 이전 문제에서는 이차원 배열의 역할 = 그래프의 연결 관계
   - 여기서는 이차원 배열이 그래프가 아니다. 단순한 '지도' 임.
      즉 인덱스를 위치정보로 사용해야한다. 
   - 현재의 지점이 1이면 상,하,좌,우를 판별하고 그 지점 또한 1이고, 방문한 적이 없다면,
     재귀하거나(DFS) 큐에 삽입(BFS)하고 방문처리 한다.
*/
void dfs(int i, int j, int n)
{
    //0. 재귀의 탈출 조건(이미 방문한 곳이면)
    if (check[i][j])
        return;

    //1. 현재 위치 방문처리
    check[i][j] = true;
    //2. 현재 위치는 1인 자리이므로 값 증가.
    house_count++;

    //3. 현재 위치에서 상,하,좌,우 판단 즉, 연결된 아파트 있나 판단
    for (int d = 0; d < 4; d++)
    {
        //4. 새로 방문할 아파트 인덱스 조정.
        int next_i = i + di[d];
        int next_j = j + dj[d];

        //5. 이차원 범위안에 들어있고
        if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < n)
        {
            //6. 아파트가 있는 자리라면 그 위치 인덱스 가지고 재귀호출
            if (map[next_i][next_j] == '1')
                dfs(next_i, next_j, n);
        }
    }
}

void bfs(int i, int j, int n)
{
    //0. 여기서는 인덱스 위치를 보관해야 하므로 pair사용.
    queue<pair<int, int>> q;

    //1. 첫 번째 시작점 큐에 삽입
    q.push(make_pair(i, j));
    //2. 첫 번째 시작점 방문처리
    check[i][j] = true;

    
    while (!q.empty())
    {
        //3. 현재 위치 뽑아낸다.
        pair<int, int> p = q.front();
        q.pop();

        //4. p는 1인 위치이므로 값 증가.
        house_count++;

        //5. p위치에서 상하좌우 조사
        for (int d = 0; d < 4; d++)
        {
            //6. p위치에서 상하좌우 위치 조정.
            int next_i = p.first + di[d];
            int next_j = p.second + dj[d];

            //7. 새로운 위치가 범위 안에 존재하고
            if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < n)
            {
                //8. 아파트가 존재하는 위치이며 아직 방문하지 않았다면
                if (map[next_i][next_j] == '1' && check[next_i][next_j] == false)
                {
                    //9. 큐에 삽입
                    q.push(make_pair(next_i, next_j));
                    //10. 방문 처리
                    check[next_i][next_j] = true;
                }
            }
        }
    }
}

void printResult(vector<int> answer)
{
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << "\n";
}

int main()
{
    int n;
    cin >> n;

    vector<int> answer;

    //1. 문자열로 입력받는다. 예제입력 보면 공백 없음...
    for (int i = 0; i < n; i++)
        cin >> map[i];
    
    //2. map을 반복하면서 1인 위치를 찾는다.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //3. 1인 위치이고, 아직 방문하지 않은 곳이라면 BFS or DFS Start!
            /* 
              여기서 핵심
              처음 1인 위치를 찾으면, 그 위치로부터 BFS or DFS를 수행하게 된다.
              수행하면서 연결된 아파트들은 모두 방문처리하게 된다.
              더 이상 연결된 아파트가 없다면, 단지가 생성된 것이다.

              다음 단지 생성을 위하여 다시 1인 위치이면서,
              방문하지 않은 아파트를 찾고 그 위치가 있다면,
              다시 그 위치에서 BFS or DFS수행한다.
             */
            if (map[i][j] == '1' && check[i][j] == false)
            {
                house_count = 0;
                //dfs(i, j, n);
                bfs(i, j, n);
                answer.push_back(house_count);
            }
        }
    }

    sort(answer.begin(), answer.end());
    printResult(answer);

    return 0;
}