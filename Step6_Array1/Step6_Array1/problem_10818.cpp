/*
  #. 최소, 최대

  #. 문제
     N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.

  #. 입력
     첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다.
     둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다.
     모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.

  #. 출력
     첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.

  #. 예제 입력 1 :: 5
                   20 10 35 30 7
     예제 출력 1 :: 7 35
*/

#include <iostream>

void initArray(int*& arr, int& size);
int findMin(int* arr, int& size);
int findMax(int* arr, int& size);

int main()
{
    //1. 배열 크기 입력 받기
    int size = 0;
    std::cin >> size;

    //2. 입력한 크기 만큼의 동적 할당 받기.
    int* arr = new int[size];
    initArray(arr, size);

    //2.1 test출력
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    //3. 결과 출력
    std::cout << findMin(arr, size) << " " << findMax(arr, size) << "\n";

    //4. 메모리 해제
    delete[] arr;
    arr = NULL;

    return 0;
}

void initArray(int*& arr, int& size)
{
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
}

int findMin(int* arr, int& size)
{
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (min >= arr[i])
            min = arr[i];
    }
    return min;
}

int findMax(int* arr, int& size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max <= arr[i])
            max = arr[i];
    }
    return max;
}