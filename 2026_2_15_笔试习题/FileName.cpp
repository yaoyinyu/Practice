#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Arr(int i, int j)
{

}

int main()
{
	//int arr[] = { 0 };
	//int i, j;
	//int* parr[] = { arr };
	//Arr(i, j);
	//void (*pArr)(int, int) = Arr;
	//void (*parr[])(int, int) = { *pArr };

	//int a[3][4] = { 0 };
	//printf("%d\n", sizeof(a[3]));	//sizeof不存在越界访问，这里接收和前几行同等的元素类型（int * 4 = 16）

	//int a[4] = { 1,2,3,4 };
	////01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00
	//int* ptr1 = (int*)(&a + 1);			//跳过一整个整型数组
	//int* ptr2 = (int*)((int)a + 1);		//跳过一个字节对00 00 00 02进行访问（小端存储），最终进行使用的时候变成2000000
	//printf("%x, %x", ptr1[-1], *ptr2);	//x86端运行，x64会出现内存大小对int类型的溢出

	//int a[3][2] = { (0,1),(2,3),(4,5) };	//逗号表达式{ 1,3,5,0,0,0 }
	//int* p;
	//p = a[0];
	//printf("%d", p[0]);

	//const char* a[] = { "work","at","alibaba" };
	//const char** pa = a;
	//pa++;
	//printf("%s\n", *pa);

	const char* c[] = { "ENTER","NEW","POINT","FIRST" };
	const char** cp[] = { c + 3,c + 2,c + 1,c };
	const char*** cpp = cp;

	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);	//对应文件夹内有动画演示



	return 0;

}