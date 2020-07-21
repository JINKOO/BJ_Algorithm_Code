/*
  #. �ܾ��� ����

  #. ����
     ���� ��ҹ��ڿ� ���⸸���� �̷���� ���ڿ��� �־�����.
     �� ���ڿ����� �� ���� �ܾ ������? �̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
     ��, �� �ܾ ���� �� �����ϸ� ������ Ƚ����ŭ ��� ����� �Ѵ�.

  #. �Է�
     ù �ٿ� ���� ��ҹ��ڿ� ����� �̷���� ���ڿ��� �־�����.
     �� ���ڿ��� ���̴� 1,000,000�� ���� �ʴ´�. �ܾ�� ���� �� ���� ���еǸ�,
     ������ �����ؼ� ������ ���� ����. ���� ���ڿ��� �հ� �ڿ��� ������ ���� ���� �ִ�.

  #. ���
     ù° �ٿ� �ܾ��� ������ ����Ѵ�.

  #. ���� �Է� 1 :: The Curious Case of Benjamin Button
     ���� ��� 1 :: 6

  #. ���� �Է� 2 :: Mazatneunde Wae Teullyeoyo
     ���� ��� 2 :: 3

  #. ���� �Է� 3 :: Teullinika Teullyeotzi
     ���� ��� 3 :: 2
*/

#include <iostream>
#include <string>

int main()
{

    //1. ���� �Է� �ޱ�
    std::string input;
    std::getline(std::cin, input);

    //2. ������ ���� ���ϱ�
    int length = input.length();

    //3. ���� ã�� �غ�. pos = �˻��� ��ġ, start_index = ���� ��ġ, word_count = �ܾ��� ���� 
    int pos = 0;
    int start_index = 0;
    int word_count = 1;

    //4. find()�� ����Ѵ�.
    while ((start_index = (int)input.find(" ", pos)) != -1)
    {
        //4.1 �Է� ���� ���� �ϳ��� ��
        if (start_index == 0 && length == 1)
            word_count = 0;

        //4.2 �������� �����ϴ� ����
        if (start_index == 0 || start_index == (length - 1))
        {
            input.erase(start_index, 1);
            length = input.length();
            continue;
        }

        word_count++;
        pos = start_index + 1;
    }

    std::cout << word_count << "\n";

    /*
    //���۸��� �ڵ�.
    bool space = true;
    int word_count = 0;
    for (int i = 0; i < length; i++)
    {
        if (input[i] == ' ')
            space = true;
        else if (space)
        {
            space = false;
            word_count++;
        }
    }
    */

    return 0;
}