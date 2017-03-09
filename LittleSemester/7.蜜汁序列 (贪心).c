/*
7.蜜汁序列 (贪心)
*/
#include <stdio.h>
#define N 1000010

int n, a[N];

int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int ans = 0;
		long long sum = 0;
		for (int i = n; i > 0; i--)
		{
			sum += a[i];
			if (sum >= 0) ans++, sum = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}