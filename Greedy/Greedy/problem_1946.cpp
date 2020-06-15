/*
  #. [ ���� ��� ]
  
  #. ����
     ������ �ְ��� �����ϴ� ������ ���� ���� �ֽ�ȸ�簡 �ű� ��� ä���� �ǽ��Ѵ�. 
     ���� ���� ������ 1�� �����ɻ�� 2�� ������������ �̷������. 
     �ְ��� �����Ѵٴ� ����� �̳信 ���� �׵��� �ְ��� ����鸸�� ������� �����ϰ� �;� �Ѵ�.

     �׷��� ���� �ֽ�ȸ���, 
     �ٸ� ��� �����ڿ� ������ �� �����ɻ� ������ �������� ���� �� 
     ��� �ϳ��� �ٸ� �����ں��� �������� �ʴ� �ڸ� �����Ѵٴ� ��Ģ�� ������. 
     ��, � ������ A�� ������ �ٸ� � ������ B�� ������ ���� ���� �ɻ� ����� ���� ������ ��� �������ٸ� A�� ���� ���ߵ��� �ʴ´�.

     �̷��� ������ ������Ű�鼭, ���� �ֽ�ȸ�簡 �̹� �ű� ��� ä�뿡�� ������ �� �ִ� ���Ի���� �ִ� �ο����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

  #. �Է�
     ù° �ٿ��� �׽�Ʈ ���̽��� ���� T(1 �� T �� 20)�� �־�����. 
     �� �׽�Ʈ ���̽��� ù° �ٿ� �������� ���� N(1 �� N �� 100,000)�� �־�����. 
     ��° �ٺ��� N�� �ٿ��� ������ �������� �����ɻ� ����, ���� ������ ������ ������ ���̿� �ΰ� �� �ٿ� �־�����. 
     �� ���� ������ ��� 1������ N������ ������ ���� �����ȴٰ� �����Ѵ�.

  #. ���
     �� �׽�Ʈ ���̽��� ���ؼ� ���� �ֽ�ȸ�簡 ������ �� �ִ� ���Ի���� �ִ� �ο����� �� �ٿ� �ϳ��� ����Ѵ�.

  #. ���� �Է� 1 
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

  #. ���� ��� 1
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

    //1. ���� ���� ���� ���� �Ѵ�.
    sort(score.begin(), score.end(), myCompare);
    
    //���� for���� ���Ѵ�. n <= 100,000�̴�....
    /*
       2. ���� ���� ������ ������ �հ� X.
       ���� ������ ������ �հ��̰� ���� ���� ����.
       �̰� ������ ������ �̸� ������ �Ͽ��� ����.
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
















