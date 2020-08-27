#include <iostream>
#include <queue>
using namespace std;

class cmp
{
public:
	bool operator() (int x, int y)
	{
		if (abs(x) == abs(y))
			return x > y;            //오름차순, 절댓값이 같으면, 작은값이 먼저
		else
			return abs(x) > abs(y);  //오름차순
	}
};

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	//절댓값 heap, 비교연산자를 사용자 정의로 한다.
	priority_queue<int, vector<int>, cmp> pq;

	int n;
	cin >> n;

	while (n != 0)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			if (pq.empty())
				cout << 0 << "\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(x);
		n--;
	}

	return 0;
}