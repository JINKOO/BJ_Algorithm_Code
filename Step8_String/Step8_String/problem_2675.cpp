/*
  #. ����
   ���ڿ� S�� �Է¹��� �Ŀ�, �� ���ڸ� R�� �ݺ��� �� ���ڿ� P�� ���� �� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
   ��, ù ��° ���ڸ� R�� �ݺ��ϰ�, �� ��° ���ڸ� R�� �ݺ��ϴ� ������ P�� ����� �ȴ�. S���� QR Code "alphanumeric" ���ڸ� ����ִ�.

   QR Code "alphanumeric" ���ڴ� 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: �̴�.

  #. �Է�
   ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1 �� T �� 1,000)�� �־�����.
   �� �׽�Ʈ ���̽��� �ݺ� Ƚ�� R(1 �� R �� 8), ���ڿ� S�� �������� ���еǾ� �־�����. S�� ���̴� ��� 1�̸�, 20���ڸ� ���� �ʴ´�.

  #. ���
   �� �׽�Ʈ ���̽��� ���� P�� ����Ѵ�.

  #. ���� �Է� 1
     2
     3 ABC
     5 /HTP

  #. ���� ��� 1
     AAABBBCCC
     /////HHHHHTTTTTPPPPP
*/

#include <iostream>
#include <string>

int main()
{
    //1. test_case�Է� �ޱ�
    int test_case = 0;
    std::cin >> test_case;

    //2. ������� �����ϱ� ���� ���� ������ ���� ����
    char** result = new char* [test_case];

    //3. test_case��ŭ �ݺ� ��, data ó���ϵ��� �Ѵ�. 
    for (int i = 0; i < test_case; i++)
    {
        //3.1 �ݺ� Ƚ�� �Է¹ޱ�.
        int repeate = 0;
        std::cin >> repeate;

        //3.2 �ܾ� �Է� �ޱ�
        std::string word;
        std::cin >> word;

        //3.3 cpp���ڿ� -> c���ڿ���ȯ
        int length = word.length();
        const char* c_word = new char[length + 1];
        c_word = word.c_str();

        //3.4 result[i] ���� �Ҵ�.
        result[i] = new char[repeate * length + 1];

        //3.5 result[i][j]�� �þ �ܾ� ����.
        for (int j = 0; j < repeate * length; j++)
            result[i][j] = c_word[j / repeate];

        result[i][repeate * length] = '\0';
    }

    //4. �� ���
    for (int i = 0; i < test_case; i++)
        std::cout << result[i] << "\n";

    delete[] result;
    result = NULL;

    return 0;
}