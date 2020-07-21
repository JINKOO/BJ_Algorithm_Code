/*
  #. [ 2108��_����� Silver IV ]

  #. ����
     ���� ó���ϴ� ���� ����п��� ����� �߿��� ���̴�. 
     ����п��� N���� ���� ��ǥ�ϴ� �⺻ ��谪���� ������ ���� �͵��� �ִ�. ��, N�� Ȧ����� ��������.

     ������ : N���� ������ ���� N���� ���� ��
     �߾Ӱ� : N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
     �ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��
     ���� : N���� ���� �� �ִ񰪰� �ּڰ��� ����
       
     N���� ���� �־����� ��, �� ���� �⺻ ��谪�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

  #. �Է�
     ù° �ٿ� ���� ���� N(1 �� N �� 500,000)�� �־�����. �� ���� N���� �ٿ��� �������� �־�����. 
     �ԷµǴ� ������ ������ 4,000�� ���� �ʴ´�.

  #. ���
     ù° �ٿ��� �������� ����Ѵ�. �Ҽ��� ���� ù° �ڸ����� �ݿø��� ���� ����Ѵ�.
     ��° �ٿ��� �߾Ӱ��� ����Ѵ�.
     ��° �ٿ��� �ֺ��� ����Ѵ�. ���� �� ���� ������ �ֺ� �� �� ��°�� ���� ���� ����Ѵ�.
     ��° �ٿ��� ������ ����Ѵ�.

  #. ���� �Է� 1 
     5
     1 3 8 -2 2
  #. ���� ��� 1 
     2
     2
     1
     10

  #. ���� �Է� 2 
     1
     4000
  #. ���� ��� 2 
     4000
     4000
     4000
     0

 #. ���� �Է� 3 
    5
    -1 -2 -3 -1 -2
 #. ���� ��� 3 
    -2
    -2
    -1
    2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> v;

bool myCompare(pair<int, int>& p1, pair<int, int>& p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

//�Ҽ� ù° �ڸ� �ݿø�.
double getAverage()
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
        sum += v[i];
    return round((double)sum / v.size());
}

int getMedian()
{
    sort(v.begin(), v.end());
    return v[v.size() / 2];
}

/*
  #. �ֺ� ���� ��...
   - ���� ���� ��.
     : vector<pair<int, int>> mode�� ����ϰ��� ������, ���� �ݺ����� ����Ͽ�,
       ���� ���� v���� ������ count�Ͽ� mode�� �����Ϸ� ��.

   - ���� Ǯ��
     : mode�� ���� ���� ��, mode�� ���� �ֱٿ� ���� ���� first�� v[i]�� ���Ѵ�.
       count���� �ʿ� ����.
     : �̰��� ������ ������, v�� �̸� �����Ͽ��� �����̴�.
     ex) v : 1 1 2 2 2 3 3 3
         mode : (1, 2), (2, 3), (3, 4);


*/
int getMode()
{
    //first : v[i] / second : count
    vector<pair<int, int>> mode;
    for (int i = 0; i < v.size(); i++)
    {
        //ù��°�� ������ ����.
        if (mode.empty())
            mode.push_back(make_pair(v[i], 1));

        //�ι�° ���ʹ� mode�� ���� �ֱ� ���� ���ϸ鼭,
        else
        {
            //���� �����̸�, �������� �ʰ�, �� ������ ���� second++
            if (mode.back().first == v[i])
                mode.back().second++;
            //�ٸ� �����̸�, ����
            else
                mode.push_back(make_pair(v[i], 1));
        }
    }

    /*for (int i = 0; i < mode.size(); i++)
    {
        cout << "(" << mode[i].first << ", " << mode[i].second << ")" << "\n";
    }*/

    sort(mode.begin(), mode.end(), myCompare);

    if (mode.size() == 1)
        return mode[0].first;
    else if (mode[0].second == mode[1].second)
        return mode[1].first;
    else
        return mode[0].first;
}

int getRange()
{
    return v[v.size() - 1] - v[0];
}

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
}

int main()
{
    int N;
    cin >> N;

    init(N);

    cout << getAverage() << "\n";
    cout << getMedian() << "\n";
    cout << getMode() << "\n";
    cout << getRange() << "\n";

    return 0;
}