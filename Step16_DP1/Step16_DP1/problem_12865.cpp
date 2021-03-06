/*
   #. [ 백준_12865번 평범한 배낭 ] Gold V 
   
   #. 문제
      이 문제는 아주 평범한 배낭에 관한 문제이다.
      한 달 후면 국가의 부름을 받게 되는 준서는 여행을 가려고 한다. 
      세상과의 단절을 슬퍼하며 최대한 즐기기 위한 여행이기 때문에, 가지고 다닐 배낭 또한 최대한 가치 있게 싸려고 한다.
      준서가 여행에 필요하다고 생각하는 N개의 물건이 있다. 각 물건은 무게 W와 가치 V를 가지는데, 
      해당 물건을 배낭에 넣어서 가면 준서가 V만큼 즐길 수 있다. 
      아직 행군을 해본 적이 없는 준서는 최대 K무게까지의 배낭만 들고 다닐 수 있다. 
      준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 알려주자.
      
   #. 입력
      첫 줄에 물품의 수 N(1 ≤ N ≤ 100)과 준서가 버틸 수 있는 무게 K(1 ≤ K ≤ 100,000)가 주어진다. 
      두 번째 줄부터 N개의 줄에 거쳐 각 물건의 무게 W(1 ≤ W ≤ 100,000)와 해당 물건의 가치 V(0 ≤ V ≤ 1,000)가 주어진다.
      입력으로 주어지는 모든 수는 정수이다.
      
   #. 출력
      한 줄에 배낭에 넣을 수 있는 물건들의 가치합의 최댓값을 출력한다.
      
   #. 예제 입력 1 
      4 7
      6 13
      4 8
      3 6
      5 12
      예제 출력 1 
      14
*/
/*
   #. 나의 풀이법.
      - 굉장히 어려웠던 문제였다.
      - 배낭 문제에는 Fractional Knapsack이랑 0-1 Kanpsack문제가 있는데 0-1kanapsack문제 였다.
      - DP로 어떻게 풀까 고민하다가 구글링함.

      - 원리는 다음과 같다.
        dp[][]를 생성한다. dp[i][j]에는 '가치'가 기록된다. i = 물건 index, j = 무게

            0   1   2   3   4   5   6   7
        1   0   0   0   0   0   0   13  13

        - dp[1][6]에서 무게가 6일때, 1번물건을 담을 수 있다. 따라서 총 가치는 13

            0   1   2   3   4   5    6     7
        1   0   0   0   0   0   0    13    13
        2   0   0   0   0   8   8    13    13

        - dp[2][4]에서 무게가 4일때, 2번 물건을 담을 수 있다. 따라서 총 가치는 8(1번 물건은 담을 수 없다.)
        - dp[2][6]에서 무게가 6일때, 2가지 값을 고려해야한다.
          1. 현재 2번물건을 배낭에 넣지 않았을 때:: 즉 바로 이전값인 dp[1][6] = 13 (dp[i-1][j])
          2. 현재 2번물건을 배낭에 넣었을 때 :: j = 6일 때, 2번 물건의 무게 = 4;
             j - 2번 물건의 무게 = 2 --> dp[i-1][2]의 값.
             즉, dp[i-1][2] + 2번 물건의 가치 = 0 + 8

          dp[2][6] = max(13, 8) = 13

          즉, 현재 물건을 넣었을 때의 가치 =  
             우선 현재 물건 넣고 + 잔여 무게 만큼(현재 무게 - 현재 물건 무게) 현재 물건 전까지 넣었던 기록
                       cost[i][j]                               dp[i-1][j - weight]

        결론 dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight] + cost[i][j])  (j >= weight)
                        dp[i-1][j] (j < weight)
*/
#include <iostream>
using namespace std;

int dp[101][100001];
int cost[101][2];

int getMax(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

int solution(int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        int weight = cost[i][0];
        int value = cost[i][1];
        for (int j = 1; j <= k; j++)
        {
            if (j >= weight)
                dp[i][j] = getMax(dp[i - 1][j], dp[i - 1][j - weight] + value);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][k];
}

int main()
{
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> cost[i][0] >> cost[i][1];

    cout << solution(N, K) << "\n";

    return 0;
}