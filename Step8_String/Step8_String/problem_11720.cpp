/*
 ����
 N���� ���ڰ� ���� ���� �����ִ�. �� ���ڸ� ��� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

 �Է�
 ù° �ٿ� ������ ���� N (1 �� N �� 100)�� �־�����.
 ��° �ٿ� ���� N���� ������� �־�����.

 ���
 �Է����� �־��� ���� N���� ���� ����Ѵ�.
*/

#include <iostream>

int main()
{

    int number = 0;
    std::cin >> number;

    int sum = 0;
    char* num_str = new char[number + 1];

    for (int i = 0; i < number; i++)
        std::cin >> num_str[i];

    num_str[number] = '\0';

    for (int i = 0; i < number; i++)
    {
        int num = num_str[i] - 48;
        sum = sum + num;
    }

    std::cout << sum << "\n";

    delete[] num_str;
    num_str = NULL;

    return 0;
}