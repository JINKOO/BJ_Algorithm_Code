#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num) {

    // 1. ���ο� ���һ���
    dat[unused] = num;
    // 2. '���ο� ����' pre�� '������ ��ġ'�� addr
    pre[unused] = addr;
    // 3. '���ο� ����' nxt�� '������ ��ġ'�� nxt
    nxt[unused] = nxt[addr];
    // 5. '������ ��ġ'�� nxt�� pre�� '���ο� ����'
    if (nxt[addr] != -1)
        pre[nxt[addr]] = unused;
    // 4. '������ ��ġ'�� nxt�� '���ο� ����'
    nxt[addr] = unused;

    unused++;
}

void erase(int addr) {

    // 1. ������ ��ġ�� pre�� nxt�� ������ ��ġ�� nxt
    nxt[pre[addr]] = nxt[addr];

    // 2. ������ ��ġ�� nxt�� pre�� ������ ��ġ�� pre
    if(nxt[addr] != -1)
        pre[nxt[addr]] = pre[addr];

    // 3. unused--
    unused--;
}

void traverse() {
    int cur = nxt[0];
    while (cur != -1)
    {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert_test() {
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test() {
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}

int main(void) {
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    insert_test();
    erase_test();
}