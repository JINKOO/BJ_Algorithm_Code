#include <iostream>
#include <vector>
using namespace std;

int chess[16][16];
bool check[16][16];
int n;

vector<int> n;

void routeCheck(int x, int y)
{
	for (int k = 1; k <= n; k++)
	{
		check[k][y] = true;
		check[x][k] = true;
		
	}
}

void clearRoute(int x, int y)
{

}

void dfs(int count)
{
	if (count == n)
	{
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (check[i][j] == false)
			{
				routeCheck(i, j);
				dfs(count + 1);
				clearRoute(i, j);
			}
		}
	}
}

int main()
{
	cin >> n;

	dfs(0, 0, 0);

	return 0;
}