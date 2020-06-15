/*
  #. [ 신입 사원 ]
  
  #. 문제
     언제나 최고만을 지향하는 굴지의 대기업 진영 주식회사가 신규 사원 채용을 실시한다. 
     인재 선발 시험은 1차 서류심사와 2차 면접시험으로 이루어진다. 
     최고만을 지향한다는 기업의 이념에 따라 그들은 최고의 인재들만을 사원으로 선발하고 싶어 한다.

     그래서 진영 주식회사는, 
     다른 모든 지원자와 비교했을 때 서류심사 성적과 면접시험 성적 중 
     적어도 하나가 다른 지원자보다 떨어지지 않는 자만 선발한다는 원칙을 세웠다. 
     즉, 어떤 지원자 A의 성적이 다른 어떤 지원자 B의 성적에 비해 서류 심사 결과와 면접 성적이 모두 떨어진다면 A는 결코 선발되지 않는다.

     이러한 조건을 만족시키면서, 진영 주식회사가 이번 신규 사원 채용에서 선발할 수 있는 신입사원의 최대 인원수를 구하는 프로그램을 작성하시오.

  #. 입력
     첫째 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 20)가 주어진다. 
     각 테스트 케이스의 첫째 줄에 지원자의 숫자 N(1 ≤ N ≤ 100,000)이 주어진다. 
     둘째 줄부터 N개 줄에는 각각의 지원자의 서류심사 성적, 면접 성적의 순위가 공백을 사이에 두고 한 줄에 주어진다. 
     두 성적 순위는 모두 1위부터 N위까지 동석차 없이 결정된다고 가정한다.

  #. 출력
     각 테스트 케이스에 대해서 진영 주식회사가 선발할 수 있는 신입사원의 최대 인원수를 한 줄에 하나씩 출력한다.

  #. 예제 입력 1 
     2
     5
     3 2
     1 4
     4 1
     2 3
     5 5
     7
     3 6
     7 3
     4 2
     1 4
     5 7
     2 5
     6 1

  #. 예제 출력 1
     4
     3
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myCompare(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.first < p2.first;
}

int solution(vector<pair<int, int>> score)
{
    int answer = 0;
    //
   /* for (int i = 0; i < n; i++)
    {
        bool check = false;
        if (score[i][0] == 1 || score[i][1] == 1)
            check = true;

        else
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (score[i][0] < score[j][0] || score[i][1] < score[j][1])
                    check = true;
                else
                {
                    check = false;
                    break;
                }
            }
        }

        if (check)
            answer++;
    }*/

    //1. 서류 순위 기준 정렬 한다.
    sort(score.begin(), score.end(), myCompare);
    
    //이중 for문을 피한다. n <= 100,000이다....
    /*
       2. 이후 면접 순위가 낮으면 합격 X.
       면접 순위가 높으면 합격이고 면접 순위 갱신.
       이게 가능한 이유는 미리 정렬을 하였기 때문.
    */
    int pivot = score[0].second;
    for (int i = 0; i < score.size(); i++)
    {
        if (score[i].second <= pivot)
        {
            pivot = score[i].second;
            answer++;
        }
    }
    //
    return answer;
}

int main()
{
    int T;
    cin >> T;

    vector<pair<int, int>> score;

    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int n1, n2;
            cin >> n1 >> n2;
            score.push_back(make_pair(n1, n2));
        }

        cout << solution(score) << "\n";

        score.clear();
    }

    return 0;
}
















