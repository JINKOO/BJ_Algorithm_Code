/*
  #. [ ���� �з� ]
  
  #. ����
     N(1��N��100,000)���� ������ �ִ�. 
     �� ������ �̿��Ͽ� �̷� ���� ��ü�� ���ø� �� �ִ�. 
     ������ ������ �� ���⳪ ���̰� �ٸ��� ������ �� �� �ִ� ��ü�� �߷��� ���� �ٸ� ���� �ִ�.

     ������ ���� ���� ������ ���ķ� �����ϸ� ������ ������ �ɸ��� �߷��� ���� �� �ִ�. 
     k���� ������ ����Ͽ� �߷��� w�� ��ü�� ���ø� ��, ������ �������� ��� ������ w/k ��ŭ�� �߷��� �ɸ��� �ȴ�.
     
     �� �����鿡 ���� ������ �־����� ��, 
     �� �������� �̿��Ͽ� ���ø� �� �ִ� ��ü�� �ִ� �߷��� ���س��� ���α׷��� �ۼ��Ͻÿ�. 
     ��� ������ ����ؾ� �� �ʿ�� ������, ���Ƿ� �� ���� ������ ��� ����ص� �ȴ�.

  #. �Է�
     ù° �ٿ� ���� N�� �־�����. ���� N���� �ٿ��� �� ������ ��ƿ �� �ִ� �ִ� �߷��� �־�����. 
     �� ���� 10,000�� ���� �ʴ� �ڿ����̴�.

  #. ���
     ù° �ٿ� ���� ����Ѵ�.

  #. ���� �Է� 1 
     2
     10
     15
  #. ���� ��� 1 
     20
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int solution(vector<int> v)
{
    int answer = 0;
    //
    //1. k���� �������� �߷� �������� ����
    sort(v.begin(), v.end());

    //2. �ʱ� max��
    int max = v[0] * v.size();

    //3. i ��° �߷� * �ڷ� ���� ���� ���� �� ���� ū ���� ����.
    for (int i = 1; i < v.size(); i++)
    {
        if (max < v[i] * (v.size() - i))
            max = v[i] * (v.size() - i);
    }
    answer = max;
    //
    return answer;
}

void init(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cin >> v[i];
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    init(v);
    cout << solution(v) << "\n";

    return 0;
}






