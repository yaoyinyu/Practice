//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//
//#define max_stu 5    //学生数量
//#define max_len 20   //学号/姓名最大长度
//#define max_sub 5    //科目数量
//#define max_score 100 //最大分数
//#define min_score 0   //最小分数
//#define max_age 100  //最大年龄
//#define min_min 1    //最小年龄
//#define max_name 20  //姓名最大长度
//#define max_code 20  //学号最大长度
//#define max_grade 100 //成绩最大值
//#define min_grade 0   //成绩最小值
//#define max_zongfen 500 //总分最大值
//#define min_zongfen 0   //总分最小值
//#define max_avg 100   //平均分最大值
//#define min_avg 0     //平均分最小值
//
//int main()
//{
//    printf("姚胤宇，2401060606");
//
//    char code[max_stu][max_len] = { 0 };
//    char name[max_stu][max_len] = { 0 };
//    int age[max_stu] = { 0 };
//    char sex[max_stu] = { 0 };
//
//    int grade[max_stu][5] = { 0 };
//    int total[max_stu] = { 0 }, avg[max_stu] = { 0 };
//    int i, j;
//
//    puts("\n\n                              \n\n");
//    puts(" ********************************************************************************");
//    puts("  *                        学生信息管理系统                          *\n ");
//    puts(" ********************************************************************************");
//    puts("              ---------------------      ");
//    puts("              *********************************      ");
//    puts("  * 本系统可完成学生信息的录入、显示与期末成绩统计的功能。 ");
//    puts("  * 请按照提示操作:  ");
//    puts("              ---------------------      ");
//
//    //输入缓冲区清理，安全输入
//    printf("              *********************************      \n");
//    printf("  * 录入学生信息（共%d人）:  \n", max_stu);
//    printf("              *********************************      \n");
//    for (i = 0; i < max_stu; i++)
//    {
//        printf("\n---- 录入第%d位学生（共%d位） ----\n", i + 1, max_stu);
//
//        //学号输入
//        printf("学号（%d字符以内）: ", max_len - 1);
//        while (1)
//        {
//            if (fgets(code[i], max_len, stdin) != NULL)
//            {  //安全输入
//                code[i][strcspn(code[i], "\n")] = '\0';
//                if (strlen(code[i]) > 0) break;
//            }
//            printf("输入无效，请重新输入: ");
//        }
//
//        //姓名输入
//        printf("姓名（%d字符以内）: ", max_len - 1);
//        while (1)
//        {
//            if (fgets(name[i], max_len, stdin) != NULL) 
//            {
//                name[i][strcspn(name[i], "\n")] = '\0';
//                if (strlen(name[i]) > 0) break;
//            }
//            printf("输入无效，请重新输入: ");
//        }
//
//        //年龄输入
//        printf("年龄（1-100）: ");
//        while (1)
//        {
//            if (scanf_s("%d", &age[i]) == 1 && age[i] >= 1 && age[i] <= 100)
//            {
//                while (getchar() != '\n');  //清理缓冲区
//                break;
//            }
//            printf("年龄无效，请重新输入: ");
//            while (getchar() != '\n');  //清空错误输入
//        }
//
//        //性别输入
//        printf("性别（M/F）: ");
//        while (1)
//        {
//            int c = getchar();
//            while (getchar() != '\n');  //清理至换行
//            if (c == 'M' || c == 'F' || c == 'm' || c == 'f')
//            {
//                sex[i] = toupper(c);  //统一大写
//                break;
//            }
//            printf("性别无效，请重新输入（M/F）: ");
//        }
//    }
//
//    //显示学生信息
//    puts("\n              ---------------------      ");
//    puts("              *********************************      ");
//    puts("  * 已录入的学生信息:  ");
//    puts("              *********************************      ");
//    printf("%-4s%-8s%-6s%-4s%-3s\n", "编号", "学号", "姓名", "年龄", "性别");
//    for (i = 0; i < max_stu; i++) {
//        printf("%-4d%-8s%-6s%-4d%-3c\n",
//            i + 1, code[i], name[i], age[i], sex[i]);
//    }
//
//    //成绩录入
//    puts("\n              ---------------------      ");
//    puts("              *********************************      ");
//    puts("  * 录入考试成绩（5科，0-100分）:  ");
//    puts("              *********************************      ");
//    for (i = 0; i < max_stu; i++)
//    {
//        printf("\n---- 学生%s（学号：%s）的成绩 ----\n", name[i], code[i]);
//        total[i] = 0;
//        for (j = 0; j < 5; j++)
//        {
//            int score;
//            printf("科目%d成绩: ", j + 1);
//            while (1)
//            {
//                if (scanf_s("%d", &score) == 1 && score >= 0 && score <= 100)
//                {
//                    grade[i][j] = score;
//                    total[i] += score;
//                    while (getchar() != '\n');  //清理缓冲区
//                    break;
//                }
//                printf("成绩无效（0-100），请重新输入: ");
//                while (getchar() != '\n');  //清空错误输入
//            }
//        }
//        avg[i] = total[i] / 5;
//    }
//
//    //成绩统计
//    puts("\n              ---------------------      ");
//    puts("              *********************************      ");
//    puts("  * 成绩统计结果:  ");
//    puts("              *********************************      ");
//    for (i = 0; i < max_stu; i++)
//    {
//        printf("\n【学生%d】%s（%s）\n", i + 1, name[i], code[i]);
//        printf("总成绩: %3d | 平均分: %3d | ", total[i], avg[i]);
//
//        //颜色标记等级
//        if (avg[i] >= 90) printf("\033[32m[优秀]\033[0m\n");  //绿色
//        else if (avg[i] >= 80) printf("\033[34m[良好]\033[0m\n");  //蓝色
//        else if (avg[i] >= 70) printf("\033[33m[中等]\033[0m\n");  //黄色
//        else if (avg[i] >= 60) printf("\033[36m[及格]\033[0m\n");  //青色
//        else printf("\033[31m[不及格]\033[0m\n");  //红色
//    }
//
//    return 0;
//}