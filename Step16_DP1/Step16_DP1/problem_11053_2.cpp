/*
   #. [백준_11053번 가장 긴 증가하는 수열 ] 또 다른 풀이
   
   #. lowerbound를 사용하여, O(nlogn)으로 푸는 방법.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int cost[1001];
int dp[1001];

int solution(int n)
{
    dp[1] = cost[1];
    int length = 1;

    for (int i = 2; i <= n; i++)
    {
        if (cost[i] > dp[length])
            dp[++length] = cost[i];
        else
        {
            int index = lower_bound(dp+1, dp+length+1, cost[i]) - dp;
            dp[index] = cost[i];
            
        }
    }
    return length;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    cout << solution(n) << "\n";

    return 0;
}