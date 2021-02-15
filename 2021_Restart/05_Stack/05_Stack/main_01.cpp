#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x) {
    // stack이 full인지 확인한다.
    if (pos == 1000005)
        return;

    dat[pos] = x;
    pos++;
}

void pop() {
    // stack이 empty인지 확인한다.
    if (pos == 0)
        return;
    pos--;
    dat[pos] = 0;
}

int top() {
    return dat[pos - 1];
}

void test() {
    push(5); push(4); push(3);
    cout << top() << '\n'; // 3
    pop(); pop();
    cout << top() << '\n'; // 5
    push(10); push(12);
    cout << top() << '\n'; // 12
    pop();
    cout << top() << '\n'; // 10
}

int main(void) {
    test();
}