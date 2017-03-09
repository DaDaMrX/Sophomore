/*
2.修剪草坪
扫描整个矩阵，对于map[i][j]，若它是所在行或列的最大值，则合法，
若它既不是所在行的最大值也不是所在列的最大值，则不合法，标记，跳出
时间复杂度O(n^3)
*/
#include <stdio.h>
#include <string.h>
#define N 110

int n, m;
int map[N][N];

int check(int i, int j, int a)
{
	int row = 1, col = 1;
	for (int k = 1; k <= n; k++)
	{
		if (map[i][k] > a) row = 0;
		if (map[k][j] > a) col = 0;
	}
	return row || col;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);

	int flag = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!check(i, j, map[i][j]))
			{
				flag = 0;
				break;
			}

	if (flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}