#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sort_cmp(const string& str1, const string& str2)
{
    // ���̰� ���� �ʴٸ�, ª�� ���� �����´�.
    if (str1.length() != str2.length())
        return str1.length() < str2.length();

    // ���̰� ���ٸ�, �� �ڸ����� �� ���Ѵ�.
    int str1_total = 0, str2_total = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] >= '0' && str1[i] <= '9')
            str1_total += (str1[i] - '0');

        if (str2[i] >= '0' && str2[i] <= '9')
            str2_total += (str2[i] - '0');
    }

    // ���� ���� �ʴٸ�, ���� ���� ���� ����
    if (str1_total != str2_total)
        return str1_total < str2_total;

    // ���� ���ٸ�, (1�� 2�� ���� ��� �������� �ʴ´ٸ�) ���� ��
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