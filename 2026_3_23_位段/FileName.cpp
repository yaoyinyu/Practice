#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

struct A
{
	//4byte - 32 bit
	int _a : 2;
	int _b : 5;
	int _c : 10;
	//4byte - 27 bit
	//		  15 bit
	int _d : 30;
	//4byte - 32 bit
	// 
	//		  47 bit
	//6byte - 48 bit
	//8byte - 64 bit
};

int main()
{
	printf("%d\n", sizeof(struct A));

	return 0;

}