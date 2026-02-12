#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>

//short占用两个字节空间，int四个
//原本01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00
//强制类型转换后每组short使用两个字节
//如01 00 00 00转换为01 00
//所以只有前2 * 4 = 8个字节置为00
//00 00 00 00 00 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00


int main()
{
	//int arr[5] = { 1,2,3,4,5 };
	//short* p = (short*)arr;
	//int i = 0;
	//for (i = 0; i < 4; i++)
	//{
	//	*(p + i) = 0;
	//}
	//for (i = 0; i < 5; i++)
	//{
	//	printf("%d ", arr[i]);
	//}

	//char arr[10001] = { 0 };
	//fgets(arr, sizeof(arr), stdin);
	//printf("%s\n", arr);
	//int left = 0;
	//int right = strlen(arr) - 1;
	//while (left < right)
	//{
	//	int tmp = arr[left];
	//	arr[left] = arr[right];
	//	arr[right] = tmp;
	//	left++;
	//	right++;
	//}

	//int a = 0;
	//int sum = 0;
	//int n = 0;
	//int ret = 0;
	//scanf("%d %d", &a, &n);
	//int i = 0;
	//for (i = 0; i < n; i++)
	//{
	//	ret = a + ret * 10;
	//	printf("%d\n", ret);
	//	sum = sum + ret;
	//}
	//printf("%d\n", sum);

	//int i = 0;
	//for (i = 0; i <= 100000; i++)
	//{
	//	int sum = 0;
	//	int n = 1;
	//	int tmp = i;
	//	while (tmp / 10)
	//	{
	//		n++;
	//		tmp = tmp / 10;
	//	}
	//	tmp = i;
	//	while (tmp) {
	//		sum = sum + pow(tmp % 10, n);
	//		tmp = tmp / 10;
	//	}
	//	if (sum == i)
	//	{
	//		printf("%d是水仙花数\n", i);
	//	}
	//}

	//int i = 0;
	//int line = 0;
	//scanf("%d", &line);
	//for (i = 0; i < line; i++)
	//{
	//	int j = 0;
	//	for (j = 0; j < line - 1 - i; j++)
	//	{
	//		printf(" ");
	//	}
	//	for (j = 0; j < 2 * i + 1; j++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	//for (i = 0; i < line - 1; i++)
	//{
	//	int j = 0;
	//	for (j = 0; j <= i; j++)
	//	{
	//		printf(" ");
	//	}
	//	for (j = 0; j < (2 * (line - 1 - i) -1); j++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}

	int money = 0;
	scanf("%d", &money);
	//int total = money;
	//int empty = money;

	//while (empty >= 2)
	//{
	//	total = total + empty / 2;
	//	empty = empty / 2 + empty % 2;
	//}
	//printf("%d", total);

	if (money > 0)
		printf("%d\n", 2 * money - 1);
	else
		printf("%d\n", 0);

	return 0;

}