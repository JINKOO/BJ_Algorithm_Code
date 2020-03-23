/*
 #. 문제
  상근이의 동생 상수는 수학을 정말 못한다. 상수는 숫자를 읽는데 문제가 있다.
  이렇게 수학을 못하는 상수를 위해서 상근이는 수의 크기를 비교하는 문제를 내주었다.
  상근이는 세 자리 수 두 개를 칠판에 써주었다. 그 다음에 크기가 큰 수를 말해보라고 했다.

 #. 상수는 수를 다른 사람과 다르게 거꾸로 읽는다.
   예를 들어, 734와 893을 칠판에 적었다면, 상수는 이 수를 437과 398로 읽는다.
   따라서, 상수는 두 수중 큰 수인 437을 큰 수라고 말할 것이다.

 #. 두 수가 주어졌을 때, 상수의 대답을 출력하는 프로그램을 작성하시오.

 #. 입력
  첫째 줄에 상근이가 칠판에 적은 두 수 A와 B가 주어진다.
  두 수는 같지 않은 세 자리 수이며, 0이 포함되어 있지 않다.

 #. 출력
  첫째 줄에 상수의 대답을 출력한다.

 #. 예제 입력 1 :: 734 893
 #. 예제 출력 1 :: 437
*/

#include <iostream>
#include <string>

int getLength(std::string str);
char* reverse(char* c_num, int size);
int findMax(int num1, int num2);

int main()
{
    //1. 두개의 수 입력 받기
    std::string num1, num2;
    std::cin >> num1 >> num2;

    //2. c_str로 변환
    char* c_num1 = new char[getLength(num1)];
    char* c_num2 = new char[getLength(num2)];
    strcpy_s(c_num1, getLength(num1), num1.c_str());
    strcpy_s(c_num2, getLength(num2), num2.c_str());


    char* reverse_num1 = reverse(c_num1, getLength(num1));
    char* reverse_num2 = reverse(c_num2, getLength(num2));


    //3. 큰 값 출력
    std::cout << findMax(atoi(reverse_num1), atoi(reverse_num2)) << "\n";

    delete[] c_num1;
    delete[] c_num2;

    return 0;
}

int getLength(std::string str)
{
    return str.length() + 1;
}

char* reverse(char* c_num, int size)
{
    char* reverse_num = new char[size];
    for (int i = 0; i < size - 1; i++)
    {
        reverse_num[i] = c_num[size - 2 - i];
    }
    reverse_num[size - 1] = c_num[size - 1];

    return reverse_num;
}

int findMax(int num1, int num2)
{
    if (num1 <= num2)
        return num2;
    else
        return num1;
}