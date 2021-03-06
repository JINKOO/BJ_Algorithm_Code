/*
   #. [ 백준_2805번 나무 자르기 ]Silver III
   
   #. 문제
      상근이는 나무 M미터가 필요하다. 근처에 나무를 구입할 곳이 모두 망해버렸기 때문에, 정부에 벌목 허가를 요청했다. 
      정부는 상근이네 집 근처의 나무 한 줄에 대한 벌목 허가를 내주었고, 상근이는 새로 구입한 목재절단기를 이용해서 나무를 구할것이다.
      
      목재절단기는 다음과 같이 동작한다. 먼저, 상근이는 절단기에 높이 H를 지정해야 한다. 
      높이를 지정하면 톱날이 땅으로부터 H미터 위로 올라간다. 그 다음, 한 줄에 연속해있는 나무를 모두 절단해버린다. 
      따라서, 높이가 H보다 큰 나무는 H 위의 부분이 잘릴 것이고, 낮은 나무는 잘리지 않을 것이다. 
      예를 들어, 한 줄에 연속해있는 나무의 높이가 20, 15, 10, 17이라고 하자. 상근이가 높이를 15로 지정했다면, 
      나무를 자른 뒤의 높이는 15, 15, 10, 15가 될 것이고, 상근이는 길이가 5인 나무와 2인 나무를 들고 집에 갈 것이다. 
      (총 7미터를 집에 들고 간다)
      
      상근이는 환경에 매우 관심이 많기 때문에, 나무를 필요한 만큼만 집으로 가져가려고 한다. 
      이때, 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 구하는 프로그램을 작성하시오.
      
   #. 입력
      첫째 줄에 나무의 수 N과 상근이가 집으로 가져가려고 하는 나무의 길이 M이 주어진다. (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)
      둘째 줄에는 나무의 높이가 주어진다. 나무의 높이의 합은 항상 M을 넘기 때문에, 상근이는 집에 필요한 나무를 항상 가져갈 수 있다. 
      높이는 1,000,000,000보다 작거나 같은 양의 정수 또는 0이다.
      
   #. 출력
      적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 출력한다.
      
   #. 예제 입력 1 
      4 7
      20 15 10 17
      예제 출력 1 
      15
*/
/*
   #. 풀이법.
      - 나무 높이가 들어있는 배열의 길이 선언 N <= 1,000,000
      - 나무의 길이가 20억이하이므로, 효율적인 알고리즘을 사용해야 한다.
      - 이분탐색을 사용한다.
      - 이분탐색은 정렬되어있는 상태에서 수행해야한다.
        1. 시작길이와 max길이를 범위로 설정
        2. 시작길이와 max길이가 엇갈릴때 까지, while문 수행한다.
        3. mid를 구하고, 해당 mid는 절단기의 높이가 된다.
        4. 각 나무 배열을 탐색하고 절단기의 높이 이상이 나무의 잔여 길이를 모두 더한다.
        5. 모두 더한 값(total)이 <= M 이면, 높이를 낮춰야 한다. max = height - 1
                                >= M이면, 높이를 높여야한다. low = height + 1;
        6. 이 때, M값이 반드시 잘린 길이의 합이 된다는 보장이 없다. 문제 조건에서도 적어도 M의 길이를 가져갈 수 있는 높이를 구하라 했다.
           4 7
           20 15 10 18
           height가 15일 때 total=8이고 이때가 M의 값(7)에 가장 가깝다. 즉, 적어도 7의 길이를 가져갈 수 있는 절단기의 높이는 15이다.
                 
           따라서 별도의 처리를 해줘야한다.
      - 나무의 길이가 20억이하이므로, 필요한 변수들은 long long으로 선언한다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll tree[1000000];
int M, N;

int main()
{
    ll answer = 0;

    cin.tie(0);
    cin.sync_with_stdio(0);

    //1. 필요한 정보 입력받기
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> tree[i];

    //2. 오름 차순 정렬 수행.
    sort(tree, tree + N);

    ll low = 0;
    ll high = *max_element(tree, tree + N);

    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll total = 0;

        for (int i = 0; i < N; i++)
        {
            if (tree[i] >= mid)
                total += (tree[i] - mid);
        }

        //적어도 M인 길이를 가져갈 수 있도록 설정해야한다.
        //M이 반드시 total과 같다는 보장이 없다.
        //total >= M이면 mid를 계속 높여가야하기 때문에, 결국에는 M에 가장 가깝거나 M인 total일 때의 mid가 정답이 된다.
        if (total >= M)
        {
            if (answer < mid)
                answer = mid;
        }

        //절단기 높이를 줄여야 한다.
        if (total <= M)
        {
            if (total == M)
            {
                answer = mid;
                break;
            }
            high = mid - 1;
        }

        //절단기 높이를 높여야 한다.
        else
            low = mid + 1;
    }
    cout << answer << "\n";

    return 0;
}











