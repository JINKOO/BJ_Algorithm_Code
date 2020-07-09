/*
  #. [ 2108번_통계학 Silver IV ]

  #. 문제
     수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 
     통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.

     산술평균 : N개의 수들의 합을 N으로 나눈 값
     중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
     최빈값 : N개의 수들 중 가장 많이 나타나는 값
     범위 : N개의 수들 중 최댓값과 최솟값의 차이
       
     N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

  #. 입력
     첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 그 다음 N개의 줄에는 정수들이 주어진다. 
     입력되는 정수의 절댓값은 4,000을 넘지 않는다.

  #. 출력
     첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
     둘째 줄에는 중앙값을 출력한다.
     셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
     넷째 줄에는 범위를 출력한다.

  #. 예제 입력 1 
     5
     1 3 8 -2 2
  #. 예제 출력 1 
     2
     2
     1
     10

  #. 예제 입력 2 
     1
     4000
  #. 예제 출력 2 
     4000
     4000
     4000
     0

 #. 예제 입력 3 
    5
    -1 -2 -3 -1 -2
 #. 예제 출력 3 
    -2
    -2
    -1
    2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> v;

bool myCompare(pair<int, int>& p1, pair<int, int>& p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

//소수 첫째 자리 반올림.
double getAverage()
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
        sum += v[i];
    return round((double)sum / v.size());
}

int getMedian()
{
    sort(v.begin(), v.end());
    return v[v.size() / 2];
}

/*
  #. 최빈값 구할 때...
   - 나의 접근 법.
     : vector<pair<int, int>> mode를 사용하고자 했으나, 이중 반복문을 사용하여,
       전역 변수 v에서 일일히 count하여 mode에 삽입하려 함.

   - 정답 풀이
     : mode에 집어 넣을 때, mode의 가장 최근에 넣은 값의 first와 v[i]를 비교한다.
       count변수 필요 없다.
     : 이것이 가능한 이유는, v를 미리 정렬하였기 때문이다.
     ex) v : 1 1 2 2 2 3 3 3
         mode : (1, 2), (2, 3), (3, 4);


*/
int getMode()
{
    //first : v[i] / second : count
    vector<pair<int, int>> mode;
    for (int i = 0; i < v.size(); i++)
    {
        //첫번째는 무조건 삽입.
        if (mode.empty())
            mode.push_back(make_pair(v[i], 1));

        //두번째 부터는 mode의 가장 최근 값과 비교하면서,
        else
        {
            //같은 원소이면, 삽입하지 않고, 맨 마지막 값의 second++
            if (mode.back().first == v[i])
                mode.back().second++;
            //다른 원소이면, 삽입
            else
                mode.push_back(make_pair(v[i], 1));
        }
    }

    /*for (int i = 0; i < mode.size(); i++)
    {
        cout << "(" << mode[i].first << ", " << mode[i].second << ")" << "\n";
    }*/

    sort(mode.begin(), mode.end(), myCompare);

    if (mode.size() == 1)
        return mode[0].first;
    else if (mode[0].second == mode[1].second)
        return mode[1].first;
    else
        return mode[0].first;
}

int getRange()
{
    return v[v.size() - 1] - v[0];
}

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
}

int main()
{
    int N;
    cin >> N;

    init(N);

    cout << getAverage() << "\n";
    cout << getMedian() << "\n";
    cout << getMode() << "\n";
    cout << getRange() << "\n";

    return 0;
}