/*
  #. [ ��ȣ ]

  #. ����
     ��ȣ ���ڿ�(Parenthesis String, PS)�� �� ���� ��ȣ ��ȣ�� ��(�� �� ��)�� ������ �����Ǿ� �ִ� ���ڿ��̴�. 
     �� �߿��� ��ȣ�� ����� �ٸ��� ������ ���ڿ��� �ùٸ� ��ȣ ���ڿ�(Valid PS, VPS)�̶�� �θ���. 
     �� ���� ��ȣ ��ȣ�� �� ��( )�� ���ڿ��� �⺻ VPS �̶�� �θ���. 
     ���� x �� VPS ��� �̰��� �ϳ��� ��ȣ�� ���� ���ο� ���ڿ� ��(x)���� VPS �� �ȴ�. 
     �׸��� �� VPS x �� y�� ����(concatenation)��Ų ���ο� ���ڿ� xy�� VPS �� �ȴ�. 
     ���� ��� ��(())()���� ��((()))�� �� VPS ������ ��(()(��, ��(())()))�� , 
     �׸��� ��(()�� �� ��� VPS �� �ƴ� ���ڿ��̴�. 

  #. �������� �Է����� �־��� ��ȣ ���ڿ��� VPS ���� �ƴ����� �Ǵ��ؼ� �� ����� YES �� NO �� ��Ÿ����� �Ѵ�. 

  #. �Է� 
     �Է� �����ʹ� ǥ�� �Է��� ����Ѵ�.  
     �Է��� T���� �׽�Ʈ �����ͷ� �־�����. �Է��� ù ��° �ٿ��� �Է� �������� ���� ��Ÿ���� ���� T�� �־�����. 
     �� �׽�Ʈ �������� ù° �ٿ��� ��ȣ ���ڿ��� �� �ٿ� �־�����. 
     �ϳ��� ��ȣ ���ڿ��� ���̴� 2 �̻� 50 �����̴�. 

  #. ���
     ����� ǥ�� ����� ����Ѵ�. 
     ���� �Է� ��ȣ ���ڿ��� �ùٸ� ��ȣ ���ڿ�(VPS)�̸� ��YES��, 
     �ƴϸ� ��NO���� �� �ٿ� �ϳ��� ���ʴ�� ����ؾ� �Ѵ�. 

  #. ���� �Է� 1 
     6
     (())())
     (((()())()
     (()())((()))
     ((()()(()))(((())))()
     ()()()()(()()())()
     (()((())()(
  #. ���� ��� 1 
     NO
     NO
     YES
     NO
     YES
     NO
  
  #. ���� �Է� 2 
     3
     ((
     ))
     ())(()
  #. ���� ��� 2 
     NO
     NO
     NO
*/
#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> v)
{
    vector<string> answer;
    //
    for (string str : v)
    {
        stack<int> s;
        string result;
        for (int j = 0; j < str.size(); j++)
        {
            if (s.empty())
                s.push(str[j]);
            else
            {
                if (s.top() == '(' && str[j] == ')')
                    s.pop();
                else
                    s.push(str[j]);
            }
        }
        s.empty() ? result = "YES" : result = "NO";
        answer.push_back(result);
    }
    //
    return answer;
}

void init(vector<string> &v)
{
    for (int i = 0; i < v.size(); i++)
        getline(cin, v[i]);
}

void printResult(vector<string> answer)
{
    for (string s : answer)
        cout << s << "\n";
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    vector<string> v(n);
    init(v);

    printResult(solution(v));

    return 0;
}










