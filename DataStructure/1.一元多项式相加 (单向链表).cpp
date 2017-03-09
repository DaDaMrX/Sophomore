#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

struct Node
{
	int coef, expn;
	Node *next;
};

struct Polyn
{
	Node *head, *tail;

	Polyn()
	{
		head = new Node;
		head->coef = head->expn = -1;
		head->next = NULL;
		tail = head;
	}

	Node *insert(Node *p, Node *q)
	{
		q->next = p->next;
		p->next = q;
		return q;
	}
	
	void append(Node *p)
	{
		tail = insert(tail, p);
	}
	void append(int coef, int expn)
	{
		Node *p = new Node;
		p->coef = coef;
		p->expn = expn;
		tail = insert(tail, p);
	}

	void print()
	{
		Node *p = head->next;
		if (p == NULL)
		{
			printf("<0,0>\n");
			return;
		}
		printf("<%d,%d>", p->coef, p->expn);

		for (p = p->next; p != NULL; p = p->next)
		{
			printf(",<%d,%d>", p->coef, p->expn);
		}
		printf("\n");
	}
};

Polyn operator+(Polyn &pa, Polyn &pb)
{
	Polyn pc = Polyn();
	Node *qa = pa.head->next, *qb = pb.head->next;
	while (qa && qb)
	{
		if (qa->expn < qb->expn)
		{
			Node *p = qa;
			qa = qa->next;
			pc.append(p);
		}
		else if (qb->expn < qa->expn)
		{
			Node *p = qb;
			qb = qb->next;
			pc.append(p);
		}
		else
		{
			Node *p = new Node;
			p->coef = qa->coef + qb->coef;
			p->expn = qa->expn;
			p->next = NULL;
			if (p->coef != 0) pc.append(p);
			qa = qa->next;
			qb = qb->next;
		}
	}

	if (qa) pc.tail->next = qa;
	if (qb) pc.tail->next = qb;
	return pc;
}

int main()
{
	int q;
	while (~scanf("%d", &q) && q)
	{
		Polyn pa = Polyn();
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int coef, expn;
			scanf("%d%d", &coef, &expn);
			pa.append(coef, expn);
		}
		pa.print();

		Polyn pb = Polyn();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int coef, expn;
			scanf("%d%d", &coef, &expn);
			pb.append(coef, expn);
		}
		pb.print();

		Polyn pc = Polyn();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int coef, expn;
			scanf("%d%d", &coef, &expn);
			pc.append(coef, expn);
		}
		pc.print();

		Polyn p = pa + pb;
		p.print();
		p = p + pc;
		p.print();
	}
	return 0;
}
