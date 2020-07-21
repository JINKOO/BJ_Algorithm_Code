/*
  #. [2751_수 정렬하기]
  
  #. 문제
     N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
     
  #. 입력
     첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 
     이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

  #. 출력
     첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

  #. 예제 입력 1 
     5
     5 2 3 4 1
  #. 예제 출력 1 
     1
     2
     3
     4
     5
*/

/*
   #. 접근법
      - N이 1,000,000까지 이다. 이때, 삽입, 선택, 버블사용 불가 비효율적이다.
      - algorithm라이브러리에 있는 sort를 사용하도록 한다. 퀵 소트도 시간초과 난다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
}

void print()
{
    for (int i : v)
        cout << i << "\n";
}

int main()
{
    int N;
    cin >> N;

    init(N);
    sort(v.begin(), v.end());
    print();

    return 0;
}