#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stddef.h>

struct Stu
{
	char name[20];
	int age;
}s1,s2;		//全局变量

struct Node
{
	int data;	
	struct Node* next;		//结构体的自引用，结构体内不能包含同类型的结构体
}* Linklest;

struct S1
{
	char c1;
	int i;
	char c2;
};

struct S2
{
	char c1;
	char c2;
	int i;
};

struct S3
{
	char c1;
	char c2;
	char c3;
	char c4;
	int i;
};

struct S
{
	int data[1000];
	int num;
};

void print1(struct S ss)
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%d ", ss.data[i]);
	}
	printf("%d\n", ss.num);
}

void print2(struct S* ps)
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("%d\n", ps->num);
}

int main()
{
	struct Stu s3;	//局部变量

	printf("%d\n", sizeof(struct S1));
	printf("%d\n", sizeof(struct S2));
	printf("%d\n", sizeof(struct S3));

	printf("\n");

	printf("%d\n", offsetof(struct S1, c1));
	printf("%d\n", offsetof(struct S1, i));
	printf("%d\n", offsetof(struct S1, c2));

	printf("\n");

	struct S s = { {1,2,3}, 100 };
	print1(s);		//传值调用（多余系统开销，效率下降）
	print2(&s);		//传址调用


	return 0;

}