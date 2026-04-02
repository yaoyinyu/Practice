#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int* test()
{
	int a = 10;
	return &a;
}
int main() 
{
	//固定内存大小
	//int a = 10;
	//int arr[10] = { 0 };
	//int* p = (int*)malloc(40);

	//if (p == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 1;
	//}
	//int i = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	*(p + i) = i;
	//	printf("%d ", *(p + i));
	//}

	//printf("\n");

	//free(p);
	//p = NULL;

	//printf("\n");

	//int* b = (int*)calloc(10, sizeof(int));
	//if (b == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 1;
	//}
	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d ", *(b + i));
	//}
	//free(b);
	//b = NULL;

	//int* p = (int*)malloc(40);
	//if (NULL == p)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 1;
	//}

	//int i = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	*(p + i) = i + 1;
	//}
	////扩容
	//int *ptr = (int*)realloc(p, 80);
	//if (ptr != NULL)
	//{
	//	p = ptr;
	//}
	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d ", *(p + i));
	//}

	////free只能释放动态内存指针空间
	//free(p);
	//p = NULL;

	//int* p = (int*)malloc(40);
	//if (p == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 1;
	//}
	//int i = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	*(p + i) = i + 1;
	//}
	//int* ptr = (int*)realloc(p, 80);		//新的加旧的空间大小

	//int* p = test();
	////printf("hehe\n");	//任意函数开辟栈针后就有可能进行覆盖
	//printf("%d\n", *p);
	//

	//int n, m;
	//while (scanf("%d %d", &n, &m) == 2)
	//{
	//	//int min = n < m ? n : m;
	//	//int max = n > m ? n : m;
	//	//int i = min;
	//	//int j = max;
	//	////最小公倍数
	//	//while (1)
	//	//{
	//	//	if (n % i == 0 && m % i == 0)
	//	//	{
	//	//		break;
	//	//	}
	//	//	i--;
	//	//}
	//	////最大公因数
	//	//while (1)
	//	//{
	//	//	if (j % n == 0 && j % m == 0)
	//	//	{
	//	//		break;
	//	//	}
	//	//	j++;
	//	//}
	//	//printf("%d", i + j);
	//	int i = n;
	//	int j = m;
	//	int r = 0;
	//	while (r = i % j)
	//	{
	//		i = j;
	//		j = r;
	//	}
	//	printf("%d\n", m * n / j + j);
	//}

	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
				{
					printf("* ");
				}
				else
				{
					printf("  ");
				}
			}
			printf("\n");
		}
	}


	return 0;

}