/*
  �迭���� �迭 ��ü�� Ư�� ������ �ʱ�ȭ�ϴ� ��.
  1. memset�� ����õ
     --> 0, -1�� �ƴ� ���� ���� ������ ������, 2���� �̻��� �迭�� �Լ� parameter�� �ѱ�� �װ����� memset�ϸ� �߸��� ��� �߻�.
  2. for���� ���� ������ �ٲٴ� ���
  3. algorithm��� ������ fill�Լ��� ����Ѵ�.

  3���� �������
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[21];
    int b[21][21];

    // 1. memset
    memset(a, 0, sizeof a);
    memset(b, -1, sizeof b);

    // 2. for�� ���
    for (int i = 0; i < 21; i++)
        a[i] = 0;
    
    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 21; j++)
            b[i][j] = -1;

    //3. fill�Լ� ���
    fill(a, a + 21, 0);
    for (int i = 0; i < 21; i++)
        fill(b[i], b[i] + 21, -1);

    return 0;
}

