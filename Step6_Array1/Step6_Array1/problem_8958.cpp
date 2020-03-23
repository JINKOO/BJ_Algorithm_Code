/*
  #. OX퀴즈

  #. 문제
     "OOXXOXXOOO"와 같은 OX퀴즈의 결과가 있다. O는 문제를 맞은 것이고, X는 문제를 틀린 것이다.
     문제를 맞은 경우 그 문제의 점수는 그 문제까지 연속된 O의 개수가 된다. 예를 들어, 10번 문제의 점수는 3이 된다.
     "OOXXOXXOOO"의 점수는 1+2+0+0+1+0+0+1+2+3 = 10점이다.
     OX퀴즈의 결과가 주어졌을 때, 점수를 구하는 프로그램을 작성하시오.

  #. 입력
     첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고,
     길이가 0보다 크고 80보다 작은 문자열이 주어진다. 문자열은 O와 X만으로 이루어져 있다.

  #. 출력
     각 테스트 케이스마다 점수를 출력한다.

  #. 예제 입력 1 :: 5
                   OOXXOXXOOO
                   OOXXOOXXOO
                   OXOXOXOXOXOXOX
                   OOOOOOOOOO
                   OOOOXOOOOXOOOOX
    예제 출력 1 ::  10
                   9
                   7
                   55
                   30
*/

#include <iostream>
#include <string>

int main()
{
    //1. test_case입력 받기
    int test_case = 0;
    std::cin >> test_case;

    //2. 각 OX문자열의 결과값 저장하는 배열.
    int* result = new int[test_case];

    //3. test_case OX문제 입력
    for (int i = 0; i < test_case; i++)
    {
        //3.1 OX문제 입력
        std::string input_OX;
        std::cin >> input_OX;

        //3.2 입력 받은 문자열 길이 구하고, c_str로 변환 
        int length = input_OX.length();
        const char* str_OX = input_OX.c_str();

        //3.3 sub_score : 'O'의 점수 계산
        //    total_score : 하나의 OX문제에서 점수 합산.
        int sub_score = 0, total_score = 0;
        for (int j = 0; j < length; j++)
        {
            str_OX[j] == 'X' ? (sub_score = 0) : (sub_score = sub_score + 1);
            total_score = total_score + sub_score;
        }

        //3.4 각 OX문제에서의 합산 점수 저장.
        result[i] = total_score;
    }

    //4. 결과 출력
    for (int i = 0; i < test_case; i++)
        std::cout << result[i] << "\n";

    return 0;
}