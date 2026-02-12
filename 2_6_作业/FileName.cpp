#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//全局变量存放在静态区内，默认不初始化就是0
int k;

int count_num_of_1_1(unsigned int n)
{
	int count = 0;
	while (n)
	{
		if (n % 2 == 1)
			count++;
		n = n / 2;
	}
	return count;
}

int count_num_of_1_2(int n)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		if ((n >> i) & 1)
			count++;
	}
	return count;
}

int count_num_of_1_3(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}

int count_deff_bit_1(int m, int n)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (((m >> i) & 1) != ((n >> i) & 1))
			count++;
	}
	return count;
}

int count_deff_bit_2(int m, int n)
{
	int count = 0;
	int ret = m ^ n;
	while (ret)
	{
		ret = ret & (ret - 1);
		count++;
	}
	return count;
}

int is_leap_year(int y)
{
	return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

int main()
{
	//int a = 0;
	//scanf("%d", &a);

	//printf("%d个1\n", count_num_of_1_1(a));
	//printf("%d个1\n", count_num_of_1_2(a));
	//printf("%d个1\n", count_num_of_1_3(a));

	//int m = 0;
	//int n = 0;
	//scanf("%d %d", &m, &n);
	//printf("二进制有%d个不同位\n", count_deff_bit_1(m, n));
	//printf("二进制有%d个不同位\n", count_deff_bit_2(m, n));

	//int x;
	//scanf("%d", &x);
	//int i = 0;
	//for (i = 30; i >= 0; i-=2)
	//{
	//	printf("%d ", (x >> i) & 1);
	//}
	//printf("\n");
	//for (i = 31; i >= 0; i -= 2)
	//{
	//	printf("%d ", (x >> i) & 1);
	//}

	//k--;	//-1
	////sizeof计算返回结果是size_t类型，是一个无符号的整形int为4
	////k的-1强制转换成无符号类型是一个超大的整数4,294,967,295
	//if (k > sizeof(k))
	//	printf(">\n");
	//else
	//	printf("<\n");

	//int n = 0;
	//while (scanf("%d", &n) == 1)
	//{
	//	int i = 0;
	//	int j = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < n; j++)
	//		{
	//			if (i == j)
	//				printf("*");
	//			else if (i + j == n - 1)
	//				printf("*");
	//			else
	//				printf(" ");
	//		}
	//		printf("\n");
	//	}
	//}

	int y = 0;
	int m = 0;
	int d = 0;
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	while (scanf("%d %d", &y, &m) == 2)
	{
		d = days[m];
		if ((is_leap_year(y) == 1) && (m == 2))
			d++;
		printf("%d\n", d);
	}

	return 0;

}