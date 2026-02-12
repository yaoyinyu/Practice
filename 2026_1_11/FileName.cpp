#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void bubble_sort(int arr[],int len)
{
	int big;
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				big = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = big;
			}
		}
	}
}

int main()
{
	//int arr[10] = {};		//C99标准后可以支持变量在[]中定义，且变长数组无法初始化
	//char arr1[10] = { 1,2,3 };	//字符数组初始化为0，数组中每个元素都被初始化为0
	//char ch[] = "abc";		//如果以字符串初始化字符数组，编译器会自动在结尾添加一个'\0'字符，且会占用一个位置
	//char ch1[] = {'a','b','c'};		//未使用的区域字符型时以/0占位
	//int i = sizeof(arr) / sizeof(arr[0]);	//计算数组元素个数
	//printf("i=%d\n", i);
	////输出arr数组元素
	//for (int j = 0; j < i; j++)
	//{
	//	printf("arr[%d]=%d\n", j, arr[j]);
	//}
	//for (int a = 0; a < i; a++)
	//{
	//	printf("arr1[%d]=%p\n", a, &arr1[a]);
	//}
	//int arr[3][4] = { {1,2},{3,4},{5,6} };	//{}可以对数据进行分组每个分组开启新的一行
	////二维数组只能省略行数，列数必须指定
	//int arr1[][4] = { {1,2,3,4},{5,6},7,8,9 };	//未分组的数据会依次存放在数组中
	//for (int x = 0; x < 3; x++)
	//{
	//	for (int y = 0; y < 4; y++)
	//	{
	//		printf("arr[%d][%d]=%p\n", x, y, &arr[x][y]);
	//	}
	//	printf("\n\n");
	//}

	//int arr[] = { 1,5,6,8,9,1,5,8,3,4,565,46, };
	//int len = sizeof(arr) / sizeof(arr[0]);	//形参数组无法计算出数组长度，sizeof(arr)计算的是指针大小
	//bubble_sort(arr, len);	//数组名作为实参传递时，传递的是数组首元素的地址
	//for(int i = 0; i < len; i++)
	//{
	//	printf("arr[%d]=%d\n", i, arr[i]);
	//}

	//int arr[10];
	//printf("%p\n", arr);			//数组名表示数组首元素地址
	//printf("%p\n", arr + 1);		//数组名表示数组首元素地址，+1表示跳过一个元素
	//printf("---------------------\n");
	//printf("%p\n", &arr[0]);		//&arr[0]表示第一个元素地址
	//printf("%p\n", &arr[0] + 1);	//&arr[0]表示第一个元素地址，+1表示跳过一个元素
	//printf("---------------------\n");
	//printf("%p\n", &arr);			//&arr表示整个数组的地址
	//printf("%p\n", &arr + 1);		//&arr表示整个数组的地址，+1表示跳过整个数组
	//
	//int sz = sizeof(arr);		//sizeof计算的是整个数组大小
	//printf("sz=%d\n", sz);

	int arr1[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int sz1 = sizeof(arr1);			//计算二维数组的整个大小
	printf("sz1=%d\n", sz1);
	printf("%p\n", arr1);			//二维数组名表示二维数组首元素地址，即第一行首元素地址
	printf("%p\n", arr1 + 1);		//arr1表示二维数组首元素地址，+1表示跳过第一行，指向第二行首元素地址
	printf("%p\n", &arr1[0]);		//&arr1[0]表示第一行首元素地址
	
	//用整个二维数组的大小除以第一行的大小，得到行数
	printf("打印行数%d\n", sizeof(arr1) / sizeof(arr1[0]));		//计算二维数组行数
	//用第一行的大小除以第一行第一个元素的大小，得到列数
	printf("打印列数%d\n", sizeof(arr1[0]) / sizeof(arr1[0][0]));			//计算二维数组列数
	//arr1表示二维数组首元素地址，即第一行首元素地址
	//arr1+1表示跳过第一行，指向第二行首元素地址
	//&arr1[0]表示第一行首元素地址
	//&arr1[0]+1表示跳过第一行，指向第二行首元素地址



	return 0;

}