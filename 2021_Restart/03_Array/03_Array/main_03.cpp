/*
  배열에서 배열 전체를 특정 값으로 초기화하는 팁.
  1. memset은 비추천
     --> 0, -1이 아닌 다은 값을 넣으면 오동작, 2차원 이상의 배열을 함수 parameter로 넘기고 그곳에서 memset하면 잘못된 경우 발생.
  2. for문을 통한 일일이 바꾸는 방식
  3. algorithm헤더 파일의 fill함수를 사용한다.

  3번을 사용하자
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[21];
    int b[21][21];

    // 1. memset
    memset(a, 0, sizeof a);
    memset(b, -1, sizeof b);

    // 2. for문 사용
    for (int i = 0; i < 21; i++)
        a[i] = 0;
    
    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 21; j++)
            b[i][j] = -1;

    //3. fill함수 사용
    fill(a, a + 21, 0);
    for (int i = 0; i < 21; i++)
        fill(b[i], b[i] + 21, -1);

    return 0;
}

