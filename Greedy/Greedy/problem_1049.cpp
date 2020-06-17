/*
  #. [���� :: #1049_��Ÿ�� ]

  #. ����
     Day Of Mourning�� ��Ÿ����Ʈ ���䰡 ����ϴ� ��Ÿ���� N���� ���� ��������.
     ���� ���ο� ���� ��ų� ��ü�ؾ� �Ѵ�. ����� �ǵ����̸� ���� ���� ������ �Ѵ�. 
     6�� ��Ű���� �� ���� �ְ�, 1�� �Ǵ� �� �̻��� ���� ������ �� ���� �ִ�.

     ������ ��Ÿ���� ���� N�� ��Ÿ�� �귣�� M���� �־�����, 
     ������ �귣�忡�� �Ĵ� ��Ÿ�� 6���� ����ִ� ��Ű���� ����, ������ �� ���� ������ �־��� ��, 
     ��� N���� ��� ���� �ʿ��� ���� ���� �ּҷ� �ϴ� ���α׷��� �ۼ��Ͻÿ�.

  #. �Է�
     ù° �ٿ� N�� M�� �־�����. N�� 100���� �۰ų� ���� �ڿ����̰�, M�� 50���� �۰ų� ���� �ڿ����̴�. 
     ��° �ٺ��� M���� �ٿ��� �� �귣���� ��Ű�� ���ݰ� ������ ������ �������� �����Ͽ� �־�����. 
     ������ 0���� ũ�ų� ����, 1,000���� �۰ų� ���� �����̴�.

  #. ���
     ù° �ٿ� ��Ÿ���� ��� N�� ��� ���� �ʿ��� ���� �ּڰ��� ����Ѵ�.

  #. ���� �Է� 1 
     4 2
     12 3
     15 4
  #. ���� ��� 1 
     12
  
  #. ���� �Է� 2 
     10 3
     20 8
     40 7
     60 4
  #. ���� ��� 2 
     36
  
  #. ���� �Է� 3 
     15 1
     100 40
  #. ���� ��� 3 
     300
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMin(int num1, int num2)
{
    return num1 < num2 ? num1 : num2;
}

int solution(int n, vector<int> package, vector<int> each)
{
    int answer = 0;
    //
    /*
      1. greedy�� ����
         - package�θ� ����
         - �����θ� ����
         - package + ����(���� �ٸ� �귣�� ���� ���)
       ������ ������ �ּڰ��� ���ϴ� ���̹Ƿ� 
       vector<int> package 
       vector<int> each 
       ���� ���� ���� ����.
       �� ù��° ��Ұ� ������ �ּڰ��̴�. �� �� 3���� ���ǿ��� �ּڰ��� ���Ѵ�.
       '���� �ٸ� �귣�� ������ ���'�� �ٽ��̴ϱ� ���� vector<pair<int, int>>�� ���ص� ��.
    */
    sort(package.begin(), package.end());
    sort(each.begin(), each.end());

    int group = n / 6 + 1;
    answer = getMin(package[0] * group, each[0] * n);
    answer = getMin(answer, package[0] * (group - 1) + each[0] * (n % 6));
    //
    return answer;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> package, each;

    for (int i = 0; i < M; i++)
    {
        int p1, p2;
        cin >> p1 >> p2;
        package.push_back(p1);
        each.push_back(p2);
    }

    cout << solution(N, package, each) << "\n";

    return 0;
}