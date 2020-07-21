/*
   #. ���� 10828 :: ����

   #. ����
      ������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
      ����� �� �ټ� �����̴�.

      push X: ���� X�� ���ÿ� �ִ� �����̴�.
      pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
      size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
      empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
      top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
   
   #. �Է�
      ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. 
      ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. 
      ������ �������� ���� ����� �־����� ���� ����.

   #. ���
      ����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
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





















