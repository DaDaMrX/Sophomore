#include <stdio.h>
#include <string.h>
typedef long long ll;
#define INF 0x7f7f7f7f
#define N 500010

int a[N], n;

inline int max(int a, int b) { return a > b ? a : b; }

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	int len = 1, ans = 0, i;
	for (i = 2; i <= n; i++)
	{
		if (a[i] != a[i - 1])
		{
			len++;
		}
		else
		{
			ans = max(ans, len / 2 + len % 2 - 1);
			if (len & 1)
			{
				for (int j = i -2; j > i - len; j--) a[j] = a[i - 1];
			}
			else
			{
				int t = len / 2;
				for (int j = i - 2; j >= i - t; j--) a[j] = a[i - 1];
				for (int j = i - len + 1; j < i - t; j++) a[j] = a[i - len];
			}
			len = 1;
		}
	}

	ans =max(ans, len / 2 + len % 2 - 1);
	if (len & 1)
	{
		for (int j = i - 2; j > i - len; j--) a[j] = a[i - 1];
	}
	else
	{
		int t = len / 2;
		for (int j = i - 2; j >= i - t; j--) a[j] = a[i - 1];
		for (int j = i - len + 1; j < i - t; j++) a[j] = a[i - len];
	}

	printf("%d\n", ans);
	for (int i = 1; i < n; i++) printf("%d ", a[i]);
	printf("%d\n", a[n]);
	return 0;
}
