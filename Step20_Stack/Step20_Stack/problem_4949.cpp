/*
  #. [ �������� ���� ] 

  #. ����
     ����� ������ �� �����־�� �Ѵ�. 
     ��� ��, ���� ��� �׸��� ���� ��ȣ�� ������ ��ȣó�� ���̴�.
     
     �������� �ӹ��� � ���ڿ��� �־����� ��, ��ȣ���� ������ �� ������ �ִ��� �Ǵ��ϴ� ���α׷��� ¥�� ���̴�.
     ���ڿ��� ���ԵǴ� ��ȣ�� �Ұ�ȣ("()") �� ���ȣ("[]")�� 2�����̰�, ���ڿ��� ������ �̷�� ������ �Ʒ��� ����.
     
     - ��� ���� �Ұ�ȣ("(")�� ������ �Ұ�ȣ(")")�͸� ¦�� �̷�� �Ѵ�.
     - ��� ���� ���ȣ("[")�� ������ ���ȣ("]")�͸� ¦�� �̷�� �Ѵ�.
     - ��� ������ ��ȣ���� �ڽŰ� ¦�� �̷� �� �ִ� ���� ��ȣ�� �����Ѵ�.
     - ��� ��ȣ���� ¦�� 1:1 ��Ī�� �����ϴ�. ��, ��ȣ �ϳ��� �� �̻��� ��ȣ�� ¦�������� �ʴ´�.
     - ¦�� �̷�� �� ��ȣ�� ���� ��, �� ���̿� �ִ� ���ڿ��� ������ ������ �Ѵ�.
     - �����̸� ���� ���ڿ��� �־����� �� �������� ���ڿ����� �ƴ����� �Ǵ��غ���.

  #. �Է�
     �ϳ� �Ǵ� �����ٿ� ���ļ� ���ڿ��� �־�����. 
     �� ���ڿ��� ���� ���ĺ�, ����, �Ұ�ȣ("( )") ���ȣ("[ ]")������ �̷���� ������, ���̴� 100���ں��� �۰ų� ����.

  #. �Է��� ������������ �� �������� �� �ϳ�(".")�� ���´�.
  
  #. ���
     �� �ٸ��� �ش� ���ڿ��� ������ �̷�� ������ "yes"��, �ƴϸ� "no"�� ����Ѵ�.

  #. ���� �Է� 1 
     So when I die (the [first] I will see in (heaven) is a score list).
     [ first in ] ( first out ).
     Half Moon tonight (At least it is better than no Moon at all].
     A rope may form )( a trail in a maze.
     Help( I[m being held prisoner in a fortune cookie factory)].
     ([ (([( [ ] ) ( ) (( ))] )) ]).
      .
     .
  #. ���� ��� 1 
     yes
     yes
     no
     no
     no
     yes
     yes
  
  #. ��Ʈ
     7��°�� " ."�� ���� ��ȣ�� �ϳ��� ���� ��쵵 �������� ���ڿ��� ������ �� �ִ�.
*/

#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

string solution(string str)
{
    //
    stack<char> s;
    bool check = false;
    for (int i = 0; i < str.length(); i++)
    {
        /*if (str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']')
        {
            if (s.empty())
                s.push(str[i]);
            else
            {
                if (s.top() == '(' && str[i] == ')')
                    s.pop();
                else if (s.top() == '[' && str[i] == ']')
                    s.pop();
                else
                    s.push(str[i]);
            }
        }*/

        if (str[i] == '(' || str[i] == '[')
            s.push(str[i]);
        else if (str[i] == ')')
        {
            if (!s.empty() && s.top() == '(')
                s.pop();
            else
            {
                check = true;
                break;
            }
        }
        else if (str[i] == ']')
        {
            if (!s.empty() && s.top() == '[')
                s.pop();
            else
            {
                check = true;
                break;
            }
        }
    }
    return (!check && s.empty()) ? "yes" : "no";
    //
}

void printResult(string answer)
{
    cout << answer << "\n";
}

int main()
{
    string input_str = "";
    while (1)
    {
        getline(cin, input_str);
        if (input_str == ".")
            break;
        printResult(solution(input_str));
    }
    return 0;
}