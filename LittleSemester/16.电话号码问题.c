/*
16.电话号码问题
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2005

struct Node
{
	int number, cnt;
} book[N];
int sum;

unsigned char cnt[2][125005];

char map(char c)
{
	switch (c)
	{
	case '0': return '0';
	case '1': return '1';
	case '2':
	case 'A':
	case 'B':
	case 'C': return '2';
	case '3':
	case 'D':
	case 'E':
	case 'F': return '3';
	case '4':
	case 'G':
	case 'H':
	case 'I': return '4';
	case '5':
	case 'J':
	case 'K':
	case 'L': return '5';
	case '6':
	case 'M':
	case 'N':
	case 'O': return '6';
	case '7':
	case 'P':
	case 'R':
	case 'S': return '7';
	case '8':
	case 'T':
	case 'U':
	case 'V': return '8';
	case '9':
	case 'W':
	case 'X':
	case 'Y': return '9';
	default: return '#';
	}
}

void transform(char s[])
{
	int len = strlen(s);
	int t[10], p = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '-') continue;
		t[p++] = map(s[i]);
	}

	for (int i = 0; i <= 6; i++) s[i] = t[i];
	s[7] = '\0';
}

int check(char s[])
{
	int len = strlen(s);

	int i = 0;
	while (i < len && s[i] == '-') i++;
	char c = map(s[i]);
	if (c != '3' && c != '6') return 0;

	int sum = 1;
	for (i++; i < len; i++)
	{
		if (s[i] == '-') continue;
		if (map(s[i]) == '#') return 0;
		sum++;
	}
	if (sum != 7) return 0;
	return 1;
}

int cmp(const void *p1, const void* p2)
{
	return ((struct Node*)p1)->number - ((struct Node*)p2)->number;
}

int main()
{
	memset(cnt, 0, sizeof(0));
	sum = 0;

	int error = 0;
	printf("Error:\n");
	char s[25];
	while (~scanf("%s", s))
	{
		if (!check(s))
		{
			printf("%s\n", s);
			error = 1;
			continue;
		}

		transform(s);
		int number = atoi(s);
		int head = number / 1000000;
		head = (head == 3) ? 0 : 1;
		int body = number % 1000000;

		if ((cnt[head][body / 8] & (1 << (body % 8))) == 0)
		{
			cnt[head][body / 8] |= (1 << (body % 8));
			continue;
		}

		int i = 0;
		while (i < sum && number != book[i].number) i++;
		if (i < sum) book[i].cnt++;
		else
		{
			book[sum].number = number;
			book[sum].cnt = 1;
			sum++;
		}
	}
	if (!error) printf("Not found.\n");
	printf("\n");

	printf("Duplication:\n");
	if (sum == 0)
	{
		printf("Not found.\n");
		return 0;
	}
	qsort(book, sum, sizeof(book[0]), cmp);
	for (int i = 0; i < sum; i++)
		printf("%03d-%04d %d\n", book[i].number / 10000, book[i].number % 10000, book[i].cnt + 1);
	return 0;
}
