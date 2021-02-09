#include <iostream>
using namespace std;

/*
  ���� 1.
  N���� �ڿ��� �߿��� 3�� ����̰ų� 5�� ����� ����
  ��� ���� ���� ��ȯ.
  N < 100,000
*/
int func1(int N) 
{
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    return sum;
}

/*
  ���� 2.
  �־��� ���� N�� int�迭���� ���� 100�� ���δٸ� ��ġ�� �� ���Ұ� �����ϸ�
  1��, �������� ������ 0�� ��ȯ�ϴ� �Լ� func2(int arr[], int N)�� �ۼ��϶�.
  arr�� �� ���� 0�̻� 100�����̰�,
  N�� 1000�����̴�.
*/
int func2(int arr[], int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] + arr[j] == 100) return 1;
        }
    }
    return 0;
}

/*
  ���� 3.
  N�� �������̸� 1�� ��ȯ�ϰ�, �������� �ƴϸ� 0�� ��ȯ�ϴ� �Լ�
  func3(int N)�� �ۼ��϶�.
  N�� 10�� ���� �ڿ����̴�.
*/
int func3(int N)
{
    for (int i = 1; i * i <= N; i++)
        if (i * i == N) return 1;
    return 0;
}

/*
  ���� 4.
  N������ �� �߿��� ���� ū 2�� �ŵ��������� ��ȯ�ϴ� �Լ�
  func4(int N)�� �ۼ��϶�.
  N�� 10������ �ڿ����̴�.
*/
int func4(int N)
{
    int val = 1;
    
    while(val * 2 <= N)
        val *= 2;
    
    return val;
    //�ð� ���⵵ --> O(log n)
}

int main() 
{
    int arr[] = { 1, 52, 48 };

    cout << func1(16) << "\n";
    cout << func2(arr, 3) << "\n";
    cout << func3(756580036) << "\n";
    cout << func4(17) << "\n";
    
    return 0;
}