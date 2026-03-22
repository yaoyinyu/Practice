#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

struct A
{
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;
	//47 bit
};

int main()
{
	printf("%d\n", sizeof(struct A));

	return 0;

}