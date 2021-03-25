#include <iostream>
#include <vector>
#include <cmath>>
#include <unordered_map>
using namespace std;

using ll = long long;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. NÀÔ·Â.
    int N;
    cin >> N;

    unordered_map<ll, int> m;
    for (int i = 0; i < N; i++)
    {
        ll num;
        cin >> num;
        
        m[num]++;
    }

    int max_count = 0;
    ll max_value = -1 * pow(2, 62) - 1;
    for (const auto& t : m)
    {
        if (t.second >= max_count)
        {
            max_count = t.second;
            max_value = t.first;
        }
    }

    cout << max_value << "\n";

    return 0;
}