/*
  #. [ ���� ���� ]

  #. ����
     ���� (stack)�� �⺻���� �ڷᱸ�� �� �ϳ���, ��ǻ�� ���α׷��� �ۼ��� �� ���� �̿�Ǵ� �����̴�. 
	 ������ �ڷḦ �ִ� (push) �Ա��� �ڷḦ �̴� (pop) �Ա��� ���� ���� ���߿� �� �ڷᰡ ���� ���� ������ 
	 (LIFO, Last in First out) Ư���� ������ �ִ�.
	 
	 1���� n������ ���� ���ÿ� �־��ٰ� �̾� �þ�������ν�, �ϳ��� ������ ���� �� �ִ�. 
	 �̶�, ���ÿ� push�ϴ� ������ �ݵ�� ���������� ��Ű���� �Ѵٰ� ����. 
	 ������ ������ �־����� �� ������ �̿��� �� ������ ���� �� �ִ��� ������, 
	 �ִٸ� � ������ push�� pop ������ �����ؾ� �ϴ����� �˾Ƴ� �� �ִ�. �̸� ����ϴ� ���α׷��� �ۼ��϶�.

  #. �Է�
     ù �ٿ� n (1 �� n �� 100,000)�� �־�����. 
	 ��° �ٺ��� n���� �ٿ��� ������ �̷�� 1�̻� n������ ������ �ϳ��� ������� �־�����. 
	 ���� ���� ������ �� �� ������ ���� ����.

  #. ���
     �Էµ� ������ ����� ���� �ʿ��� ������ �� �ٿ� �� ���� ����Ѵ�. 
	 push������ +��, pop ������ -�� ǥ���ϵ��� �Ѵ�. �Ұ����� ��� NO�� ����Ѵ�.

  #. ���� �Է� 1 
     8
	 4
	 3
	 6
	 8
	 7
	 5
	 2
	 1
    ���� ��� 1 
	 +
	 +
	 +
	 +
	 -
	 -
	 +
	 +
	 -
	 +
	 +
	 -
	 -
	 -
	 -
	 -
  #. ���� �Է� 2 
     5
	 1
	 2
	 5
	 3
	 4
  #. ���� ��� 2 
     NO
  
  #. ��Ʈ
     1���� n������ ���� ���� ���ʷ� 
	 [push, push, push, push, pop, pop, push, push, pop, push, push, pop, pop, pop, pop, pop] 
	 ������ �����ϸ� ���� [4, 3, 6, 8, 7, 5, 2, 1]�� ���� �� �ִ�.
*/

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

void solution(vector<int> &input_num, vector<pair<int, bool>> &num)
{
	vector<string> answer;
	//
	stack<int> s;
	bool check = true;

	for (int i = 0; i < input_num.size(); i++)
	{
		int val = input_num[i];
		if (s.empty())
		{
			for (int j = 0; j < val; j++)
			{
				if (!num[j].second)
				{
					s.push(num[j].first);
					answer.push_back("+");
				}
			}
		}

		else if (s.top() < val)
		{
			for (int j = s.top(); j < val; j++)
			{
				if (!num[j].second)
				{
					s.push(num[j].first);
					answer.push_back("+");
				}
			}
		}

		if (s.top() == val)
		{
			num[s.top() - 1].second = true;
			s.pop();
			answer.push_back("-");
		}

		else
		{
			check = false;
			break;
		}
	}

	if (!check)
		cout << "NO" << "\n";
	else
	{
		for (string s : answer)
			cout << s << "\n";
	}
	//
}

void init(vector<int> &input_num, vector<pair<int, bool>> &num)
{
	for (int i = 0; i < input_num.size(); i++)
	{
		cin >> input_num[i];
		num.push_back(make_pair(i + 1, false));
	}
}

int main()
{
	int n;
	cin >> n;

	vector<int> input_num(n);
	vector<pair<int, bool>> num;

	init(input_num, num);
	solution(input_num, num);

	return 0;
}