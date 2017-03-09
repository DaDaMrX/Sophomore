/*
5.传送带 (贪心)
贪心策略：任意一段距离s，可以选择跑或者不跑，目标要让跑比不跑节省的时间最多
节省的时间 = 不跑花的时间 - 跑花的时间
        = s / (v+w) - s / (v+r) = s * (r-w) / ( (v+w)*(v+r) )
故v越小节省的时间越多，按v从小到大排序，依次将t用完为止
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
const double eps = 1e-10;
#define N 1000010

struct section
{
	int x, v;
} sec[N];
int X, w, r, n;
double t;

int cmp(const void *p1, const void *p2)
{
	struct section *pa = (struct section*)p1;
	struct section *pb = (struct section*)p2;
	return pa->v - pb->v;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%lf%d", &X, &w, &r, &t, &n);
		for (int i = 1; i <= n; i++)
		{
			int a, b;
			scanf("%d%d%d", &a, &b, &sec[i].v);
			sec[i].x = b - a;
			X -= sec[i].x;
		}
		sec[0].x = X; sec[0].v = 0;
		qsort(sec, n + 1, sizeof(struct section), cmp);
		double ans = 0.0;
		for (int i = 0; i <= n; i++)
		{
			if (fabs(t) < eps)
			{
				ans += (double)sec[i].x / (sec[i].v + w);
				continue;
			}

			double time = (double)sec[i].x / (sec[i].v + r);
			if (time < t + eps)
			{
				t -= time;
				ans += time;
			}
			else
			{
				ans += t + (double)(sec[i].x - (sec[i].v + r) * t) / (sec[i].v + w);
				t = 0;
			}
		}
		printf("%.6f\n", ans);
	}
	return 0;
}