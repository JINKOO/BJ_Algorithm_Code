/*
  #. �ּ�, �ִ�

  #. ����
     N���� ������ �־�����. �̶�, �ּڰ��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

  #. �Է�
     ù° �ٿ� ������ ���� N (1 �� N �� 1,000,000)�� �־�����.
     ��° �ٿ��� N���� ������ �������� �����ؼ� �־�����.
     ��� ������ -1,000,000���� ũ�ų� ����, 1,000,000���� �۰ų� ���� �����̴�.

  #. ���
     ù° �ٿ� �־��� ���� N���� �ּڰ��� �ִ��� �������� ������ ����Ѵ�.

  #. ���� �Է� 1 :: 5
                   20 10 35 30 7
     ���� ��� 1 :: 7 35
*/

#include <iostream>

void initArray(int*& arr, int& size);
int findMin(int* arr, int& size);
int findMax(int* arr, int& size);

int main()
{
    //1. �迭 ũ�� �Է� �ޱ�
    int size = 0;
    std::cin >> size;

    //2. �Է��� ũ�� ��ŭ�� ���� �Ҵ� �ޱ�.
    int* arr = new int[size];
    initArray(arr, size);

    //2.1 test���
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    //3. ��� ���
    std::cout << findMin(arr, size) << " " << findMax(arr, size) << "\n";

    //4. �޸� ����
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