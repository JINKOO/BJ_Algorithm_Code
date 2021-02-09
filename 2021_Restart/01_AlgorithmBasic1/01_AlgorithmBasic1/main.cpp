#include <iostream>
using namespace std;

/*
  문제 1.
  N이하 자연수 중에서 3의 배수이거나 5의 배수인 수를
  모두 합한 값을 반환.
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
  문제 2.
  주어진 길이 N의 int배열에서 합이 100인 서로다른 위치의 두 원소가 존재하면
  1을, 존재하지 않으면 0을 반환하는 함수 func2(int arr[], int N)을 작성하라.
  arr의 각 수는 0이상 100이하이고,
  N은 1000이하이다.
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
  문제 3.
  N이 제곱수이면 1을 반환하고, 제곱수가 아니면 0을 반환하는 함수
  func3(int N)을 작성하라.
  N은 10억 이하 자연수이다.
*/
int func3(int N)
{
    for (int i = 1; i * i <= N; i++)
        if (i * i == N) return 1;
    return 0;
}

/*
  문제 4.
  N이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 함수
  func4(int N)을 작성하라.
  N은 10억이하 자연수이다.
*/
int func4(int N)
{
    int val = 1;
    
    while(val * 2 <= N)
        val *= 2;
    
    return val;
    //시간 복잡도 --> O(log n)
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