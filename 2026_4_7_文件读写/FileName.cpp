#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<errno.h>
#include<string>

int main()
{
	//打开文件
	FILE* pf = fopen("test.txt", "a");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}

	//写入文件
	//char i = 0;
	//for (i = 'a'; i <= 'z'; i++)
	//{
	//	fputc(i, pf);
	//}
	fputs("hello bit\n", pf);

	//读取文件
	//int ch = fgetc(pf);
	//printf("%c\n", ch);
	//int ch = 0;
	//while ((ch = fgetc(pf)) != EOF)
	//{
	//	printf("%c\n", ch);
	//}

	//关闭文件
	fclose(pf);
	pf = NULL;

	return 0;

}