/*
二叉树类BiTree
存储方式：二叉链表
输入：扩展的中序遍历
输出：先序遍历P，中序遍历I，后序遍历T（递归算法/非递归算法）

INPUT
abc**de*g**f***

OUTPUT
abcdegf
cbegdfa
cgefdba
abcdegf
cbegdfa
cgefdba
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

class BiTree
{
private:
	struct Node
	{
		char data;
		Node *left, *right;
	};

	char sep;
	Node *T;

	Node *create(char *&p)
	{
		if (*p == sep)
		{
			p++;
			return NULL;
		}
		Node *pNode = new Node;
		pNode->data = *p++;
		pNode->left = create(p);
		pNode->right = create(p);
		return pNode;
	}

	void pre_order(Node *T)
	{
        if (T == NULL) return;
		printf("%c", T->data);
		pre_order(T->left);
		pre_order(T->right);
	}

	void in_order(Node *T)
	{
        if (T == NULL) return;
		in_order(T->left);
		printf("%c", T->data);
		in_order(T->right);
	}

	void post_order(Node *T)
	{
        if (T == NULL) return;
		post_order(T->left);
		post_order(T->right);
		printf("%c", T->data);
	}

	void pre_order_nonrecursion(Node *T)
	{

	}

	void in_order_nonrecursion(Node *T)
	{
		stack<Node *> s;
		s.push(T);
		while (!s.empty())
		{
			while (Node *p = s.top()) s.push(p->left);
			s.pop();
			if (!s.empty())
			{
				Node *p = s.top(); s.pop();
				printf("%c", p->data);
				s.push(p->right);
			}
		}
	}

	void post_order_nonrecursion(Node *T)
	{

	}

public:
	BiTree() {}

	BiTree(char s[], char c = '*') : sep(c)
	{
		char *p = s;
		T = create(p);
	}

	void print(char c, bool recursion = true)
	{
		if (recursion)
		{
			switch (c)
			{
			case 'P': pre_order(T);	break;
			case 'I': in_order(T); break;
			case 'T': post_order(T); break;
			}
		}
		else
		{
			switch (c)
			{
			case 'P': pre_order_nonrecursion(T); break;
			case 'I': in_order_nonrecursion(T); break;
			case 'T': post_order_nonrecursion(T); break;
			}
		}
		printf("\n");
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	char s[N];
	scanf("%s", s);
	BiTree tree(s);


	tree.print('P');
	tree.print('I');
	tree.print('T');
	/*tree.print('P', false);
	tree.print('I', false);
	tree.print('T', false);*/
	return 0;
}
