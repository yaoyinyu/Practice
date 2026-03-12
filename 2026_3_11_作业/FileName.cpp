#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>

int main()
{
	//int input;
	//scanf("%d", &input);
	//int sum = 0;
	//int i = 0;
	//while (input)
	//{
	//	int bit = input % 10;
	//	if (bit % 2 == 1)
	//	{
	//		bit = 1;
	//	}
	//	else
	//	{
	//		bit = 0;
	//	}
	//	sum += bit * pow(10, i);
	//	i++;
	//	input /= 10;
	//}
	//printf("%d\n", sum);

	//int n;
	//while (scanf("%d", &n) == 1)
	//{
	//	int i = 0;
	//	int j = 0;
	//	for (i = 0; i < n; i++)
	//	{
	//		for (j = 0; j < n; j++)
	//		{
	//			if (i + j < n - 1)
	//			{
	//				printf("  ");
	//			}
	//			else
	//			{
	//				printf("* ");
	//			}
	//		}
	//		printf("\n");
	//	}
	//}

	//double price = 0;
	//int m = 0;
	//int d = 0;
	//int flag = 0;
	//scanf("%lf %d %d %d", &price, &m, &d, &flag);
	//if (m == 11 && d == 11)
	//{
	//	price = price * 0.7 - flag * 50;
	//}
	//else if (m == 12 & d == 12)
	//{
	//	price = price * 0.8 - flag * 50;
	//}
	//if (price < 0.0)
	//	printf("%.2lf\n", 0);
	//else
	//{
	//	printf("%.2lf\n", price);
	//}

	//int a = 0;
	//int b = 0;
	//int c = 0;
	//int d = 0;
	//int e = 0;
	//for (a = 1; a <= 5; a++)
	//{
	//	for (b = 1; b <= 5; b++)
	//	{
	//		for (c = 1; c <= 5; c++)
	//		{
	//			for (d = 1; d <= 5; d++)
	//			{
	//				for (e = 1; e <= 5; e++)
	//				{
	//					if (((b == 2) + (a == 3)) == 1
	//						&& ((b == 2) + (e == 4)) == 1
	//						&& ((c == 1) + (d == 2)) == 1
	//						&& ((c == 5) + (d == 3)) == 1
	//						&& ((e == 4) + (a == 1)) == 1)
	//					{
	//						if (a * b * c * d * e == 120 && a + b + c + d + e == 15)
	//						{
	//							printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
	//						}
	//					}
	//				}
	//			}
	//		}
	//	}
	//}

	//int killer = 0;
	//for (killer = 'a'; killer <= 'd'; killer++)
	//{
	//	if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
	//	{
	//		printf("%c\n", killer);
	//	}
	//}
	
	int arr[10][10] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0)
				arr[i][j] = 1;
			if (j == i)
				arr[i][j] = 1;
			if (i >= 2 && j >= 1)
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}



	return	0;

}