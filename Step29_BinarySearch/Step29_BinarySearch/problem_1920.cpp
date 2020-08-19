/*
   #. [ ����_1920�� �� ã�� �з� ] Silver IV
   
   #. ����
      N���� ���� A[1], A[2], ��, A[N]�� �־��� ���� ��, �� �ȿ� X��� ������ �����ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.
      
   #. �Է�
      ù° �ٿ� �ڿ��� N(1��N��100,000)�� �־�����. 
      ���� �ٿ��� N���� ���� A[1], A[2], ��, A[N]�� �־�����. 
      ���� �ٿ��� M(1��M��100,000)�� �־�����. 
      ���� �ٿ��� M���� ������ �־����µ�, �� ������ A�ȿ� �����ϴ��� �˾Ƴ��� �ȴ�. 
      ��� ������ ������ -2��31�� ���� ũ�ų� ���� 2��31�º��� �۴�.
      
   #. ���
      M���� �ٿ� ���� ����Ѵ�. �����ϸ� 1��, �������� ������ 0�� ����Ѵ�.
      
   #. ���� �Է� 1 
      5
      4 1 5 2 3
      5
      1 3 7 9 5
      ���� ��� 1 
      1
      1
      0
      0
      1
*/
/*
   #. ���� Ǯ�̹�.
      - �� ������ �ܼ� ���� �ݺ������� Ǯ �� ����.
      - �־��� ��� n = 1,000,000�̰� m�� 1,000,000�̸� ���� Ƚ���� �鸸 x �鸸�� �Ǳ� ����.
      - �̺� Ž���� ����ؾ� �Ѵ�. O(log n)
      - �̺� Ž���� ������ �Ǿ� ���� �� ����ؾ� �Ѵ�.

*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[1000000];
int b[1000000];

bool binary_search(int s, int e, int key)
{
    if (s > e)
        return false;
    int mid = (s + e) / 2;

    if (a[mid] == key)
        return true;
    else if (a[mid] < key)
        return binary_search(mid + 1, e, key);
    else
        return binary_search(s, mid - 1, key);
}

int main()
{
    vector<int> answer;

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    //���� �ؾ��Ѵ�.
    sort(a, a + n, less<int>());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        answer.push_back(binary_search(0, n - 1, b[i]));
    }

    for (int i : answer)
        cout << i << "\n";
}