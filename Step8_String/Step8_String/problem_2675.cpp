/*
  #. 문제
   문자열 S를 입력받은 후에, 각 문자를 R번 반복해 새 문자열 P를 만든 후 출력하는 프로그램을 작성하시오.
   즉, 첫 번째 문자를 R번 반복하고, 두 번째 문자를 R번 반복하는 식으로 P를 만들면 된다. S에는 QR Code "alphanumeric" 문자만 들어있다.

   QR Code "alphanumeric" 문자는 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: 이다.

  #. 입력
   첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다.
   각 테스트 케이스는 반복 횟수 R(1 ≤ R ≤ 8), 문자열 S가 공백으로 구분되어 주어진다. S의 길이는 적어도 1이며, 20글자를 넘지 않는다.

  #. 출력
   각 테스트 케이스에 대해 P를 출력한다.

  #. 예제 입력 1
     2
     3 ABC
     5 /HTP

  #. 예제 출력 1
     AAABBBCCC
     /////HHHHHTTTTTPPPPP
*/

#include <iostream>
#include <string>

int main()
{
    //1. test_case입력 받기
    int test_case = 0;
    std::cin >> test_case;

    //2. 결과값을 저장하기 위한 더블 포인터 변수 정의
    char** result = new char* [test_case];

    //3. test_case만큼 반복 후, data 처리하도록 한다. 
    for (int i = 0; i < test_case; i++)
    {
        //3.1 반복 횟수 입력받기.
        int repeate = 0;
        std::cin >> repeate;

        //3.2 단어 입력 받기
        std::string word;
        std::cin >> word;

        //3.3 cpp문자열 -> c문자열변환
        int length = word.length();
        const char* c_word = new char[length + 1];
        c_word = word.c_str();

        //3.4 result[i] 동적 할당.
        result[i] = new char[repeate * length + 1];

        //3.5 result[i][j]에 늘어난 단어 설정.
        for (int j = 0; j < repeate * length; j++)
            result[i][j] = c_word[j / repeate];

        result[i][repeate * length] = '\0';
    }

    //4. 값 출력
    for (int i = 0; i < test_case; i++)
        std::cout << result[i] << "\n";

    delete[] result;
    result = NULL;

    return 0;
}