/*
  #. [ 백준 1181_단어 정렬 Silver V ]
  
  #. 문제
     알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
     - 길이가 짧은 것부터
     - 길이가 같으면 사전 순으로
  #. 입력
     첫째 줄에 단어의 개수 N이 주어진다. (1≤N≤20,000) 
     둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 
     주어지는 문자열의 길이는 50을 넘지 않는다.

  #. 출력
     조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.
     
  #. 예제 입력 1 
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
  #. 예제 출력 1 
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
  단어 입력 받을 때, 중복 된 단어이면, vector에 삽입하지 않는다.
  find(v.begin(), v.end(), value) == v.end() 이면, v에서 value가 없다는 뜻.
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
  내가 생각한 중복 제거.
  새로운 vector에 중복 제외된 단어들 삽입.
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

    vector<string> v_str;     //단어 입력 받은 vector
    //vector<string> result;    //중복 단어 제거 vector

    //1. 기존 나의 풀이
    /*
      sort(v_str.begin(), v_str.end());
      init(result, v_str);
      sort(result.begin(), result.end(), myCompare);
      print(result);
    */

    //2. find()사용한 풀이
    init(v_str, N);
    sort(v_str.begin(), v_str.end(), myCompare);
    print(v_str);

    return 0;
}
