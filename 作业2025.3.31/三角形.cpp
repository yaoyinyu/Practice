//#include <stdio.h>
//#include <math.h>
//#define _CRT_SECURE_NO_WARNINGS
//
//int main() 
//{
//    float a, b, c;
//
//	printf("姚胤宇 2401060606\n");
//    printf("请输入三角形三个边长：");
//    scanf_s("%f%f%f", &a, &b, &c);
//    printf("边长 a=%.2f, b=%.2f, c=%.2f\n", a, b, c);
//
//    if (a + b > c && a + c > b && b + c > a) 
//    {
//        if (fabs(a - b) < 1e-6 && fabs(b - c) < 1e-6) 
//        {
//            printf("等边三角形\n");
//        }
//        else if (fabs(a - b) < 1e-6 || fabs(a - c) < 1e-6 || fabs(b - c) < 1e-6) 
//        {
//            printf("等腰三角形\n");
//        }
//        else 
//        {
//            if (fabs(a * a + b * b - c * c) < 1e-6 || fabs(a * a + c * c - b * b) < 1e-6 || fabs(b * b + c * c - a * a) < 1e-6) 
//            {
//                printf("直角三角形\n");
//            }
//            else 
//            {
//                printf("一般三角形\n");
//            }
//        }
//    }
//    else 
//    {
//        printf("不能构成三角形\n");
//    }
//
//    return 0;
//}