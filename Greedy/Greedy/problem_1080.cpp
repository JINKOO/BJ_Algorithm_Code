/*
  #. [ ��� ]
  
  #. ����
     0�� 1�θ� �̷���� ��� A�� ��� B�� �ִ�. �̶�, ��� A�� ��� B�� �ٲٴµ� 
     �ʿ��� ������ Ƚ���� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
     ����� ��ȯ�ϴ� ������ � 3*3ũ���� �κ� ��Ŀ� �ִ� ��� ���Ҹ� ������ ���̴�. (0 -> 1, 1 -> 0)

  #. �Է�
     ù° �ٿ� ����� ũ�� N M�� �־�����. 
     N�� M�� 50���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ��� ��� A�� �־�����, 
     �� �����ٺ��� N���� �ٿ��� ��� B�� �־�����.

  #. ���
     ù° �ٿ� ������ ������ ����Ѵ�. ���� A�� B�� �ٲ� �� ���ٸ� -1�� ����Ѵ�.

  #. ���� �Է� 1 
     3 4
     0000
     0010
     0000
     1001
     1011
     1001
  #. ���� ��� 1 
     2
*/

#include <iostream>
using namespace std;

int a[50][50];
int b[50][50];

int solution(int n, int m)
{
    int answer = 0;
    //
    if (n >= 3 && m >= 3)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

            }
        }
    }

    else
    {
        answer = -1;
    }
    //
    return answer;
}

void initMatrix(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    initMatrix(n, m);
   
    cout << solution(n, m) << "\n";

    return 0;
}