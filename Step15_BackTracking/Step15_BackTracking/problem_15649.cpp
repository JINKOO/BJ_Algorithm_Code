/*
   #. [ ����_15649�� N�� M (1) ] 
   
   #. ����
      �ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
      - 1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
      
   #. �Է�
      ù° �ٿ� �ڿ��� N�� M�� �־�����. (1 �� M �� N �� 8)
      
   #. ���
      �� �ٿ� �ϳ��� ������ ������ �����ϴ� ������ ����Ѵ�. �ߺ��Ǵ� ������ ���� �� ����ϸ� �ȵǸ�, 
      �� ������ �������� �����ؼ� ����ؾ� �Ѵ�.
      
   #. ������ ���� ������ �����ϴ� ������ ����ؾ� �Ѵ�.
   
   #. ���� �Է� 1 
      3 1
      ���� ��� 1 
      1
      2
      3

   #. ���� �Է� 2 
      4 2
      ���� ��� 2 
      1 2
      1 3
      1 4
      2 1
      2 3
      2 4
      3 1
      3 2
      3 4
      4 1
      4 2
      4 3
*/

#include <iostream>
#include <vector>
using namespace std;

int n, m;
int cost[9];
bool check[9];

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

    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            v.push_back(cost[i]);
            dfs(count + 1);
            check[i] = false;
            v.pop_back();
        }
    }
}

void solution()
{
    dfs(0);
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cost[i] = i;

    solution();

    return 0;
}