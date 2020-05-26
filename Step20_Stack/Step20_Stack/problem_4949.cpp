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

vector<string> solution(vector<string> v)
{
    vector<string> answer;
    //
    cout << v.size() << "\n";
    for (string str : v)
    {
        stack<char> s;
        string result;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == '(' || str[j] == ')' || str[j] == '[' || str[j] == ']')
            {
                if (s.empty())
                    s.push(str[j]);
                else
                {
                    if (s.top() == '(' && str[j] == ')')
                        s.pop();
                    else if (s.top() == '[' && str[j] == ']')
                        s.pop();
                    else
                        s.push(str[j]);
                }
            }
        }
        s.empty() ? result = "YES" : result = "NO";
        answer.push_back(result);
    }
    //
    return answer;
}

void init(string &str, vector<string> &v)
{
    int start = 0, index;
    while ((index = str.find('.', start)) != std::string::npos)
    {
        string sub_str = str.substr(start, index - start);
        v.push_back(sub_str);
        start = index + 1;
    }
}

void printResult(const vector<string> &answer)
{
    for (string s : answer)
        cout << s << "\n";
}

int main()
{
    string long_str = 
    "So when I die (the [first] I will see in (heaven) is a score list).[first in](first out).Half Moon tonight(At least it is better than no Moon at all].A rope may form)(a trail in a maze.Help(I[m being held prisoner in a fortune cookie factory)].([(([([]) () (())]))]).. .";
    //getline(cin, long_str);

    vector<string> v;
    init(long_str, v);

    printResult(solution(v));

    return 0;
}