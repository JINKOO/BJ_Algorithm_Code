/*
 #. 크로아티아 알파벳
 #. 문제
    예전에는 운영체제에서 크로아티아 알파벳을 입력할 수가 없었다. 따라서, 다음과 같이 크로아티아 알파벳을 변경해서 입력했다.

 #. 크로아티아 알파벳	변경
   c=  c-  dz=  d-  lj  nj  s=  z=

   예를 들어, ljes=njak은 크로아티아 알파벳 6개로 이루어져 있다.
   단어가 주어졌을 때, 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.


   lj와 nj도 마찬가지이다. 위 목록에 없는 알파벳은 한 글자씩 센다.

 #. 입력
   첫째 줄에 최대 100글자의 단어가 주어진다. 알파벳 소문자와 '-', '='로만 이루어져 있다.
   단어는 크로아티아 알파벳으로 이루어져 있다. 문제 설명의 표에 나와있는 알파벳은 변경된 형태로 입력된다.

 #. 출력
   입력으로 주어진 단어가 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.

 #. 예제 입력 1  :: ljes=njak
    예제 출력 1  :: 6

 #. 예제 입력 2  :: ddz=z=
    예제 출력 2  :: 3

 #. 예제 입력 3  :: nljj
    예제 출력 3  :: 3

 #. 예제 입력 4  :: c=c=
    예제 출력 4  :: 2
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

    //1. 크로아티아 단어 배열 설정
    std::string croatic_word[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };


    //2. 크로아티아 단어 입력 받기
    std::string input_word;
    std::getline(std::cin, input_word);


    //3. 입력한 단어 길이 만큼의 marking배열 동적 할당(널 문자 제외)
    int length = input_word.length();
    int* mark = new int[length];


    //4. mark배열 0으로 모두 초기화.
    initMarking(mark, length);
    //printMarking(mark, length);


    //5. 크로아티아 알파벳 count
    int croatic_count = countCroaticAlphabet(croatic_word, input_word, mark);
    //std::cout << croatic_count << "\n"
    printMarking(mark, length);


    //6. 일반 알파벳 카운트
    int normal_count = countNormalAlphabet(mark, length);
    //std::cout << normal_count << "\n";


    //7. 결과값 출력
    std::cout << normal_count + croatic_count << "\n";

    return 0;
}