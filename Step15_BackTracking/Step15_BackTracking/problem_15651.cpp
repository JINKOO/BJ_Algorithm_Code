/*
  #. [ ����_15651�� N�� M (3) ]Silver III

  #. ����
     �ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
     - 1���� N���� �ڿ��� �߿��� M���� ���� ����
     - ���� ���� ���� �� ��� �ȴ�.
     
  #. �Է�
     ù° �ٿ� �ڿ��� N�� M�� �־�����. (1 �� M �� N �� 7)
     
  #. ���
     �� �ٿ� �ϳ��� ������ ������ �����ϴ� ������ ����Ѵ�. �ߺ��Ǵ� ������ ���� �� ����ϸ� �ȵǸ�, 
     �� ������ �������� �����ؼ� ����ؾ� �Ѵ�.
     ������ ���� ������ �����ϴ� ������ ����ؾ� �Ѵ�.

  #. ���� �Է� 1 
     3 1
     ���� ��� 1 
     1
     2
     3
     
  #. ���� �Է� 2 
     4 2
  #. ���� ��� 2 
     1 1
     1 2
     1 3
     1 4
     2 1
     2 2
     2 3
     2 4
     3 1
     3 2
     3 3
     3 4
     4 1
     4 2
     4 3
     4 4
*/

#include <iostream>
#include <vector>
using namespace std;

int n, m;
int cost[8];

vector<int> v;

void dfs(int count)
{
    if (count == m)
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }

    //�� �������� ���Ұ� �ߺ������ϹǷ�, ���ݱ��� ����ߴ� check[]�迭�� �ʿ����.
    //�ܼ��� vector�� �����ϰ�, dfs�� �ٽ� �������ֱ⸸ �ϸ� �ȴ�.
    for (int i = 1; i <= n; i++)
    {
        v.push_back(cost[i]);
        dfs(count + 1);
        v.pop_back();
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cost[i] = i;

    dfs(0);

    return 0;
}