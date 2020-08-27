#include <iostream>
#include <queue>
using namespace std;

class cmp
{
public:
	bool operator() (int x, int y)
	{
		if (abs(x) == abs(y))
			return x > y;            //��������, ������ ������, �������� ����
		else
			return abs(x) > abs(y);  //��������
	}
};

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	//���� heap, �񱳿����ڸ� ����� ���Ƿ� �Ѵ�.
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