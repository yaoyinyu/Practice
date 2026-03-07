#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
#include<ctype.h>

size_t my_strlen(const char* str)
{
	assert(str);
	size_t count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

char* my_strcpy(char* str1, const char* str2)
{
	assert(str1 && str2);
	int i = 0;
	char* ret = str1;
	while ((str1[i] = str2[i]) != '\0')
	{
		i++;
	}
	return ret;
}

char *my_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int my_strcmp(const char* arr1,  const char* arr2)
{
	assert(arr1 && arr2);
	while (*arr1 == *arr2)
	{
		if (*arr1 == '\0')
		{
			return 0;
		}
		arr1++;
		arr2++;
	}
	return (*arr1 - *arr2);
}

char *my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* p = str1;
	while (*p)
	{
		s1 = p;
		s2 = str2;
		while (*s1 != '\0' && *s2 != '\0' && * s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)p;
		}
		p++;
	}
	return NULL;
}

void* my_memcpy(void* dest, void* src, size_t num)
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

int main()
{
	//char arr[] = { 'b','i','t' };
	//char arr1[] = { "abcdef" };
	//int len = strlen(arr);		//无“\0”则产生随机值
	//int len1 = strlen(arr1);	//strlrn仅计算“\0”之前的字符长度不包括“\0”(不是所占空间大小，不同于sizeof) 
	////strlen返回unsigned int类型（size_t）
	//printf("%d\n", len);
	//printf("%d\n", len1);

	//if (strlen("abc") - strlen("abcdef") > 0)	//无符号整形没有负数
	//{
	//	printf(">\n");
	//}
	//else
	//{
	//	printf("<\n");
	//}

	//size_t n = my_strlen(arr1);
	//printf("%u\n", n);

	//char name[20] = { 0 };
	//strcpy(name, "ZhangSan");	//遇到“\0”停止并将“\0”拷贝
	////strcpy(name, arr);			//Err，无“\0”无法进行拷贝
	//printf("%s\n", name);

	////strcpy的目标空间大小必须可以修改
	////const char* p = "abcdef";
	////char arr2[] = "bit";
	////strcpy(p, arr2);		//目标空间大小无法修改

	//char arr2[] = "abcdef";
	//char arr3[20] = { 0 };
	//my_strcpy(arr3, arr2);
	//printf("%s\n", arr3);

	//// strcat
	//// 目标空间足够大
	//// 目标空间大小可修改
	//// 必须包含“\0”
	//char arr4[20] = { "Change " };
	//strcat(arr4, "World ");
	//printf("%s\n", arr4);

	//my_strcat(arr4, "Yeah");
	////my_strcat(arr4, arr4);	//无法自增加
	//printf("%s\n", arr4);

	//char arr1[20] = "zhangsan";
	//char arr2[20] = "zhangsanfeng";
	////判断字符串是否相等
	////arr1和arr2是数组名
	////数组名是首元素地址
	////地址不相等
	////if (arr1 == arr2)		//Err地址比较
	////{
	////	printf("==\n");
	////}
	////else
	////{
	////	printf("!=\n");
	////}
	//int ret = strcmp(arr1, arr2);
	////strcmp比较内容Asic大小不比较长度
	//if (ret < 0)
	//	printf("<\n");
	//else if (ret == 0)
	//	printf("==\n");
	//else
	//	printf(">\n");

	//int ret1 = my_strcmp(arr1, arr2);
	//if (ret1 < 0)
	//	printf("<\n");
	//else if (ret1 == 0)
	//	printf("==\n");
	//else
	//	printf(">\n");

	//char arr1[20] = "abcdef";
	//char arr2[] = "hello bit";
	////strcpy(arr1, arr2);
	//strncpy(arr1, arr2, 5);
	//strncat(arr1, arr2, 3);
	//printf("%s\n", arr1);

	//char arr3[] = "abcdef";
	//char arr4[] = "abc";
	//int ret = strncmp(arr3, arr4, 3);
	//if (ret < 0)
	//	printf("<\n");
	//else if (ret == 0)
	//	printf("==\n");
	//else
	//	printf(">\n");

	//char email[] = "3181484805@qq.com";
	//char substr[] = "@qq.com";
	//char* ret = strstr(email, substr);
	//if (ret == NULL)
	//{
	//	printf("子串不存在");
	//}
	//else
	//{
	//	printf("%s\n", ret);
	//}

	//char* ret1 = my_strstr(email, substr);
	//if (ret1 == NULL)
	//{
	//	printf("子串不存在");
	//}
	//else
	//{
	//	printf("%s\n", ret1);
	//}

	const char* sep = "@.";
	char email[] = "3181484805@qq.com";
	char cp[30] = { 0 };
	strcpy(cp, email);

	char* ret = NULL;
	for (ret = strtok(cp, sep);
		ret != NULL;
		ret = strtok(NULL, sep))
	{
		printf("%s\n", ret);
	}

	//char* ret = strtok(cp, sep);
	//printf("%s\n", ret);

	//ret = strtok(NULL, sep);
	//printf("%s\n", ret);

	//ret = strtok(NULL, sep);
	//printf("%s\n", ret);	

	//ret = strtok(NULL, sep);
	//printf("%s\n", ret);


	//errno - c语言设置的一个全局变量，存放错误代码
	//errno始终存放最新的错误代码
	FILE* pf = fopen("C:\\Users\\YaoYinyu\\Desktop\\IMG_5202.JPG", "r");	//绝对路径“\”需要进行转译“\\”
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}

	int a = isspace(' ');
	printf("%d\n", a);


	//memcpy不能进行内存重叠拷贝
	//需要使用memmove
	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
	int arr2[20] = { 0 };
	my_memcpy(arr2, arr1, 36);
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		printf("%d\n", arr2[i]);
	}


	return 0;

}