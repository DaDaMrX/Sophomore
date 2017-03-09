/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int    coef, exp;
	struct node  *next;
} NODE;

void multiplication(NODE *, NODE *, NODE *);
void input(NODE *);
void output(NODE *);

void input(NODE * head)
{
	int flag, sign, sum, x;
	char c;

	NODE * p = head;

	while ((c = getchar()) != '\n')
	{
		if (c == '<')
		{
			sum = 0;
			sign = 1;
			flag = 1;
		}
		else if (c == '-') sign = -1;
		else if (c >= '0'&& c <= '9')
		{
			sum = sum * 10 + c - '0';
		}
		else if (c == ',')
		{
			if (flag == 1)
			{
				x = sign * sum;
				sum = 0;
				flag = 2;
				sign = 1;
			}
		}
		else if (c == '>')
		{
			p->next = (NODE *)malloc(sizeof(NODE));
			p->next->coef = x;
			p->next->exp = sign * sum;
			p = p->next;
			p->next = NULL;
			flag = 0;
		}
	}
}

void output(NODE * head)
{
	while (head->next != NULL)
	{
		head = head->next;
		printf("<%d,%d>,", head->coef, head->exp);
	}
	printf("\n");
}

int main()
{
	NODE * head1, *head2, *head3;

	head1 = (NODE *)malloc(sizeof(NODE));
	input(head1);

	head2 = (NODE *)malloc(sizeof(NODE));
	input(head2);

	head3 = (NODE *)malloc(sizeof(NODE));
	head3->next = NULL;
	multiplication(head1, head2, head3);

	output(head3);
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

NODE *insert(NODE *p, NODE *q)
{
	q->next = p->next;
	p->next = q;
	return q;
}

NODE* del(NODE *pp)
{
	NODE *p = pp->next;
	pp->next = p->next;
	free(p);
	return pp->next;
}

void add(NODE *head, NODE *h)
{
	NODE *p = head->next;
	NODE *pp = head;
	NODE *q = h->next;
	while (p && q)
	{
		if (p->exp < q->exp)
		{
			pp = p;
			p = p->next;
		}
		else if (q->exp < p->exp)
		{
			NODE *qq = q->next;
			pp = insert(pp, q);
			q = qq;
		}
		else
		{
			p->coef += q->coef;
			q = q->next;
			if (p->coef == 0) p = del(pp);
		}
	}

	if (q) pp->next = q;
}

void multiplication(NODE *h1, NODE *h2, NODE *h3)
{
	for (NODE *p = h1; p && p->next != NULL; p = p->next)
	{
		if (p->next->coef == 0) p->next = p->next->next;
	}
	for (NODE *p = h2; p && p->next != NULL; p = p->next)
	{
		if (p->next->coef == 0) p->next = p->next->next;
	}


	for (NODE *p = h2->next; p != NULL; p = p->next)
	{
		NODE *head = (NODE *)malloc(sizeof(NODE));
		head->next = NULL;
		NODE *tail = head;
		for (NODE *q = h1->next; q != NULL; q = q->next)
		{
			NODE *t = (NODE *)malloc(sizeof(NODE));
			t->coef = p->coef * q->coef;
			t->exp = p->exp + q->exp;
			tail = insert(tail, t);
		}
		add(h3, head);
	}
	if (h3->next == NULL)
	{
		NODE *p = (NODE *)malloc(sizeof(NODE));
		p->coef = p->exp = 0;
		insert(h3, p);
	}
}
