/*
 #. ����
  ���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, �� �ܾ�� ���� ���� ���� ���ĺ��� �������� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�. ��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.

 #. �Է�
  ù° �ٿ� ���ĺ� ��ҹ��ڷ� �̷���� �ܾ �־�����. �־����� �ܾ��� ���̴� 1,000,000�� ���� �ʴ´�.

 #. ���
  ù° �ٿ� �� �ܾ�� ���� ���� ���� ���ĺ��� �빮�ڷ� ����Ѵ�. ��, ���� ���� ���� ���ĺ��� ���� �� �����ϴ� ��쿡�� ?�� ����Ѵ�.

 #. ���� �Է� 1   Mississipi
 #. ���� ��� 1   ?

 #. ���� �Է� 2   zZa
 #. ���� ��� 2   Z

 #. ���� �Է� 3   z
 #. ���� ��� 3   Z

 #. ���� �Է� 4   baaa
 #. ���� ��� 4   A
*/

#include <iostream>
#include <string>

const int SIZE = 26;

int main()
{
    //1. ���ܾ� �Է� �ޱ�
    std::string input_word;
    std::getline(std::cin, input_word);

    //2. c_str�� ��ȯ�ϱ�
    int length = input_word.length();
    //char* c_word = new char[length + 1];
    const char* c_word = input_word.c_str();

    //3. ���ĺ� �迭 ����
    int alphabet_arr[SIZE];
    std::fill_n(alphabet_arr, SIZE, 0);
    char alphabet = 'A';
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (alphabet == c_word[j] || alphabet == c_word[j] - 32)
                alphabet_arr[i]++;
        }
        alphabet++;
    }

    //4. �ִ� ���ĺ� ã��
    int max = alphabet_arr[0];
    char result = 'A';
    for (int i = 1; i < SIZE; i++)
    {
        if (max < alphabet_arr[i])
        {
            max = alphabet_arr[i];
            result = (char)(i + 65);
        }
        else if (max == alphabet_arr[i])
        {
            max = alphabet_arr[i];
            result = '?';
        }
    }

    //5. ��� ���
    std::cout << result << "\n";

    //delete[] c_word;

    return 0;
}