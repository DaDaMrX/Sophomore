/*
17.有吃的 (搜索)
BFS，新鲜之处在于有些点被用作传送点
从起点终点分别DFS
*/
#include <stdio.h>
#include <string.h>
#define N 2010

struct point
{
	int x, y;
};
typedef struct point Point;
typedef struct point Vector;

Vector dir[4] = { { 0, 1 },{ 1, 0 },{ 0, -1 },{ -1, 0 } };

int n, m;
char map[N][N];
int step[N][N];

int range(Point P)
{
	return P.x >= 1 && P.x <= n && P.y >= 1 && P.y <= m;
}

Point q[N * N];
int front, rear;
int bfs(Point start, char c)
{
	memset(step, -1, sizeof(step));
	front = rear = 0;
	q[rear++] = start; step[start.x][start.y] = 0;
	while (front < rear)
	{
		Point from = q[front++];
		for (int i = 0; i < 4; i++)
		{
			Point to;
			to.x = from.x + dir[i].x; to.y = from.y + dir[i].y;
			if (!range(to) || map[to.x][to.y] == 'M' || ~step[to.x][to.y]) continue;
			step[to.x][to.y] = step[from.x][from.y] + 1;
			if (map[to.x][to.y] == c)
			{
				return step[to.x][to.y];
			}
			q[rear++] = to;
		}
	}
	return -1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", map[i] + 1);

	Point start, finish;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 'N') start.x = i, start.y = j;
			else if (map[i][j] == 'C') finish.x = i, finish.y = j;
		}

	int ans = -1;
	int tmp1 = bfs(start, 'E');
	if (tmp1 != -1)
	{
		int tmp2 = bfs(finish, 'E');
		if (tmp2 != -1) ans = tmp1 + tmp2;
	}

	int tmp = bfs(start, 'C');
	if (ans == -1) ans = tmp;
	if (tmp != -1 && tmp < ans) ans = tmp;

	if (ans == -1)
	{
		printf("Bad Eureka\n");
		return 0;
	}
	printf("%d\n", ans);
	return 0;
}
