/*
   #. [ ����_3055�� Ż�� ] �з� Gold V
   
   #. ����
      ����� ������ ���� �̹����� ���� ���� ������ �տ� �־���, �� �ɷ��� �����غ��� ���� ��ó�� Ƽ������ ȫ���� ����Ű���� �Ѵ�. 
      �� ������ ����ġ�� �� ���� ��� �ִ�. ����ġ�� ���� ģ�� ģ���� ����� ���� ������ ���� ������ ȫ���� ���Ϸ��� �Ѵ�.
      
      Ƽ������ ������ R�� C���� �̷���� �ִ�. ����ִ� ���� '.'�� ǥ�õǾ� �ְ�, ���� ���ִ� ������ '*', ���� 'X'�� ǥ�õǾ� �ִ�. 
      ����� ���� 'D'��, ����ġ�� ��ġ�� 'S'�� ��Ÿ������ �ִ�.
      
      �� �и��� ����ġ�� ���� �ִ� ĭ�� ������ �� ĭ �� �ϳ��� �̵��� �� �ִ�. 
      (��, �Ʒ�, ������, ����) ���� �� �и��� ����ִ� ĭ���� Ȯ���Ѵ�. 
      ���� �ִ� ĭ�� �������ִ� ����ִ� ĭ(��� �� ���� ����)�� ���� ���� �ȴ�. 
      ���� ����ġ�� ���� ����� �� ����. 
      ��, ����ġ�� ���� ���ִ� �������� �̵��� �� ����, ���� ����� �ұ��� �̵��� �� ����.
      
      Ƽ������ ������ �־����� ��, ����ġ�� �����ϰ� ����� ���� �̵��ϱ� ���� �ʿ��� �ּ� �ð��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
      ����ġ�� ���� �� ������ ĭ���� �̵��� �� ����. ��, ���� �ð��� ���� �� ������ ĭ���� ����ġ�� �̵��� �� ����. 
      �̵��� �� ������ ����ġ�� ���� ������ �����̴�. 
      
   #. �Է�
      ù° �ٿ� 50���� �۰ų� ���� �ڿ��� R�� C�� �־�����.
      ���� R�� �ٿ��� Ƽ������ ������ �־�����, �������� ������ ���ڸ� �־�����. 'D'�� 'S'�� �ϳ����� �־�����.
      
   #. ���
      ù° �ٿ� ����ġ�� ����� ���� �̵��� �� �ִ� ���� ���� �ð��� ����Ѵ�. 
      ����, �����ϰ� ����� ���� �̵��� �� ���ٸ�, "KAKTUS"�� ����Ѵ�.
      
   #. ���� �Է� 1 
      3 3
      D.*
      ...
      .S.
   #. ���� ��� 1 
      3

   #. ���� �Է� 2 
      3 3
      D.*
      ...
      ..S
   #. ���� ��� 2 
      KAKTUS
      
   #. ���� �Է� 3 
      3 6
      D...*.
      .X.X..
      ....S.
   #. ���� ��� 3 
      6
      
   #. ���� �Է� 4 
      5 4
      .D.*
      ....
      ..X.
      S.*.
      ....
   #. ���� ��� 4 
      4
*/

/*
  #. Ǯ�̹�.
     - ���� �� �ð� ���� ������ ���� bfs�ϰ�, ���� ����ġ�� �� �� �ִ� ���� bfs�Ѵ�.
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
    //1. water_map�ʱ�ȭ
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            //999�� �ʱ�ȭ�ϴ� ���� : ����ġ�� �� �� �ִ� ���� ���� ���ִ� ��������, ������ ���� �������� ����ϴµ�
            //0���� �ʱ�ȭ�ϸ�, D�ڸ��� ����ġ�� �̵��� �� ����. �ִ��� ���� ���ڷ� �����ؾ� �Ѵ�.
            water_map[i][j] = 999;
    }

    //2. ���� ������������ ������ �� ������ ������ ���� ť�� �����Ѵ�.
    queue<vector<pair<int, int>>> q;

    //2.1 ť�� �������� vector push�ϰ�, �湮ó���ϰ�, ���� ���� ������ 0���� set�Ѵ�.
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
                    //���� �� ��ġ�� '��'�̰�, ���� �湮���� ���� ���̸�,
                    if (map[ni][nj] == '.' && !check[ni][nj])
                    {
                        check[ni][nj] = true;
                        //�ִ� �Ÿ� ���
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
    //��ǥ��, �ش� ��ǥ������ ����ġ�� �� �� �ִ� �ִ� ��� ��
    queue<pair<pair<int, int>, int>> q;

    q.push(make_pair(make_pair(start_i, start_j), 0));
    check[start_i][start_j] = true;

    while (!q.empty())
    {
        pair<pair<int, int>, int> curr = q.front();
        pair<int, int> curr_p = curr.first;
        int record = curr.second;

        q.pop();

        //D�� ���� �ϸ� return�Ѵ�.
        if (curr_p.first == end_i && curr_p.second == end_j)
            return record;

        for (int k = 0; k < 4; k++)
        {
            int ni = curr_p.first + di[k];
            int nj = curr_p.second + dj[k];

            if (0 <= ni && ni < R && 0 <= nj && nj < C)
            {
                //���� ��ġ�� ���� �ƴϰ�, �湮���� ���� ���̸�, ���� ���� �ʰ� �ٷ� ���� �ð����� ���� ���� �ʴ� ���̸�,
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
    
    //1.1 ���� ���۵Ǵ� ������ ������ �� �� �ֱ� ������ �ʱ� ���������� �����ϴ� vector.
    vector<pair<int, int>> water_start;

    //1.2 ����ġ�� ������, ����.
    int start_i, start_j, end_i, end_j;

    //1.3 map�Է� �ޱ�
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

    //2. ���� ������ bfs�� ���� �����Ѵ�.
    water_bfs(water_start);
    /*for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << water_map[i][j] << " ";
        cout << "\n";
    }*/
    memset(check, false, sizeof(check));

    //3. ����ġ�� �̵��ϴ� bfs�� �����Ѵ�.
    answer = hedgehog_bfs(start_i, start_j, end_i, end_j);

    if (answer != -1)
        cout << answer << "\n";
    else
        cout << "KAKTUS" << "\n";

    return 0;
}