/*
  #. [ 11651_��ǥ �����ϱ�2 Silver V ]

  #. ����
     2���� ��� ���� �� N���� �־�����. 
     ��ǥ�� y��ǥ�� �����ϴ� ������, y��ǥ�� ������ x��ǥ�� �����ϴ� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

  #. �Է�
     ù° �ٿ� ���� ���� N (1 �� N �� 100,000)�� �־�����. 
     ��° �ٺ��� N���� �ٿ��� i������ ��ġ xi�� yi�� �־�����. 
     (-100,000 �� xi, yi �� 100,000) ��ǥ�� �׻� �����̰�, ��ġ�� ���� �� ���� ����.

  #. ���
     ù° �ٺ��� N���� �ٿ� ���� ������ ����� ����Ѵ�.

  #. ���� �Է� 1 
     5
     0 4
     1 2
     1 -1
     2 2
     3 3
  #. ���� ��� 1 
     1 -1
     1 2
     2 2
     3 3
     0 4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myCompare(pair<int, int> &p1, pair<int, int> &p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

void init(vector<pair<int, int>> &v, int &n)
{
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
}

void print(vector<pair<int, int>> &v)
{
    for (pair<int, int> p : v)
        cout << p.first << " " << p.second << "\n";
}

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> v;
    init(v, N);

    sort(v.begin(), v.end(), myCompare);
    print(v);

    return 0;
}