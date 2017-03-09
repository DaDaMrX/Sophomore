/*
21.连连看游戏辅助 (BFS)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 110;

struct Point
{
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
};
typedef Point Vector;
Point operator+(Point& p, Vector& v)
{
	return Point(p.x + v.x, p.y + v.y);
}
bool operator==(Point &p1, Point &p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}
bool operator!=(Point &p1, Point &p2)
{
	return !(p1 == p2);
}
//方向向量, 0,1,2,3分别代表下，右，上，左
Vector dir[4];
void init_dir()
{
	dir[0] = Vector(1, 0);
	dir[1] = Vector(0, 1);
	dir[2] = Vector(-1, 0);
	dir[3] = Vector(0, -1);
}

int n, m;
int map[N][N];
Point start, finish;

bool in_range(Point& to)
{
	return to.x >= 0 && to.x < n && to.y >= 0 && to.y < m;
}

queue<Point> q;
int step[N][N], direct[N][N]; 
//step[x][y]记录起点到(x,y)点转弯次数
//direct[x][y]记录起走到(x,y)点的方向
bool bfs(Point start)
{
	memset(direct, -1, sizeof(direct));
	memset(step, -1, sizeof(step));
	while (!q.empty()) q.pop();
	init_dir();

	q.push(start); step[start.x][start.y] = 0;
	while (!q.empty())
	{
		Point from = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			Point to = from + dir[i];
			if (!in_range(to)) continue; //出界
			if (to != finish && map[to.x][to.y]) continue; //遇到墙
			if (step[to.x][to.y] != -1) continue; //之前走过
			if (step[from.x][from.y] == 2 && i != direct[from.x][from.y]) continue; //转弯数大于2
			if (to == finish) return true; //到终点

            //其他情况，正常入队
			q.push(to); direct[to.x][to.y] = i;
			if (direct[from.x][from.y] != -1 && i != direct[from.x][from.y]) step[to.x][to.y] = step[from.x][from.y] + 1;
			else step[to.x][to.y] = step[from.x][from.y];
		}
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	scanf("%d%d", &start.x, &start.y);
	scanf("%d%d", &finish.x, &finish.y);

	if (map[start.x][start.y] != map[finish.x][finish.y]) printf("FALSE\n");
	else printf("%s\n", bfs(start) ? "TRUE" : "FALSE");
	return 0;
}
