/*
18.�����ֽ��
�ӵ�һ���˵���n���˵���
���ڵ�i���ˣ�����Ҫ��¸������num = i * q / 100
�ҳ�ǰi-1�����������õ��Ľ�����ٵ�num���ˣ�ÿ�˶��һ����ң�ʣ���ҹ��i��������
Ϊ�����´β�����Сֵ���ڷ�����֮���ǰi���������Ľ���������򣬴˴�����ԭ���������ԣ�O(n)���
����ʱ�临�Ӷ�O(n^2)
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
		int num = i * q / 100; //��Ҫ��¸������

		int sum = m;
		for (int j = i - num; j < i; j++)	//����i�����Ƿ����
		{
			sum -= dp[j] + 1;
			if (sum < 0) break;
		}
		if (sum < 0)
		{
			dp[i] = -1;
			continue; //��������Ϊ-1��������Ȼ����ֱ�ӽ�����һ��ѭ��
		}

		for (int j = i - num; j < i; j++) dp[j]++; //����������num���˽������ֵ��1
		dp[i] = sum;
		if (i == n) break; //��Ϊ��n���ˣ�ֱ�����������dp[n]

		for (int j = i - num, p = 1; j < i; j++, p++) dp[p] = dp[j]; //����ֻ�轫��num����һ�����п�ͷ�������Ѿ�����
		int j = num;
		while (j >= 1 && dp[i] > dp[j]) dp[j + 1] = dp[j], j--; //�ҵ�dp[i]��λ��
		dp[j + 1] = dp[i];
		for (int j = num + 2; j <= i; j++) dp[j] = 0; //�����˷�0�����
	}
	printf("%d\n", dp[n]);
	return 0;
}
