//Singly linked list
template<class T>
class List
{
private:
	struct Node
	{
		T data;
		Node *next;
		Node() : next(NULL) {}
		Node(T data, Node *next = NULL) : data(data), next(next) {};
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
	T _del_after(Node *p)
	{
		Node *q = p->next;
		T tmp = q->data;
		if (q == tail) tail = p;
		p->next = q->next;
		delete q;
		size--;
		return tmp;
	}

public:
	List()
	{
		head = new Node();
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
			Node *q = p;
			for (int i = 1; i <= n; i++) q = q->next;
			return iterator(q);
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
	iterator insert_after(iterator it, T x)
	{
		return iterator(_insert_after(it.p, x));
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
		return _insert_after(tail, x)->data;
	}

	//Delete an item
	T del_after(iterator& it)
	{
		return _del_after(it.p);
	}
	T del(int pos)
	{
		return _del_after(_forward(head, pos));
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