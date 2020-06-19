/*
  #. [ �ε�ȣ ]
  
  #. ����
     �� ������ �ε�ȣ ��ȣ ��<���� ��>���� k�� ������ ������  A�� �ִ�. 
     �츮�� �� �ε�ȣ ��ȣ �յڿ� ���� �ٸ� �� �ڸ��� ���ڸ� �־ ��� �ε�ȣ ���踦 ������Ű���� �Ѵ�. 
     ���� ���, ���õ� �ε�ȣ ������ A�� ������ ���ٰ� ����. 
     
     A =>  < < < > < < > < >
     �ε�ȣ ��ȣ �յڿ� ���� �� �ִ� ���ڴ� 0���� 9������ �����̸� ���õ� ���ڴ� ��� �޶�� �Ѵ�. 
     �Ʒ��� �ε�ȣ ������ A�� ������Ű�� �� ���̴�. 
     
     3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0
     
     �� ��Ȳ���� �ε�ȣ ��ȣ�� ������ ��, ���ڸ� ��� ���̸� �ϳ��� ���� ���� �� �ִµ� 
     �� ���� �־��� �ε�ȣ ���踦 ������Ű�� ������� �Ѵ�. 
     �׷��� �־��� �ε�ȣ ���踦 �����ϴ� ������ �ϳ� �̻� �����Ѵ�. 
     ���� ��� 3456128790 �Ӹ� �ƴ϶� 5689023174�� �Ʒ��� ���� �ε�ȣ ���� A�� ������Ų��. 
     
     5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4
     
     �������� ���õ� k���� �ε�ȣ ������ �����ϴ� (k+1)�ڸ��� ���� �߿��� �ִ񰪰� �ּڰ��� ã�ƾ� �Ѵ�. 
     �ռ� ������ ��� �� �ε�ȣ�� �յڿ� ���� ���ڴ� { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }�߿��� �����ؾ� �ϸ� 
     ���õ� ���ڴ� ��� �޶�� �Ѵ�. 

  #. �Է�
     ù �ٿ� �ε�ȣ ������ ������ ��Ÿ���� ���� k�� �־�����. 
     �� ���� �ٿ��� k���� �ε�ȣ ��ȣ�� �ϳ��� ������ �ΰ� �� �ٿ� ��� ���õȴ�. k�� ������ 2 �� k �� 9 �̴�. 

  #. ���
     �������� ���õ� �ε�ȣ ���踦 �����ϴ� k+1 �ڸ��� �ִ�, �ּ� ������ ù° �ٰ� ��° �ٿ� ���� ����ؾ� �Ѵ�. 
     �� �Ʒ� ��(1)�� ���� ù �ڸ��� 0�� ��쵵 ������ ���ԵǾ�� �Ѵ�. 
     ��� �Է¿� ���� �׻� �����ϸ� ��� ������ �ϳ��� ���ڿ��� �ǵ��� �ؾ� �Ѵ�. 

  #. ���� �Է� 1 
     2
     < > 
  #. ���� ��� 1 
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
    //pivot_index�� ���� :: min_answer���� bottom���� ���� �ڸ�
    int bottom = 0, pivot_index = 0;

    /*
      3. Greedy�� ���� ������� min�� ��� min_answer[0] = 0
         �� ��, min�� 1�� �����Ѵ�.(�� ���� �ּڰ�)
    */
    min_answer[0] = bottom;
    for (int i = 0; i < str.length(); i++)
    {
        /*
          4. max�� ���� �ݴ��
            > �� ���
            - ���� �ε�ȣ index + 1���� pivot_index���� �� ĭ�� �а�(���� �����)
            - pivot_index�ڸ��� �� ���� �ּڰ�(++bottom) �ִ´�. 

            < �� ���
            - min_answer[���� �ε�ȣ index + 1]�� �� ���� �ּڰ� �ִ´�.
            - pivot_index�� ����.
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
   
    //pivot_index�� ���� :: max_answer���� top���� ���� �ڸ�
    int top = 9, pivot_index = 0;
    
    /*
      1. Greedy�� ���� ������� max�� ��� max_answer[0] = 9
         �� ��, top�� -1�� �پ���.(�� ���� �ִ�)
    */
    max_answer[0] = top;
    for (int i = 0; i < str.length(); i++)
    {
        /*
          2. < �� ���,
             - ���� �ε�ȣ index+1 ���� pivot_index�� ���� �� ĭ�� �а�(���� �����)
             - ���� �ִ�(--top)�� pivot_index�� �ִ´�. 

             > �� ���,
             - max_index[���� �ε�ȣ index+1]�� ���� �ִ��� �ִ´�.
             - pivot_index�� �����Ѵ�. (+1)
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