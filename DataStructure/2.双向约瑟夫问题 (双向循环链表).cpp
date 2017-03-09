#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

struct Node
{
	int data;
	Node *pre, *next;
};

Node *insert(Node *p, Node *q)
{
	q->next = p->next;
	p->next = q;
	q->next->pre = q;
	q->pre = p;
	return q;
}

Node *forward(Node *p, int n)
{
	for (int i = 1; i <= n; i++) p = p->next;
	return p;
}

Node *back(Node *p, int n)
{
	for (int i = 1; i <= n; i++) p = p->pre;
	return p;
}

void del(Node *p)
{
	p->pre->next = p->next;
	p->next->pre = p->pre;
	delete p;
}

int main()
{
	int n, k, m;
	scanf("%d,%d,%d", &n, &k, &m);
	if ((n && k && m) == 0)
	{
		printf("n,m,k must bigger than 0.\n");
		return 0;
	}
	if (k > n)
	{
		printf("k should not bigger than n.\n");
		return 0;
	}

	Node *head = new Node;
	head->data = 1;
	head->next = head->pre = head;

	Node *p = head;
	for (int i = 2; i <= n; i++)
	{
		Node *q = new Node;
		q->data = i;
		p = insert(p, q);
	}

	p = forward(head, k - 1);

	Node *clockwise_del = NULL, *clockwise_start = p;
	Node *anticlockwise_del = NULL, *anticlockwise_start = p;

	int step = m - 1;
	while (clockwise_del != clockwise_start)
	{
		clockwise_del = forward(clockwise_start, step);
		clockwise_start = clockwise_del->next;

		anticlockwise_del = back(anticlockwise_start, step);
		if (anticlockwise_del == clockwise_start)
		{
			clockwise_start = clockwise_start->next;
			anticlockwise_start = clockwise_del->pre;
		}
		else
		{
			anticlockwise_start = anticlockwise_del->pre;
		}

		if (clockwise_del == anticlockwise_del)
		{
			printf("%d,", clockwise_del->data);
			del(clockwise_del);
		}
		else
		{
			printf("%d-%d,", clockwise_del->data, anticlockwise_del->data);
			del(clockwise_del);
			del(anticlockwise_del);
		}
	}
	printf("\n");
	return 0;
}
