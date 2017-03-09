/*
15.Ë­¸ü»úÖÇ (DP+²©ÞÄ)
*/
#include <stdio.h>
#include <stdlib.h>
#define N 50010

int a[N], n;
int dp[N];

inline int max(int a, int b) { return a > b ? a : b; }

int cmp(const void *p1, const void *p2)
{
	return *(int*)p1 - *(int*)p2;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

		qsort(a + 1, n, sizeof(a[0]), cmp);
		dp[0] = 0;
		for (int i = 1; i <= n; i++)
			dp[i] = max(dp[i - 1], a[i] - dp[i - 1]);

		printf("%d\n", dp[n]);
	}
	return 0;
}