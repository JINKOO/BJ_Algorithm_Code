/*
  #. [ 한 줄로 서기 ]
  
  #. 문제
     N명의 사람들은 매일 아침 한 줄로 선다. 
	 이 사람들은 자리를 마음대로 서지 못하고 오민식의 지시대로 선다.
	 
	 어느 날 사람들은 오민식이 사람들이 줄 서는 위치를 기록해 놓는다는 것을 알았다. 
	 그리고 아침에 자기가 기록해 놓은 것과 사람들이 줄을 선 위치가 맞는지 확인한다.
     사람들은 자기보다 큰 사람이 왼쪽에 몇 명 있었는지만을 기억한다. 
	 N명의 사람이 있고, 사람들의 키는 1부터 N까지 모두 다르다.

     각 사람들이 기억하는 정보가 주어질 때, 줄을 어떻게 서야 하는지 출력하는 프로그램을 작성하시오.

  #. 입력
     첫째 줄에 사람의 수 N이 주어진다. N은 10보다 작거나 같은 자연수이다. 
	 둘째 줄에는 키가 1인 사람부터 차례대로 자기보다 키가 큰 사람이 왼쪽에 몇 명이 있었는지 주어진다. 
	 i번째 수는 0보다 크거나 같고, N-i보다 작거나 같다.

  #. 출력
     첫째 줄에 줄을 선 순서대로 키를 출력한다.

  #. 예제 입력 1 
     4
	 2 1 1 0
  #. 예제 출력 1 
     4 2 1 3
*/

#include <iostream>
#include <vector>
using namespace std;

/*
  0. Greedy한 접근
    - 키가 가장 큰 사람부터 자리에 배치한다.
	  이 때, '자기보다 큰 사람이 왼쪽에 몇 명있는지'에 대한 정보가 그 사람의 위치이다.

	4
	1 2 3 4
	2 1 1 0   인 경우,

	키가 4인 사람은 0번째,
	키가 3인 사람은 1번째,
	키가 2인 사람은 1번째, 
	   이 때 키가 3인사람이 1번째 자리에 이미 있음.
	   키가 3인 사람을 뒤로 밀어야 한다. 즉 키가 3인 사람은 2번째로 이동.
	키가 1인 사람은 2번째
	   이 때 키가 3인 사람이 2번째 자리에 이미 있다.
	   키가 3인 사람을 뒤로 밀어야 한다. 즉 키가 3인 사람은 3번째로 이동.

	이 때, 키가 큰 사람 순으로 배치하므로, 키 큰 사람들을 뒤로 밀때, 
	자기보다 키가 큰 사람 명수 정보는 그대로 유지할 수 있다. 
	(뒤로 밀릴 때 원래의 자기 자리에 자신보다 작은 사람이 앞에 오므로)
*/
vector<int> solution(int n)
{
	vector<int> line(n);
	vector<int> answer(n);
	//

	for (int i = 0; i < n; i++)
		cin >> line[i];

	int pivot_index = 0;
	for (int i = n; i >= 1; i--)
	{
		int target_index = line[i - 1];
		if (answer[target_index] == 0)
		{
			answer[target_index] = i;
			pivot_index = target_index + 1;
		}
		else
		{
			for (int j = pivot_index; j > target_index; j--)
			{
				answer[j] = answer[j - 1];
			}
			answer[target_index] = i;
			pivot_index++;
		}
	}
	//
	return answer;
}

void printResult(vector<int> answer)
{
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	cout << "\n";
}

int main()
{
	int n;
	cin >> n;

	printResult(solution(n));

	return 0;
}