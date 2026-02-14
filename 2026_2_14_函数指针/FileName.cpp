#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

//回调函数
void calc(int (*pf)(int, int))
{
	int x = 0;
	int y = 0;
	int ret = 0;

	printf("请输入两个参数：");
	scanf("%d %d", &x, &y);
	ret = pf(x, y);
	printf("计算结果是：%d\n", ret);
}

typedef void(* pf_t)(int);	//将void (*)(int)类型重命名成pf_t

void menu()
{
	printf("1.add\n2.sub\n3.mul\n4.div\n0.exit\n");
}

void bubble_sort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	int flag = 1;	//假设数组是有序的
	for (i = 0; i < sz - 1; i++)			//趟数
	{
		for (j = 0; j < sz - 1 - i; j++)	//每趟内部
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = 0;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
			break;
		flag = 1;
	}
}

//qsort
int cmp_int(const void* e1, const void* e2)
{
	//if (*(int*)e1 > *(int*)e2)
	//	return 1;
	//else if (*(int*)e1 < *(int*)e2)
	//	return -1;
	//else
	//	return 0;
	return (*(int*)e1 - *(int*)e2);
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

	//(* (void (*)() ) 0)();
	// 以上代码是一次函数调用，调用的是0作为地址的函数。
	// 1.将0强制类型转换为：无参，返回类型是void的函数地址
	// 2.调用0地址处的这个函数
	// (*)					明确是指针
	// (*)()				参数为空
	// (void (*)())			明确是函数指针
	// (void (*)()) 0		对0强制转换为一个地址，并调用地址为0处的函数（主要目的是调用函数，因为需要调用函数所以对0强制类型转换成无参返回类型是void类型的函数地址）
	// (*(void (*)()) 0)	对该地址函数解引用
	// (*(void (*)()) 0)()	调用地址为0地址的函数，传参为空
	//

	void (* signal( int, void(*)(int) ) )(int);
	// 以上代码是一次函数声明，声明signal函数的第一个参数类型是int，第二个参数类型是一个函数指针
	// 该函数指针指向的是void(*)(int)参数是int，返回类型是void
	// signal返回类型是一个函数指针，参数是int，返回类型是void
	// void(*)(int)								函数指针，参数是int，返回类型是void
	// signal									signal是一个函数名
	// signal(int, void(*)(int)					signal函数第一个参数类型是int，第二个参数是void(*)(int)的函数指针返回类型是void
	// (*signal(int, void(*)(int))				signal最终返回类型是一个函数指针类型
	// void (*signal(int, void(*)(int)))(int)	函数指针，调用*signal函数，参数是int，返回类型是void
	//
	// typedef void(*pf_t)(int);	//将void (*)(int)类型重命名成pf_t
	// 使用上述重命名方案简化逻辑
	pf_t signal(int, pf_t);			//简化书写

	//do
	//{
	//	menu();
	//	printf("请输入:");
	//	scanf("%d", &input);

	//	switch (input)
	//	{
	//	case 1:
	//		calc(Add);
	//		break;
	//	case 2:
	//		calc(Sub);
	//		break;
	//	case 3:
	//		calc(Mul);
	//		break;
	//	case 4:
	//		calc(Div);
	//		break;
	//	default:
	//		printf("已退出\n");
	//		break;
	//	}
	//} while (input);

	int (*pb)(int, int) = Add;							//函数指针
	int (*arr1[4])(int, int) = { Add, Sub, Mul, Div };	//函数指针数组
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		int ret1 = arr1[i](8, 4);
		printf("%d\n", ret1);
	}

	int input = 0;
	int x = 0;
	int y = 0;
	int ret2 = 0;

	//转移表
	int (*parr[])(int, int) = { 0, Add, Sub, Mul, Div };

	do
	{
		menu();
		printf("请输入选择：");
		scanf("%d", &input);
		if (input == 0)
			printf("退出计算器\n");
		else if (input > 0 && input < 5)
		{
			printf("请输入两个参数：");
			scanf("%d %d", &x, &y);
			ret2 = parr[input](x, y);
			printf("计算结果是：%d\n", ret2);
		}
		else
			printf("选择错误\n");
	} while (input);

	//指向【函数指针数组】的指针
	int (*(*pparr)[5])(int, int) = &parr;
	// (*pparr)
	// (*pparr)[5]
	// (*(*pparr)[5])
	// int (*(*pparr)[5])(int, int)
	// int (*(*pparr)[5])(int, int) = &parr;
	//

	int arr2[] = { 20,9,7,6,5,4,8,6,2,5,12,0 };
	int arr3[] = { 20,5,8,6,4,9,2,3498,3,5,96,0 };
	//将数组拍成升序
	int sz = sizeof(arr2) / sizeof(arr2[0]);
	bubble_sort(arr2,sz);
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%d ", arr2[j]);
	}
	printf("\n");

	qsort(arr3, sz, sizeof(arr3[20]), cmp_int);
	for (j = 0; j < sz; j++)
	{
		printf("%d ", arr3[j]);
	}


	return 0;

}