// 다차원 배열에서의 BFS 기본 틀.

#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int board[502][502] =
{ {1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} };

// 방문 표시 다차원 배열
bool vis[502][502];

// 7행, 10열
int n = 7, m = 10;

// 상하좌우 움직임
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,-1,0 };

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;

    // 1. 시작점 (0, 0) 방문표시
    vis[0][0] = 1;

    // 2. 시작점 Q에 삽입
    Q.push(make_pair(0, 0));


    // 3. 본격적인 BFS시작
    while (!Q.empty())
    {
        // 3.1 Q의 front() 가져오고, pop
        pair<int, int> curr = Q.front();
        Q.pop();

        // test 출력
        cout << curr.X << ", " << curr.Y << "\n";

        // 3.2 curr에서 상하좌우 탐색 시작
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = curr.X + dx[dir];
            int ny = curr.Y + dy[dir];

            // 3.3 다차원 배열 범위안에 있지 않으면 continue;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            // 3.4 이미 방문했고, 1이 아니면
            if (vis[nx][ny] || board[nx][ny] != 1) continue;

            // 3.5 방문표시 후 큐에 삽입
            vis[nx][ny] = 1;
            Q.push(make_pair(nx, ny));
        }
    }

	return 0;
}