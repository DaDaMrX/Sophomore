/*
22.新真感情醉酒
*/
#include <stdio.h>
#include <string.h>
typedef long long ll;
#define INF 0x7f7f7f7f
#define N 1000010

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	ll s;
	int n, m;
	while (~scanf("%lld%d%d", &s, &n, &m))
	{
		if (s & 1)
		{
			printf("ZGQ drinks off !\n");
			continue;
		}
		s /= gcd(n, m);
		if (s & 1)
		{
			printf("ZGQ drinks off !\n");
			continue;
		}
		printf("%lld\n", s - 1);
	}
	return 0;
}
