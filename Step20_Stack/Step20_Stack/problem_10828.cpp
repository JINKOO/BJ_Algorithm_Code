/*
   #. 문제 10828 :: 스택

   #. 문제
      정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
      명령은 총 다섯 가지이다.

      push X: 정수 X를 스택에 넣는 연산이다.
      pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
      size: 스택에 들어있는 정수의 개수를 출력한다.
      empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
      top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
   
   #. 입력
      첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 
      둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 
      문제에 나와있지 않은 명령이 주어지는 경우는 없다.

   #. 출력
      출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
*/
#include <iostream>
#include <string>
using namespace std;

class MyStack
{
private:
    int n;
    int top;
    int* arr;

public:
    MyStack(int n)
    {
        this->n = n;
        this->top = -1;
        arr = new int[this->n];
    }

    ~MyStack()
    {
        delete[] arr;
        arr = NULL;
    }

public:
    void push(int x)
    {
        if (isFull())
            return;
        arr[++top] = x;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << -1 << "\n";
            return;
        }
        cout << arr[top--] << "\n";
    }

    bool isEmpty()
    {
        return top == -1 ? true : false;
    }

    bool isFull()
    {
        return top ==  n - 1? true : false;
    }

    int size()
    {
        return this->top + 1;
    }

    int getTop()
    {
        return top == -1 ? -1 : arr[top];
    }
};

int main()
{

    int n;
    cin >> n;
    cin.ignore();

    MyStack *s = new MyStack(n);
    
    for (int i = 0; i < n; i++)
    {
        string operation;
        getline(cin, operation);
        if (operation.substr(0, 4) == "push")
        {
            string num_str = operation.substr(5, operation.size() - 5);
            s->push(stoi(num_str));
        }
        else if (operation == "pop")
            s->pop();
        else if (operation == "size")
            cout << s->size() << "\n";
        else if (operation == "empty")
            cout << s->isEmpty() << "\n";
        else if (operation == "top")
            cout << s->getTop() << "\n";
        else
        {
            cout << "Wrong Operation" << "\n";
            i--;
        }
    }

    delete s;
    return 0;
}





















