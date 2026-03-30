#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

int main() 
{
	//固定内存大小
	int a = 10;
	int arr[10] = { 0 };
	int* p = (int*)malloc(40);
	printf("\n");

	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;
		printf("%d ", *(p + i));
	}

	printf("\n");

	free(p);
	p = NULL;

	return 0;

}