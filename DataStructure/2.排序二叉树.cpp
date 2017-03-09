/*
2.排序二叉树
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

struct Node
{
    int data;
    Node *left, *right;
    Node() {}
    Node(int data, Node *left = NULL, Node *right = NULL):
        data(data), left(left), right(right) {}
};
Node *T;

void init()
{
    T = NULL;
}

void insert(Node *&T, int x)
{
    if (!T) T = new Node(x);
    else if (x < T->data) insert(T->left, x);
    else if (x > T->data) insert(T->right, x);
}

void indent(Node *T, int deep)
{
    if (!T) return;
    indent(T->left, deep + 1);
    for (int i = 1; i <= deep; i++) printf("    ");
    printf("%d\n", T->data);
    indent(T->right, deep + 1);
}

void in_order(Node *T)
{
    if (!T) return;
    in_order(T->left);
    printf(" %d", T->data);
    in_order(T->right);
}

int main()
{
    init();
    int x;
    while (scanf("%d", &x), x) 
        insert(T, x);
    indent(T, 0);
    printf("\n");
    in_order(T);
    printf("\n");
    return 0;
}
