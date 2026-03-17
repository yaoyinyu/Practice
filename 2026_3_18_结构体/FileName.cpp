#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

struct Stu
{
	char name[20];
	int age;
}s1,s2;		//全局变量

struct Node
{
	int data;
	struct Node next;
};

int main()
{
	struct Stu s3;	//局部变量


	return 0;

}