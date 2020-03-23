/*
 #. 문제
  알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

 #. 입력
  첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

 #. 출력
  첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.

 #. 예제 입력 1   Mississipi
 #. 예제 출력 1   ?

 #. 예제 입력 2   zZa
 #. 예제 출력 2   Z

 #. 예제 입력 3   z
 #. 예제 출력 3   Z

 #. 예제 입력 4   baaa
 #. 예제 출력 4   A
*/

#include <iostream>
#include <string>

const int SIZE = 26;

int main()
{
    //1. 영단어 입력 받기
    std::string input_word;
    std::getline(std::cin, input_word);

    //2. c_str로 변환하기
    int length = input_word.length();
    //char* c_word = new char[length + 1];
    const char* c_word = input_word.c_str();

    //3. 알파벳 배열 선언
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

    //4. 최다 알파벳 찾기
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

    //5. 결과 출력
    std::cout << result << "\n";

    //delete[] c_word;

    return 0;
}