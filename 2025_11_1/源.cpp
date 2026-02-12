#define _CRT_SECURE_NO_WARNINGS  //禁用安全警告
#include <stdio.h>
#include <string.h>

void print(unsigned int num)
{
    if (num > 9)
    {
        print(num / 10);
    }
    printf("%d\n", num % 10);
}

//int my_strlen(char* str)
//{
//    int count = 0;
//    while(*str != '\0')
//    {
//        count++;
//		str++;  //指针后移
//    }
//    return count;
//}

int my_strlen(char* str)
{
    if (*str != '\0')
    {
        return 1 + my_strlen(str +1);
    }
    else
    {
        return 0;
    }
}

int main()
{
    unsigned int a;
    scanf_s("%u", &a);
    print(a);

	char arr[] = "abcdef";
    int len = my_strlen(arr);   //
	printf("len=%d\n", len);

    return 0;
}