/*

 #. ���� 10872 :: ���丮�� 

 #. ����
    0���� ũ�ų� ���� ���� N�� �־�����. �̶�, N!�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

 #. �Է�
    ù° �ٿ� ���� N(0 �� N �� 12)�� �־�����.

 #. ���
    ù° �ٿ� N!�� ����Ѵ�.

 #. ���� �Է� 1 >> 10
    ���� ��� 1 >> 3628800
*/
#include <iostream>
int factorial(int n)
{
    return n == 0 ? 1 : n * factorial(n - 1);
}

int main()
{
    int input_num = 0;
    std::cin >> input_num;
    std::cout << factorial(input_num) << "\n";
    return 0;
}