#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e2 + 10;

int a[N];
ll dp[N][N];
int dpp[N][N];

void print(int i, int j)
{
	if (i == j)
	{
		printf("A%d", i);
		return;
	}
	printf("(");
	print(i, dpp[i][j]);
	print(dpp[i][j] + 1, j);
	printf(")");
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n + 1; i++) scanf("%d", a + i);
	if (n == 1) return printf("0\n(A1)\n"), 0;
	for (int i = 1; i <= n; i++) dp[i][i] = 0;
	for (int len = 2; len <= n; len++)
		for (int i = 1; i <= n - len + 1; i++)
		{
			int j = i + len - 1;
			dp[i][j] = INF;
			for (int k = i; k < j; k++)
			{
				ll t = dp[i][k] + dp[k + 1][j] + a[i] * a[k + 1] * a[j + 1];
				if (t < dp[i][j])
				{
					dp[i][j] = t;
					dpp[i][j] = k;
				}
			}
		}
	printf("%lld\n", dp[1][n]);
	print(1, n); printf("\n");
	return 0;
}
