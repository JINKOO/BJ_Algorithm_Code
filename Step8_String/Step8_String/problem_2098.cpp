/*
 #. ����
  ������� ���� ����� ������ ���� ���Ѵ�. ����� ���ڸ� �дµ� ������ �ִ�.
  �̷��� ������ ���ϴ� ����� ���ؼ� ����̴� ���� ũ�⸦ ���ϴ� ������ ���־���.
  ����̴� �� �ڸ� �� �� ���� ĥ�ǿ� ���־���. �� ������ ũ�Ⱑ ū ���� ���غ���� �ߴ�.

 #. ����� ���� �ٸ� ����� �ٸ��� �Ųٷ� �д´�.
   ���� ���, 734�� 893�� ĥ�ǿ� �����ٸ�, ����� �� ���� 437�� 398�� �д´�.
   ����, ����� �� ���� ū ���� 437�� ū ����� ���� ���̴�.

 #. �� ���� �־����� ��, ����� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

 #. �Է�
  ù° �ٿ� ����̰� ĥ�ǿ� ���� �� �� A�� B�� �־�����.
  �� ���� ���� ���� �� �ڸ� ���̸�, 0�� ���ԵǾ� ���� �ʴ�.

 #. ���
  ù° �ٿ� ����� ����� ����Ѵ�.

 #. ���� �Է� 1 :: 734 893
 #. ���� ��� 1 :: 437
*/

#include <iostream>
#include <string>

int getLength(std::string str);
char* reverse(char* c_num, int size);
int findMax(int num1, int num2);

int main()
{
    //1. �ΰ��� �� �Է� �ޱ�
    std::string num1, num2;
    std::cin >> num1 >> num2;

    //2. c_str�� ��ȯ
    char* c_num1 = new char[getLength(num1)];
    char* c_num2 = new char[getLength(num2)];
    strcpy_s(c_num1, getLength(num1), num1.c_str());
    strcpy_s(c_num2, getLength(num2), num2.c_str());


    char* reverse_num1 = reverse(c_num1, getLength(num1));
    char* reverse_num2 = reverse(c_num2, getLength(num2));


    //3. ū �� ���
    std::cout << findMax(atoi(reverse_num1), atoi(reverse_num2)) << "\n";

    delete[] c_num1;
    delete[] c_num2;

    return 0;
}

int getLength(std::string str)
{
    return str.length() + 1;
}

char* reverse(char* c_num, int size)
{
    char* reverse_num = new char[size];
    for (int i = 0; i < size - 1; i++)
    {
        reverse_num[i] = c_num[size - 2 - i];
    }
    reverse_num[size - 1] = c_num[size - 1];

    return reverse_num;
}

int findMax(int num1, int num2)
{
    if (num1 <= num2)
        return num2;
    else
        return num1;
}