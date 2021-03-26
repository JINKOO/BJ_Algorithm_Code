#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

using ll = long long;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. N입력.
    int N;
    cin >> N;

    vector<ll> nums(N, 0);
    for (int i = 0; i < nums.size(); i++)
        cin >> nums[i];

    // 2. 정렬 수행(오름차순)
    sort(nums.begin(), nums.end());

    // 3. max_value찾기
    ll count = 0;
    ll max_value = -1 * pow(2, 62) - 1;
    ll max_count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // 3.1 정렬 되어있으므로 같은 값들은 연속적이다.
        // 3.2 같지 않다면, max_value, max_count, count값 갱신
        if (i != 0 && nums[i - 1] != nums[i])
        {
            // 3.3 count가 더 크면(같은 경우에는 작은 값이 정답이므로, =제외)
            if (max_count < count)
            {
                max_count = count;
                max_value = nums[i - 1];
            }
            // 3.4 count는 1로 다시 초기화.
            count = 0;
        }
        else
            count++;
    }

    // 3.5 맨 마지막 원소를 체크해야한다.
    if (max_count < count || nums.size() == 1)
        max_value = nums.back();

    cout << max_value << "\n";

    return 0;
}
