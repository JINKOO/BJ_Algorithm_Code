/*
  [ ȸ�ǽǹ��� �з� ] - Silver II

  #. ����
     �� ���� ȸ�ǽ��� �ִµ� �̸� ����ϰ��� �ϴ� N���� ȸ�ǿ� ���Ͽ� ȸ�ǽ� ���ǥ�� ������� �Ѵ�. 
     �� ȸ�� I�� ���� ���۽ð��� ������ �ð��� �־��� �ְ�, 
     �� ȸ�ǰ� ��ġ�� �ʰ� �ϸ鼭 ȸ�ǽ��� ����� �� �ִ� ȸ���� �ִ� ������ ã�ƺ���. 
     ��, ȸ�Ǵ� �ѹ� �����ϸ� �߰��� �ߴܵ� �� ������ �� ȸ�ǰ� ������ �Ͱ� ���ÿ� ���� ȸ�ǰ� ���۵� �� �ִ�. 
     ȸ���� ���۽ð��� ������ �ð��� ���� ���� �ִ�. 
     �� ��쿡�� �������ڸ��� ������ ������ �����ϸ� �ȴ�.

  #. �Է�
     ù° �ٿ� ȸ���� �� N(1 �� N �� 100,000)�� �־�����. 
     ��° �ٺ��� N+1 �ٱ��� �� ȸ���� ������ �־����µ� 
     �̰��� ������ ���̿� �ΰ� ȸ���� ���۽ð��� ������ �ð��� �־�����. 
     ���� �ð��� ������ �ð��� 231-1���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

  #. ���
     ù° �ٿ� �ִ� ����� �� �ִ� ȸ���� �ִ� ������ ����Ѵ�.

  #. ���� �Է� 1 
     11
     1 4
     3 5
     0 6
     5 7
     3 8
     5 9
     6 10
     8 11
     8 12
     2 13
     12 14
     ���� ��� 1 
     4
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}


int solution(vector<pair<int, int>> m)
{
    int answer = 1;
    sort(m.begin(), m.end(), compare);

    int endTime = m[0].second;
    for (int i = 1; i < m.size(); i++)
    {
        if (endTime <= m[i].first)
        {
            answer++;
            endTime = m[i].second;
        }
    }
    return answer;
}

vector<pair<int, int>> initialize(int n)
{
    vector<pair<int, int>> m;
    for (int i = 0; i < n; i++)
    {
        int val1, val2;
        cin >> val1 >> val2;
        m.push_back({ val1, val2 });
    }
    return m;
}

void printResult(int answer)
{
    cout << answer << "\n";
}

int main() 
{
    int n;
    cin >> n;

    printResult(solution(initialize(n)));

    return 0;
}