
/*
  #. ���� :: 1002, �ͷ�

  #. ����
     �������� ���ȯ�� �ͷ��� �ٹ��ϴ� �����̴�.
     ������ ���� ���簨�� ��� �α����� �������� �ʴ´�. ������ �������� ���ȯ�� �����̴�.
     �̼����� �������� ���ȯ���� ����� ����(�����)�� ��ġ�� ����϶�� ����� ���ȴ�.

     �������� ���ȯ�� ���� �ڽ��� �ͷ� ��ġ���� ���� �������� �Ÿ��� ����ߴ�.
     �������� ��ǥ (x1, y1)�� ���ȯ�� ��ǥ (x2, y2)�� �־�����,
     �������� ����� �������� �Ÿ� r1�� ���ȯ�� ����� �������� �Ÿ� r2�� �־����� ��,
     ������� ���� �� �ִ� ��ǥ�� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

  #. �Է�
     ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� ������ ���� �̷���� �ִ�.
     �� �ٿ� x1, y1, r1, x2, y2, r2�� �־�����. x1, y1, x2, y2�� -10,000���� ũ�ų� ����, 10,000���� �۰ų� ���� �����̰�,
     r1, r2�� 10,000���� �۰ų� ���� �ڿ����̴�.

  #. ���
     �� �׽�Ʈ ���̽����� ������� ���� �� �ִ� ��ġ�� ���� ����Ѵ�.
     ���� ������� ���� �� �ִ� ��ġ�� ������ ���Ѵ��� ��쿡�� -1�� ����Ѵ�.
    
  #. ���� �Է� 1 :: 3
                   0 0 13 40 0 37
                   0 0 3 0 7 4
                   1 1 1 1 1 5
     ���� ��� 1 :: 2
                   1
                   0
*/

#include <iostream>
#include <math.h>

int main()
{
    //1. test_case�Է� �ޱ�
    int test_case = 0;
    std::cin >> test_case;

    //2. test_case��ŭ �ݺ�
    for (int i = 0; i < test_case; i++)
    {
        double x1, y1, r1, x2, y2, r2;
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double center_distance = sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
        double radius_distance = r1 + r2;

        double max_radius = r1 < r2 ? r2 : r1;
        double min_radius = r1 < r2 ? r1 : r2;

        if (center_distance > radius_distance)
            std::cout << 0 << "\n";
        else if (center_distance == radius_distance)
            std::cout << 1 << "\n";
        else if (center_distance < radius_distance)
        {
            if (x1 == x2 && y1 == y2 && r1 == r2)
                std::cout << -1 << "\n";
            else if (center_distance + min_radius > max_radius)
                std::cout << 2 << "\n";
            else if (center_distance + min_radius == max_radius)
                std::cout << 1 << "\n";
            else if (center_distance + min_radius < max_radius)
                std::cout << 0 << "\n";
        }
    }
    return 0;
}
    