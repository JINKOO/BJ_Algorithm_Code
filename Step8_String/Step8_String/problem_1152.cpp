/*
  #. 단어의 개수

  #. 문제
     영어 대소문자와 띄어쓰기만으로 이루어진 문자열이 주어진다.
     이 문자열에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오.
     단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.

  #. 입력
     첫 줄에 영어 대소문자와 띄어쓰기로 이루어진 문자열이 주어진다.
     이 문자열의 길이는 1,000,000을 넘지 않는다. 단어는 띄어쓰기 한 개로 구분되며,
     공백이 연속해서 나오는 경우는 없다. 또한 문자열의 앞과 뒤에는 공백이 있을 수도 있다.

  #. 출력
     첫째 줄에 단어의 개수를 출력한다.

  #. 예제 입력 1 :: The Curious Case of Benjamin Button
     예제 출력 1 :: 6

  #. 예제 입력 2 :: Mazatneunde Wae Teullyeoyo
     예제 출력 2 :: 3

  #. 예제 입력 3 :: Teullinika Teullyeotzi
     예제 출력 3 :: 2
*/

#include <iostream>
#include <string>

int main()
{

    //1. 문장 입력 받기
    std::string input;
    std::getline(std::cin, input);

    //2. 문장의 길이 구하기
    int length = input.length();

    //3. 공백 찾을 준비. pos = 검사할 위치, start_index = 공백 위치, word_count = 단어의 개수 
    int pos = 0;
    int start_index = 0;
    int word_count = 1;

    //4. find()를 사용한다.
    while ((start_index = (int)input.find(" ", pos)) != -1)
    {
        //4.1 입력 값이 공백 하나일 때
        if (start_index == 0 && length == 1)
            word_count = 0;

        //4.2 공백으로 시작하는 문장
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
    //구글링한 코드.
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