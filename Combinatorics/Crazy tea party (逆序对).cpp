#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int ans = n & 1 ? 1 : 0;
		ans += n * (n - 2) / 4;
		printf("%d\n", ans);
	}
	return 0;
}
