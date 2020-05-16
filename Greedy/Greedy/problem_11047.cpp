/*
  [���� 0 �з�] - Silver I

  #. ����
     �ر԰� ������ �ִ� ������ �� N�����̰�, ������ ������ �ſ� ���� ������ �ִ�.
     ������ ������ ����ؼ� �� ��ġ�� ���� K�� ������� �Ѵ�. 
     �̶� �ʿ��� ���� ������ �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

  #. �Է�
     ù° �ٿ� N�� K�� �־�����. (1 �� N �� 10, 1 �� K �� 100,000,000)
     ��° �ٺ��� N���� �ٿ� ������ ��ġ Ai�� ������������ �־�����. (1 �� Ai �� 1,000,000, A1 = 1, i �� 2�� ��쿡 Ai�� Ai-1�� ���)

  #. ���
     ù° �ٿ� K���� ����µ� �ʿ��� ���� ������ �ּڰ��� ����Ѵ�.

  #. ���� �Է� 1 
     10 4200
     1
     5
     10
     50
     100
     500
     1000
     5000
     10000
     50000
     
     ���� ��� 1 
     6
*/

#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

int solution(int k, vector<int> m)
{
    int answer = 0;
    //
    //sort(m.begin(), m.end(), greater<int>());
    for (int i = m.size() - 1; i >= 0; i--)
    {
        if ((k / m[i]) != 0)
            answer += (k / m[i]);
        k %= m[i];
    }
    //
    return answer;
}

vector<int> initialize(int n)
{
    vector<int> m;
    for (int i = 0; i < n; i++)
    {
        int money;
        cin >> money;
        m.push_back(money);
    }
    return m;
}

void printResult(int answer)
{
    cout << answer << "\n";
}

int main()
{
    int n, k;
    cin >> n >> k;

    printResult(solution(k, initialize(n)));
    
    return 0;
}