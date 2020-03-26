/*
  #. ���� 1085 :: ���簢������ Ż�� 

  #. ����
     �Ѽ��� ���� (x, y)�� �ִ�. ���簢���� ���� �Ʒ� �������� (0, 0)�� �ְ�, ������ �� �������� (w, h)�� �ִ�. 
     ���簢���� ��輱���� ���� �Ÿ��� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

  #. �Է�
     ù° �ٿ� x y w h�� �־�����. w�� h�� 1,000���� �۰ų� ���� �ڿ����̰�, x�� 1���� ũ�ų� ����, 
     w-1���� �۰ų� ���� �ڿ����̰�, y�� 1���� ũ�ų� ����, h-1���� �۰ų� ���� �ڿ����̴�.

  #. ���
     ù° �ٿ� ������ ������ ����Ѵ�.

  #. ���� �Է� 1 >> 6 2 10 3
     ���� ��� 1 >> 1
*/

#include <iostream>

struct Point
{
    int x;
    int y;
};

int main()
{
    int x, y, w, h;
    std::cin >> x >> y >> w >> h;

    Point input_point;
    input_point.x = x;
    input_point.y = y;

    Point pivot_point[4];
    pivot_point[0].x = x;
    pivot_point[0].y = 0;

    pivot_point[1].x = x;
    pivot_point[1].y = h;

    pivot_point[2].x = 0;
    pivot_point[2].y = y;

    pivot_point[3].x = w;
    pivot_point[3].y = y;

    int min = pow(pivot_point[0].x - input_point.x, 2) + pow(pivot_point[0].y - input_point.y, 2);
    for (int i = 1; i < 4; i++)
    {
        int distance = pow(pivot_point[i].x - input_point.x, 2) + pow(pivot_point[i].y - input_point.y, 2);
        if (min <= distance)
            min = distance;
    }

    std::cout << min << "\n";
    return 0;
}