/*
  #. [ �Ҿ���� ��ȣ ]
  
  #. ����
     �����̴� ����� +, -, �׸��� ��ȣ�� ������ ���̰� �ִ� 50�� ���� �������. 
     �׸��� ���� �����̴� ��ȣ�� ��� ������.
     �׸��� ���� �����̴� ��ȣ�� ������ �ļ� �� ���� ���� �ּҷ� ������� �Ѵ�.
     
     ��ȣ�� ������ �ļ� �� ���� ���� �ּҷ� ����� ���α׷��� �ۼ��Ͻÿ�.

  #. �Է�
     ù° �ٿ� ���� �־�����. 
     ���� ��0��~��9��, ��+��, �׸��� ��-�������� �̷���� �ְ�, ���� ó���� ������ ���ڴ� �����̴�. 
     �׸��� �����ؼ� �� �� �̻��� �����ڰ� ��Ÿ���� �ʰ�, 5�ڸ����� ���� ���ӵǴ� ���ڴ� ����. 
     ���� 0���� ������ �� �ִ�.

  #. ���
     ù° �ٿ� ������ ����Ѵ�.
     
  #. ���� �Է� 1 
     55-50+40
  #. ���� ��� 1 
     -35
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int answer = 0;
    string n_str = "";
    bool is_minus = false;

    for (int i = 0; i <= str.length(); i++)
    {
        n_str += str[i];
        if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
        {
            cout << is_minus << "\n";
            if (is_minus)
                answer -= stoi(n_str);
            else
                answer += stoi(n_str);
            n_str = "";

            if (str[i] == '-')
                is_minus = true;
        }
    }
    cout << answer << "\n";
    return 0;
}








