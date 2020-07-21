/*
  #. [ ���� 10814_���̼� ����  Silver V ]

  #. ����
     �¶��� ������ ������ ������� ���̿� �̸��� ������ ������� �־�����. 
     �̶�, ȸ������ ���̰� �����ϴ� ������, ���̰� ������ ���� ������ ����� �տ� ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

  #. �Է�
     ù° �ٿ� �¶��� ���� ȸ���� �� N�� �־�����. (1 �� N �� 100,000)
     ��° �ٺ��� N���� �ٿ��� �� ȸ���� ���̿� �̸��� �������� ���еǾ� �־�����. 
     - ���̴� 1���� ũ�ų� ������, 200���� �۰ų� ���� �����̰�, 
     - �̸��� ���ĺ� ��ҹ��ڷ� �̷���� �ְ�, ���̰� 100���� �۰ų� ���� ���ڿ��̴�. 
     �Է��� ������ ������ �־�����.

  #. ���
     ù° �ٺ��� �� N���� �ٿ� ���� �¶��� ���� ȸ���� ���� ��, 
     ���̰� ������ ������ ������ �� �ٿ� �� �� ���̿� �̸��� �������� ������ ����Ѵ�.

  #. ���� �Է� 1 
     3
     21 Junkyu
     21 Dohyun
     20 Sunyoung
  #. ���� ��� 1 
     20 Sunyoung
     21 Junkyu
     21 Dohyun
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//solution 1
bool myCompare(pair<pair<int, string>, int> &p1, pair<pair<int, string>, int> &p2)
{
    //���̰� ���ٸ� ==> ���� ������ ��(���������� �ȴ�.)
    if (p1.first.first == p2.first.first)
        return p1.second < p2.second;
    return p1.first.first < p2.first.first;
}

void init(vector<pair<pair<int, string>, int>>& v, int& n)
{
    for(int i = 0; i < n; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        v.push_back(make_pair(make_pair(age, name), i));
    }
}

void print(vector<pair<pair<int, string>, int>>& v)
{
    for (pair<pair<int, string>, int> p : v)
        cout << p.first.first << " " << p.first.second << "\n";
}


//===========================================================================//

//solutin 2
bool myCompare2(const pair<int, string> &p1, const pair<int, string> &p2)
{
    //stable_sort�� ����ϹǷ�, ������ �����ȴ�.
    //�������� ������ ������ �����̹Ƿ� ���� �� ���������� ���ϸ� �ȴ�.
    return p1.first < p2.first;
}

void init(vector<pair<int, string>>& v, int& n)
{
    for (int i = 0; i < n; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        v.push_back(make_pair(age, name));
    }
}

void print(vector<pair<int, string>>& v)
{
    for (pair<int, string> p : v)
        cout << p.first << " " << p.second << "\n";
}

int main()
{
    int N;
    cin >> N;

    //1. sort() ���.
    /*
    vector<pair<pair<int, string>, int>> v;
    
    init(v, N);
    sort(v.begin(), v.end(), myCompare);
    print(v);
    */

    //2. stable_sort() ���.
    /*
      stable_sort()����� ��, compare�Լ� �Ķ���Ϳ� ���۷����� ���̸� �ȵ�.
      const Ű���带 �߰��ϰ� &���̰ų�, &������ �ʾƾ��Ѵ�.
    */
    vector<pair<int, string>> v;
    init(v, N);
    stable_sort(v.begin(), v.end(), myCompare2);
    print(v);

    return 0;
}