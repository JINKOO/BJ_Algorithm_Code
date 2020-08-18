/*
    #. [ ����_2164�� ī��2 ] Silver IV
    
    #. ����
       N���� ī�尡 �ִ�. ������ ī��� ���ʷ� 1���� N������ ��ȣ�� �پ� ������, 1�� ī�尡 ���� ����, 
       N�� ī�尡 ���� �Ʒ��� ���·� ������� ī�尡 ���� �ִ�.
       
       ���� ������ ���� ������ ī�尡 �� �� ���� ������ �ݺ��ϰ� �ȴ�. �켱, ���� ���� �ִ� ī�带 �ٴڿ� ������. 
       �� ����, ���� ���� �ִ� ī�带 ���� �Ʒ��� �ִ� ī�� ������ �ű��.
       
       ���� ��� N=4�� ��츦 ������ ����. ī��� ���� ���������� 1234 �� ������ �����ִ�. 1�� ������ 234�� ���´�. 
       ���⼭ 2�� ���� �Ʒ��� �ű�� 342�� �ȴ�. 3�� ������ 42�� �ǰ�, 4�� ������ �ű�� 24�� �ȴ�. 
       ���������� 2�� ������ ����, ���� ī��� 4�� �ȴ�.
       
       N�� �־����� ��, ���� �������� ���� �Ǵ� ī�带 ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
       
    #. �Է�
       ù° �ٿ� ���� N(1��N��500,000)�� �־�����.
    #. ���
       ù° �ٿ� ���� �Ǵ� ī���� ��ȣ�� ����Ѵ�.

    #. ���� �Է� 1 
       6
    #. ���� ��� 1 
       4
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
   
    int n;
    cin >> n;

    queue<int> q;

    for (int i = 1; i <= n; i++)
        q.push(i);

    bool flag = true;
    while (q.size() != 1)
    {
        int front = q.front();
        q.pop();
        if (flag)
            flag = false;
        else
        {
            q.push(front);
            flag = true;
        }
    }

    cout << q.front() << "\n";

    return 0;
}