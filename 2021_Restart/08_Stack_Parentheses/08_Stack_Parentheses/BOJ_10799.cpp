// https://www.acmicpc.net/problem/10799
// 쇠막대기

#include <iostream>
#include <stack>
using namespace std;

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	// 1. 입력 받고
	string pipeline;
	cin >> pipeline;

	// 2. stack, 결과값 선언
	stack<char> stk;
	int answer = 0;

	// 3. 파악 시작
	for (int i = 0; i < pipeline.length(); i++)
	{
		// 3.1 문제에서 괄호쌍은 모두 맞게 나오므로 '('면 stack에 삽입
		if (pipeline[i] == '(')
			stk.push(pipeline[i]);

		// 3.2 ')'을 만나면 파악해야함 (1.레이저? or 2. 쇠막대기의 끝?) 기준 --> 바로이전 원소
		else if (pipeline[i] == ')')
		{
			// 레이저인 경우
			if (pipeline[i - 1] == '(')  
			{
				// 3.3 pop()하고, 레이저 처리 
				stk.pop();

				// 3.4 stack의 size()만큼 더한다. 현재 쌓여있는 쇠막대기를 모두 절단하니까!
				answer += stk.size();
			}
			// 쇠막대기의 끝인 경우
			else 
			{
				// 3.5 pop()하고,

				stk.pop();
				// 3.6 그냥 +1한다. 쇠막대기 1개가 절단되면 잘린개수는 한개가 늘어나므로
				answer += 1;
			}
		}
	}

	cout << answer << "\n";

	return 0;
}