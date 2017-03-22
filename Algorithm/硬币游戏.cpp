#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e3 + 10;

int n, a[N];
ll dp[N], sum[N];

int main()
{
	scanf("%d", &n);
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
	   	sum[i] = a[i] + sum[i - 1];
	}	
	dp[n] = a[n];
	dp[n - 1] = a[n - 1] + a[n];
	for (int i = n - 2; i >= 1; i--)
	{
		int x = a[i] + sum[n] - sum[i] - dp[i + 1];
		int y = a[i] + a[i + 1] + sum[n] - sum[i + 1] - dp[i + 2];
		dp[i] = max(x, y);
	}
	printf("%lld\n", dp[1]);
	return 0;
}
