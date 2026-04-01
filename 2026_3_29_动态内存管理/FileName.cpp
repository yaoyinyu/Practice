#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

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

	int* p = (int*)malloc(40);
	if (NULL == p)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i + 1;
	}
	//扩容
	int *ptr = (int*)realloc(p, 80);
	if (ptr != NULL)
	{
		p = ptr;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
	free(p);
	p = NULL;


	return 0;

}