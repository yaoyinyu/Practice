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

//内存拷贝
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

//内存移动
void test2()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr1 + 2, arr1, 20);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
}

//内存比较
void test3()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,3 };
	int ret = memcmp(arr1, arr2, 4);
	printf("%d\n", ret);
}

//内存设置
void test4()
{
	char arr1[] = "hello world";
	memset(arr1 + 6, 'x', 4);
	printf("%s\n", arr1);
}
//memset设置每个字节而不是每个整形
void test5()
{
	int arr[10] = { 0 };
	memset(arr, 1, 40);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();



	return 0;

}