/*
  #. [ ���ٲ��� ]
  #. ����
     �����̴� ������ ���ٲ����� �ϰ� �ִ�. 
     �����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�, ������ �� K(0 �� K �� 100,000)�� �ִ�. 
     �����̴� �Ȱų� �����̵��� �� �� �ִ�. 
     ����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X-1 �Ǵ� X+1�� �̵��ϰ� �ȴ�. 
     �����̵��� �ϴ� ��쿡�� 1�� �Ŀ� 2*X�� ��ġ�� �̵��ϰ� �ȴ�.

     �����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

  #. �Է�
     ù ��° �ٿ� �����̰� �ִ� ��ġ N�� ������ �ִ� ��ġ K�� �־�����. N�� K�� �����̴�.

  #. ���
     �����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.

  #. ���� �Է� 1 
     5 17
     ���� ��� 1 
     4
     ��Ʈ
     �����̰� 5-10-9-18-17 ������ ���� 4�ʸ��� ������ ã�� �� �ִ�.

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX_SIZE 1000000


/*
  #. ���ٹ�.
     - ���� �丶�� ������ �����ϴ�.
       ��, �� ���������� ������ ���� '����'�̴�.
     - BFS�� ���Ͽ� ù ��° ��ġ���� -1, +1, *2 ��ġ�� Ž���ϸ鼭
       �湮 ó���ϰ�, ������ ã�´�.
       �� ��, �� cycle(queue���� ������ ��)�� ���� �Ǹ�, 1�ʾ� ����.
*/


int check[MAX_SIZE + 1];

int bfs(vector<int> first_loc, int k)
{
    int answer = 0;
    //0. ù ���� ��ġ�� 1��������,
    //   �� ��° Ž�� �� ��ġ�� 3��, �� �� �� ��ġ���� �ִ� 3������ Ž�� ��ġ �þ.
    //   ��, �� cycle���� Ž�� �� ���� �����ϱ� ���� ������ ���� queue����.
    queue<vector<int>> q;

    //1. �������� ������ġ vector�� queue�� �ְ�, �湮 ó��
    q.push(first_loc);
    for (int i = 0; i < first_loc.size(); i++)
        check[first_loc[i]] = true;

    //2. �������� ���� ��ġ�� ���� ����.
    while (!q.empty())
    {
        //3. ������ �ִ� �� ã�Ҵ���
        bool found = false;

        //4. queue���� �ϳ� ������, -1, +1, *2 ��ġ Ž�� ����.
        vector<int> v = q.front();
        q.pop();

        //5. queue�� ���� �� ���� ��ġ vector
        vector<int> next_loc;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == k)
            {
                found = true;
                break;
            }

            //6. ��ġ ���� ��, 
            int m1 = v[i] + 1;
            int m2 = v[i] - 1;
            int m3 = v[i] * 2;

            //7. �� ��ġ�� ������ �ְ�, �湮���� ���� ���̸�
            //   �湮ó���ϰ�, �� ��ġ���� �ٽ� Ž���ϵ��� vector�� ����.
            if (m1 >= 0 && m1 < MAX_SIZE && check[m1] == false)
            {
                check[m1] = true;
                next_loc.push_back(m1);
            }

            if (m2 >= 0 && m2 < MAX_SIZE && check[m2] == false)
            {
                check[m2] = true;
                next_loc.push_back(m2);
            }

            if (m3 >= 0 && m3 <= MAX_SIZE && check[m3] == false)
            {
                check[m3] = true;
                next_loc.push_back(m3);
            }   
        }

        //8. ���� ã������ �׸�.
        if (found)
            break;

        //9. ����� 0�� �ƴ϶�� �ǹ� : ���� Ž���� ��ġ�� ����.
        if (next_loc.size() != 0)
        {
            answer++;
            q.push(next_loc);
        }
    }
    return answer;
}

int main()
{
    //0. �Է�.
    int N, K;
    cin >> N >> K;

    //1. queue�� ���Ҹ� vector�� ����ϱ� ����,
    vector<int> v;
    v.push_back(N);

    //2. BFS����.
    cout << bfs(v, K) << "\n";

	return 0;
}