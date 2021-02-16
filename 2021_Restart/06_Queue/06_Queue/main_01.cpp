#include <iostream>
using namespace std;

const int MX = 100005;
int arr[MX];
int head = 0, tail = 0;

void push(int x) {
    //tail¿¡ »ğÀÔÈÄ tail++
    arr[tail++] = x;
}

void pop() {
    //head++;
    head++;
}

int front() {
    return arr[head];
}

int back() {
    return arr[tail - 1];
}

void test() {
    push(10); push(20); push(30);
    cout << front() << '\n'; // 10
    cout << back() << '\n'; // 30
    pop(); pop();
    push(15); push(25);
    cout << front() << '\n'; // 30
    cout << back() << '\n'; // 25
}


int main()
{
    test();

	return 0;
}