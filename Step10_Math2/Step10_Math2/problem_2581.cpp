/*
  #. ���� 2581 :: �Ҽ�

  #. ����
     �ڿ��� M�� N�� �־��� �� M�̻� N������ �ڿ��� �� �Ҽ��� ���� ��� ��� �̵� �Ҽ��� �հ� �ּڰ��� ã�� ���α׷��� �ۼ��Ͻÿ�.

  #. ���� ��� M=60, N=100�� ��� 60�̻� 100������ �ڿ��� �� 
     �Ҽ��� 61, 67, 71, 73, 79, 83, 89, 97 �� 8���� �����Ƿ�, �̵� �Ҽ��� ���� 620�̰�, �ּڰ��� 61�� �ȴ�.

  #. �Է�
     �Է��� ù° �ٿ� M��, ��° �ٿ� N�� �־�����.
     M�� N�� 10,000������ �ڿ����̸�, M�� N���� �۰ų� ����.

  #. ���
     M�̻� N������ �ڿ��� �� �Ҽ��� ���� ��� ã�� ù° �ٿ� �� ����, ��° �ٿ� �� �� �ּڰ��� ����Ѵ�. 

  #. ��, M�̻� N������ �ڿ��� �� �Ҽ��� ���� ���� ù° �ٿ� -1�� ����Ѵ�.

  #. ���� �Է� 1 >> 60
                   100
     ���� ��� 1 << 620
                   61
  
  #. ���� �Է� 2 >> 64
                   65
     ���� ��� 2 << -1
*/

#include <iostream>
int main()
{
    //1. M(start), N(end)�Է� �ޱ�
    int start = 0, end = 0;
    std::cin >> start >> end;

    //2. M <= primeNUmber <= N ã��
    int size = 0, primeNumber_sum = 0, min_primeNum = 0;
    bool isFirst = true;
    for (int num = start; num <= end; num++)
    {
        int divided_number = 1;
        int sub_count = 0;
        while (divided_number <= num)
        {
            if((num % divided_number) == 0)
                sub_count++;
            divided_number++;
        }
        if (sub_count == 2)
        {
            if (isFirst)
            {
                min_primeNum = num;
                isFirst = false;
            }
            primeNumber_sum = primeNumber_sum + num;
            size++;
        }
    }

    if (size == 0)
        std::cout << -1 << "\n";
    else 
    {
        std::cout << primeNumber_sum << "\n";
        std::cout << min_primeNum << "\n";
    }
    return 0;
}