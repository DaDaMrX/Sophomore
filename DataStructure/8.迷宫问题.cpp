#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

template<class T>
class Maze
{
private:
	int row, col;
	T map[1010][1010];
	int dis[1010][1010];
	T wall;

	struct Point
	{
		int x, y;
		Point() {}
		Point(int x, int y) :x(x), y(y) {}
		Point operator+(const Point& p)
		{
			return Point(x + p.x, y + p.y);
		}
		bool operator==(const Point& p)
		{
			return x == p.x && y == p.y;
		}
	};

	Point start, finish;
	stack<Point> path;
	Point dir[8];
	int _num_dirs;

	bool in_range(const Point& p)
	{
		return p.x >= 1 && p.x <= row && p.y >= 1 && p.y <= col;
	}
	bool _dfs(Point from, int step)
	{
		dis[from.x][from.y] = step;
		path.push(from);
		if (from == finish) return true;

		for (int i = 0; i < _num_dirs; i++)
		{
			Point to = from + dir[i];
			if (!in_range(to) || map[to.x][to.y] == wall || dis[to.x][to.y] != -1) continue;
			if (_dfs(to, step + 1)) return true;
		}

		dis[from.x][from.y] = -1;
		path.pop();
		return false;
	}

	void _print_path()
	{
		Point p = path.top(); path.pop();
		if (!path.empty()) _print_path();
		cout << '<' << p.x << ',' << p.y << "> ";
	}

public:
	Maze()
	{
		dir[0] = Point(1, 0);
		dir[1] = Point(0, 1);
		dir[2] = Point(-1, 0);
		dir[3] = Point(0, -1);
		_num_dirs = 4;
	}

	void input(int n, int m)
	{
		row = n; col = m;
		start = Point(1, 1);
		finish = Point(row, col);

		memset(map, 0, sizeof(map));
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++)
				cin >> map[i][j];
	}

	void set_wall(T x)
	{
		wall = x;
	}
	
	int go()
	{
		memset(dis, -1, sizeof(dis));
		while (!path.empty()) path.pop();
		_dfs(start, 0);
		return dis[finish.x][finish.y];
	}

	void print_path()
	{
		_print_path();
		cout << endl;
	}
};

Maze<int> maze;

int main()
{
	int n, m;
	cin >> n >> m;
	maze.input(n, m);
	maze.set_wall(1);

	if (maze.go() != -1)
	{
		maze.print_path();
	}
	else
	{
		cout << "There is no solution!" << endl;
	}
	return 0;
}
