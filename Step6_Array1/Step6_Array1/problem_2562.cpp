/*
  #. �ִ�

  #. ����
     9���� ���� �ٸ� �ڿ����� �־��� ��, �̵� �� �ִ��� ã�� �� �ִ��� �� ��° �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
     ���� ���, ���� �ٸ� 9���� �ڿ���
     3, 29, 38, 12, 57, 74, 40, 85, 61
     �� �־�����, �̵� �� �ִ��� 85�̰�, �� ���� 8��° ���̴�.

  #. �Է�
     ù ° �ٺ��� ��ȩ ��° �ٱ��� �� �ٿ� �ϳ��� �ڿ����� �־�����. �־����� �ڿ����� 100 ���� �۴�.

  #. ���
     ù° �ٿ� �ִ��� ����ϰ�, ��° �ٿ� �ִ��� �� ��° �������� ����Ѵ�.

  #. ���� �Է� 1 :: 3
                   29
                   38
                   12
                   57
                   74
                   40
                   85
                   61
    ���� ��� 1 ::  85
                   8
*/

#include <iostream>

int findMax(int* arr, int size);
int findMaxPosition(int* arr, int size, int max);

int main()
{
    //1. size�� 9�� �迭 ���� �� �ʱ�ȭ.
    int arr[9] = { 0 };
    for (int i = 0; i < 9; i++)
    {
        std::cin >> arr[i];
    }

    //2. �ִ� ã��
    int max = findMax(arr, 9);

    //3. max�� �ִ� indexã��
    int index = findMaxPosition(arr, 9, max);

    //4. ����� ���
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