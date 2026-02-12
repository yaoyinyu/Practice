//#include <stdio.h>
//#include <math.h>
//
//int main() {
//    // 计算三角形面积部分
//    float side_a, side_b, side_c, semi_perimeter, triangle_area;
//    printf("输入 a,b,c:");
//    scanf("%f,%f,%f", &side_a, &side_b, &side_c);
//    if (side_a + side_b > side_c && side_b + side_c > side_a && side_a + side_c > side_b) {
//        semi_perimeter = (side_a + side_b + side_c) / 2;
//        triangle_area = sqrt(semi_perimeter * (semi_perimeter - side_a) * (semi_perimeter - side_b) * (semi_perimeter - side_c));
//        printf("area = %.2f\n", triangle_area);
//    }
//    else {
//        printf("您输入的数字无法构成三角形\n");
//    }
//
//    // 计算简单利息存款部分
//    float years;
//    double interest_rate, principal, simple_deposit;
//    printf("输入利率，本金,存期:");
//    scanf("%f,%lf,%f", &interest_rate, &principal, &years);
//    simple_deposit = principal * (1 + interest_rate * years);
//    printf("deposit = %.2f\n", simple_deposit);
//
//    // 清空输入缓冲区
//    while (getchar() != '\n');
//
//    // 字符判断部分
//    printf("任意按一个键然后回车");
//    char input_char = getchar();
//    if ((input_char >= 'a' && input_char <= 'z') || (input_char >= 'A' && input_char <= 'Z')) {
//        printf("您输入的是一个英文字母!\n");
//    }
//    else if (input_char <= '9' && input_char >= '0') {
//        printf("您输入的是一个数字字符!\n");
//    }
//    else if (input_char == ' ') {
//        printf("您输入的是一个空格字符!\n");
//    }
//    else {
//        printf("您输入的是一个其他字符!\n");
//    }
//
//    // 求三个数中的最大值部分
//    int num1, num2, num3, max_num;
//    printf("输入三个整数，用逗号分隔:");
//    scanf("%d,%d,%d", &num1, &num2, &num3);
//    max_num = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);
//    printf("最大值是: %d\n", max_num);
//
//    return 0;
//}