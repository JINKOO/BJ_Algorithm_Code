/*
  #. 1978 :: �Ҽ� ã�� 

  #. ����
     �־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

  #. �Է�
     ù �ٿ� ���� ���� N�� �־�����. N�� 100�����̴�. �������� N���� ���� �־����µ� ���� 1,000 ������ �ڿ����̴�.
 
  #. ���
     �־��� ���� �� �Ҽ��� ������ ����Ѵ�.

  #. ���� �Է� 1 :: 4
                   1 3 5 7
     ���� ��� 1 :: 3
*/

#include <iostream>
int main()
{
    //1. N�Է� �ޱ�
    int num = 0;
    std::cin >> num;

    int result = 0;
    for (int i = 0; i < num; i++)
    {
        int input_number;
        std::cin >> input_number;
        int divided_num = 1;
        int count = 0;
        while (divided_num <= input_number)
        {
            if ((input_number % divided_num) == 0)
                count++;
            divided_num++;
        }

        if (count == 2)
            result++;
    }

    std::cout << result << "\n";

    return 0;
}