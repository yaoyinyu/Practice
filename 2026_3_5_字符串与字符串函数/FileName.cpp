#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>

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

int main()
{
	char arr[] = { 'b','i','t' };
	char arr1[] = { "abcdef" };
	int len = strlen(arr);		//无“\0”则产生随机值
	int len1 = strlen(arr1);	//strlrn仅计算“\0”之前的字符长度不包括“\0”(不是所占空间大小，不同于sizeof) 
	//strlen返回unsigned int类型（size_t）
	printf("%d\n", len);
	printf("%d\n", len1);

	if (strlen("abc") - strlen("abcdef") > 0)	//无符号整形没有负数
	{
		printf(">\n");
	}
	else
	{
		printf("<\n");
	}

	size_t n = my_strlen(arr1);
	printf("%u\n", n);

	char name[20] = { 0 };
	strcpy(name, "ZhangSan");	//遇到“\0”停止并将“\0”拷贝
	//strcpy(name, arr);			//Err，无“\0”无法进行拷贝
	printf("%s\n", name);

	//strcpy的目标空间大小必须可以修改
	//const char* p = "abcdef";
	//char arr2[] = "bit";
	//strcpy(p, arr2);		//目标空间大小无法修改

	char arr2[] = "abcdef";
	char arr3[20] = { 0 };
	my_strcpy(arr3, arr2);
	printf("%s\n", arr3);

	// strcat
	// 目标空间足够大
	// 目标空间大小可修改
	// 必须包含“\0”
	char arr4[20] = { "Change " };
	strcat(arr4, "World ");
	printf("%s\n", arr4);

	my_strcat(arr4, "Yeah");
	//my_strcat(arr4, arr4);	//无法自增加
	printf("%s\n", arr4);

	return 0;

}