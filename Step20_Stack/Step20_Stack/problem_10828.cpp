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

class ArrayStack
{
private:
	int size;
	int top;
	int* array;

public:
	ArrayStack(int size)
	{
		this->size = size;
		this->top = -1;
		this->array = new int[size];
	}

	~ArrayStack()
	{
		std::cout << "~destructor() called" << "\n";
		delete[] array;
		array = NULL;
	}

public:
	void push(int data)
	{
		if (!isFull())
			array[++top] = data;
	}

	void pop()
	{
		if (!isEmpty())
			top--;
		else
			std::cout << "0" << "\n";
	}

	int size() { return this->top + 1;}

	bool isEmpty() { return this->top == -1 ? true : false; }

	bool isFull() { return top == this->size ? true : false; }

	void printElements()
	{
		for (int i = top; i >= 0; i--)
			std::cout << array[i] << "\n";
		std::cout << "\n";
	}
};


int main()
{
    int N;
    std::cin >> N;
    std::cin.clear();

	ArrayStack *stack = new ArrayStack(N);

    for (int i = 0; i <= N; i++)
    {
        std::string operation;
        std::getline(std::cin, operation);

    }

	delete stack;
	return 0;
}





















