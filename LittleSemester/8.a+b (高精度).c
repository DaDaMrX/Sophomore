/*
8.a+b (高精度)
*/
#include <stdio.h>
#include <string.h>
#define N 410

struct Big
{
	int a[N], b[N], la, lb;
} a, b, c;

char s[N];

inline int max(int a, int b) { return a > b ? a : b; }

void set_integer(struct Big *pa, char *begin, char *end)
{
	int i = 0;
	for (char *p = end - 1; p >= begin; p--, i++) pa->a[i] = *p - '0';
	pa->la = end - begin;
}

void set_decimal(struct Big *pa, char *begin, char *end)
{
	if (begin >= end)
	{
		pa->lb = 0;
		return;
	}
	int i = 0;
	for (char *p = begin; p < end; p++, i++) pa->b[i] = *p - '0';
	pa->lb = end - begin;
}

void init(struct Big *pa, char s[])
{
	memset(pa->a, 0, sizeof(pa->a));
	memset(pa->b, 0, sizeof(pa->b));
	int len = strlen(s);
	int i = 0;
	while (i < len && s[i] != '.') i++;
	set_integer(pa, s, s + i);
	set_decimal(pa, s + i + 1, s + len);
}

void print(struct Big *pa)
{
	while (pa->la > 0 && pa->a[(pa->la) - 1] == 0) (pa->la)--;
	for (int i = (pa->la - 1); i >= 0; i--) printf("%d", pa->a[i]);
	if (pa->la == 0) printf("0");
	if (pa->lb == 0) return;
	printf(".");
	for (int i = 0; i < pa->lb; i++) printf("%d", pa->b[i]);
}

void plus(struct Big *pc, struct Big *pa, struct Big *pb)
{
	memset(pc->a, 0, sizeof(pc->a));
	memset(pc->b, 0, sizeof(pc->b));
	pc->lb = max(pa->lb, pb->lb);
	for (int i = pc->lb - 1; i > 0; i--)
	{
		pc->b[i] += pa->b[i] + pb->b[i];
		pc->b[i - 1] = pc->b[i] / 10;
		pc->b[i] %= 10;
	}
	pc->b[0] += pa->b[0] + pb->b[0];
	pc->a[0] = pc->b[0] / 10;
	pc->b[0] %= 10;
	while (pc->lb > 0 && pc->b[(pc->lb) - 1] == 0) (pc->lb)--;

	pc->la = max(pa->la, pb->la);
	for (int i = 0; i < pc->la; i++)
	{
		pc->a[i] += pa->a[i] + pb->a[i];
		pc->a[i + 1] = pc->a[i] / 10;
		pc->a[i] %= 10;
	}
	if (pc->a[pc->la]) pc->la++;
}

int main()
{
	while (~scanf("%s", s))
	{
		init(&a, s);
		scanf("%s", s);
		init(&b, s);
		plus(&c, &a, &b);
		print(&c); printf("\n");
	}
	return 0;
}