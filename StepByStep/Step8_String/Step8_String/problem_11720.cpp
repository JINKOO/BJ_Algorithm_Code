/*
 문제
 N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.

 입력
 첫째 줄에 숫자의 개수 N (1 ≤ N ≤ 100)이 주어진다.
 둘째 줄에 숫자 N개가 공백없이 주어진다.

 출력
 입력으로 주어진 숫자 N개의 합을 출력한다.
*/

#include <iostream>

int main()
{

    int number = 0;
    std::cin >> number;

    int sum = 0;
    char* num_str = new char[number + 1];

    for (int i = 0; i < number; i++)
        std::cin >> num_str[i];

    num_str[number] = '\0';

    for (int i = 0; i < number; i++)
    {
        int num = num_str[i] - 48;
        sum = sum + num;
    }

    std::cout << sum << "\n";

    delete[] num_str;
    num_str = NULL;

    return 0;
}