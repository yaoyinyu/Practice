#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//char* ps	-	创建一个char类型的指针
//sizeof(*ps)	-	测量指针指向的数据的大小（char是1，int是4……）
//sizeof(ps)	-	测量指针本身的大小（64位系统是8，32是4）
//指针类型决定了解引用时访问几个字节
//int*访问4个字节
//char*访问1个字节

//int my_strlen(char* a)
//{
//	int count = 0;
//	while (*a != '\0')
//	{
//		count++;
//		a++;
//	}
//	return count;
//}

int my_strlen(const char* a)
{
	const char* start = a;
	while (*a != '\0')
	{
		a++;
	}
	return (int)(a - start);
}

//声明Peo结构体类型
struct peo
{
	char name[20];
	char tele[12];
	char sex[5];
	int high;
}; 

struct peo1
{
	char name[20];
	char tele[12];
	char sex[5];
	int high;
}p3, p2;	//p1和p2是两个全局变量，一般不使用

struct st
{
	struct peo p;
	int num;
	float f;
};

void print(struct peo* a)
{
	printf("%s %s %s %d\n", a->name, a->tele, a->sex, a->high);
}

void print1(struct peo a)
{
	printf("%s %s %s %d\n", a.name, a.tele, a.sex, a.high);

}

int main()
{
	//char* ps = NULL;
	//short* pr = NULL;
	//int* pt = NULL;
	//double* pd = NULL;

	//printf("char:%d\n", sizeof(ps));
	//printf("short:%d\n", sizeof(pr));
	//printf("int:%d\n", sizeof(pt));
	//printf("double:%d\n", sizeof(pd));
	
	int len = my_strlen("abcdef");
	printf("%d\n", len);

	//int i = 0;

	//int a = 10;
	//int b = 20;
	//int c = 30;
	//int arr[10] = { a,b,c };
	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d：%d\n", i, arr[i]);
	//}
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//int* pa = &a;
	//int* pb = &b;
	//int* pc = &c;
	//int* parr[10] = { &a,&b,&c };
	//for (i = 0; i < sz; i++)
	//{
	//	printf("%d：%d\n", i, *(parr[i]));
	//}

	int arr1[4] = { 1,2,3,4 };
	int arr2[4] = { 2,3,4,5 };
	int arr3[4] = { 3,4,5,6 };
	int i;

	int* parr1[3] = { arr1,arr2,arr3 };
	for (i = 0; i < 3; i++)
	{
		int j;
		for (j = 0; j < 4; j++)
		{
			printf("%d ", parr1[i][j]);
		}
		printf("%\n");
	}

	//结构体变量的创建
	struct peo p1 = { "张三", "17316627835", "男", 181 };
	struct st s1 = { {"李四", "13636819378", "女", 185}, 100, 3.14f };
	printf("%s %s %s %d\n", p1.name, p1.tele, p1.sex, p1.high);
	printf("%s %s %s %d %d %.2f\n", s1.p.name, s1.p.tele, s1.p.sex, s1.p.high, s1.num, s1.f);

	//指针情况下，传输地址使用箭头"->"找到成员变量
	//建议使用地址传输，在函数压栈的过程中性能更高
	print(&p1);
	//传输变量内容时使用"."找到成员变量
	print1(p1);

	return 0;

}