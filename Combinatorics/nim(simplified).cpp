#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a;
		scanf("%d", &a);
		printf("%d\n", (a % 3 + 2) % 3);
	}
	return 0;
}
