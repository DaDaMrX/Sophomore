/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int         data;
	struct node * next;
} NODE;

void output(NODE *);
void change(int, int, NODE *);

void output(NODE * head)
{
	int k = 0;

	printf("0.");
	while (head->next != NULL && k<50)
	{
		printf("%d", head->next->data);
		head = head->next;
		k++;
	}
	printf("\n");
}

int main()
{
	int n, m;
	NODE * head;

	scanf("%d%d", &n, &m);
	head = (NODE *)malloc(sizeof(NODE));
	head->next = NULL;
	head->data = -1;
	change(n, m, head);
	output(head);
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

NODE *insert(NODE *p, int n)
{
	NODE *q = (NODE *)malloc(sizeof(NODE));
	q->data = n;
	q->next = p->next;
	p->next = q;
	return q;
}

void change(int n, int m, NODE *head)
{
	NODE *p = head;
	for (int i = 1; n && i <= 50; i++)
	{
		n *= 10;
		p = insert(p, n / m);
		n %= m;
	}
}
