#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<errno.h>
#include<string>

struct S
{
	char arr[10];
	int age;
	float score;
};

int main()
{
	//打开文件
	//FILE* pf = fopen("test.txt", "a");
	//if (pf == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 1;
	//}

	//写入文件
	//char i = 0;
	//for (i = 'a'; i <= 'z'; i++)
	//{
	//	fputc(i, pf);
	//}
	//fputs("hello bit\n", pf);

	//读取文件
	//int ch = fgetc(pf);
	//printf("%c\n", ch);
	//int ch = 0;
	//while ((ch = fgetc(pf)) != EOF)
	//{
	//	printf("%c\n", ch);
	//}

	//关闭文件
	//fclose(pf);
	//pf = NULL;

	struct S s = { "zhangsan", 20, 55.5f };
	struct S tmp;
	char buf[100] = { 0 };

	//sprintf - 将一个格式化的数据转换成字符串的形式
	sprintf(buf, "%s %d %f", s.arr, s.age, s.score);

	//"zhangsan 20 55.500000"
	printf("字符串：%s\n", buf);

	//sscanf - 从一个字符串中转换出一个格式化数据
	//从字符串buf中获取一个格式化的数据到tmp中
	sscanf(buf, "%s %d %f", tmp.arr, &(tmp.age), &(tmp.score));
	printf("格式化：%s %d %f\n", tmp.arr, tmp.age, tmp.score);


	return 0;

}