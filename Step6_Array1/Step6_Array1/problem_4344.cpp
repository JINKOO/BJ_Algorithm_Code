/*
  #. ���� 4344

  #. ����� �Ѱ���

  #. ����
     ���л� ��������� 90%�� �ڽ��� �ݿ��� ����� �Ѵ´ٰ� �����Ѵ�. ����� �׵鿡�� ���� ������ �˷���� �Ѵ�.

  #. �Է�
     ù° �ٿ��� �׽�Ʈ ���̽��� ���� C�� �־�����.
     ��° �ٺ��� �� �׽�Ʈ ���̽����� �л��� �� N(1 �� N �� 1000, N�� ����)�� ù ���� �־�����,
     �̾ N���� ������ �־�����. ������ 0���� ũ�ų� ����, 100���� �۰ų� ���� �����̴�.

  #. ���
     �� ���̽����� �� �پ� ����� �Ѵ� �л����� ������ �ݿø��Ͽ� �Ҽ��� ��° �ڸ����� ����Ѵ�.

  #. ���� �Է� 1 :: 5
                   5 50 50 70 80 100
                   7 100 95 90 80 70 60 50
                   3 70 90 80
                   3 70 90 81
                   9 100 99 98 97 96 95 94 93 91

     ���� ��� 1 :: 40.000%
                   57.143%
                   33.333%
                   66.667%
                   55.556%
*/

#include <iostream>
int main()
{
    //1. test_case�Է� �ޱ�
    int test_case = 0;
    std::cin >> test_case;

    //2. �� test_case�� ������� ������ float�迭 ����
    float* result = new float[test_case];

    //2. test_case��ŭ �ݺ��ϸ鼭 ��� ����, �л� ��, ��� ���� �Ѵ� �л��� ���� ���.
    for (int i = 0; i < test_case; i++)
    {
        //2.1 �л� �� �Է� �ޱ�
        int number_of_student = 0;
        std::cin >> number_of_student;

        //2.2 �л� �� ��ŭ�� ������ �Է� �ޱ����� ���� �Ҵ�ޱ�
        int* score = new int[number_of_student];

        //2.3
        int total = 0, over_average = 0;
        float average = 0.0f;

        //2.4 i��° test_case���� �л����� ���� �Է� �ޱ�.
        for (int j = 0; j < number_of_student; j++)
        {
            std::cin >> score[j];
            total = total + score[j];
        }

        //2.5 i��° test_case���� ��� ���� ����ϱ�
        average = (float)total / number_of_student;

        //2.6 i��° test_case���� ��պ��� ���� ���� ������ �л����� �� ���
        for (int k = 0; k < number_of_student; k++)
        {
            if (score[k] > average)
                over_average++;
        }

        //2.7 ��� ���� ���� ���� ������ �л� �� ���.
        result[i] = ((float)over_average / number_of_student) * 100;
    }

    //3. ��� �� ���
    std::cout << std::fixed;
    std::cout.precision(3);
    for (int i = 0; i < test_case; i++)
        std::cout << result[i] << "%" << "\n";

    return 0;
}