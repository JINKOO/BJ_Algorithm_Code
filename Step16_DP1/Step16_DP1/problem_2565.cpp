/*
   #. [ 백준_2565번 전깃줄 ] Silver I
   
   #. 문제
      두 전봇대 A와 B 사이에 하나 둘씩 전깃줄을 추가하다 보니 전깃줄이 서로 교차하는 경우가 발생하였다. 
      합선의 위험이 있어 이들 중 몇 개의 전깃줄을 없애 전깃줄이 교차하지 않도록 만들려고 한다.
      
      예를 들어, <그림 1>과 같이 전깃줄이 연결되어 있는 경우 A의 1번 위치와 B의 8번 위치를 잇는 전깃줄, 
      A의 3번 위치와 B의 9번 위치를 잇는 전깃줄, 
      A의 4번 위치와 B의 1번 위치를 잇는 전깃줄을 없애면 
      남아있는 모든 전깃줄이 서로 교차하지 않게 된다.
      
      전깃줄이 전봇대에 연결되는 위치는 전봇대 위에서부터 차례대로 번호가 매겨진다. 
      전깃줄의 개수와 전깃줄들이 두 전봇대에 연결되는 위치의 번호가 주어질 때, 
      남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 구하는 프로그램을 작성하시오.
      
   #. 입력
      - 첫째 줄에는 두 전봇대 사이의 전깃줄의 개수가 주어진다. 
      - 전깃줄의 개수는 100 이하의 자연수이다. 
      - 둘째 줄부터 한 줄에 하나씩 전깃줄이 A전봇대와 연결되는 위치의 번호와 B전봇대와 연결되는 위치의 번호가 차례로 주어진다. 위치의 번호는 500 이하의 자연수이고, 같은 위치에 두 개 이상의 전깃줄이 연결될 수 없다.
      
      
   #. 출력
      첫째 줄에 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 출력한다.
      
   #. 예제 입력 1 
      8
      1 8
      3 9
      2 2
      4 1
      6 4
      10 10
      9 7
      7 6
      
   #. 예제 출력 1 
   3
*/

/*
   #. 나의 풀이법.
      - DP를 어떻게 접근 해야 할 지 몰랐다.
      - 입력 받은 전봇대 연결 정보에서 뭔가 정렬을 해야 할 거 같은 느낌적인 느낌을 받긴 함....
        실행해보진 않고, 느낌만 받음

   #. 풀이법.
      - 우선 A전봇대 기준으로 정렬한다.
      - LIS(Largest Increases Subsequences)를 이용한 풀이이다.
      - 정렬하고 나서 B전봇대에서 '가장 긴 증가하는 수열'을 찾으면, 
        꼬이지 않는 전깃줄의 최댓값을 구할 수 있다.
      - 정답 = n - 꼬이지 않는 전깃줄 최댓값

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100];
vector <pair<int, int>> v;

bool myCompare(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.first < p2.first;
}

int solution(int n)
{
    int answer = 0;
    //0. 꼬이지 않는 전깃줄 개수 최댓값
    int max_line = 0;

    //1. A전봇대를 오름차순으로 정렬한다.
    sort(v.begin(), v.end(), myCompare);

    //2. B전봇대에서 '가장 긴 증가하는 수열'의 길이를 구한다.
    for (int i = 0; i < n; i++)
    {
        int max_dp = 0;
        for (int j = 0; j < i; j++)
        {
            if (v[i].second > v[j].second)
            {
                if (max_dp < dp[j])
                    max_dp = dp[j];
            }
        }
        dp[i] = max_dp + 1;
    }

   
    for (int i = 0; i < n; i++)
    {
        if (max_line < dp[i])
            max_line = dp[i];
    }

    answer = n - max_line;

    return answer;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    cout << solution(n) << "\n";

    return 0;
}