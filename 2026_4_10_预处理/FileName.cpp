#define _CRT_SECURE_NO_WARNINGS 1

#define SQUARE(X) ((X)*(X))
//#define PRINT(N) printf("the value of "#N" is %d", N)
#define PRINT(N, FORMAT) printf("the value of "#N" is " FORMAT "\n", N)
#define CAT(Class, Num) Class##Num

#include<stdio.h>

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	int r = SQUARE(5);
	PRINT(r, "%d");

	float f = 3.14f;
	PRINT(f, "%f");

	int Class106 = 100;
	printf("%d\n", CAT(Class, 106));

	return 0;

}