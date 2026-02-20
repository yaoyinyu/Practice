#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int main()
{
	char arr[] = { 'b','i','t' };
	char arr1[] = { "abcdef" };
	int len = strlen(arr);			//无“\0”则产生随机值
	int len1 = strlen(arr1);		//strlrn仅计算“\0”之前的字符长度(不是所占空间大小，不同于sizeof) 
	//strlen返回unsigned int类型（size_t）
	printf("%d\n", len);
	printf("%d\n", len1);

	return 0;

}