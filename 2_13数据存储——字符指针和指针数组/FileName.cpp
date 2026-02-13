#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void printf1(int arr[3][5], int r, int c)
{
	int i = 0;
	for (i = 0; i < r; i++)
	{
		int j = 0;
		for (j = 0; j < c; j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("%\n");
	}
}

//int (*p)[5]指向一行的数组指针
void printf2(int (*p)[5], int r, int c)
{
	int i = 0;
	for (i = 0; i < r; i++)
	{
		int j = 0;
		for (j = 0; j < c; j++)
		{
			printf("%d", *(*(p + i) + j));
		}
		printf("%\n");
	}
}

int main()
{
	//char ch = 'w';
	//char* pc = &ch;
	//const char* p = "abcdef";
	//printf("%d", *p);	//打印*p的首地址

	//char arr1[] = "abcdef";
	//char arr2[] = "abcdef";

	//const char* p1 = "abcdef";
	//const char* p2 = "abcdef";

	//if (p1 == p2)
	//	printf("p1 == p2");
	//else
	//	printf("p1 != p2");
	//printf("\n");
	//if (arr1 == arr2)
	//	printf("arr1 == arr2");
	//else
	//	printf("arr1 != arr2");
	////
	//// *p1,*p2存储相同的数据所以公用静态内存
	//// p1,p2存储的都是同一组数据的首地址所以p1 == p2
	//// 
	//// arr1[],arr2[]是两个数组，申请了两块不同的内存空间
	//// 数组名称是数组的首地址
	//// 所以arr1[] != arr2[]
	////

	//int arr1[] = { 1,2,3,4,5 };
	//int arr2[] = { 2,3,4,5,6 };
	//int arr3[] = { 3,4,5,6,7 };

	//int* parr[] = { arr1,arr2,arr3 };

	//int j, i;
	//// 指针数组模拟二维数组
	//for (i = 0; i < 3; i++)
	//{
	//	for (j = 0; j < 5; j++)
	//	{
	//		printf("%d ", (parr[i])[j]);
	//	}
	//	printf("\n");
	//}

	//int arr[10] = { 0 };
	//printf("%p\n", arr);
	//printf("%p\n", arr+1);

	//printf("%p\n", &arr[0]);
	//printf("%p\n", &arr[0]+1);

	//printf("%p\n", &arr);
	//printf("%p\n", &arr+1);

	//int sz = sizeof(arr);
	//printf("%d\n", sz);

	////
	//// 数组名通产表示的是数组首地址元素的地址
	//// 除了两个例外：
	//// 1.sizeof(单独放数组名(arr)，不包括(arr+1))计算整个数组的大小
	//// 2.&数组名，这里依然表示整个数组
	//// 

	//int arr[10] = { 0 };
	//int* p = arr;			//整形指针
	//int (*p)[10] = &arr;	//数组指针类型是：int (*)[10]
	//int* p[10] = { arr };	//指针数组

	//char* arr[5] = { 0 };
	//char* (*pc)[5] = &arr;

	int arr[3][5] = { 1,2,3,4,5,2,3,4,5,6,3,4,5,6,7 };
	printf1(arr, 3, 5);
	printf("%\n");
	//二维指针首元素传的是第一行
	printf2(arr, 3, 5);

	return 0;

}