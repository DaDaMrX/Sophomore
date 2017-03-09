/*
17.前缀码判定
对每一个字符串在Huffman树中查找
    1. 如果查找到叶节点，说明不合法
    2. 如果中途出现了新分支，说明合法
    3. 如果直到字符串扫描结束都没有新分支，说明不合法
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

struct Node
{
    int data;
    Node *left, *right;
    Node(): left(NULL), right(NULL) {}
    Node(int data, Node *left = NULL, Node *right = NULL): 
        data(data), left(left), right(right) {}
};
Node *H;

void init()
{
    H = new Node(-1);
}

bool insert(char s[])
{
    int len = strlen(s);
    Node *p = H;
    bool flag = false;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '0')
        {
            if (p->left)
            {
                if (p->left->data != -1) return false;
                p = p->left;
            }
            else
            {
                flag = true;
                p = p->left = new Node(i == len - 1 ? i : -1);
            }
        }
        else
        {
            if (p->right)
            {
                if (p->right->data != -1) return false;
                p = p->right;
            }
            else
            {
                flag = true;
                p = p->right = new Node(i == len - 1 ? i : -1);
            }
        }
    }
    return flag;
}

char s[N];
int main()
{
    init();
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", s);
        if (!insert(s))
        {
            printf("%s\n", s);
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
