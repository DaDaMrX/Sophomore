/*
9.琪露诺的完美算数教室--9的统计I (高精度)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long ll;
#define N 5000

inline int max(int a, int b) { return a > b ? a : b; }
inline void swap(char *p1, char *p2) { char t = *p1; *p1 = *p2; *p2 = t; }

void reverse(char s[])
{
	int len = strlen(s);
	if (len < 2) return;
	int mid = len / 2 - 1;
	for (int i = 0; i <= mid; i++) swap(&s[i], &s[len - 1 - i]);
}

const int power = 8, base = 100000000;
struct Big
{
	int a[N], len;
};

void Big_construct(struct Big *p)
{
	memset(p->a, 0, N);
	p->len = 1;
}

void Big_construct_string(struct Big *p, char s[])
{
	memset(p->a, 0, N);

	reverse(s);
	int ls = strlen(s);
	while (ls > 1 && s[ls - 1] == '0') ls--;

	p->len = -1;
	int w = 1;
	for (int i = 0; i < ls; i++)
	{
		if (i % power == 0) p->a[++(p->len)] = 0, w = 1;
		p->a[p->len] += (s[i] - '0') * w;
		w *= 10;
	}
	p->len++;
}

void Big_construct_int(struct Big *p, int x)
{
	memset(p->a, 0, N);

	p->a[0] = x;
	p->len = 0;
	while (p->a[p->len] > 0)
	{
		p->a[(p->len) + 1] = p->a[p->len] / base;
		p->a[p->len] %= base;
		(p->len)++;
	}
}

void Big_print(struct Big *p)
{
	printf("%d", p->a[(p->len) - 1]);
	for (int i = (p->len) - 2; i >= 0; i--) printf("%0*d", power, p->a[i]);
	printf("\n");
}

struct Big Big_plus(struct Big *p1, struct Big *p2)
{
	struct Big c;
	Big_construct(&c);
	c.len = max(p1->len, p2->len);
	for (int i = 0; i < c.len; i++)
	{
		ll sum = (ll)c.a[i] + p1->a[i] + p2->a[i];
		c.a[i + 1] = sum / base;
		c.a[i] = sum % base;
	}
	if (c.a[c.len] > 0) c.len++;
	return c;
}

struct Big Big_minus(struct Big *p1, struct Big *p2)
{
	struct Big c;
	Big_construct(&c);
	c.len = max(p1->len, p2->len);
	for (int i = 0; i < c.len; i++)
	{
		if (p1->a[i] < p2->a[i]) (p1->a[i + 1])--, p1->a[i] += base;
		c.a[i] = p1->a[i] - p2->a[i];
	}
	while (c.len > 1 && c.a[c.len - 1] == 0) c.len--;
	return c;
}

struct Big Big_multi(struct Big *p1, struct Big *p2)
{
	struct Big c;
	Big_construct(&c);
	c.len = p1->len + p2->len - 1;
	for (int i = 0; i < p1->len; i++)
		for (int j = 0; j < p2->len; j++)
		{
			long long sum = c.a[i + j] + (long long)p1->a[i] * p2->a[j];
			c.a[i + j + 1] += sum / base;
			c.a[i + j] = sum % base;
		}
	if (c.a[c.len]) c.len++;
	return c;
}

struct Big Big_multi_int(struct Big *p, int x)
{
	struct Big c;
	Big_construct(&c);
	for (int i = 0; i < p->len; i++)
	{
		long long sum = c.a[i] + (long long)p->a[i] * x;
		c.a[i + 1] = sum / base;
		c.a[i] = sum % base;
	}
	c.len = p->len;
	if (c.a[c.len]) c.len++;
	return c;
}

struct Big Big_power(int x, int n)
{
	struct Big a_power;
	Big_construct_int(&a_power, x);
	struct Big ans;
	Big_construct_int(&ans, 1);
	while (n)
	{
		if (n & 1) ans = Big_multi(&ans, &a_power);
		a_power = Big_multi(&a_power, &a_power);
		n >>= 1;
	}
	return ans;
}

struct Big Big_set(int n)
{
	struct Big c;
	Big_construct(&c);
	c.a[n / power] = pow(10, n % power);
	c.len = n / power + 1;
	return c;
}

struct Big count(char s[])
{
	char t[10010];
	strcpy(t, s);
	reverse(t);
	struct Big ans;
	Big_construct_int(&ans, 0);

	struct Big t1, t2, w, tmp;
	int i, len = strlen(s);
	for (i = len - 1; i >= 0; i--)
	{
		if (t[i] == '0') continue;

		t1 = Big_set(i);
		t2 = Big_power(9, i);
		w = Big_minus(&t1, &t2);

		tmp = Big_multi_int(&w, t[i] - '0');
		ans = Big_plus(&ans, &tmp);

		if (t[i] == '9') break;
	}
	if (i > 0)
	{
		Big_construct_string(&tmp, s + len - i);
		ans = Big_plus(&ans, &tmp);
	}
	return ans;
}

int check(char s[])
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		if (s[i] == '9') return 1;
	return 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s[10010];
		scanf("%s", s);
		struct Big a = count(s);
		scanf("%s", s);
		struct Big b = count(s);
		struct Big ans = Big_minus(&b, &a);
		struct Big tmp;
		Big_construct_int(&tmp, check(s));
		ans = Big_plus(&ans, &tmp);
		Big_print(&ans);
	}
	return 0;
}
