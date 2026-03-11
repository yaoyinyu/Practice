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

	double price = 0;
	int m = 0;
	int d = 0;
	int flag = 0;
	scanf("%lf %d %d %d", &price, &m, &d, &flag);
	if (m == 11 && d == 11)
	{
		price = price * 0.7 - flag * 50;
	}
	else if (m == 12 & d == 12)
	{
		price = price * 0.8 - flag * 50;
	}
	if (price < 0.0)
		printf("%.2lf\n", 0);
	else
	{
		printf("%.2lf\n", price);
	}


	return	0;

}