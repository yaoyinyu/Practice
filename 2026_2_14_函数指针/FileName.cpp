#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Add(int x, int y)
{
	return x + y;
}

int main()
{
	int arr[5] = { 0 };
	// &数组名	-	取出的是数组的地址
	int (*p)[5] = &arr;		//数组指针

	//	&函数名	-	取出的是函数的地址
	//	函数名	-	是函数的地址
	//	函数名 == &函数名
	printf("%p\n", &Add);	//函数指针
	printf("%p\n", Add);	//函数指针

	int (*pf)(int, int) = &Add;
	//int表示返回类型	(*pf)表示指针	(int, int)表示函数参数类型

	//指针可以找到内存位置内部的东西，也可以进行修改
	int a = 10;
	int* pa = &a;
	*pa = 20;
	printf("%d\n", *pa);

	//函数指针可以对函数（地址）进行访问和传参
	int (*pi)(int, int) = &Add;
	int ret = (*pi)(2, 3);
	//int ret = pi(2, 3);	两种写法
	printf("%d\n", ret);


	return 0;

}