#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

//整形存放的都是补码
//有符号类型进行计算的时候需要整形提升
//小于4 * 8字符类型进行计算的时候（如char类型1 * 8）把第一位复制补充成4 * 8
//但是源类型存储时会截断
//char类型若超过2^7时数据符号会发生改变

//若数据类型大于整形则发生算数转换
//低精度转换为高精度

int fib(int n)
{
	if (n > 2)
		return fib(n - 1) + fib(n - 2);
	else
		return n;
}

int main()
{
	//char a = 5;
	////00000101
	////00000000000000000000000000000101
	//char b = 126;
	////01111110
	////00000000000000000000000001111110
	//char c = a + b;
	////00000101	-	a
	////01111110	-	b
	////10000011	-	a + b
	////11111111111111111111111110000011
	//printf("%d\n", c);
	////11111111111111111111111110000011	-	补码
	////11111111111111111111111110000010	-	反码
	////10000000000000000000000001111101	-	源码	-	125

	//int n = 0;
	//scanf("%d", &n);
	//printf("%d\n", fib(n));

	//int a = 0;
	//scanf("%d", &a);
	//int arr[50];
	//int i;
	//for (i = 0; i < a; i++)
	//{
	//	scanf("%d", &arr[i]);
	//}
	//int del = 0;
	//scanf("%d", &del);
	//int j = 0;		//指向被保存的序列
	//for (i = 0; i < a; i++)
	//{
	//	if (arr[i] != del)
	//	{
	//		arr[j] = arr[i];
	//		j++;
	//	}
	//}
	//for (i = 0; i < j; i++)
	//{
	//	printf("%d ", arr[i]);
	//}

	//int n = 0;
	//scanf("%d", &n);
	//int arr[10000] = { 0 };
	//int i;
	//int max = 0;
	//int min = 100;
	//for (i = 0; i < n; i++)
	//{
	//	scanf("%d", &arr[i]);
	//	if (arr[i] > max)
	//		max = arr[i];
	//	if (arr[i] < min)
	//		min = arr[i];
	//}
	//printf("%d\n", max - min);

	//char ch = 0;
	//while (scanf("%c", &ch) == 1)
	//{
	//	if (ch >= 'a' && ch <= 'z')
	//		printf("%c\n", ch - 32);
	//	else
	//		printf("%c\n", ch + 32);
	//	getchar();
	//}

	//char ch = 0;
	//while (scanf("%c", &ch) == 1)
	//{
	//	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
	//		printf("%c是字母\n", ch);
	//	else
	//		printf("%c是数字\n", ch);
	//	getchar();		//可以以scanf(" %c", &ch) == 1来代替
	//					//' '%c前加空格可以跳过下次读取字符前的所有字符
	//}

	int i = 0;
	for (i = 10000; i <= 99999; i++)
	{
		int j = 0;
		int sum = 0;
		for (j = 1; j <= 4; j++)
		{
			int k = (int)pow(10, j);
			sum += (i % k)* (i / k);
		}
		if (sum == i)
		{
			printf("%d\n", i);
		}
	}

	return 0;

}