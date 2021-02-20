// https://www.acmicpc.net/problem/10799
// �踷���

#include <iostream>
#include <stack>
using namespace std;

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	// 1. �Է� �ް�
	string pipeline;
	cin >> pipeline;

	// 2. stack, ����� ����
	stack<char> stk;
	int answer = 0;

	// 3. �ľ� ����
	for (int i = 0; i < pipeline.length(); i++)
	{
		// 3.1 �������� ��ȣ���� ��� �°� �����Ƿ� '('�� stack�� ����
		if (pipeline[i] == '(')
			stk.push(pipeline[i]);

		// 3.2 ')'�� ������ �ľ��ؾ��� (1.������? or 2. �踷����� ��?) ���� --> �ٷ����� ����
		else if (pipeline[i] == ')')
		{
			// �������� ���
			if (pipeline[i - 1] == '(')  
			{
				// 3.3 pop()�ϰ�, ������ ó�� 
				stk.pop();

				// 3.4 stack�� size()��ŭ ���Ѵ�. ���� �׿��ִ� �踷��⸦ ��� �����ϴϱ�!
				answer += stk.size();
			}
			// �踷����� ���� ���
			else 
			{
				// 3.5 pop()�ϰ�,

				stk.pop();
				// 3.6 �׳� +1�Ѵ�. �踷��� 1���� ���ܵǸ� �߸������� �Ѱ��� �þ�Ƿ�
				answer += 1;
			}
		}
	}

	cout << answer << "\n";

	return 0;
}