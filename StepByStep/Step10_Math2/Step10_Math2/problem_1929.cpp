/*
  #. ���� 1929 ::  �Ҽ� ���ϱ� 

  #. ����
     M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

  #. �Է�
     ù° �ٿ� �ڿ��� M�� N�� �� ĭ�� ���̿� �ΰ� �־�����. (1 �� M �� N �� 1,000,000)

  #. ���
     �� �ٿ� �ϳ���, �����ϴ� ������� �Ҽ��� ����Ѵ�.

  #. ���� �Է� 1 >> 3 16

     ���� ��� 1 << 3
                   5
                   7
                   11
                   13
*/

#include <iostream>
int SIZE = 1000000;

int main()
{
    //�����佺�׳׽��� ä�� ����Ѵ�.
    int m, n;
    std::cin >> m >> n;

    //1 ~ 1,000,000���ڿ� ���Ͽ� true�� �ʱ�ȸ
    bool* num_arr = new bool[SIZE + 1];
    
    num_arr[1] = false;
    for (int i = 2; i <= SIZE; i++)
        num_arr[i] = true;

    for (int i = 2; i * i <= SIZE; i++)
    {
        if (num_arr[i])
        {
            for (int j = i * i; j <= SIZE; j += i)
                num_arr[j] = false;
        }
    }

    for (int i = m; i <= n; i++)
    {
        if (num_arr[i])
            std::cout << i << "\n";
    }

    return 0;
}