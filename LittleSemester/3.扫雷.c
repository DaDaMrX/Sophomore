/*
3.扫雷
*/
#include <stdio.h>
#include <string.h>
#define N 110

struct Point
{
	int x, y;
};
struct Point dir[8] = { { -1, 0 },{ -1, 1 },{ 0, 1 },{ 1, 1 },
{ 1, 0 },{ 1, -1 },{ 0, -1 },{ -1, -1 } };

int n, m;
char map[N][N];

int count(int i, int j)
{
	struct Point from;
	from.x = i; from.y = j;
	int sum = 0;
	for (int k = 0; k < 8; k++)
	{
		struct Point to;
		to.x = from.x + dir[k].x; to.y = from.y + dir[k].y;
		if (map[to.x][to.y] == '*') sum++;
	}
	return sum;
}

int main()
{
	int n, m, cnt = 0;
	while (scanf("%d%d", &n, &m), n)
	{
		cnt++;
		if (cnt > 1) printf("\n");

		memset(map, 0, sizeof(map));
		for (int i = 1; i <= n; i++) scanf("%s", &map[i][1]);

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (map[i][j] == '.')
					map[i][j] = count(i, j) + '0';

		printf("Field #%d:\n", cnt);
		for (int i = 1; i <= n; i++) printf("%s\n", &map[i][1]);
	}
	return 0;
}