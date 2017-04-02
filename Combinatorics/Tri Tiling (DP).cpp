#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 22;

int dp[N][2];

int main()
{
	dp[2][0] = 1; dp[2][1] = 2;
	for (int i = 4; i <= 20; i += 2)
	{
		dp[i][0] = dp[i - 2][0] + dp[i - 2][1];
		dp[i][1] = 2 * dp[i - 2][0] + 3 * dp[i - 2][1];
	}
	int n;
	while (scanf("%d", &n), ~n) 
		printf("%d\n", n & 1 ? 0 : dp[n][0] + dp[n][1]);
	return 0;
}
