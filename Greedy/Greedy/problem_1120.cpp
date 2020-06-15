/*
  #. [ ���ڿ� �з� ]
  
  #. ����
     ���̰� N���� ���� ���ڿ� X�� Y�� ���� ��, �� ���ڿ� X�� Y�� ���̴� X[i] �� Y[i]�� i�� �����̴�. 
     ���� ���, X=jimin, Y=minji�̸�, ���� ���̴� 4�̴�.

     �� ���ڿ� A�� B�� �־�����. �̶�, A�� ���̴� B�� ���̺��� �۰ų� ����. 
     ���� A�� ���̰� B�� ���̿� ������ �� ���� ������ ���� ������ �� �� �ִ�.

     A�� �տ� �ƹ� ���ĺ��̳� �߰��Ѵ�.
     A�� �ڿ� �ƹ� ���ĺ��̳� �߰��Ѵ�.
     �̶�, A�� B�� ���̰� �����鼭, A�� B�� ���̸� �ּҷ� �ϴ� ���α׷��� �ۼ��Ͻÿ�.

  #. �Է�
     ù° �ٿ� A�� B�� �־�����. A�� B�� ���̴� �ִ� 50�̰�, A�� ���̴� B�� ���̺��� �۰ų� ����, 
     ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.

  #. ���
     A�� B�� ���̰� �����鼭, A�� B�� ���̸� �ּҰ� �ǵ��� ���� ��, �� ���̸� ����Ͻÿ�.

  #. ���� �Է� 1 
     adaabc aababbc
  #. ���� ��� 1 
     2
*/

#include <iostream>
#include <string>
using namespace std;

int getMin(int num1, int num2)
{
    return num1 < num2 ? num1 : num2;
}

int solution(string a, string b)
{
    int answer = b.length();
    //
    int diff = b.length() - a.length();
    
    /*
      a�� ���ڿ��� shift�Ͽ� �� �ڸ��� ���ڰ� �ٸ� ��츦
      count�ϰ�, �� �� �ּڰ��� ���Ѵ�.
      shift�ϴ� Ƚ�� :: ���ڿ� ������ ���̸�ŭ.
    */
    for (int i = 0; i <= diff; i++)
    {
        int count = 0;
        for (int j = 0; j < a.length(); j++)
        {
            if (a[j] != b[i + j])
                count++;
        }
        answer = getMin(answer, count);
    }
    return answer;
    //
}
int main()
{

    string str_a, str_b;
    cin >> str_a >> str_b;

    cout << solution(str_a, str_b);

    return 0;
}