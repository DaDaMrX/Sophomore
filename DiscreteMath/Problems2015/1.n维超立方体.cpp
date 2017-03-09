/********************************************************************************
1.n维超立方体

立方体，每条边长均为1，即每条边的两个端点坐标只有0和1，故考虑与二进制有关。
每一个维度上，只有0和1两种选择，每增加一维，就增加一个二进制位。一个二进制位控制一个维度。
每个顶点的二进制编号，既是它的编号，又是它的坐标。
相邻的两个定点，或者说从一个点走到相邻的点，有且仅有一个维度坐标发生变化，
即：两个顶点相邻 <==> 这两个顶点编号的二进制表示（其坐标）有且仅有一位不同

方法一：暴力枚举每组点的组合，若异或结果的二进制表示中有且仅有一个1，建边。O(2^n^2)
方法二：每个点有且仅有n个点与其相邻，对每个点二进制编号中的每一位取反，建边。O(n^2)
方法三：下文代码中的方法，二分递归，一维一维地拆解。O(n*2^n)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 130;

int n, a[N], adj[N][N];

void build(int left, int right)
{
    if (left == right) return;
    int mid = left + right >> 1;
    int d = right - left + 1 >> 1;
    for (int i = left; i <= mid; i++) 
        adj[i][i + d] = adj[i + d][i] = 1;
    build(left, mid);
    build(mid + 1, right);
}

int main() 
{
    scanf("%d", &n);
    int s = 1 << n;
    for (int i = 0; i < s; i++) scanf("%d", a + i);

    memset(adj, 0, sizeof(adj));
    build(0, s - 1);

    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
            printf("%d%c", adj[a[i]][a[j]], j < s - 1 ? ' ' : '\n');
    return 0;
}
