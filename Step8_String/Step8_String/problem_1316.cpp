/*
 #. �׷� �ܾ� üĿ

 #. ����
  �׷� �ܾ�� �ܾ �����ϴ� ��� ���ڿ� ���ؼ�, �� ���ڰ� �����ؼ� ��Ÿ���� ��츸�� ���Ѵ�.
  ���� ���, ccazzzzbb�� c, a, z, b�� ��� �����ؼ� ��Ÿ����, kin�� k, i, n�� �����ؼ� ��Ÿ���� ������ �׷� �ܾ�������,
  aabbbccb�� b�� �������� ��Ÿ���� ������ �׷� �ܾ �ƴϴ�.

 #. �ܾ� N���� �Է����� �޾� �׷� �ܾ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

 #. �Է�
  ù° �ٿ� �ܾ��� ���� N�� ���´�. N�� 100���� �۰ų� ���� �ڿ����̴�.
  ��° �ٺ��� N���� �ٿ� �ܾ ���´�. �ܾ�� ���ĺ� �ҹ��ڷθ� �Ǿ��ְ� �ߺ����� ������, ���̴� �ִ� 100�̴�.

 #. ���
  ù° �ٿ� �׷� �ܾ��� ������ ����Ѵ�.

 #. ���� �Է� 1 :: 3
                  happy
                  new
                  year

 #. ���� ��� 1 :: 3

 #. ���� �Է� 2 :: 4
                  aba
                  abab
                  abcabc
                  a
 #. ���� ��� 2 :: 1
*/

#include <iostream>
#include <string>

int main()
{
    //1.  �Է� ���� �ܾ� ���� �Է�
    int num = 0;
    std::cin >> num;

    //2.  num��ŭ �ܾ� �Է�
    //2.1 �Է� ���� �� ���� �˻��Ѵ�. 
    int group_word = 0;
    for (int i = 0; i < num; i++)
    {
        std::string input_word;
        std::cin >> input_word;

        //�Է� ���� �ܾ��� ���� data����
        int length = input_word.length();
        const char* c_word = input_word.c_str();

        //�ѹ� �˻��ߴ� index���� ����.
        int* mark = new int[length];
        for (int m = 0; m < length; m++)
            mark[m] = 0;

        int result = 0;

        //i��° �Է� ���� �ܾ ���Ͽ�...
        int start_index = 0;
        int end_index = 0;
        for (int j = 0; j < length; j++)
        {
            int count = 1;
            if (mark[j] == 0)
            {
                std::cout << j << ", " << c_word[j] << "\n";
                start_index = j;
                for (int k = j + 1; k < length; k++)
                {
                    if (c_word[j] == c_word[k])
                    {
                        mark[k] = 1;
                        end_index = k;
                        count++;
                    }
                }
                std::cout << "count :: " << count << "\n";
                std::cout << "start :: " << start_index << ", end :: " << end_index << "\n";
            }

            if (count == (end_index - start_index + 1) || count == 1)
                result++;
        }

        if (result == length)
            group_word++;

        std::cout << "\n";
    }

    std::cout << group_word << "\n";

    return 0;
}