#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

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
		bool operator==(iterator it)
		{
			return p == it.p;
		}
		bool operator!=(iterator it)
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
	T max_to_min_insert(T x)
	{
		List<T>::iterator it = begin();
		while (it != end() && (*it).price >= x.price) it++;
		insert_before(it, x);
		return x;
	}
	T min_to_max_insert(T x)
	{
		List<T>::iterator it = begin();
		while (it != end() && (*it).price <= x.price) it++;
		insert_before(it, x);
		return x;
	}

	//Delete an item
	T del(iterator it)
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

struct Entrust
{
	int orderid;
	double price;
	int quantity;
	Entrust() {}
	Entrust(int orderid, double price, int quantity)
		:orderid(orderid), price(price), quantity(quantity) {};
};

struct Stock
{
	int id;
	List<Entrust> buy, sell;
	Stock() {};
	Stock(int id) :id(id) {};
};

class Market :protected List<Stock>
{
private:
	int _max_orderid;

	List<Stock>::iterator _find_stock(int stockid)
	{
		List<Stock>::iterator stock_iter;
		for (stock_iter = begin(); stock_iter != end(); stock_iter++)
		{
			if ((*stock_iter).id == stockid) return stock_iter;
		}
		return end();
	}

	int _new_orderid()
	{
		return ++_max_orderid;
	}

public:
	Market() :_max_orderid(0) {};

	void entrust(int stockid, double price, int quantity, char bs)
	{
		int orderid = _new_orderid();
		printf("orderid: %04d\n", orderid);

		List<Stock>::iterator stock_iter;
		stock_iter = _find_stock(stockid);
		if (stock_iter == end())
		{
			append(Stock(stockid));
			stock_iter = end() - 1;
		}

		bool flag = true;

		if (bs == 'b')
		{
			List<Entrust>& sell = (*stock_iter).sell;

			List<Entrust>::iterator entrust_iter;
			for (entrust_iter = sell.begin(); entrust_iter != sell.end(); entrust_iter++)
			{
				if ((*entrust_iter).price > price) break;
				if ((*entrust_iter).quantity > quantity) break;
				printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n", (price + (*entrust_iter).price) / 2, (*entrust_iter).quantity, orderid, (*entrust_iter).orderid);
				quantity -= (*entrust_iter).quantity;
				(*entrust_iter).quantity = 0;

				List<Entrust>::iterator iter = entrust_iter;
				entrust_iter--;
				sell.del(iter);

				if (quantity == 0)
				{
					flag = false;
					break;
				}
			}

			if (entrust_iter != sell.end() && (*entrust_iter).quantity > quantity && (*entrust_iter).price <= price)
			{
				printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n", (price + (*entrust_iter).price) / 2, quantity, orderid, (*entrust_iter).orderid);
				(*entrust_iter).quantity -= quantity;
				quantity = 0;
				flag = false;
			}

			if (flag) (*stock_iter).buy.max_to_min_insert(Entrust(orderid, price, quantity));
		}

		if (bs == 's')
		{
			List<Entrust>& buy = (*stock_iter).buy;

			List<Entrust>::iterator entrust_iter;
			for (entrust_iter = buy.begin(); entrust_iter != buy.end(); entrust_iter++)
			{
				if ((*entrust_iter).price < price) break;
				if ((*entrust_iter).quantity > quantity) break;
				printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n", (price + (*entrust_iter).price) / 2, (*entrust_iter).quantity, orderid, (*entrust_iter).orderid);
				quantity -= (*entrust_iter).quantity;
				(*entrust_iter).quantity = 0;

				List<Entrust>::iterator iter = entrust_iter;
				entrust_iter--;
				buy.del(iter);

				if (quantity == 0)
				{
					flag = false;
					break;
				}
			}

			if (entrust_iter != buy.end() && (*entrust_iter).quantity > quantity && (*entrust_iter).price >= price)
			{
				printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n", (price + (*entrust_iter).price) / 2, quantity, orderid, (*entrust_iter).orderid);
				(*entrust_iter).quantity -= quantity;
				quantity = 0;
				flag = false;
			}

			if (flag) (*stock_iter).sell.min_to_max_insert(Entrust(orderid, price, quantity));
		}
	}

	void query(int stockid)
	{
		List<Stock>::iterator stock_iter = _find_stock(stockid);
		if (stock_iter == end())
		{
			cout << "buy orders:" << endl;
			cout << "sell orders:" << endl;
			return;
		}

		List<Entrust>::iterator entrust_iter;

		cout << "buy orders:" << endl;
		List<Entrust>& buy = (*stock_iter).buy;
		for (entrust_iter = buy.begin(); entrust_iter != buy.end(); entrust_iter++)
			if ((*entrust_iter).quantity > 0)
				printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: b\n", (*entrust_iter).orderid, (*stock_iter).id, (*entrust_iter).price, (*entrust_iter).quantity);

		cout << "sell orders:" << endl;
		List<Entrust>& sell = (*stock_iter).sell;
		for (entrust_iter = sell.begin(); entrust_iter != sell.end(); entrust_iter++)
			if ((*entrust_iter).quantity > 0)
				printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: s\n", (*entrust_iter).orderid, (*stock_iter).id, (*entrust_iter).price, (*entrust_iter).quantity);
	}

	void cancel(int orderid)
	{
		List<Stock>::iterator stock_iter;
		for (stock_iter = begin(); stock_iter != end(); stock_iter++)
		{
			List<Entrust>::iterator entrust_iter;

			List<Entrust>& buy = (*stock_iter).buy;
			for (entrust_iter = buy.begin(); entrust_iter != buy.end(); entrust_iter++)
			{
				if ((*entrust_iter).orderid == orderid)
				{
					printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: b\n", (*entrust_iter).orderid, (*stock_iter).id, (*entrust_iter).price, (*entrust_iter).quantity);
					buy.del(entrust_iter);
					return;
				}
			}

			List<Entrust>& sell = (*stock_iter).sell;
			for (entrust_iter = sell.begin(); entrust_iter != sell.end(); entrust_iter++)
			{
				if ((*entrust_iter).orderid == orderid)
				{
					printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: s\n", (*entrust_iter).orderid, (*stock_iter).id, (*entrust_iter).price, (*entrust_iter).quantity);
					sell.del(entrust_iter);
					return;
				}
			}
		}
		cout << "not found" << endl;
	}
};

int main()
{
	Market market;
	int sign;
	while (scanf("%d", &sign), sign)
	{
		if (sign == 1)
		{
			int stockid, quantity;
			double price;
			char bs;
			scanf("%d%lf%d %c", &stockid, &price, &quantity, &bs);
			market.entrust(stockid, price, quantity, bs);
		}
		else if (sign == 2)
		{
			int stockid;
			scanf("%d", &stockid);
			market.query(stockid);
		}
		else if (sign == 3)
		{
			int orderid;
			scanf("%d", &orderid);
			market.cancel(orderid);
		}
	}
	return 0;
}
