/*
24.波兰表达式
建3个栈，在线处理每个字符
flag[]记录序列中每一个元素是运算符还是数字，运算符用0表示，数字用1表示
num[]存储数字，op[]存储运算符
1.遇到+或*，压栈
2.遇到-，再读取一个，若为空格，则-作为运算符压栈，若为数字，则存储一个负数
3.遇到数字，处理到整个数结尾，若上一个元素也是数字，则根据栈顶运算符和数字计算结果，
压栈，循环，直到上个元素不是数字为止
*/
#include <stdio.h>
#define N 100

int flag[N];
char op[N];
int num[N];
int top_flag, top_op, top_num;

int calc(int a, char op, int b)
{
	switch (op)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	}
}

int main()
{
	int T;
	scanf("%d%*c", &T);
	while (T--)
	{
		flag[0] = 0;
		top_flag = top_op = top_num = 0;
		char c = getchar();
		while (c != '\n')
		{
			if (c == '+' || c == '*')
			{
				op[++top_op] = c;
				flag[++top_flag] = 0;

				while ((c = getchar()) == ' ');
				continue;
			}

			if (c == '-')
			{
				if ((c = getchar()) == ' ')
				{
					op[++top_op] = '-';
					flag[++top_flag] = 0;

					while ((c = getchar()) == ' ');
					continue;
				}
				else
				{
					int s = 0;
					while (c >= '0' && c <= '9')
					{
						s = s * 10 + c - '0';
						c = getchar();
					}
					s = -s;
					num[++top_num] = s;
					flag[++top_flag] = 1;

					while (flag[top_flag - 1])
					{
						num[top_num - 1] = calc(num[top_num - 1], op[top_op], num[top_num]);
						top_num--; top_op--;
						top_flag -= 2;
						flag[top_flag] = 1;
					}

					while (c == ' ') c = getchar();
					continue;
				}
			}

			if (c >= '0' && c <= '9')
			{
				int s = 0;
				while (c >= '0' && c <= '9')
				{
					s = s * 10 + c - '0';
					c = getchar();
				}
				num[++top_num] = s;
				flag[++top_flag] = 1;

				while (flag[top_flag - 1])
				{
					num[top_num - 1] = calc(num[top_num - 1], op[top_op], num[top_num]);
					top_num--; top_op--;
					top_flag -= 2;
					flag[top_flag] = 1;
				}

				while (c == ' ') c = getchar();
				continue;
			}
		}
	printf("%d\n", num[top_num]);
	}
	return 0;
}