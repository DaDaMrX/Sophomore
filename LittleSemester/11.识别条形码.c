/*
11.识别条形码
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const double eps = 1e-20;
#define N 25

int a[N], b[N], n;

int cmp(const void *p1, const void *p2)
{
	return *(int *)p1 - *(int *)p2;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}

	qsort(b + 1, n, sizeof(b[1]), cmp);
	double mid = (double)(b[1] + b[n]) / 2;
	if (b[1] / mid > 0.95 + eps)
	{
		for (int i = 1; i <= n; i++) printf("1");
		printf("\n");
		return 0;
	}

	int rmin = 1;
	while (b[rmin] < mid - eps) rmin++;
	double t = 1.05 / 0.95;
	if ((double)b[rmin - 1] / b[1] > t + eps || (double)b[n] / b[rmin] > t + eps)
	{
		printf("Bad Barcodes\n");
		return 0;
	}
	if ((double)b[n] / b[1] > 2.1 / 0.95 + eps || (double)b[rmin] / b[rmin - 1] < 1.9 / 1.05 - eps)
	{
		printf("Bad Barcodes\n");
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		if (a[i] < mid - eps) printf("0");
		else printf("1");
	}
	printf("\n");
	return 0;
}