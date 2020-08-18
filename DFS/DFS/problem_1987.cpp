/*
   #. [ ����_1987�� ���ĺ� ] Gold IV
   
   #. ����
      ���� Rĭ, ���� Cĭ���� �� ǥ ����� ���尡 �ִ�. 
      ������ �� ĭ���� �빮�� ���ĺ��� �ϳ��� ���� �ְ�, ���� ��� ĭ (1�� 1��) ���� ���� ���� �ִ�.
      ���� �����¿�� ������ �� ĭ ���� �� ĭ���� �̵��� �� �ִµ�, 
      ���� �̵��� ĭ�� ���� �ִ� ���ĺ��� ���ݱ��� ������ ��� ĭ�� ���� �ִ� ���ĺ����� �޶�� �Ѵ�. 
      ��, ���� ���ĺ��� ���� ĭ�� �� �� ���� �� ����.
     
   #. ���� ��ܿ��� �����ؼ�, ���� �ִ��� �� ĭ�� ���� �� �ִ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 
      ���� ������ ĭ�� ���� ����� ĭ�� ���Եȴ�.
      
   #. �Է�
      ù° �ٿ� R�� C�� ��ĭ�� ���̿� �ΰ� �־�����. 
      (1 �� R,C �� 20) ��° �ٺ��� R���� �ٿ� ���ļ� ���忡 ���� �ִ� C���� �빮�� ���ĺ����� ��ĭ ���� �־�����.
      
   #. ���
      ù° �ٿ� ���� ���� �� �ִ� �ִ��� ĭ ���� ����Ѵ�.
      
   #. ���� �Է� 1 
      2 4
      CAAB
      ADCB
   #. ���� ��� 1 
      3 
*/

#include <string>
#include <iostream>
using namespace std;

int r, c;
string map[20];
bool check[26];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
int answer;

void dfs(int i, int j, int count)
{
    //���Ⱑ �߿��� �κ��̾���.
    if (answer < count)
        answer = count;

    for (int k = 0; k < 4; k++)
    {
        int ni = i + di[k];
        int nj = j + dj[k];

        if (0 <= ni && ni < r && 0 <= nj && nj < c)
        {
            if (check[map[ni][nj] - 'A'] == false)
            {
                check[map[ni][nj] - 'A'] = true;
                dfs(ni, nj, count + 1);
                check[map[ni][nj] - 'A'] = false;
            }
        }
    }
}

int main()
{
    cin >> r >> c;

    for (int i = 0; i < r; i++)
        cin >> map[i];

    check[map[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << answer << "\n";

    return 0;
}