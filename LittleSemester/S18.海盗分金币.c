/*
18.海盗分金币
从第一个人到第n个人递推
对于第i个人，他需要贿赂的人数num = i * q / 100
找出前i-1个人中期望得到的金币最少的num个人，每人多给一个金币，剩余金币归第i个人所有
为方便下次查找最小值，在分配完之后对前i个人期望的金币数量排序，此处利用原来的有序性，O(n)完成
整体时间复杂度O(n^2)
*/
#include <stdio.h>
#include <string.h>
#define N 10010

int dp[N];
int n, m, q;

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	{
		int num = i * q / 100; //需要贿赂的人数

		int sum = m;
		for (int j = i - num; j < i; j++)	//检查第i个人是否必死
		{
			sum -= dp[j] + 1;
			if (sum < 0) break;
		}
		if (sum < 0)
		{
			dp[i] = -1;
			continue; //若必死，为-1，序列仍然有序，直接进入下一次循环
		}

		for (int j = i - num; j < i; j++) dp[j]++; //不必死，后num个人金币期望值加1
		dp[i] = sum;
		if (i == n) break; //若为第n个人，直接跳出，输出dp[n]

		for (int j = i - num, p = 1; j < i; j++, p++) dp[p] = dp[j]; //排序，只需将后num个数一到序列开头，它们已经有序
		int j = num;
		while (j >= 1 && dp[i] > dp[j]) dp[j + 1] = dp[j], j--; //找到dp[i]的位置
		dp[j + 1] = dp[i];
		for (int j = num + 2; j <= i; j++) dp[j] = 0; //其余人分0个金币
	}
	printf("%d\n", dp[n]);
	return 0;
}
