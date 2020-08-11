/*
   #. [ 백준_2644번 촌수계산 ] Silver II
   
   #. 문제
      우리 나라는 가족 혹은 친척들 사이의 관계를 촌수라는 단위로 표현하는 독특한 문화를 가지고 있다. 
	  이러한 촌수는 다음과 같은 방식으로 계산된다. 기본적으로 부모와 자식 사이를 1촌으로 정의하고 이로부터 
	  사람들 간의 촌수를 계산한다. 예를 들면 나와 아버지, 아버지와 할아버지는 각각 1촌으로 나와 할아버지는 2촌이 되고, 
	  아버지 형제들과 할아버지는 1촌, 나와 아버지 형제들과는 3촌이 된다.
	  
	  여러 사람들에 대한 부모 자식들 간의 관계가 주어졌을 때, 주어진 두 사람의 촌수를 계산하는 프로그램을 작성하시오.
   
   #. 입력
      사람들은 1, 2, 3, …, n (1≤n≤100)의 연속된 번호로 각각 표시된다. 
	  첫째 줄에는 전체 사람의 수 n이 주어지고, 
	  둘째 줄에는 촌수를 계산해야 하는 서로 다른 두 사람의 번호가 주어진다. 그리고 
	  셋째 줄에는 부모 자식들 간의 관계의 개수 m이 주어진다. 
	  넷째 줄부터는 부모 자식간의 관계를 나타내는 두 번호 x,y가 각 줄에 나온다. 
	  이때 앞에 나오는 번호 x는 뒤에 나오는 정수 y의 부모 번호를 나타낸다.
	  
	  각 사람의 부모는 최대 한 명만 주어진다.
	  
   #. 출력
      입력에서 요구한 두 사람의 촌수를 나타내는 정수를 출력한다. 
	  어떤 경우에는 두 사람의 친척 관계가 전혀 없어 촌수를 계산할 수 없을 때가 있다. 이때에는 -1을 출력해야 한다.
	  
   #. 예제 입력 1 
      9
	  7 3
	  7
	  1 2
	  1 3
	  2 7
	  2 8
	  2 9
	  4 5
	  4 6
   #. 예제 출력 1
      3
*/
/*
   #. 나의 풀이법.
      - 촌수 계산을 최단 거리로 생각하여 BFS로 풀었다.
	  - 관계 수를 입력받고, 해당 관계에 따라 family[][]라는 배열에 관계가 있으면 1표시
	  - record는 start부터 현재 번호인 사람까지의 촌수를 저장하는 배열이다.
*/
#include <iostream>
#include <queue>
using namespace std;

int n;
int family[101][101];
int record[101];

int bfs(int start, int end, int n)
{
	queue<int> q;

	q.push(start);
	//자신의 촌수 1부터 시작, return할 때, 1빼줘야 한다.
	//방문 처리겸, 기록용으로 사용한다.
	record[start] = 1;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		if (curr == end)
			return record[curr] - 1;

		for (int k = 1; k <= n; k++)
		{
			if (family[curr][k] == 1 && record[k] == 0)
			{
				record[k] = record[curr] + 1;
				q.push(k);
			}
		}
	}
	return -1;
}

int main()
{
	int n, start, end, relation;
	cin >> n;
	cin >> start >> end;
	cin >> relation;

	//1. 부모, 자식 입력 받을 때. family[][]에 연결 정보 저장(연결 되어있으면 1)
	for (int i = 0; i < relation; i++)
	{
		int parent, child;
		cin >> parent >> child;

		family[parent][child] = family[child][parent] = 1;
	}

	cout << bfs(start, end, n) << "\n";

	return 0;
}