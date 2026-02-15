#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Arr(int i, int j)
{

}

int main()
{
	int arr[] = { 0 };
	int i, j;
	int* parr[] = { arr };
	Arr(i, j);
	void (*pArr)(int, int) = Arr;
	void (*parr[])(int, int) = { *pArr };

	return 0;

}