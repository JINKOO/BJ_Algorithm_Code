/*
   #. [ 백준_2352번 반도체 설계 ] Gold III
   
   #. 문제
      반도체를 설계할 때 n개의 포트를 다른 n개의 포트와 연결해야 할 때가 있다.
      예를 들어 왼쪽 그림이 n개의 포트와 다른 n개의 포트를 어떻게 연결해야 하는지를 나타낸다. 
      하지만 이와 같이 연결을 할 경우에는 연결선이 서로 꼬이기 때문에 이와 같이 연결할 수 없다. 
      n개의 포트가 다른 n개의 포트와 어떻게 연결되어야 하는지가 주어졌을 때, 연결선이 서로 꼬이지(겹치지, 교차하지) 않도록 
      하면서 최대 몇 개까지 연결할 수 있는지를 알아내는 프로그램을 작성하시오
      
   #. 입력
      첫째 줄에 정수 n(1 ≤ n ≤ 40,000)이 주어진다. 
      다음 줄에는 차례로 1번 포트와 연결되어야 하는 포트 번호, 2번 포트와 연결되어야 하는 포트 번호, …, n번 포트와 연결되어야 하는 포트 번호가 주어진다. 이 수들은 1 이상 n 이하이며 서로 같은 수는 없다고 가정하자.
   
   #. 출력
      첫째 줄에 최대 연결 개수를 출력한다.
      
   #. 예제 입력 1 
      6
      4 2 6 3 1 5
      
   #. 예제 출력 1 
      3
*/

/*
   #. 풀이법.
      - DP를 활용하고, LIS방식으로 푸는데 O(nlogn)으로 풀어야하는 문제이다.
      - n <= 40000이기 때문에 이중 반복문으로 풀게 되면, 안된다.
      - lowerbound를 사용하게 된다.
        --> 이분 탐색으로 구현되어 있다. lowerbound(start, end, value)인데, value이상의 값이 있는 처음 위치를 반환한다.
            배열인 경우 -배열이름 = index를 구할 수 있다.
            vector인 경우 -vector.begin()하면, index구할 수 있다.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[40001];
int cost[40001];

int solution(int n)
{
    int answer = 0;
    //
    dp[1] = cost[1];
    int length = 1;
    for (int i = 2; i <= n; i++)
    {
        if (cost[i] > dp[length])
            dp[++length] = cost[i];
        else
        {
            //lowerbound사용법, 여기서는 dp가 1부터 시작하므로 시작과 끝지점 1더해준다.
            int index = lower_bound(dp+1, dp+length + 1, cost[i]) - dp;
            dp[index] = cost[i];
        }
    }
    answer = length;
    //
    return answer;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    cout << solution(n) << "\n";
}