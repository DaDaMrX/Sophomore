#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 20 + 5;

ll dp[N][N][2];
void init(int n)
{
	memset(dp, 0, sizeof(dp));
	dp[1][1][0] = dp[1][1][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
		{
			for (int k = 1; k < j; k++) dp[i][j][1] += dp[i - 1][k][0];
			for (int k = j; k < i; k++) dp[i][j][0] += dp[i - 1][k][1];
		}
}

int main()
{
	init(20);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n; ll c;
		scanf("%d%lld", &n, &c);
		int mp[N];
		for (int i = 1; i <= n; i++) mp[i] = i;
		int ans[N];

		int j;
		for (j = 1; j <= n; j++)
		{
			ll sum = dp[n][j][0] + dp[n][j][1];
			if (sum >= c) break;
			c -= sum;
		}
		ans[n] = mp[j];
		for (; j < n; j++) mp[j] = mp[j + 1];

		for (int i = n - 1; i >= 1; i--)
		{
			int j;
			for (j = 1; j <= i; j++)
			{
				if (i <= n - 2 && (mp[j] - ans[i + 1]) * (ans[i + 1] - ans[i + 2]) > 0) continue;
				if (mp[j] > ans[i + 1])
				{
					if (dp[i][j][1] >= c) break;
					c -= dp[i][j][1];
				}
				else
				{
					if (dp[i][j][0] >= c) break;
					c -= dp[i][j][0];
				}
			}
			ans[i] = mp[j];
			for (; j < i; j++) mp[j] = mp[j + 1];
		}
		for (int i = n; i >= 1; i--) printf("%d ", ans[i]); printf("\n");
	}
	return 0;
}
