#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
const int INF = 0x7f7f7f7f;
const int N = 1e2 + 10;

class Game
{
private:
	int a[10][10], n;

	void left()
	{
		for (int i = 0; i < n; i++)
		{
			int j = -1, k = -1;
			while (k < n)
			{
				for (k++; k < n && a[i][k] == 0; k++);
				if (k == n) break;
				j++;
				if (k != j) a[i][j] = a[i][k], a[i][k] = 0;

				bool flag = false;
				while (!flag)
				{
					for (k++; k < n && a[i][k] == 0; k++);
					if (k == n) break;
					if (a[i][k] == a[i][j])
					{
						a[i][j] *= 2;
						a[i][k] = 0;
						flag = true;
					}
					else
					{
						j++;
						if (k != j) a[i][j] = a[i][k], a[i][k] = 0;
					}
				}
			}
		}
	}

	void right()
	{
		for (int i = 0; i < n; i++)
		{
			int j = n, k = n;
			while (k >= 0)
			{
				for (k--; k >= 0 && a[i][k] == 0; k--);
				if (k < 0) break;
				j--;
				if (k != j) a[i][j] = a[i][k], a[i][k] = 0;

				bool flag = false;
				while (!flag)
				{
					for (k--; k >= 0 && a[i][k] == 0; k--);
					if (k < 0) break;
					if (a[i][k] == a[i][j])
					{
						a[i][j] *= 2;
						a[i][k] = 0;
						flag = true;
					}
					else
					{
						j--;
						if (k != j) a[i][j] = a[i][k], a[i][k] = 0;
					}
				}
			}
		}
	}

	void up()
	{
		for (int j = 0; j < n; j++)
		{
			int i = -1, k = -1;
			while (k < n)
			{
				for (k++; k < n && a[k][j] == 0; k++);
				if (k == n) break;
				i++;
				if (k != i) a[i][j] = a[k][j], a[k][j] = 0;

				bool flag = false;
				while (!flag)
				{
					for (k++; k < n && a[k][j] == 0; k++);
					if (k == n) break;
					if (a[k][j] == a[i][j])
					{
						a[i][j] *= 2;
						a[k][j] = 0;
						flag = true;
					}
					else
					{
						i++;
						if (k != i) a[i][j] = a[k][j], a[k][j] = 0;
					}
				}
			}
		}
	}

	void down()
	{
		for (int j = 0; j < n; j++)
		{
			int i = n, k = n;
			while (k >= 0)
			{
				for (k--; k >= 0 && a[k][j] == 0; k--);
				if (k < 0) break;
				i--;
				if (k != i) a[i][j] = a[k][j], a[k][j] = 0;

				bool flag = false;
				while (!flag)
				{
					for (k--; k >= 0 && a[k][j] == 0; k--);
					if (k < 0) break;
					if (a[k][j] == a[i][j])
					{
						a[i][j] *= 2;
						a[k][j] = 0;
						flag = true;
					}
					else
					{
						i--;
						if (k != i) a[i][j] = a[k][j], a[k][j] = 0;
					}
				}
			}
		}
	}

public:
	Game() {}

	Game(int t[10][10])
	{
		n = 4;
		memcpy(a, t, sizeof(a));
	}

	void move(char c)
	{
		switch (c)
		{
		case 'a': left(); break;
		case 'd': right(); break;
		case 'w': up(); break;
		case 's': down(); break;
		}
	}

	void appear(int index, int x)
	{
		index--;
		while (a[index / n][index % n]) index = (index + 1) % (n * n);
		a[index / n][index % n] = x;
	}

	void print()
	{
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n; j++)
				printf("%d ", a[i][j]);
		for (int j = 0; j < n - 1; j++) printf("%d ", a[n - 1][j]);
		printf("%d\n", a[n - 1][n - 1]);
	}
};

int main()
{
	int a[10][10], n = 4;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	getchar();

	Game game(a);
	char c;
	while (isalpha(c = getchar()))
	{
		game.move(c);
		int index, x;
		scanf("%d%d", &index, &x);
		game.appear(index, x);
		getchar();
	}

	game.print();
	return 0;
}
