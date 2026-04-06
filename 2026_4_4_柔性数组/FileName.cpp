#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string>

//柔性数组，最后一个成员大小是未知大小
//柔性数组前必须有一个其它成员
struct S
{
	int i;
	int arr[];	//柔性数组
};

struct S1
{
	int i;
	int* arr;
};

int main()
{
	//int sz = sizeof(struct S);
	//printf("%d\n", sz);	//大小仅计算柔性数组前大小

	////柔性数组的使用
	//struct S* ps = (struct S*)malloc(sizeof(struct S) + 40);
	//ps->i = 100;	
	//if (ps == NULL)
	//{
	//	return 1;
	//}
	//int i = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	ps->arr[i] = i;
	//}
	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d ", ps->arr[i]);
	//}
	//struct S* ptr = (struct S*)realloc(ps, (sizeof(struct S) + 80));
	//if (ptr != NULL)
	//{
	//	ps = ptr;
	//	ptr = NULL;
	//}
	////释放
	//free(ps);
	//ps = NULL;

	struct S1* ps = (struct S1*)malloc(sizeof(struct S1));
	if (ps == NULL)
	{
		return 1;
	}
	ps->i = 100;
	ps->arr = (int*)malloc(40);
	if (ps->arr == NULL)
	{
		return 1;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	int* ptr = (int*)realloc(ps->arr, 80);
	if (ptr == NULL)
	{
		return 1;
	}
	ps->arr = ptr;
	//释放
	free(ps->arr);
	free(ps);
	ps = NULL;


	return 0;

}