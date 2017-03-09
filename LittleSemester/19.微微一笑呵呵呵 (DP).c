/*
19.΢΢һЦ�ǺǺ� (DP)
*/
#include <stdio.h>
#define N 1000010
#define MOD 666

int dp[N][2][2], n;
int top = 2;

int main()
{
	int T;
	scanf("%d", &T);
	dp[2][0][0] = dp[2][0][1] = dp[2][1][0] = dp[2][1][1] = 1;
	while (T--)
	{
		scanf("%d", &n);
		if (n == 1)
		{
			printf("2\n");
			continue;
		}
		if (n < top)
		{
			int ans = (dp[n][0][0] + dp[n][0][1] + dp[n][1][0] + dp[n][1][1]) % MOD;
			printf("%d\n", ans);
			continue;
		}
		for (int i = top + 1; i <= n; i++)
		{
			dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1]) % MOD;
			dp[i][0][1] = (dp[i - 1][1][0] + dp[i - 1][1][1]) % MOD;
			dp[i][1][0] = dp[i - 1][0][0];
			dp[i][1][1] = dp[i - 1][1][0];
		}
		int ans = (dp[n][0][0] + dp[n][0][1] + dp[n][1][0] + dp[n][1][1]) % MOD;
		printf("%d\n", ans);
		top = n;
	}
	return 0;
}