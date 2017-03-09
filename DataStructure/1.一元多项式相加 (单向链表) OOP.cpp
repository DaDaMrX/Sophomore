#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;
typedef pair<int, int> pii;

template<class T>
class List
{
private:
	struct Node
	{
		T data;
		Node *next;
		Node() { next = NULL; }
		Node(T data, Node *next) : data(data), next(next) {};
	};
	Node *head, *tail;
	int size;

	Node *_forward(Node *p, int n)
	{
		for (int i = 1; i <= n; i++) p = p->next;
		return p;
	}
	Node *_insert_after(Node *p, T x)
	{
		p->next = new Node(x, p->next);
		size++;
		if (p == tail) tail = p->next;
		return p->next;
	}
	void _del_after(Node *p)
	{
		Node *q = p->next;
		if (q == tail) tail = p;
		p->next = q->next;
		delete q;
		size--;
	}

public:
	List()
	{
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail = head;
		size = 0;
	}

	struct iterator
	{
		Node *p;
		iterator(Node *p = NULL) : p(p) {}

		iterator& operator++()
		{
			p = p->next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator tmp(*this);
			p = p->next;
			return tmp;
		}
		iterator operator+(int n)
		{
			for (int i = 1; i <= n; i++) p = p->next;
			return iterator(p);
		}
		bool operator==(iterator &it)
		{
			return p == it.p;
		}
		bool operator!=(iterator &it)
		{
			return p != it.p;
		}
		T& operator*()
		{
			return p->data;
		}
	};

	//Insert an item
	iterator& insert_after(iterator& it, T x)
	{
		it.p = _insert_after(it.p, x);
		return it;
	}
	T insert(int pos, T x)
	{
		Node *p = _forward(head, pos);
		return _insert_after(p, x)->data;
	}
	int insert(T x)
	{
		return insert(0, x);
	}
	iterator append(T x)
	{
		return iterator(_insert_after(tail, x));
	}

	//Delete an item
	void del_after(iterator& it)
	{
		_del_after(it.p);
	}
	void del(int pos)
	{
		_del_after(_forward(head, pos));
	}

	iterator begin()
	{
		return iterator(head->next);
	}
	iterator end()
	{
		return iterator(tail->next);
	}

	int len()
	{
		return size;
	}
	bool empty()
	{
		return size == 0;
	}

	T& operator[](int i)
	{
		return _forward(head, i + 1)->data;
	}

};

class Polyn :public List<pii>
{
public:
	void input()
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int coef, expn;
			scanf("%d%d", &coef, &expn);
			append(pii(coef, expn));
		}
	}

	void print(char separate = ' ', char ending = '\n')
	{
		if (empty())
		{
			printf("<0,0>\n");
			return;
		}
		List<pii>::iterator it = begin();
		printf("<%d,%d>", (*it).first, (*it).second);
		for (it++; it != end(); it++)
			printf("%c<%d,%d>", separate, (*it).first, (*it).second);
		putchar(ending);
	}
};

bool operator<(pii p1, pii p2)
{
	return p1.second < p2.second;
}
bool operator>(pii p1, pii p2)
{
	return p2 < p1;
}
pii operator+(pii p1, pii p2)
{
	return pii(p1.first + p2.first, p1.second);
}

Polyn operator+(Polyn &polyn1, Polyn &polyn2)
{
	Polyn polyn = Polyn();
	List<pii>::iterator it1 = polyn1.begin();
	List<pii>::iterator it2 = polyn2.begin();
	while (it1 != polyn1.end() && it2 != polyn2.end())
	{
		if (*it1 < *it2)
		{
			polyn.append(*it1);
			it1++;
		}
		else if (*it1 > *it2)
		{
			polyn.append(*it2);
			it2++;
		}
		else
		{
			pii p = *it1 + *it2;
			if (p.first) polyn.append(p);
			it1++; it2++;
		}
	}
	while (it1 != polyn1.end()) polyn.append(*it1++);
	while (it2 != polyn2.end()) polyn.append(*it2++);
	return polyn;
}

int main()
{
	int Q;
	while (~scanf("%d", &Q) && Q)
	{
		Polyn polyn1 = Polyn();
		polyn1.input();
		polyn1.print(',');
		Polyn polyn2 = Polyn();
		polyn2.input();
		polyn2.print(',');
		Polyn polyn3 = Polyn();
		polyn3.input();
		polyn3.print(',');

		Polyn polyn = polyn1 + polyn2;
		polyn.print(',');
		polyn = polyn + polyn3;
		polyn.print(',');
	}
	return 0;
}
