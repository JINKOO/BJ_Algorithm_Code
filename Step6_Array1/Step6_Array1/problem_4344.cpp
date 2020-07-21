/*
  #. 문제 4344

  #. 평균은 넘겠지

  #. 문제
     대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.

  #. 입력
     첫째 줄에는 테스트 케이스의 개수 C가 주어진다.
     둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고,
     이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

  #. 출력
     각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.

  #. 예제 입력 1 :: 5
                   5 50 50 70 80 100
                   7 100 95 90 80 70 60 50
                   3 70 90 80
                   3 70 90 81
                   9 100 99 98 97 96 95 94 93 91

     예제 출력 1 :: 40.000%
                   57.143%
                   33.333%
                   66.667%
                   55.556%
*/

#include <iostream>
int main()
{
    //1. test_case입력 받기
    int test_case = 0;
    std::cin >> test_case;

    //2. 각 test_case의 결과값을 저장할 float배열 선언
    float* result = new float[test_case];

    //2. test_case만큼 반복하면서 평균 점수, 학생 수, 평균 점수 넘는 학생의 비율 계산.
    for (int i = 0; i < test_case; i++)
    {
        //2.1 학생 수 입력 받기
        int number_of_student = 0;
        std::cin >> number_of_student;

        //2.2 학생 수 만큼의 점수를 입력 받기위한 동적 할당받기
        int* score = new int[number_of_student];

        //2.3
        int total = 0, over_average = 0;
        float average = 0.0f;

        //2.4 i번째 test_case에서 학생들의 점수 입력 받기.
        for (int j = 0; j < number_of_student; j++)
        {
            std::cin >> score[j];
            total = total + score[j];
        }

        //2.5 i번째 test_case에서 평균 점수 계산하기
        average = (float)total / number_of_student;

        //2.6 i번째 test_case에서 평균보다 높은 점수 가지는 학생들의 수 계산
        for (int k = 0; k < number_of_student; k++)
        {
            if (score[k] > average)
                over_average++;
        }

        //2.7 평균 점수 보다 높은 점수의 학생 수 계산.
        result[i] = ((float)over_average / number_of_student) * 100;
    }

    //3. 결과 값 출력
    std::cout << std::fixed;
    std::cout.precision(3);
    for (int i = 0; i < test_case; i++)
        std::cout << result[i] << "%" << "\n";

    return 0;
}