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

    // 1. N�Է�.
    int N;
    cin >> N;

    vector<ll> nums(N, 0);
    for (int i = 0; i < nums.size(); i++)
        cin >> nums[i];

    // 2. ���� ����(��������)
    sort(nums.begin(), nums.end());

    // 3. max_valueã��
    ll count = 0;
    ll max_value = -1 * pow(2, 62) - 1;
    ll max_count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // 3.1 ���� �Ǿ������Ƿ� ���� ������ �������̴�.
        // 3.2 ���� �ʴٸ�, max_value, max_count, count�� ����
        if (i != 0 && nums[i - 1] != nums[i])
        {
            // 3.3 count�� �� ũ��(���� ��쿡�� ���� ���� �����̹Ƿ�, =����)
            if (max_count < count)
            {
                max_count = count;
                max_value = nums[i - 1];
            }
            // 3.4 count�� 1�� �ٽ� �ʱ�ȭ.
            count = 0;
        }
        else
            count++;
    }

    // 3.5 �� ������ ���Ҹ� üũ�ؾ��Ѵ�.
    if (max_count < count || nums.size() == 1)
        max_value = nums.back();

    cout << max_value << "\n";

    return 0;
}
