/*
6.贪婪的你 (贪心)
贪心原则：分数尽量大，时间尽量晚
排序：分数为第一关键字，从大到小，deadline为第二关键字，从大到小
依次选取每一道题，从deadline向前一直找到没有被占用的日期，标记，累加
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10100

struct Problem
{
	int point, dead;
} p[N];

int day[N], n;

int cmp(const void *p1, const void *p2)
{
	struct Problem *pa = (struct Problem*)p1;
	struct Problem *pb = (struct Problem*)p2;
	if (pa->point != pb->point) return pb->point - pa->point;
	return pb->dead - pa->dead;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i].point);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i].dead);

	qsort(p + 1, n, sizeof(struct Problem), cmp);
	memset(day, 0, sizeof(day));
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int j = p[i].dead;
		while (j > 0 && day[j]) j--;
		if (j == 0) continue;
		day[j] = 1;
		ans += p[i].point;
	}
	printf("%d\n", ans);
	return 0;
}