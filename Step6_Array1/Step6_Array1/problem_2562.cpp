/*
  #. 최댓값

  #. 문제
     9개의 서로 다른 자연수가 주어질 때, 이들 중 최댓값을 찾고 그 최댓값이 몇 번째 수인지를 구하는 프로그램을 작성하시오.
     예를 들어, 서로 다른 9개의 자연수
     3, 29, 38, 12, 57, 74, 40, 85, 61
     이 주어지면, 이들 중 최댓값은 85이고, 이 값은 8번째 수이다.

  #. 입력
     첫 째 줄부터 아홉 번째 줄까지 한 줄에 하나의 자연수가 주어진다. 주어지는 자연수는 100 보다 작다.

  #. 출력
     첫째 줄에 최댓값을 출력하고, 둘째 줄에 최댓값이 몇 번째 수인지를 출력한다.

  #. 예제 입력 1 :: 3
                   29
                   38
                   12
                   57
                   74
                   40
                   85
                   61
    예제 출력 1 ::  85
                   8
*/

#include <iostream>

int findMax(int* arr, int size);
int findMaxPosition(int* arr, int size, int max);

int main()
{
    //1. size가 9인 배열 선언 및 초기화.
    int arr[9] = { 0 };
    for (int i = 0; i < 9; i++)
    {
        std::cin >> arr[i];
    }

    //2. 최댓값 찾기
    int max = findMax(arr, 9);

    //3. max가 있는 index찾기
    int index = findMaxPosition(arr, 9, max);

    //4. 결과값 출력
    std::cout << max << "\n";
    std::cout << index << "\n";

    return 0;
}

int findMax(int* arr, int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max <= arr[i])
            max = arr[i];
    }
    return max;
}

int findMaxPosition(int* arr, int size, int max)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == max)
            break;
    }
    return i + 1;
}