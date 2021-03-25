// ������ �迭������ BFS �⺻ Ʋ.

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

// �湮 ǥ�� ������ �迭
bool vis[502][502];

// 7��, 10��
int n = 7, m = 10;

// �����¿� ������
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,-1,0 };

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;

    // 1. ������ (0, 0) �湮ǥ��
    vis[0][0] = 1;

    // 2. ������ Q�� ����
    Q.push(make_pair(0, 0));


    // 3. �������� BFS����
    while (!Q.empty())
    {
        // 3.1 Q�� front() ��������, pop
        pair<int, int> curr = Q.front();
        Q.pop();

        // test ���
        cout << curr.X << ", " << curr.Y << "\n";

        // 3.2 curr���� �����¿� Ž�� ����
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = curr.X + dx[dir];
            int ny = curr.Y + dy[dir];

            // 3.3 ������ �迭 �����ȿ� ���� ������ continue;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            // 3.4 �̹� �湮�߰�, 1�� �ƴϸ�
            if (vis[nx][ny] || board[nx][ny] != 1) continue;

            // 3.5 �湮ǥ�� �� ť�� ����
            vis[nx][ny] = 1;
            Q.push(make_pair(nx, ny));
        }
    }

	return 0;
}