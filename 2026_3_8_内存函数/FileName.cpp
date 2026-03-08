#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>

void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}

void* my_memmove(void* dest, void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	if (dest < src)
	{
		//从前向后
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		//从后向前
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}

void test1()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[20] = {};
	my_memcpy(arr2, arr1, 20);
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");
}

void test2()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr1 + 2, arr1, 20);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
}


int main()
{
	test1();
	test2();



	return 0;

}