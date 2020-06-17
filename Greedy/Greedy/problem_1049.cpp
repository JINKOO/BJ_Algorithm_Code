/*
  #. [백준 :: #1049_기타줄 ]

  #. 문제
     Day Of Mourning의 기타리스트 강토가 사용하는 기타에서 N개의 줄이 끊어졌다.
     따라서 새로운 줄을 사거나 교체해야 한다. 강토는 되도록이면 돈을 적게 쓰려고 한다. 
     6줄 패키지를 살 수도 있고, 1개 또는 그 이상의 줄을 낱개로 살 수도 있다.

     끊어진 기타줄의 개수 N과 기타줄 브랜드 M개가 주어지고, 
     각각의 브랜드에서 파는 기타줄 6개가 들어있는 패키지의 가격, 낱개로 살 때의 가격이 주어질 때, 
     적어도 N개를 사기 위해 필요한 돈의 수를 최소로 하는 프로그램을 작성하시오.

  #. 입력
     첫째 줄에 N과 M이 주어진다. N은 100보다 작거나 같은 자연수이고, M은 50보다 작거나 같은 자연수이다. 
     둘째 줄부터 M개의 줄에는 각 브랜드의 패키지 가격과 낱개의 가격이 공백으로 구분하여 주어진다. 
     가격은 0보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

  #. 출력
     첫째 줄에 기타줄을 적어도 N개 사기 위해 필요한 돈의 최솟값을 출력한다.

  #. 예제 입력 1 
     4 2
     12 3
     15 4
  #. 예제 출력 1 
     12
  
  #. 예제 입력 2 
     10 3
     20 8
     40 7
     60 4
  #. 예제 출력 2 
     36
  
  #. 예제 입력 3 
     15 1
     100 40
  #. 예제 출력 3 
     300
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMin(int num1, int num2)
{
    return num1 < num2 ? num1 : num2;
}

int solution(int n, vector<int> package, vector<int> each)
{
    int answer = 0;
    //
    /*
      1. greedy한 접근
         - package로만 구매
         - 낱개로만 구매
         - package + 낱개(서로 다른 브랜드 교차 허용)
       어차피 가격의 최솟값을 구하는 것이므로 
       vector<int> package 
       vector<int> each 
       각각 오름 차순 정렬.
       각 첫번째 요소가 가격의 최솟값이다. 이 후 3개의 조건에서 최솟값을 구한다.
       '서로 다른 브랜드 교차의 허용'이 핵심이니까 굳이 vector<pair<int, int>>로 안해도 됨.
    */
    sort(package.begin(), package.end());
    sort(each.begin(), each.end());

    int group = n / 6 + 1;
    answer = getMin(package[0] * group, each[0] * n);
    answer = getMin(answer, package[0] * (group - 1) + each[0] * (n % 6));
    //
    return answer;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> package, each;

    for (int i = 0; i < M; i++)
    {
        int p1, p2;
        cin >> p1 >> p2;
        package.push_back(p1);
        each.push_back(p2);
    }

    cout << solution(N, package, each) << "\n";

    return 0;
}