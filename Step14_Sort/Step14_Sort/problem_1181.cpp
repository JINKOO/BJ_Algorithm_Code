/*
  #. [ ���� 1181_�ܾ� ���� Silver V ]
  
  #. ����
     ���ĺ� �ҹ��ڷ� �̷���� N���� �ܾ ������ �Ʒ��� ���� ���ǿ� ���� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
     - ���̰� ª�� �ͺ���
     - ���̰� ������ ���� ������
  #. �Է�
     ù° �ٿ� �ܾ��� ���� N�� �־�����. (1��N��20,000) 
     ��° �ٺ��� N���� �ٿ� ���� ���ĺ� �ҹ��ڷ� �̷���� �ܾ �� �ٿ� �ϳ��� �־�����. 
     �־����� ���ڿ��� ���̴� 50�� ���� �ʴ´�.

  #. ���
     ���ǿ� ���� �����Ͽ� �ܾ���� ����Ѵ�. ��, ���� �ܾ ���� �� �Էµ� ��쿡�� �� ������ ����Ѵ�.
     
  #. ���� �Է� 1 
     13
     but
     i
     wont
     hesitate
     no
     more
     no
     more
     it
     cannot
     wait
     im
     yours
  #. ���� ��� 1 
     i
     im
     it
     no
     but
     more
     wait
     wont
     yours
     cannot
     hesitate
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myCompare(string& s1, string& s2)
{
    if (s1.length() == s2.length())
        return s1 < s2;
    return s1.length() < s2.length();
}

/*
  �ܾ� �Է� ���� ��, �ߺ� �� �ܾ��̸�, vector�� �������� �ʴ´�.
  find(v.begin(), v.end(), value) == v.end() �̸�, v���� value�� ���ٴ� ��.
*/
void init(vector<string>& v_str, int& n)
{
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if(find(v_str.begin(), v_str.end(), str) == v_str.end())
            v_str.push_back(str);
    }
}

/*
  ���� ������ �ߺ� ����.
  ���ο� vector�� �ߺ� ���ܵ� �ܾ�� ����.
*/
/*
void init(vector<string>& dest, vector<string>& origin)
{
    for (int i = 0; i < origin.size(); i++)
    {
        if (dest.empty())
        {
            dest.push_back(origin[i]);
            continue;
        }

        if (dest.back() != origin[i])
            dest.push_back(origin[i]);
    }
}
*/

void print(vector<string> &result)
{
    for (string s : result)
        cout << s << "\n";
}

int main()
{
    int N;
    cin >> N;

    vector<string> v_str;     //�ܾ� �Է� ���� vector
    //vector<string> result;    //�ߺ� �ܾ� ���� vector

    //1. ���� ���� Ǯ��
    /*
      sort(v_str.begin(), v_str.end());
      init(result, v_str);
      sort(result.begin(), result.end(), myCompare);
      print(result);
    */

    //2. find()����� Ǯ��
    init(v_str, N);
    sort(v_str.begin(), v_str.end(), myCompare);
    print(v_str);

    return 0;
}
