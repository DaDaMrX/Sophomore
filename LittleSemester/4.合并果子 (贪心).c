/*
4.合并果子 (贪心)
1.n堆果子，每合并一次会减少一堆，故共需合并n-1次
2.因为每次合并消耗的体力是两堆果子的重量之和，
故每次合并时都选当前剩余堆中重量最小的两堆，贪心
*/
#include <stdio.h>
#include <string.h>
#define N 10010

int heap[N], size;

inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1; }
inline int P(int i) { return i >> 1; }

inline void init() { size = 0; }

void up(int i)
{
	if (i == 1) return;
	if (heap[i] < heap[P(i)])
	{
		int t = heap[i]; heap[i] = heap[P(i)]; heap[P(i)] = t;
		up(P(i));
	}
}
void push(int x)
{
	heap[++size] = x;
	up(size);
}

int top()
{
	return heap[1];
}

void down(int i)
{
	int mini = i;
	if (L(i) <= size && heap[L(i)] < heap[mini]) mini = L(i);
	if (R(i) <= size && heap[R(i)] < heap[mini]) mini = R(i);
	if (mini != i)
	{
		int t = heap[i]; heap[i] = heap[mini]; heap[mini] = t;
		down(mini);
	}
}
void pop()
{
	heap[1] = heap[size--];
	down(1);
}

int main()
{
	int n;
	scanf("%d", &n);
	init();
	for (int i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		push(a);
	}

	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		int sum = top(); pop();
		sum += top(); pop();
		ans += sum;
		push(sum);
	}

	printf("%d\n", ans);
	return 0;
}