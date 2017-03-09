//Doubly linked list
template<class T>
class List
{
private:
	struct Node
	{
		T data;
		Node *pre, *next;
		Node() : pre(NULL), next(NULL) {};
		Node(T data, Node *pre = NULL, Node *next = NULL) : data(data), pre(pre), next(next) {};
	};
	Node *head, *tail;
	int size;

	Node *_insert_after(Node *p, T x)
	{
		size++;
		return p->next = p->next->pre = new Node(x, p, p->next);
	}
	Node *_insert_before(Node *p, T x)
	{
		size++;
		return p->pre = p->pre->next = new Node(x, p->pre, p);
	}
	Node *_forward(Node *p, int n)
	{
		for (int i = 1; i <= n; i++) p = p->next;
		return p;
	}
	Node *_back(Node *p, int n)
	{
		for (int i = 1; i <= n; i++) p = p->pre;
		return p;
	}
	T _del(Node *p)
	{
		p->pre->next = p->next;
		p->next->pre = p->pre;
		T tmp = p->data;
		delete p;
		size--;
		return tmp;
	}

public:
	List()
	{
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->pre = head;
		size = 0;
	}
	struct iterator
	{
		Node *p;
		iterator(Node *p = NULL) : p(p) {};

		iterator& operator++()
		{
			p = p->next;
			return *this
		}
		iterator operator++(int)
		{
			iterator tmp(*this);
			p = p->next;
			return tmp;
		}
		iterator operator+(int n)
		{
			Node *q = p;
			for (int i = 1; i <= n; i++) q = q->next;
			return iterator(q);
		}
		iterator& operator--()
		{
			p = p->pre;
			return *this;
		}
		iterator operator--(int)
		{
			iterator tmp(*this);
			p = p->pre;
			return tmp;
		}
		iterator operator-(int n)
		{
			Node *q = p;
			for (int i = 1; i <= n; i++) q = q->pre;
			return iterator(q);
		}
		bool operator==(iterator& it)
		{
			return p == it.p;
		}
		bool operator!=(iterator& it)
		{
			return p != it.p;
		}
		T& operator*()
		{
			return p->data;
		}
	};

	//Insert an item
	iterator insert_after(iterator it, T x)
	{
		return iterator(_insert_after(it.p, x));
	}
	iterator insert_before(iterator& it, T x)
	{
		return iterator(_insert_before(it.p, x));
	}
	T insert(int pos, T x)
	{
		Node *p = _forward(head, pos);
		return _insert_after(p, x)->data;
	}
	T insert(T x)
	{
		return insert(0, x);
	}
	T append(T x)
	{
		return _insert_before(tail, x)->data;
	}

	//Delete an item
	T del(iterator& it)
	{
		return _del(it.p);
	}
	T del(int pos)
	{
		return _del(_forward(head, pos + 1));
	}

	iterator begin()
	{
		return iterator(head->next);
	}
	iterator end()
	{
		return iterator(tail);
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