/*
   #. [ 백준_14889번 스타트와 링크 ]
   
   #. 문제
      오늘은 스타트링크에 다니는 사람들이 모여서 축구를 해보려고 한다. 
      축구는 평일 오후에 하고 의무 참석도 아니다. 
      축구를 하기 위해 모인 사람은 총 N명이고 신기하게도 N은 짝수이다. 
      이제 N/2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.
      
      BOJ를 운영하는 회사 답게 사람에게 번호를 1부터 N까지로 배정했고, 아래와 같은 능력치를 조사했다. 
      능력치 Sij는 i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치이다. 
      팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합이다. Sij는 Sji와 다를 수도 있으며, 
      i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치는 Sij와 Sji이다.
      
      N=4이고, S가 아래와 같은 경우를 살펴보자.
      
      i\j	1	2	3	4
       1	 	1	2	3
       2	4	 	5	6
       3	7	1	 	2
       4	3	4	5	 
       
       예를 들어, 1, 2번이 스타트 팀, 3, 4번이 링크 팀에 속한 경우에 두 팀의 능력치는 아래와 같다.
       스타트 팀: S12 + S21 = 1 + 4 = 5
       링크 팀: S34 + S43 = 2 + 5 = 7
       
       1, 3번이 스타트 팀, 2, 4번이 링크 팀에 속하면, 두 팀의 능력치는 아래와 같다.
       스타트 팀: S13 + S31 = 2 + 7 = 9
       링크 팀: S24 + S42 = 6 + 4 = 10
       
       축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다. 
       위의 예제와 같은 경우에는 1, 4번이 스타트 팀, 2, 3번 팀이 링크 팀에 속하면 스타트 팀의 능력치는 6, 
       링크 팀의 능력치는 6이 되어서 차이가 0이 되고 이 값이 최소이다.
       
   #. 입력
      첫째 줄에 N(4 ≤ N ≤ 20, N은 짝수)이 주어진다. 
      둘째 줄부터 N개의 줄에 S가 주어진다. 
      각 줄은 N개의 수로 이루어져 있고, i번 줄의 j번째 수는 Sij 이다. Sii는 항상 0이고, 나머지 Sij는 1보다 크거나 같고, 
      100보다 작거나 같은 정수이다.
      
   #. 출력
      첫째 줄에 스타트 팀과 링크 팀의 능력치의 차이의 최솟값을 출력한다.
      
   #. 예제 입력 1 
      4
      0 1 2 3
      4 0 5 6
      7 1 0 2
      3 4 5 0
   #. 예제 출력 1 
      0
      
   #. 예제 입력 2 
      6
      0 1 2 3 4 5
      1 0 2 3 4 5
      1 2 0 3 4 5
      1 2 3 0 4 5
      1 2 3 4 0 5
      1 2 3 4 5 0
   #. 예제 출력 2 
      2
      
   #. 예제 입력 3 
      8
      0 5 4 5 4 5 4 5
      4 0 5 1 2 3 4 5
      9 8 0 1 2 3 1 2
      9 9 9 0 9 9 9 9
      1 1 1 1 0 1 1 1
      8 7 6 5 4 0 3 2
      9 1 9 1 9 1 0 9
      6 5 4 3 2 1 9 0

   #. 예제 출력 3 
      1
   #. 힌트
      예제 2의 경우에 (1, 3, 6), (2, 4, 5)로 팀을 나누면 되고, 
      예제 3의 경우에는 (1, 2, 4, 5), (3, 6, 7, 8)로 팀을 나누면 된다.

*/

#include <iostream>
#include <vector>
using namespace std;

int n;
int map[21][21];
int numbers[21];
bool check[21];
int _min = 100;   

void dfs(int index, int count)
{
    //start팀이 완성되면 link팀도 되고 여기서 조건처리 
    if (count == n / 2)
    {
        //각 팀에는 사람 번호가 삽입된다.
        vector<int> start;
        vector<int> link;
        int total_start = 0, total_link = 0; // 각 팀의 총 능력치.

        //check[]를 사용하여 T이면 start팀으로, F이면 link팀으로 분배.
        for (int k = 1; k <= n; k++)
        {
            if (check[k])
                start.push_back(k);
            else
                link.push_back(k);
        }

        //분배 끝나면, 능력치 계산
        /*
           start :: <1,2,3> link :: <4,5,6>이면,
           total_start = (map[1][2] + map[2][1]) + (map[1][3] + map[3][1]) + (map[2][3] + map[3][2])
           total_link = (map[4][5] + map[5][4]) + (map[4][6] + map[6][4]) + (map[4][6] + map[6][4])
        */
        for (int k = 0; k < start.size(); k++)
        {
            int i_start = start[k];
            int i_link = link[k];
            for (int p = k + 1; p < start.size(); p++)
            {
                int j_start = start[p];
                int j_link = link[p];

                total_start += (map[i_start][j_start] + map[j_start][i_start]);
                total_link += (map[i_link][j_link] + map[j_link][i_link]);
            }
        }

        if (abs(total_start - total_link) < _min)
            _min = abs(total_start - total_link);

        return;
    }

    //팀을 분배하기 위한 backTracking. numbers를 가지고 팀이 완성되는 경우마다 각팀의 능력치 차이를 계산한다.
    for (int i = index; i <= n; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            dfs(i + 1, count + 1);
            check[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        numbers[i] = i;
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];
    }

    dfs(1, 0);

    cout << _min << "\n";

    return 0;
}