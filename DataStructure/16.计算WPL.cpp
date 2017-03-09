/*
16.计算WPL
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

priority_queue<int, vector<int>, greater<int> > pq;
int main()
{
    int n;
    scanf("%d", &n);
    while (!pq.empty()) pq.pop();
    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        pq.push(a);
    }

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int sum = pq.top(); pq.pop();
        sum += pq.top(); pq.pop();
        ans += sum;
        pq.push(sum);
    }

    printf("WPL=%d\n", ans);
    return 0;
}
