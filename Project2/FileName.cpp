#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

void uint32_to_binary_str(uint32_t num, char* str)
{
    for (int i = 31; i >= 0; i--) 
    {
        str[31 - i] = (num >> i) & 1 ? '1' : '0';
    }
    str[32] = '\0';
}

int main() 
{
    float num1;
    scanf_s("%f", &num1);
    union 
    {
        float f;
        uint32_t u;
    } u_num;
    u_num.f = num1;
    char binary_str[33];
    uint32_to_binary_str(u_num.u, binary_str);
    printf("num1的二进制: %s\n", binary_str);

    return 0;

}