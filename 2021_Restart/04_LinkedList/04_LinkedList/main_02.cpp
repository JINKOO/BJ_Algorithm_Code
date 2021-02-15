// STL List ����.

#include <iostream>
#include <list>
using namespace std;

int main()
{
	
	list<int> L = { 1,2 };  // 1 2
	//cout << *L.begin();
	list<int>::iterator t = L.begin();  // t�� 1�� ����Ű�� ���̴�.

	L.push_front(10); // 10, 1, 2
	cout << *t << "\n";  //t�� ����Ű�� �� 1���

	L.push_back(5);  // 10 1 2 5
	L.insert(t, 6);  // t�� ����Ű�� �� �տ� 6�� �����Ѵ�. 10 6 1 2 5
	t++;             // t ����, 2�� ����Ű�� �ȴ�.
	t = L.erase(t);  // t�� ����Ű�� �� ����. �� ���� ������ 5�� ��ġ�� return.
	                 // 10 6 1 5, t�� 5�� ����Ų��.

	cout << *t << "\n";
	for (auto i : L) cout << i << ' ';
	cout << "\n";

	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
		cout << *it << ' ';

	return 0;
}