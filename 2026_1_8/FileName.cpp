#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

void swap(int* y, int* x)
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}

int main() {
	//int a, b, c;
	//int x = 0;
	//scanf("%d %d %d", &a, &b, &c);
	//if (a < b)
	//{
	//	x = a;
	//	a = b;
	//	b = x;
	//}
	//if (a < c)
	//{
	//	x = a;
	//	a = c;
	//	c = x;
	//}
	//if (b < c)
	//{
	//	x = b;
	//	b = c;
	//	c = x;
	//}
	//if (a < b)
	//{
	//	swap(&a, &b);
	//}
	//if (a < c)
	//{
	//	swap(&a, &c);
	//}
	//if(b<c)
	//{
	//	swap(&b, &c);
	//}

	//printf("%d,%d,%d\n", a, b, c);

	//int a;
	//for (a = 3; a < 100; a += 3)
	//{
	//	printf("%d ", a);
	//}

	//int a, b;
	//scanf("%d %d", &a, &b);
	//int min = a < b ? a : b;
	//for (int i = min; i >= 1; i--)
	//{
	//	if (a % i == 0 && b % i == 0)
	//	{
	//		printf("%d ", i);
	//		break;
	//	}
	//}

	//int a, b;
	//int r;
	//scanf("%d %d", &a, &b);
	//while (r = a % b)
	//{
	//	a = b;
	//	b = r;
	//}
	//printf("%d\n", b);

	//int j;
	//for (int i = 100; i <= 200; i++)
	//{
	//	for (j = 2; j <= sqrt(i); j++)
	//	{
	//		if (i % j == 0)
	//			break;
	//	}
	//	if (j > sqrt(i))
	//		printf("%d ", i);
	//}

	//int count = 0;
	//for (int i = 1; i <= 100; i++)
	//{
	//	if(i % 10 == 9)
	//		count++;
	//	if(i / 10 == 9)
	//		count++;			//99算两次
	//}
	//printf("%d ", count);


	//int i = 0;
	//double sum = 0.0;
	//int flag = 1;
	//for (i = 1; i <= 100; i++)
	//{
	//	sum = sum + flag * (1.0 / i);
	//	flag = -flag;
	//}
	//printf("%2f ", sum);


	//int arr[10] = { 0 };
	//int i;
	//for (i = 0; i < 10; i++)
	//{
	//	scanf("%d", &arr[i]);
	//}
	//int max = arr[0];
	//for (int j = 1; j < 10; j++)
	//{
	//	if (arr[j] > max)
	//	{
	//		max = arr[j];
	//	}
	//}
	//printf("最大的是%d", max);


int a, b;
int i;
printf("请输入行数和列数：\n");
scanf("%d", &i);
//99乘法表
//打印9行
for (a = 1; a <= i; a++)
{
	//打印每行的内容
	for (b = 1; b <= a; b++)
	{
		printf("%d*%d=%-2d ", a, b, a * b);		//%-2d表示左对齐，占两位,\t同样占位
	}
	printf("\n");
}


//int a;
//printf("请输入a和i的值：\n");
//scanf("%d", &a);
//int i;
//scanf("%d", &i);
//if(i>a)
//	printf("猜大了\n");
//else if (i < a)
//	printf("猜小了\n");






	return 0;

}