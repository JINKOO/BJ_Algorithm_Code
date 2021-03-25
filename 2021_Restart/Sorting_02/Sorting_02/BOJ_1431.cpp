#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sort_cmp(const string& str1, const string& str2)
{
    // 길이가 같지 않다면, 짧은 것이 먼저온다.
    if (str1.length() != str2.length())
        return str1.length() < str2.length();

    // 길이가 같다면, 각 자리숫자 합 구한다.
    int str1_total = 0, str2_total = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] >= '0' && str1[i] <= '9')
            str1_total += (str1[i] - '0');

        if (str2[i] >= '0' && str2[i] <= '9')
            str2_total += (str2[i] - '0');
    }

    // 합이 같지 않다면, 합이 작은 것이 먼저
    if (str1_total != str2_total)
        return str1_total < str2_total;

    // 합이 같다면, (1번 2번 조건 모두 만족하지 않는다면) 사전 순
    return str1 < str2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<string> guitars(N, "");
    for (int i = 0; i < guitars.size(); i++)
        cin >> guitars[i];

    sort(guitars.begin(), guitars.end(), sort_cmp);

    for (const auto& t : guitars)
        cout << t << "\n";

    return 0;
}