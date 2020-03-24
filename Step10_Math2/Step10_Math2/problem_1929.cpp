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
int main()
{
    int M, N = 0;
    std::cin >> M >> N;

    for (int num = M; num <= N; num++)
    {
        int divided_number = 1, count = 0;
        while (divided_number <= num)
        {
            if ((num % divided_number) == 0)
                count++;
            divided_number++;
        }
        if (count == 2)
            printf("%d\n", num);
    }
    return 0;
}