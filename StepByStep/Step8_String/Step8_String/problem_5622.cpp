/*

 #. 문제
  상근이의 할머니는 아래 그림과 같이 오래된 다이얼 전화기를 사용한다.
  전화를 걸고 싶은 번호가 있다면, 숫자를 하나를 누른 다음에 금속 핀이 있는 곳 까지 시계방향으로 돌려야 한다.
  숫자를 하나 누르면 다이얼이 처음 위치로 돌아가고, 다음 숫자를 누르려면 다이얼을 처음 위치에서 다시 돌려야 한다.

  숫자 1을 걸려면 총 2초가 필요하다.
  1보다 큰 수를 거는데 걸리는 시간은 이보다 더 걸리며, 한 칸 옆에 있는 숫자를 걸기 위해선 1초씩 더 걸린다.

  상근이의 할머니는 전화 번호를 각 숫자에 해당하는 문자로 외운다.
  즉, 어떤 단어를 걸 때, 각 알파벳에 해당하는 숫자를 걸면 된다.
  예를 들어, UNUCIC는 868242와 같다.

  할머니가 외운 단어가 주어졌을 때, 이 전화를 걸기 위해서 필요한 시간을 구하는 프로그램을 작성하시오.

 #. 입력
  첫째 줄에 알파벳 대문자로 이루어진 단어가 주어진다. 단어는 2글자~15글자로 이루어져 있다.

 #. 출력
  첫째 줄에 다이얼을 걸기 위해서 필요한 시간을 출력한다.

 #. 예제 입력 1 :: UNUCIC
 #. 예제 출력 1 :: 36

*/

#include <iostream>
#include <string>

int main()
{
    //1. dial에 대한 정보 입력
    std::string dial_data[10] = { "1", "2ABC", "3DEF", "4GHI", "5JKL", "6MNO", "7PQRS", "8TUV", "9WXYZ", "0" };


    //2. 각 dial 버튼별 소요시간 초기화.
    int dial_sec[10];
    for (int i = 0; i < 10; i++)
        dial_sec[i] = i + 2;


    //3. 대문자로 이루어진 영단어 입력
    std::string input_word;
    std::getline(std::cin, input_word);

    //3. c_str로 변환
    int length = input_word.length();
    const char* c_word = input_word.c_str();

    //4. 소요시간 계산
    int total_time = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (dial_data[j].find(c_word[i]) != std::string::npos)
                total_time = total_time + dial_sec[j];
        }
    }

    std::cout << total_time << "\n";

    return 0;
}