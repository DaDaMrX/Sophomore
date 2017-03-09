/*
13.平面上的邮局 (曼哈顿距离)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef long long ll;
#define N 1000010

struct Point
{
	int x, y;
} p[N];

int cmpx(const void* p1, const void* p2)
{
	return ((struct Point*)p1)->x - ((struct Point*)p2)->x;
}
int cmpy(const void* p1, const void* p2)
{
	return ((struct Point*)p1)->y - ((struct Point*)p2)->y;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &p[i].x, &p[i].y);

	ll ans = 0;
	int mid = n / 2 - 1;
	qsort(p, n, sizeof(struct Point), cmpx);
	for (int i = 0; i <= mid; i++) ans += p[n - 1 - i].x - p[i].x;
	qsort(p, n, sizeof(struct Point), cmpy);
	for (int i = 0; i <= mid; i++) ans += p[n - 1 - i].y - p[i].y;
	
	printf("%lld\n", ans);
	return 0;
}