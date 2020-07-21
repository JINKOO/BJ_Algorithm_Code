#include <iostream>

class ArrayStack
{
private:
	int size;
	int top;
	int *array;

public:
	ArrayStack(int size)
	{
		this->size = size;
		this->top = -1;
		this->array = new int[size];
	}

	~ArrayStack()
	{
		delete[] array;
		array = NULL;
	}

public:
	void push(int data)
	{
		if (isFull())
			return;
		array[++top] = data;
	}

	void pop()
	{
		if (isEmpty())
			return;
		array[top--] = 0;
	}

	bool isEmpty() { return this->top == -1 ? true : false; }
	bool isFull() { return top == this->size ? true : false; }

	void printElements()
	{
		for (int i = top; i >= 0; i--)
			std::cout << "   " << array[i] << "\n";
		std::cout << "|_____|" << "\n";
		std::cout << "\n";
	}
};

int main()
{
	ArrayStack *stack = new ArrayStack(7);
	stack->push(3);
	stack->push(2);
	stack->push(1);
	stack->printElements();
	
	stack->pop();
	stack->printElements();
	return 0;
}