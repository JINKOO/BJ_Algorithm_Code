/*
   #. [ ����_5430�� AC ]Silver II
   
   #. ����
      �����̴� �ָ��� �� ���� ��� ���ο� ��� AC�� �������. AC�� ���� �迭�� ������ �ϱ� ���� ���� ����̴�. 
      �� ���� �� ���� �Լ� R(������)�� D(������)�� �ִ�.
      �Լ� R�� �迭�� �ִ� ������ ������ ������ �Լ��̰�, D�� ù ��° ���ڸ� ������ �Լ��̴�. �迭�� ����ִµ� D�� ����� ��쿡�� ������ �߻��Ѵ�.
      �Լ��� �����ؼ� �� ���� ����� �� �ִ�. ���� ���, "AB"�� A�� ������ ������ �ٷ� �̾ B�� �����ϴ� �Լ��̴�. 
      ���� ���, "RDD"�� �迭�� ������ ���� ó�� �� ���ڸ� ������ �Լ��̴�.
      
      �迭�� �ʱⰪ�� ������ �Լ��� �־����� ��, ���� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
      
   #. �Է�
      ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. T�� �ִ� 100�̴�.
      �� �׽�Ʈ ���̽��� ù° �ٿ��� ������ �Լ� p�� �־�����. p�� ���̴� 1���� ũ�ų� ����, 100,000���� �۰ų� ����.
      ���� �ٿ��� �迭�� ����ִ� ���� ���� n�� �־�����. (0 �� n �� 100,000)
      ���� �ٿ��� [x1,...,xn]�� ���� ���·� �迭�� ����ִ� ���� �־�����. (1 �� xi �� 100)
      ��ü �׽�Ʈ ���̽��� �־����� p�� ������ �հ� n�� ���� 70���� ���� �ʴ´�.
      
   #. ���
      �� �׽�Ʈ ���̽��� ���ؼ�, �Է����� �־��� ���� �迭�� �Լ��� ������ ����� ����Ѵ�. 
      ����, ������ �߻��� ��쿡�� error�� ����Ѵ�.
     
   #. ���� �Է� 1 
      4
      RDD
      4
      [1,2,3,4]
      DD
      1
      [42]
      RRD
      6
      [1,1,2,3,5,8]
      D
      0
      []
      ���� ��� 1 
      [2,1]
      error
      [1,2,3,5,8]
      error
*/

#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;

    while (T > 0)
    {
        int n;
        string function, arr;
        cin >> function >> n;
        cin >> arr;

        deque<int> dq;
        bool reverse = false;
        bool error = false;

        string temp = "";
        for (int i = 0; i < arr.length(); i++)
        {
            if (arr[i] == '[')
                continue;
            else if ('0' <= arr[i] && arr[i] <= '9')
                temp += arr[i];
            else if (arr[i] == ',' || arr[i] == ']')
            {
                if (!temp.empty())
                {
                    dq.push_back(stoi(temp));
                    temp.clear();
                }
            }
                
        }
        
        for (int i = 0; i < function.size(); i++)
        {
            if (function[i] == 'R')
                reverse = !reverse;            //�� �κ��� ���� �߿��ߴ�

            else if (function[i] == 'D')
            {
                if (dq.empty())
                {
                    error = true;
                    break;
                }

                if (reverse)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }

        if (error)
            cout << "error" << "\n";
        else
        {
            cout << "[";
            if (reverse)
            {
                for (int i = dq.size() - 1; i >= 0; i--)
                {
                    if (i == 0)
                        cout << dq[i];
                    else
                        cout << dq[i] << ",";
                }
            }
            else
            {
                for (int i = 0; i < dq.size(); i++)
                {
                    if (i == dq.size() - 1)
                        cout << dq[i];
                    else
                        cout << dq[i] << ",";
                }
            }
            cout << "]\n";
        }
        T--;
    }

    return 0;
}