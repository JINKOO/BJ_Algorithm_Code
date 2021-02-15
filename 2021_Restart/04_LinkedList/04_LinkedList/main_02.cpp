// STL List 사용법.

#include <iostream>
#include <list>
using namespace std;

int main()
{
	
	list<int> L = { 1,2 };  // 1 2
	//cout << *L.begin();
	list<int>::iterator t = L.begin();  // t는 1을 가리키는 중이다.

	L.push_front(10); // 10, 1, 2
	cout << *t << "\n";  //t가 가리키는 값 1출력

	L.push_back(5);  // 10 1 2 5
	L.insert(t, 6);  // t가 가리키는 곳 앞에 6을 삽입한다. 10 6 1 2 5
	t++;             // t 증가, 2를 가리키게 된다.
	t = L.erase(t);  // t가 가리키는 값 제거. 그 다음 원소인 5의 위치를 return.
	                 // 10 6 1 5, t는 5를 가리킨다.

	cout << *t << "\n";
	for (auto i : L) cout << i << ' ';
	cout << "\n";

	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
		cout << *it << ' ';

	return 0;
}