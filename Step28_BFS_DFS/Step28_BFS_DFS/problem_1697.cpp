/*
  #. [ 숨바꼭질 ]
  #. 문제
     수빈이는 동생과 숨바꼭질을 하고 있다. 
     수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
     수빈이는 걷거나 순간이동을 할 수 있다. 
     만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
     순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

     수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

  #. 입력
     첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

  #. 출력
     수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

  #. 예제 입력 1 
     5 17
     예제 출력 1 
     4
     힌트
     수빈이가 5-10-9-18-17 순으로 가면 4초만에 동생을 찾을 수 있다.

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX_SIZE 1000000


/*
  #. 접근법.
     - 이전 토마토 문제와 유사하다.
       단, 이 문제에서는 일차원 공간 '직선'이다.
     - BFS를 통하여 첫 번째 위치부터 -1, +1, *2 위치를 탐색하면서
       방문 처리하고, 동생을 찾는다.
       이 때, 한 cycle(queue에서 꺼내는 것)을 돌게 되면, 1초씩 증가.
*/


int check[MAX_SIZE + 1];

int bfs(vector<int> first_loc, int k)
{
    int answer = 0;
    //0. 첫 시작 위치는 1곳이지만,
    //   두 번째 탐색 할 위치는 3곳, 이 후 각 위치에서 최대 3개씩의 탐색 위치 늘어남.
    //   즉, 한 cycle에서 탐색 할 개수 구분하기 위해 다음과 같이 queue생성.
    queue<vector<int>> q;

    //1. 수빈이의 시작위치 vector를 queue에 넣고, 방문 처리
    q.push(first_loc);
    for (int i = 0; i < first_loc.size(); i++)
        check[first_loc[i]] = true;

    //2. 수빈이의 현재 위치로 부터 시작.
    while (!q.empty())
    {
        //3. 동생이 있는 곳 찾았는지
        bool found = false;

        //4. queue에서 하나 꺼내고, -1, +1, *2 위치 탐색 시작.
        vector<int> v = q.front();
        q.pop();

        //5. queue에 삽입 할 다음 위치 vector
        vector<int> next_loc;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == k)
            {
                found = true;
                break;
            }

            //6. 위치 조정 후, 
            int m1 = v[i] + 1;
            int m2 = v[i] - 1;
            int m3 = v[i] * 2;

            //7. 각 위치가 범위에 있고, 방문하지 않은 곳이면
            //   방문처리하고, 그 위치에사 다시 탐색하도록 vector에 삽입.
            if (m1 >= 0 && m1 < MAX_SIZE && check[m1] == false)
            {
                check[m1] = true;
                next_loc.push_back(m1);
            }

            if (m2 >= 0 && m2 < MAX_SIZE && check[m2] == false)
            {
                check[m2] = true;
                next_loc.push_back(m2);
            }

            if (m3 >= 0 && m3 <= MAX_SIZE && check[m3] == false)
            {
                check[m3] = true;
                next_loc.push_back(m3);
            }   
        }

        //8. 동생 찾았으면 그만.
        if (found)
            break;

        //9. 사이즈가 0이 아니라는 의미 : 아직 탐색할 위치가 존재.
        if (next_loc.size() != 0)
        {
            answer++;
            q.push(next_loc);
        }
    }
    return answer;
}

int main()
{
    //0. 입력.
    int N, K;
    cin >> N >> K;

    //1. queue의 원소를 vector로 사용하기 위해,
    vector<int> v;
    v.push_back(N);

    //2. BFS시작.
    cout << bfs(v, K) << "\n";

	return 0;
}