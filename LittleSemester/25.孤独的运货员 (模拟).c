/*
25.孤独的运货员 (模拟)
*/
#include <stdio.h>
#include <string.h>
typedef long long ll;
#define INF 0x7f7f7f7f
#define N 110

int q[N][1010], front[N], rear[N], Q;
int s[N], top, S;
int n, sum, ans;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &S, &Q);
		sum = 0;
		for (int i = 1; i <= n; i++)
		{
			int total;
			scanf("%d", &total);
			sum += total;
			front[i] = rear[i] = 0;
			for (int j = 1; j <= total; j++) scanf("%d", &q[i][rear[i]++]);
		}

		ans = 0; top = 0;
		int i = 0;
		while (sum)
		{
			if (i == n) i = 1;
			else i++;
			ans += 2;

			while (top && rear[i] - front[i] < Q)
			{
				if (s[top] == i) top--, sum--;
				else q[i][rear[i]++] = s[top--];
				ans++;
			}
			while (top && s[top] == i) top--, sum--, ans++;

			while (top < S && front[i] < rear[i])
			{
				s[++top] = q[i][front[i]++];
				ans++;
			}
		}

		printf("%d\n", ans - 2);
	}
	return 0;
}
