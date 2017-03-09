/*
1.约瑟夫问题 (单向循环链表)
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

struct Node
{
	int data;
	Node *next;
};

void insert(Node *head, Node *p)
{
	p->next = head->next;
	head->next = p;
}

Node *forward(Node *p, int step)
{
	for (int i = 2; i <= step; i++) p = p->next;
	return p;
}

void del(Node *p)
{
	Node *q = p->next;
	p->next = q->next;
	free(q);
}

int main()
{
	int n, k, m;
	scanf("%d,%d,%d", &n, &k, &m);
	if (n < 1 || k < 1 || m < 1)
	{
		printf("n,m,k must bigger than 0.\n");
		return 0;
	}
	if (k > n)
	{
		printf("k should not bigger than n.\n");
		return 0;
	}

	Node *head = (Node *)malloc(sizeof(Node));
	head->data = 1;
	head->next = NULL;

	Node *rear = (Node *)malloc(sizeof(Node));
	rear->data = n;
	insert(head, rear);
	rear->next = head;

	for (int i = n - 1; i >= 2; i--)
	{
		Node *p = (Node *)malloc(sizeof(Node));
		p->data = i;
		insert(head, p);
	}

	Node *p = forward(head, k);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		p = forward(p, m - 1);
		Node *q = p->next;
		printf("%d", q->data);
		del(p);
		p = p->next;
		cnt++;
		if (i == n || cnt == 10) printf("\n"), cnt = 0;
		else printf(" ");
	}
	return 0;
}
