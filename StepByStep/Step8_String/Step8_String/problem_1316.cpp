/*
 #. 그룹 단어 체커

 #. 문제
  그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다.
  예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만,
  aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.

 #. 단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.

 #. 입력
  첫째 줄에 단어의 개수 N이 들어온다. N은 100보다 작거나 같은 자연수이다.
  둘째 줄부터 N개의 줄에 단어가 들어온다. 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.

 #. 출력
  첫째 줄에 그룹 단어의 개수를 출력한다.

 #. 예제 입력 1 :: 3
                  happy
                  new
                  year

 #. 예제 출력 1 :: 3

 #. 예제 입력 2 :: 4
                  aba
                  abab
                  abcabc
                  a
 #. 예제 출력 2 :: 1
*/

#include <iostream>
#include <string>

int main()
{
    //1.  입력 받을 단어 개수 입력
    int num = 0;
    std::cin >> num;

    //2.  num만큼 단어 입력
    //2.1 입력 받을 때 마다 검사한다. 
    int group_word = 0;
    for (int i = 0; i < num; i++)
    {
        std::string input_word;
        std::cin >> input_word;

        //입력 받은 단어의 길이 data저장
        int length = input_word.length();
        const char* c_word = input_word.c_str();

        //한번 검사했던 index인지 구분.
        int* mark = new int[length];
        for (int m = 0; m < length; m++)
            mark[m] = 0;

        int result = 0;

        //i번째 입력 받은 단어에 대하여...
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