/*
 #. ũ�ξ�Ƽ�� ���ĺ�
 #. ����
    �������� �ü������ ũ�ξ�Ƽ�� ���ĺ��� �Է��� ���� ������. ����, ������ ���� ũ�ξ�Ƽ�� ���ĺ��� �����ؼ� �Է��ߴ�.

 #. ũ�ξ�Ƽ�� ���ĺ�	����
   c=  c-  dz=  d-  lj  nj  s=  z=

   ���� ���, ljes=njak�� ũ�ξ�Ƽ�� ���ĺ� 6���� �̷���� �ִ�.
   �ܾ �־����� ��, �� ���� ũ�ξ�Ƽ�� ���ĺ����� �̷���� �ִ��� ����Ѵ�.


   lj�� nj�� ���������̴�. �� ��Ͽ� ���� ���ĺ��� �� ���ھ� ����.

 #. �Է�
   ù° �ٿ� �ִ� 100������ �ܾ �־�����. ���ĺ� �ҹ��ڿ� '-', '='�θ� �̷���� �ִ�.
   �ܾ�� ũ�ξ�Ƽ�� ���ĺ����� �̷���� �ִ�. ���� ������ ǥ�� �����ִ� ���ĺ��� ����� ���·� �Էµȴ�.

 #. ���
   �Է����� �־��� �ܾ �� ���� ũ�ξ�Ƽ�� ���ĺ����� �̷���� �ִ��� ����Ѵ�.

 #. ���� �Է� 1  :: ljes=njak
    ���� ��� 1  :: 6

 #. ���� �Է� 2  :: ddz=z=
    ���� ��� 2  :: 3

 #. ���� �Է� 3  :: nljj
    ���� ��� 3  :: 3

 #. ���� �Է� 4  :: c=c=
    ���� ��� 4  :: 2
*/

#include <iostream>
#include <string>

void initMarking(int*& mark, int length)
{
    for (int i = 0; i < length; i++)
        mark[i] = 0;
}

void printMarking(int*& mark, int length)
{
    for (int i = 0; i < length; i++)
        std::cout << mark[i] << " ";
    std::cout << "\n";
}

int countCroaticAlphabet(std::string croatic_word[], std::string input_word, int*& mark)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        int start_index = 0;
        int pos = 0;
        while ((start_index = input_word.find(croatic_word[i], pos)) != std::string::npos)
        {
            if (mark[start_index] == 0)
            {
                for (int j = start_index; j < start_index + croatic_word[i].length(); j++)
                    mark[j] = 1;

                count++;
            }

            pos = start_index + croatic_word[i].length() - 1;
        }
    }
    return count;
}

int countNormalAlphabet(int*& mark, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (mark[i] == 0)
            count++;
    }
    return count;
}

int main()
{

    //1. ũ�ξ�Ƽ�� �ܾ� �迭 ����
    std::string croatic_word[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };


    //2. ũ�ξ�Ƽ�� �ܾ� �Է� �ޱ�
    std::string input_word;
    std::getline(std::cin, input_word);


    //3. �Է��� �ܾ� ���� ��ŭ�� marking�迭 ���� �Ҵ�(�� ���� ����)
    int length = input_word.length();
    int* mark = new int[length];


    //4. mark�迭 0���� ��� �ʱ�ȭ.
    initMarking(mark, length);
    //printMarking(mark, length);


    //5. ũ�ξ�Ƽ�� ���ĺ� count
    int croatic_count = countCroaticAlphabet(croatic_word, input_word, mark);
    //std::cout << croatic_count << "\n"
    printMarking(mark, length);


    //6. �Ϲ� ���ĺ� ī��Ʈ
    int normal_count = countNormalAlphabet(mark, length);
    //std::cout << normal_count << "\n";


    //7. ����� ���
    std::cout << normal_count + croatic_count << "\n";

    return 0;
}