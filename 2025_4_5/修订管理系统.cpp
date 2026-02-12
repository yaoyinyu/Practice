#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// === 常量与宏定义 ================================================
#define MAX_STU 5           // 最大学生数量
#define MAX_INFO 32         // 学号/姓名最大长度（支持16汉字）
#define MAX_SUB 5           // 考试科目数
#define AGE_RANGE "12-100"   // 年龄范围提示
#define MAX_SCORE 100       // 单科最高分
#define MIN_SCORE 0         // 单科最低分

// ANSI颜色宏（需终端支持）
#define ANSI_COLOR(n) "\033[38;5;"#n"m"
#define ANSI_RESET "\033[0m"
#define COLOR_GREEN ANSI_COLOR(2)
#define COLOR_BLUE ANSI_COLOR(4)
#define COLOR_YELLOW ANSI_COLOR(3)
#define COLOR_CYAN ANSI_COLOR(6)
#define COLOR_RED ANSI_COLOR(1)

// === 结构体定义 ==================================================
typedef struct
{
    char code[MAX_INFO];  // 学号（）
    char name[MAX_INFO];  // 姓名（支持16汉字）
    int age;              // 年龄（12-100岁）
    char sex;             // 性别（M/F）
    int scores[MAX_SUB];  // 各科成绩
    int total;            // 总分
    float avg;            // 平均分（浮点）
} Student;

// === 全局变量 ====================================================
const char* subjects[] = { "语文", "数学", "英语", "物理", "化学" }; // 科目名称

// === 函数声明 ====================================================
void init_system();
void input_student(Student* stu, int idx);
bool validate_code(const char* code);
char input_sex();
void input_scores(Student* stu);
void print_table(Student* stus);
void analyze_grades(Student* stus);
void clear_input();
int count_chars(const char* str);
void print_divider(const char* title);
const char* join(const char* arr[], int n, const char* sep);

// === 主函数 ======================================================
int main()
{
    Student students[MAX_STU] = { 0 }; // 初始化结构体数组

    init_system(); // 系统初始化

    // 学生信息录入流程
    for (int i = 0; i < MAX_STU; i++)
    {
        printf("\n正在录入第%d/%d位学生\n", i + 1, MAX_STU);
        input_student(&students[i], i + 1);
        input_scores(&students[i]);
    }

    // 结果展示
    print_table(students);
    analyze_grades(students);

    return 0;
}

// === 函数实现 ====================================================

// 系统初始化
void init_system()
{
    system("cls||clear"); // 跨平台清屏
    puts(R"(
 ██████╗ ██████╗ ███████╗██╗   ██╗    ██████╗ ███████╗██████╗ 
██╔════╝██╔═══██╗██╔════╝██║   ██║    ██╔══██╗██╔════╝██╔══██╗
██║     ██║   ██║███████╗██║   ██║    ██████╔╝█████╗  ██████╔╝
██║     ██║   ██║╚════██║██║   ██║    ██╔══██╗██╔══╝  ██╔══██╗
╚██████╗╚██████╔╝███████║╚██████╔╝    ██████╔╝███████╗██║  ██║
 ╚═════╝ ╚═════╝ ╚══════╝ ╚═════╝     ══════╝ ╚══════╝╚═╝  ╚═╝
    )");
    print_divider("学生信息管理系统 V2.1");
    printf("本系统支持录入%d名学生，每生%d科成绩（%s）\n",
        MAX_STU, MAX_SUB, join(subjects, MAX_SUB, "、"));
}

// 学生基本信息录入（带严格校验）
void input_student(Student* stu, int idx)
{
    // 学号校验（字母开头，6-12位，支持数字/下划线）
    while (1)
    {
        printf("\n[%d] 学号（字母开头，6-12位）: ", idx);
        fgets(stu->code, MAX_INFO, stdin);
        stu->code[strcspn(stu->code, "\n")] = '\0';
        if (validate_code(stu->code)) break;
        printf(COLOR_RED "✖ 学号格式错误！示例：S_2024001（6-12位）" ANSI_RESET "\n");
    }

    // 姓名校验（2-8汉字，兼容全角）
    printf("[%d] 姓名（2-8汉字）: ", idx);
    do
    {
        fgets(stu->name, MAX_INFO, stdin);
        stu->name[strcspn(stu->name, "\n")] = '\0';
        if (count_chars(stu->name) < 2 || count_chars(stu->name) > 8)
        {
            printf(COLOR_RED "✖ 姓名需2-8汉字！当前：%d字" ANSI_RESET "\n",
                count_chars(stu->name));
        }
    } while (count_chars(stu->name) < 2 || count_chars(stu->name) > 8);

    // 年龄校验（12-100岁）
    printf("[%d] 年龄（%s）: ", idx, AGE_RANGE);
    while (1)
    {
        if (scanf_s("%d", &stu->age) == 1 && stu->age >= 12 && stu->age <= 100)
        {
            clear_input();
            break;
        }
        printf(COLOR_RED "✖ 年龄超出范围！%s: " ANSI_RESET, AGE_RANGE);
        clear_input();
    }

    // 性别输入（带图标提示）
    stu->sex = input_sex();
}

// 性别输入（带可视化提示）
char input_sex()
{
    char c;
    printf(COLOR_CYAN "[性别] 👨(M) / 👩(F): " ANSI_RESET);
    while (1)
    {
        c = toupper(getchar());
        clear_input();
        if (c == 'M' || c == 'F') return c;
        printf(COLOR_RED "✖ 请输入M/F: " ANSI_RESET);
    }
}

// 成绩录入（带科目名称和动态标题）
void input_scores(Student* stu)
{
    char title[100];
    snprintf(title, sizeof(title), "📚 成绩录入 - %s", stu->name); // 安全拼接
    print_divider(title);

    stu->total = 0;
    for (int i = 0; i < MAX_SUB; i++)
    {
        int score;
        while (1)
        {
            printf("▷ %-6s成绩（%d-%d）: ", subjects[i], MIN_SCORE, MAX_SCORE);
            if (scanf_s("%d", &score) == 1 && score >= MIN_SCORE && score <= MAX_SCORE)
            {
                stu->scores[i] = score;
                stu->total += score;
                clear_input();
                break;
            }
            printf(COLOR_RED "✖ 成绩无效！请输入%d-%d的整数: " ANSI_RESET,
                MIN_SCORE, MAX_SCORE);
            clear_input();
        }
    }
    stu->avg = (float)stu->total / MAX_SUB; // 浮点平均分
}

// 学生信息表格展示（ASCII表格）
void print_table(Student* stus)
{
    print_divider("📊 学生信息总览");
    printf("┌────┬───────────┬────────┬────┬────┐\n");
    printf("│ ID │ 学号        │ 姓名   │ 年龄 │ 性别 │\n");
    printf("├────┼───────────┼────────┼────┼────┤\n");
    for (int i = 0; i < MAX_STU; i++)
    {
        printf("│ %2d │ %-9s │ %-6s │ %3d │ %2c │\n",
            i + 1, stus[i].code, stus[i].name, stus[i].age, stus[i].sex);
    }
    printf("└────┴───────────┴────────┴────┴────┘\n");
}

// 成绩分析（带颜色等级+雷达图+进度条）
void analyze_grades(Student* stus)
{
    const char* level[] = { "不及格", "及格", "中等", "良好", "优秀" };
    const char* colors[] = { COLOR_RED, COLOR_CYAN, COLOR_YELLOW, COLOR_BLUE, COLOR_GREEN };

    print_divider("📈 成绩分析报告");
    for (int i = 0; i < MAX_STU; i++)
    {
        Student* s = &stus[i];
        int level_idx = (int)(s->avg / 10) - 5;
        level_idx = level_idx < 0 ? 0 : (level_idx > 4 ? 4 : level_idx);

        // 学生基本信息
        printf("\n【%s】学号: %s\n", s->name, s->code);
        printf("  %s总分: %3d │ 平均分: %.1f %s[%s]%s\n",
            COLOR_BLUE, s->total, s->avg, colors[level_idx],
            level[level_idx], ANSI_RESET);

        // 科目成绩雷达图
        printf("  各科成绩: ");
        for (int j = 0; j < MAX_SUB; j++) 
        {
            char trend = s->scores[j] > s->avg ? '▲' :
                s->scores[j] < s->avg ? '▼' : '─';
            printf("%s:%d%s ", subjects[j], s->scores[j],
                trend == '▲' ? COLOR_GREEN : (trend == '▼' ? COLOR_RED : ""));
            printf(ANSI_RESET); // 重置颜色
        }

        // 学习进度条（50格）
        int bar = (int)(s->avg / 2);
        printf("\n  学习进度: ▏");
        for (int j = 0; j < 50; j++)
        {
            printf(j < bar ? COLOR_GREEN "█" ANSI_RESET : " ");
        }
        printf("▕ %.0f%%\n", s->avg);
    }
}

// === 工具函数 ====================================================

// 清理输入缓冲区
void clear_input()
{
    while (getchar() != '\n');
}

// 计算字符串字符数（区分全半角）
int count_chars(const char* str)
{
    int count = 0;
    while (*str)
    {
        count++;
        str += (*(unsigned char*)str > 0x80) ? 2 : 1; // 简单处理双字节字符
    }
    return count;
}

// 学号格式校验
bool validate_code(const char* code)
{
    int len = strlen(code);
    return len >= 6 && len <= 12
        && isalpha(code[0])
        && strspn(code, "0123456789_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == len;
}

// 打印分隔线
void print_divider(const char* title)
{
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║  %-30s  ║\n", title);
    printf("╚════════════════════════════════════════╝\n");
}

// 数组拼接
const char* join(const char* arr[], int n, const char* sep)
{
    static char buf[1024] = { 0 };
    for (int i = 0; i < n; i++)
    {
        strncat_s(buf, arr[i], sizeof(buf) - strlen(buf) - 1);
        if (i != n - 1 && sizeof(buf) - strlen(buf) > strlen(sep))
        {
            strcat_s(buf, sep);
        }
    }
    return buf;
}