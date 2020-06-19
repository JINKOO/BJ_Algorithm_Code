/*
  #. [ 부등호 ]
  
  #. 문제
     두 종류의 부등호 기호 ‘<’와 ‘>’가 k개 나열된 순서열  A가 있다. 
     우리는 이 부등호 기호 앞뒤에 서로 다른 한 자릿수 숫자를 넣어서 모든 부등호 관계를 만족시키려고 한다. 
     예를 들어, 제시된 부등호 순서열 A가 다음과 같다고 하자. 
     
     A =>  < < < > < < > < >
     부등호 기호 앞뒤에 넣을 수 있는 숫자는 0부터 9까지의 정수이며 선택된 숫자는 모두 달라야 한다. 
     아래는 부등호 순서열 A를 만족시키는 한 예이다. 
     
     3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0
     
     이 상황에서 부등호 기호를 제거한 뒤, 숫자를 모두 붙이면 하나의 수를 만들 수 있는데 
     이 수를 주어진 부등호 관계를 만족시키는 정수라고 한다. 
     그런데 주어진 부등호 관계를 만족하는 정수는 하나 이상 존재한다. 
     예를 들어 3456128790 뿐만 아니라 5689023174도 아래와 같이 부등호 관계 A를 만족시킨다. 
     
     5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4
     
     여러분은 제시된 k개의 부등호 순서를 만족하는 (k+1)자리의 정수 중에서 최댓값과 최솟값을 찾아야 한다. 
     앞서 설명한 대로 각 부등호의 앞뒤에 들어가는 숫자는 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }중에서 선택해야 하며 
     선택된 숫자는 모두 달라야 한다. 

  #. 입력
     첫 줄에 부등호 문자의 개수를 나타내는 정수 k가 주어진다. 
     그 다음 줄에는 k개의 부등호 기호가 하나의 공백을 두고 한 줄에 모두 제시된다. k의 범위는 2 ≤ k ≤ 9 이다. 

  #. 출력
     여러분은 제시된 부등호 관계를 만족하는 k+1 자리의 최대, 최소 정수를 첫째 줄과 둘째 줄에 각각 출력해야 한다. 
     단 아래 예(1)과 같이 첫 자리가 0인 경우도 정수에 포함되어야 한다. 
     모든 입력에 답은 항상 존재하며 출력 정수는 하나의 문자열이 되도록 해야 한다. 

  #. 예제 입력 1 
     2
     < > 
  #. 예제 출력 1 
     897
     021
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> minSolution(string str)
{
    vector<int> min_answer(str.length() + 1);
    //
    //pivot_index의 역할 :: min_answer에서 bottom값을 넣을 자리
    int bottom = 0, pivot_index = 0;

    /*
      3. Greedy한 접근 방식으로 min인 경우 min_answer[0] = 0
         이 후, min은 1씩 증가한다.(그 다음 최솟값)
    */
    min_answer[0] = bottom;
    for (int i = 0; i < str.length(); i++)
    {
        /*
          4. max인 경우와 반대로
            > 인 경우
            - 현재 부등호 index + 1부터 pivot_index까지 한 칸씩 밀고(덮어 씌우기)
            - pivot_index자리에 그 다음 최솟값(++bottom) 넣는다. 

            < 인 경우
            - min_answer[현재 부등호 index + 1]에 그 다음 최솟값 넣는다.
            - pivot_index값 조정.
        */
        if (str[i] == '>')
        {
            for (int j = i + 1; j > pivot_index; j--)
            {
                min_answer[j] = min_answer[j-1];
            }
            min_answer[pivot_index] = ++bottom;
        }
        else
        {
            min_answer[i + 1] = ++bottom;
            pivot_index = i + 1;
        }
    }
    //
    return min_answer;
}

vector<int> maxSolution(string str)
{
    //
    vector<int> max_answer(str.length() + 1);
   
    //pivot_index의 역할 :: max_answer에서 top값을 넣을 자리
    int top = 9, pivot_index = 0;
    
    /*
      1. Greedy한 접근 방식으로 max인 경우 max_answer[0] = 9
         이 후, top은 -1씩 줄어든다.(그 다음 최댓값)
    */
    max_answer[0] = top;
    for (int i = 0; i < str.length(); i++)
    {
        /*
          2. < 인 경우,
             - 현재 부등호 index+1 부터 pivot_index전 까지 한 칸씩 밀고(덮어 씌우기)
             - 다음 최댓값(--top)을 pivot_index에 넣는다. 

             > 인 경우,
             - max_index[현재 부등호 index+1]에 다음 최댓값을 넣는다.
             - pivot_index값 조정한다. (+1)
        */
        if (str[i] == '<')
        {
            for (int j = i + 1; j > pivot_index ; j--)
            {
                max_answer[j] = max_answer[j-1];
            }
            
            max_answer[pivot_index] = --top;
        }
        else
        {
            max_answer[i + 1] = --top;
            pivot_index = i + 1;
        }
    }
    //
    return max_answer;
}

void printResult(vector<int> answer)
{
    //
    string str_answer = "";
    for (int e : answer)
        str_answer += to_string(e);
    cout << str_answer << "\n";
}

int main()
{
    int k;
    cin >> k;
    string str = "";

    for (int i = 0; i < k; i++)
    {
        char c;
        cin >> c;
        str += c;
    }

    printResult(maxSolution(str));
    printResult(minSolution(str));

    return 0;
}