/*
   #. [ ����_2352�� �ݵ�ü ���� ] Gold III
   
   #. ����
      �ݵ�ü�� ������ �� n���� ��Ʈ�� �ٸ� n���� ��Ʈ�� �����ؾ� �� ���� �ִ�.
      ���� ��� ���� �׸��� n���� ��Ʈ�� �ٸ� n���� ��Ʈ�� ��� �����ؾ� �ϴ����� ��Ÿ����. 
      ������ �̿� ���� ������ �� ��쿡�� ���ἱ�� ���� ���̱� ������ �̿� ���� ������ �� ����. 
      n���� ��Ʈ�� �ٸ� n���� ��Ʈ�� ��� ����Ǿ�� �ϴ����� �־����� ��, ���ἱ�� ���� ������(��ġ��, ��������) �ʵ��� 
      �ϸ鼭 �ִ� �� ������ ������ �� �ִ����� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�
      
   #. �Է�
      ù° �ٿ� ���� n(1 �� n �� 40,000)�� �־�����. 
      ���� �ٿ��� ���ʷ� 1�� ��Ʈ�� ����Ǿ�� �ϴ� ��Ʈ ��ȣ, 2�� ��Ʈ�� ����Ǿ�� �ϴ� ��Ʈ ��ȣ, ��, n�� ��Ʈ�� ����Ǿ�� �ϴ� ��Ʈ ��ȣ�� �־�����. �� ������ 1 �̻� n �����̸� ���� ���� ���� ���ٰ� ��������.
   
   #. ���
      ù° �ٿ� �ִ� ���� ������ ����Ѵ�.
      
   #. ���� �Է� 1 
      6
      4 2 6 3 1 5
      
   #. ���� ��� 1 
      3
*/

/*
   #. Ǯ�̹�.
      - DP�� Ȱ���ϰ�, LIS������� Ǫ�µ� O(nlogn)���� Ǯ����ϴ� �����̴�.
      - n <= 40000�̱� ������ ���� �ݺ������� Ǯ�� �Ǹ�, �ȵȴ�.
      - lowerbound�� ����ϰ� �ȴ�.
        --> �̺� Ž������ �����Ǿ� �ִ�. lowerbound(start, end, value)�ε�, value�̻��� ���� �ִ� ó�� ��ġ�� ��ȯ�Ѵ�.
            �迭�� ��� -�迭�̸� = index�� ���� �� �ִ�.
            vector�� ��� -vector.begin()�ϸ�, index���� �� �ִ�.

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
            //lowerbound����, ���⼭�� dp�� 1���� �����ϹǷ� ���۰� ������ 1�����ش�.
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