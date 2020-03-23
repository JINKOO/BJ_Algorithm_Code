/*
  #. OX����

  #. ����
     "OOXXOXXOOO"�� ���� OX������ ����� �ִ�. O�� ������ ���� ���̰�, X�� ������ Ʋ�� ���̴�.
     ������ ���� ��� �� ������ ������ �� �������� ���ӵ� O�� ������ �ȴ�. ���� ���, 10�� ������ ������ 3�� �ȴ�.
     "OOXXOXXOOO"�� ������ 1+2+0+0+1+0+0+1+2+3 = 10���̴�.
     OX������ ����� �־����� ��, ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

  #. �Է�
     ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�,
     ���̰� 0���� ũ�� 80���� ���� ���ڿ��� �־�����. ���ڿ��� O�� X������ �̷���� �ִ�.

  #. ���
     �� �׽�Ʈ ���̽����� ������ ����Ѵ�.

  #. ���� �Է� 1 :: 5
                   OOXXOXXOOO
                   OOXXOOXXOO
                   OXOXOXOXOXOXOX
                   OOOOOOOOOO
                   OOOOXOOOOXOOOOX
    ���� ��� 1 ::  10
                   9
                   7
                   55
                   30
*/

#include <iostream>
#include <string>

int main()
{
    //1. test_case�Է� �ޱ�
    int test_case = 0;
    std::cin >> test_case;

    //2. �� OX���ڿ��� ����� �����ϴ� �迭.
    int* result = new int[test_case];

    //3. test_case OX���� �Է�
    for (int i = 0; i < test_case; i++)
    {
        //3.1 OX���� �Է�
        std::string input_OX;
        std::cin >> input_OX;

        //3.2 �Է� ���� ���ڿ� ���� ���ϰ�, c_str�� ��ȯ 
        int length = input_OX.length();
        const char* str_OX = input_OX.c_str();

        //3.3 sub_score : 'O'�� ���� ���
        //    total_score : �ϳ��� OX�������� ���� �ջ�.
        int sub_score = 0, total_score = 0;
        for (int j = 0; j < length; j++)
        {
            str_OX[j] == 'X' ? (sub_score = 0) : (sub_score = sub_score + 1);
            total_score = total_score + sub_score;
        }

        //3.4 �� OX���������� �ջ� ���� ����.
        result[i] = total_score;
    }

    //4. ��� ���
    for (int i = 0; i < test_case; i++)
        std::cout << result[i] << "\n";

    return 0;
}