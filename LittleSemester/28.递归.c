/*
28.递归
f[n][m] = f[n - 2^17][m] ^ f[n][m - 2^17]
在存储空间上做优化
*/
#include <stdio.h>
#include <string.h>
typedef long long ll;
#define INF 0x7f7f7f7f
#define N 131180
const int maxn = 131172;

int a[110][N], c[110][110];

inline void swap(int *pa, int *pb) { int t = *pa; *pa = *pb; *pb = t; }

int main()
{
	for (int j = 2; j <= maxn; j++) scanf("%d", &a[1][j]);
	for (int i = 2; i <= 100; i++) scanf("%d", &a[i][1]);
	for (int i = 2; i <= 100; i++)
		for (int j = 2; j <= maxn; j++)
			a[i][j] = a[i - 1][j] ^ a[i][j - 1];
	for (int i = 1; i <= 100; i++)
		for (int j = 131073; j <= 131172; j++)
			c[i][j - 131072] = a[i][j];

	for (int i = 1; i <= 100; i++) swap(&a[1][i], &a[i][1]);
	for (int j = 101; j <= maxn; j++) scanf("%d", &a[1][j]);
	for (int j = 2; j <= maxn; j++)
		for (int i = 2; i <= 100; i++)
			a[i][j] = a[i - 1][j] ^ a[i][j - 1];

	for (int j = 131073; j <= maxn; j++)
		for (int i = 1; i <= 100; i++)
			c[j - 131072][i] ^= a[i][j];

	int q;
	scanf("%d", &q);
	while (q--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%d\n", c[n][m]);
	}
	return 0;
}
