/*
  #. ���� 4153 :: �����ﰢ��

  #. ����
     ���� ����Ʈ�ε��� �� ������ ���̰� 3, 4, 5�� �ﰢ���� ���� �ﰢ���ΰ��� �˾Ƴ´�.
     �־��� ������ ���̷� �ﰢ���� �������� �ƴ��� �����Ͻÿ�.

  #. �Է�
     �Է��� �������� �׽�Ʈ���̽��� �־����� �������ٿ��� 0 0 0�� �Էµȴ�.
     �� �׽�Ʈ���̽��� ��� 30,000���� ���� ���� ������ �־�����, �� �Է��� ���� ���̸� �ǹ��Ѵ�.

  #. ���
     �� �Է¿� ���� ���� �ﰢ���� �´ٸ� "right", �ƴ϶�� "wrong"�� ����Ѵ�.

  #. ���� �Է� 1 >> 6 8 10
                   25 52 60
                   5 12 13
                   0 0 0
  #. ���� ��� 1 << right
                   wrong
                   right
*/

#include <iostream>

void findMidMin(int& mid, int& min, int num2, int num3)
{
    mid = num2 > num3 ? num2 : num3;
    min = num2 < num3 ? num2 : num3;
}

int main()
{
    while (1)
    {
        int x = 0, y = 0, z = 0;
        std::cin >> x >> y >> z;

        if (x == 0 && y == 0 && z == 0)
            break;

        int max = 0, mid = 0, min = 0;
        if (x > y && x > z)
        {
            max = x;
            findMidMin(mid, min, y, z);
        }

        else if (y > x && y > z)
        {
            max = y;
            findMidMin(mid, min, x, z);
        }

        else if (z > x && z > y)
        {
            max = z;
            findMidMin(mid, min, x, y);
        }

        std::cout << max << ">" << mid << ">" << min << "\n";

        if ((max * max) == (mid * mid) + (min * min))
            std::cout << "right" << "\n";
        else
            std::cout << "wrong" << "\n";
    }
    return 0;
}