/*
   #. [ ����_11866�� �似Ǫ�� ���� 0 ] Silver IV
   
   #. ����
      �似Ǫ�� ������ ������ ����.
      1������ N������ N���� ����� ���� �̷�鼭 �ɾ��ְ�, ���� ���� K(�� N)�� �־�����. ���� ������� K��° ����� �����Ѵ�.
      �� ����� ���ŵǸ� ���� ������ �̷���� ���� ���� �� ������ ����� ������. 
      �� ������ N���� ����� ��� ���ŵ� ������ ��ӵȴ�. ������ ������� ���ŵǴ� ������ (N, K)-�似Ǫ�� �����̶�� �Ѵ�. 
      ���� ��� (7, 3)-�似Ǫ�� ������ <3, 6, 2, 7, 5, 1, 4>�̴�.
      
      N�� K�� �־����� (N, K)-�似Ǫ�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
      
   #. �Է�
      ù° �ٿ� N�� K�� �� ĭ�� ���̿� �ΰ� ������� �־�����. (1 �� K �� N �� 1,000)
   
   #. ���
      ������ ���� �似Ǫ�� ������ ����Ѵ�.
      
   #. ���� �Է� 1 
      7 3
   #. ���� ��� 1 
      <3, 6, 2, 7, 5, 1, 4>
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n, k;
    cin >> n >> k;

    vector<int> answer;
    queue<int> q;

    for (int i = 1; i <= n; i++)
        q.push(i);

    int count = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        count++;
        if (count == k)
        {
            answer.push_back(front);
            count = 0;
        }
        else
            q.push(front);
    }
    
    if (answer.size() == 1)
        cout << "<" << answer[0] << ">" << "\n";
    else
    {
        for (int i = 0; i < answer.size(); i++)
        {
            if (i == 0)
                cout << "<" << answer[i] << ", ";
            else if (i == answer.size() - 1)
                cout << answer[i] << ">";
            else
                cout << answer[i] << ", ";
        }
    }

    return 0;
}