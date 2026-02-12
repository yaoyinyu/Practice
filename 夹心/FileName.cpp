#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031) // 忽略返回值被忽略的警告
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENT 100  //学生数
#define MAX_TEACHER 50   //教师数
#define MAX_COURSE 20    //课程数
#define MAX_NOTICE 30    //通知数
#define MAX_SIGNUP 10    //报名项数
#define MAX_STR_LEN 50   //字符串最大长度

//用户类型
typedef enum {
    STUDENT,
    TEACHER,
    ADMIN
} UserType;

//学生信息
typedef struct {
    char id[20];     //学号
    char name[20];   //姓名
    char pwd[20];    //密码
    char gender[10]; //性别
    int age;         //年龄
} Student;

//课程成绩
typedef struct {
    char stu_id[20]; //学号
    char course_id[20]; //课程号
    char course_name[30]; //课程名
    float score;     //成绩
} Score;

//教师信息
typedef struct {
    char id[20];     //教师编号 
    char name[20];   //姓名
    char pwd[20];    //密码
    char course_id[20]; //负责课程编号 
} Teacher;

//通知
typedef struct {
    char title[50];  //标题
    char content[200]; //内容
    char type[20];   //类型：成绩/补考
} Notice;

//报名信息
typedef struct {
    char id[20];     //报名项ID
    char course_id[20]; //课程编号
    char content[100]; //报名说明
} Signup;


//清空输入缓冲区
void clearBuffer() {
    while (getchar() != '\n');
}

//判断字符串是否为数字
int isNumber(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

//全局变量
Student students[MAX_STUDENT];
Teacher teachers[MAX_TEACHER];
Score scores[MAX_STUDENT * MAX_COURSE];
Notice notices[MAX_NOTICE];
Signup signups[MAX_SIGNUP];

int stu_count = 0;   //学生总数
int tea_count = 0;   //教师总数
int sco_count = 0;   //成绩总数
int noti_count = 0;  //通知总数
int sign_count = 0;  //报名项总数

//数据加载函数 
//加载学生数据
void loadStudents() {
    FILE* fp = fopen("students.txt", "r");
    if (!fp) return;
    while (fscanf(fp, "%s %s %s %s %d", students[stu_count].id, students[stu_count].name,
        students[stu_count].pwd, students[stu_count].gender, &students[stu_count].age) != EOF) {
        stu_count++;
    }
    fclose(fp);
}

//保存学生数据
void saveStudents() {
    FILE* fp = fopen("students.txt", "w");
    if (!fp) {
        printf("文件打开失败！\n");
        return;
    }
    for (int i = 0; i < stu_count; i++) {
        fprintf(fp, "%s %s %s %s %d\n", students[i].id, students[i].name,
            students[i].pwd, students[i].gender, students[i].age);
    }
    fclose(fp);
}

//加载教师数据
void loadTeachers() {
    FILE* fp = fopen("teachers.txt", "r");
    if (!fp) return;
    while (fscanf(fp, "%s %s %s %s", teachers[tea_count].id, teachers[tea_count].name,
        teachers[tea_count].pwd, teachers[tea_count].course_id) != EOF) {
        tea_count++;
    }
    fclose(fp);
}

//保存教师数据
void saveTeachers() {
    FILE* fp = fopen("teachers.txt", "w");
    if (!fp) {
        printf("文件打开失败！\n");
        return;
    }
    for (int i = 0; i < tea_count; i++) {
        fprintf(fp, "%s %s %s %s\n", teachers[i].id, teachers[i].name,
            teachers[i].pwd, teachers[i].course_id);
    }
    fclose(fp);
}

//加载成绩数据
void loadScores() {
    FILE* fp = fopen("scores.txt", "r");
    if (!fp) return;
    while (fscanf(fp, "%s %s %s %f", scores[sco_count].stu_id, scores[sco_count].course_id,
        scores[sco_count].course_name, &scores[sco_count].score) != EOF) {
        sco_count++;
    }
    fclose(fp);
}

//保存成绩数据
void saveScores() {
    FILE* fp = fopen("scores.txt", "w");
    if (!fp) {
        printf("文件打开失败！\n");
        return;
    }
    for (int i = 0; i < sco_count; i++) {
        fprintf(fp, "%s %s %s %.1f\n", scores[i].stu_id, scores[i].course_id,
            scores[i].course_name, scores[i].score);
    }
    fclose(fp);
}

//加载通知数据
void loadNotices() {
    FILE* fp = fopen("notices.txt", "r");
    if (!fp) return;
    while (fscanf(fp, "%[^\n]%*c%[^\n]%*c%s", notices[noti_count].title,
        notices[noti_count].content, notices[noti_count].type) != EOF) {
        noti_count++;
    }
    fclose(fp);
}

//保存通知数据
void saveNotices() {
    FILE* fp = fopen("notices.txt", "w");
    if (!fp) {
        printf("文件打开失败！\n");
        return;
    }
    for (int i = 0; i < noti_count; i++) {
        fprintf(fp, "%s\n%s\n%s\n", notices[i].title, notices[i].content, notices[i].type);
    }
    fclose(fp);
}

//加载报名数据
void loadSignups() {
    FILE* fp = fopen("signups.txt", "r");
    if (!fp) return;
    while (fscanf(fp, "%s %s %[^\n]%*c", signups[sign_count].id, signups[sign_count].course_id,
        signups[sign_count].content) != EOF) {
        sign_count++;
    }
    fclose(fp);
}

//保存报名数据
void saveSignups() {
    FILE* fp = fopen("signups.txt", "w");
    if (!fp) {
        printf("文件打开失败！\n");
        return;
    }
    for (int i = 0; i < sign_count; i++) {
        fprintf(fp, "%s %s %s\n", signups[i].id, signups[i].course_id, signups[i].content);
    }
    fclose(fp);
}

//初始化
void initSystem() {
    loadStudents();
    loadTeachers();
    loadScores();
    loadNotices();
    loadSignups();
}

//用户登录函数
int login(UserType* type, char* id) {
    char pwd[20];
    printf("请输入账号：");
    scanf("%s", id);
    printf("请输入密码：");
    scanf("%s", pwd);
    clearBuffer();

    //验证管理员
    if (strcmp(id, "呆呆") == 0 && strcmp(pwd, "呆呆666") == 0) {
        *type = ADMIN;
        return 1;
    }

    //验证学生
    for (int i = 0; i < stu_count; i++) {
        if (strcmp(id, students[i].id) == 0 && strcmp(pwd, students[i].pwd) == 0) {
            *type = STUDENT;
            return 1;
        }
    }

    //验证教师
    for (int i = 0; i < tea_count; i++) {
        if (strcmp(id, teachers[i].id) == 0 && strcmp(pwd, teachers[i].pwd) == 0) {
            *type = TEACHER;
            return 1;
        }
    }

    return 0;
}

//学生功能函数
//查看个人信息
void studentViewInfo(char* id) {
    for (int i = 0; i < stu_count; i++) {
        if (strcmp(id, students[i].id) == 0) {
            printf("\n===== 个人信息 =====\n");
            printf("学号：%s\n", students[i].id);
            printf("姓名：%s\n", students[i].name);
            printf("性别：%s\n", students[i].gender);
            printf("年龄：%d\n", students[i].age);
            printf("====================\n");
            return;
        }
    }
    printf("未找到个人信息！\n");
}

//修改个人信息
void studentModifyInfo(char* id) {
    for (int i = 0; i < stu_count; i++) {
        if (strcmp(id, students[i].id) == 0) {
            printf("当前密码：%s\n", students[i].pwd);
            printf("请输入新密码：");
            scanf("%s", students[i].pwd);
            while (1) {
                printf("请输入新年龄（15-40）：");
                scanf("%d", &students[i].age);
                if (students[i].age >= 15 && students[i].age <= 40) {
                    break;
                }
                printf("年龄输入非法，请重新输入！\n");
            }
            saveStudents();
            printf("信息修改成功！\n");
            return;
        }
    }
    printf("未找到个人信息！\n");
}

//查看成绩报告
void studentViewScore(char* id) {
    printf("\n===== 成绩报告 =====\n");
    int flag = 0;
    float avg = 0.0;
    int count = 0;
    for (int i = 0; i < sco_count; i++) {
        if (strcmp(id, scores[i].stu_id) == 0) {
            printf("课程号：%s\n课程名：%s\n成绩：%.1f\n",
                scores[i].course_id, scores[i].course_name, scores[i].score);
            printf("------------------\n");
            avg += scores[i].score;
            count++;
            flag = 1;
        }
    }
    if (!flag) {
        printf("暂无成绩记录！\n");
    }
    else {
        printf("平均成绩：%.1f\n", avg / count);
    }
    printf("====================\n");
}

//查看通知
void studentViewNotice() {
    printf("\n===== 系统通知 =====\n");
    if (noti_count == 0) {
        printf("暂无通知！\n");
        printf("====================\n");
        return;
    }
    for (int i = 0; i < noti_count; i++) {
        printf("【%s】\n标题：%s\n内容：%s\n", notices[i].type, notices[i].title, notices[i].content);
        printf("------------------\n");
    }
    printf("====================\n");
}

//菜单
void studentMenu(char* id) {
    int choice;
    while (1) {
        printf("\n===== 学生功能菜单 =====\n");
        printf("1. 查看个人信息\n");
        printf("2. 修改个人信息\n");
        printf("3. 查看成绩报告\n");
        printf("4. 查看系统通知\n");
        printf("5. 退出登录\n");
        printf("请选择操作（1-5）：");
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
            clearBuffer();
            printf("输入非法，请输入1-5的数字：");
        }
        clearBuffer();
        switch (choice) {
        case 1:
            studentViewInfo(id);
            break;
        case 2:
            studentModifyInfo(id);
            break;
        case 3:
            studentViewScore(id);
            break;
        case 4:
            studentViewNotice();
            break;
        case 5:
            printf("退出成功！\n");
            return;
        default:
            printf("输入错误，请重新选择！\n");
        }
    }
}

//教师功能函数
//录入成绩
void teacherAddScore(char* tea_id) {
    if (sco_count >= MAX_STUDENT * MAX_COURSE) {
        printf("成绩记录已满，无法添加！\n");
        return;
    }
    char course_id[20] = { 0 };
    //获取教师负责课程
    for (int i = 0; i < tea_count; i++) {
        if (strcmp(tea_id, teachers[i].id) == 0) {
            strcpy(course_id, teachers[i].course_id);
            break;
        }
    }
    if (strlen(course_id) == 0) {
        printf("教师无负责课程，无法录入成绩！\n");
        return;
    }

    char stu_id[20];
    printf("请输入学生学号：");
    scanf("%s", stu_id);
    //学生是否存在
    int stu_exist = 0;
    for (int i = 0; i < stu_count; i++) {
        if (strcmp(stu_id, students[i].id) == 0) {
            stu_exist = 1;
            break;
        }
    }
    if (!stu_exist) {
        printf("该学生不存在！\n");
        return;
    }
    //是否已存在该成绩
    for (int i = 0; i < sco_count; i++) {
        if (strcmp(stu_id, scores[i].stu_id) == 0 && strcmp(course_id, scores[i].course_id) == 0) {
            printf("该学生此课程成绩已存在！\n");
            return;
        }
    }

    printf("请输入课程名称：");
    scanf("%s", scores[sco_count].course_name);
    float score;
    while (1) {
        printf("请输入成绩（0-100）：");
        scanf("%f", &score);
        if (score >= 0 && score <= 100) {
            break;
        }
        printf("成绩非法，请输入0-100的数字！\n");
    }
    strcpy(scores[sco_count].stu_id, stu_id);
    strcpy(scores[sco_count].course_id, course_id);
    scores[sco_count].score = score;
    sco_count++;
    saveScores();
    printf("成绩录入成功！\n");
}

//修改成绩
void teacherModifyScore(char* tea_id) {
    char course_id[20] = { 0 };
    for (int i = 0; i < tea_count; i++) {
        if (strcmp(tea_id, teachers[i].id) == 0) {
            strcpy(course_id, teachers[i].course_id);
            break;
        }
    }
    if (strlen(course_id) == 0) {
        printf("教师无负责课程！\n");
        return;
    }

    char stu_id[20];
    printf("请输入学生学号：");
    scanf("%s", stu_id);
    for (int i = 0; i < sco_count; i++) {
        if (strcmp(stu_id, scores[i].stu_id) == 0 && strcmp(course_id, scores[i].course_id) == 0) {
            printf("当前成绩：%.1f\n", scores[i].score);
            float new_score;
            while (1) {
                printf("请输入新成绩（0-100）：");
                scanf("%f", &new_score);
                if (new_score >= 0 && new_score <= 100) {
                    break;
                }
                printf("成绩非法，请重新输入！\n");
            }
            scores[i].score = new_score;
            saveScores();
            printf("成绩修改成功！\n");
            return;
        }
    }
    printf("未找到该学生的该课程成绩！\n");
}

//删除成绩
void teacherDeleteScore(char* tea_id) {
    char course_id[20] = { 0 };
    for (int i = 0; i < tea_count; i++) {
        if (strcmp(tea_id, teachers[i].id) == 0) {
            strcpy(course_id, teachers[i].course_id);
            break;
        }
    }
    if (strlen(course_id) == 0) {
        printf("教师无负责课程！\n");
        return;
    }

    char stu_id[20];
    printf("请输入学生学号：");
    scanf("%s", stu_id);
    for (int i = 0; i < sco_count; i++) {
        if (strcmp(stu_id, scores[i].stu_id) == 0 && strcmp(course_id, scores[i].course_id) == 0) {
            //覆写
            for (int j = i; j < sco_count - 1; j++) {
                scores[j] = scores[j + 1];
            }
            sco_count--;
            saveScores();
            printf("成绩删除成功！\n");
            return;
        }
    }
    printf("未找到该学生的该课程成绩！\n");
}

//发布通知
void teacherPublishNotice() {
    if (noti_count >= MAX_NOTICE) {
        printf("通知数量已达上限！\n");
        return;
    }
    printf("请选择通知类型：1.成绩通知  2.补考通知\n");
    int type_choice;
    while (scanf("%d", &type_choice) != 1 || (type_choice != 1 && type_choice != 2)) {
        clearBuffer();
        printf("输入非法，请输入1或2：");
    }
    strcpy(notices[noti_count].type, type_choice == 1 ? "成绩通知" : "补考通知");

    printf("请输入通知标题：");
    clearBuffer();
    fgets(notices[noti_count].title, MAX_STR_LEN, stdin);
    notices[noti_count].title[strcspn(notices[noti_count].title, "\n")] = '\0';

    printf("请输入通知内容：");
    fgets(notices[noti_count].content, 200, stdin);
    notices[noti_count].content[strcspn(notices[noti_count].content, "\n")] = '\0';

    noti_count++;
    saveNotices();
    printf("通知发布成功！\n");
}

//创建报名信息
void teacherCreateSignup(char* tea_id) {
    if (sign_count >= MAX_SIGNUP) {
        printf("报名项数量已达上限！\n");
        return;
    }
    char course_id[20] = { 0 };
    for (int i = 0; i < tea_count; i++) {
        if (strcmp(tea_id, teachers[i].id) == 0) {
            strcpy(course_id, teachers[i].course_id);
            break;
        }
    }
    if (strlen(course_id) == 0) {
        printf("教师无负责课程！\n");
        return;
    }

    char signup_id[20];
    printf("请输入报名项ID：");
    scanf("%s", signup_id);
    //报名ID是否重复
    for (int i = 0; i < sign_count; i++) {
        if (strcmp(signup_id, signups[i].id) == 0) {
            printf("该报名ID已存在！\n");
            return;
        }
    }

    printf("请输入报名说明：");
    clearBuffer();
    fgets(signups[sign_count].content, 100, stdin);
    signups[sign_count].content[strcspn(signups[sign_count].content, "\n")] = '\0';

    strcpy(signups[sign_count].id, signup_id);
    strcpy(signups[sign_count].course_id, course_id);
    sign_count++;
    saveSignups();
    printf("报名信息创建成功！\n");
}

//教师菜单
void teacherMenu(char* id) {
    int choice;
    while (1) {
        printf("\n===== 教师功能菜单 =====\n");
        printf("1. 录入学生成绩\n");
        printf("2. 修改学生成绩\n");
        printf("3. 删除学生成绩\n");
        printf("4. 发布成绩/补考通知\n");
        printf("5. 创建报名信息\n");
        printf("6. 退出登录\n");
        printf("请选择操作（1-6）：");
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 6) {
            clearBuffer();
            printf("输入非法，请输入1-6的数字：");
        }
        clearBuffer();
        switch (choice) {
        case 1:
            teacherAddScore(id);
            break;
        case 2:
            teacherModifyScore(id);
            break;
        case 3:
            teacherDeleteScore(id);
            break;
        case 4:
            teacherPublishNotice();
            break;
        case 5:
            teacherCreateSignup(id);
            break;
        case 6:
            printf("退出成功！\n");
            return;
        default:
            printf("输入错误，请重新选择！\n");
        }
    }
}

//管理员功能函数
//添加学生
void adminAddStudent() {
    if (stu_count >= MAX_STUDENT) {
        printf("学生数量已达上限！\n");
        return;
    }
    char stu_id[20];
    printf("请输入学号：");
    scanf("%s", stu_id);
    //检查学号是否重复
    for (int i = 0; i < stu_count; i++) {
        if (strcmp(stu_id, students[i].id) == 0) {
            printf("该学号已存在！\n");
            return;
        }
    }
    if (!isNumber(stu_id)) {
        printf("学号必须为数字！\n");
        return;
    }

    printf("请输入姓名：");
    scanf("%s", students[stu_count].name);
    printf("请输入初始密码：");
    scanf("%s", students[stu_count].pwd);
    printf("请输入性别（男/女）：");
    scanf("%s", students[stu_count].gender);
    while (1) {
        printf("请输入年龄（15-40）：");
        scanf("%d", &students[stu_count].age);
        if (students[stu_count].age >= 15 && students[stu_count].age <= 40) {
            break;
        }
        printf("年龄非法，请重新输入！\n");
    }
    strcpy(students[stu_count].id, stu_id);
    stu_count++;
    saveStudents();
    printf("学生添加成功！\n");
}

//删除学生
void adminDeleteStudent() {
    char stu_id[20];
    printf("请输入要删除的学生学号：");
    scanf("%s", stu_id);
    for (int i = 0; i < stu_count; i++) {
        if (strcmp(stu_id, students[i].id) == 0) {
            //同时删除该学生的所有成绩
            for (int j = 0; j < sco_count; j++) {
                if (strcmp(stu_id, scores[j].stu_id) == 0) {
                    for (int k = j; k < sco_count - 1; k++) {
                        scores[k] = scores[k + 1];
                    }
                    sco_count--;
                    j--;
                }
            }
            saveScores();

            //删除学生信息
            for (int j = i; j < stu_count - 1; j++) {
                students[j] = students[j + 1];
            }
            stu_count--;
            saveStudents();
            printf("学生及关联成绩删除成功！\n");
            return;
        }
    }
    printf("未找到该学生！\n");
}

//添加教师
void adminAddTeacher() {
    if (tea_count >= MAX_TEACHER) {
        printf("教师数量已达上限！\n");
        return;
    }
    char tea_id[20];
    printf("请输入教师号：");
    scanf("%s", tea_id);
    //检查教师号是否重复
    for (int i = 0; i < tea_count; i++) {
        if (strcmp(tea_id, teachers[i].id) == 0) {
            printf("该教师号已存在！\n");
            return;
        }
    }
    if (!isNumber(tea_id)) {
        printf("教师号必须为数字！\n");
        return;
    }

    printf("请输入姓名：");
    scanf("%s", teachers[tea_count].name);
    printf("请输入初始密码：");
    scanf("%s", teachers[tea_count].pwd);
    printf("请输入负责课程号：");
    scanf("%s", teachers[tea_count].course_id);

    strcpy(teachers[tea_count].id, tea_id);
    tea_count++;
    saveTeachers();
    printf("教师添加成功！\n");
}

//删除教师
void adminDeleteTeacher() {
    char tea_id[20];
    printf("请输入要删除的教师号：");
    scanf("%s", tea_id);
    for (int i = 0; i < tea_count; i++) {
        if (strcmp(tea_id, teachers[i].id) == 0) {
            for (int j = i; j < tea_count - 1; j++) {
                teachers[j] = teachers[j + 1];
            }
            tea_count--;
            saveTeachers();
            printf("教师删除成功！\n");
            return;
        }
    }
    printf("未找到该教师！\n");
}

//查看所有用户
void adminViewUsers() {
    printf("\n===== 学生列表 =====\n");
    if (stu_count == 0) {
        printf("暂无学生数据！\n");
    }
    else {
        for (int i = 0; i < stu_count; i++) {
            printf("学号：%s  姓名：%s  性别：%s  年龄：%d\n",
                students[i].id, students[i].name, students[i].gender, students[i].age);
        }
    }

    printf("\n===== 教师列表 =====\n");
    if (tea_count == 0) {
        printf("暂无教师数据！\n");
    }
    else {
        for (int i = 0; i < tea_count; i++) {
            printf("教师号：%s  姓名：%s  负责课程：%s\n",
                teachers[i].id, teachers[i].name, teachers[i].course_id);
        }
    }
    printf("====================\n");
}

//查看所有成绩
void adminViewAllScores() {
    printf("\n===== 所有成绩记录 =====\n");
    if (sco_count == 0) {
        printf("暂无成绩数据！\n");
        printf("====================\n");

        return;
    }
    for (int i = 0; i < sco_count; i++) {
        printf("学生学号：%s  课程号：%s  课程名：%s  成绩：%.1f\n",
            scores[i].stu_id, scores[i].course_id, scores[i].course_name, scores[i].score);
    }
    printf("====================\n");
}

//管理员菜单
void adminMenu() {
    int choice;
    while (1) {
        printf("\n===== 管理员功能菜单 =====\n");
        printf("1. 添加学生\n");
        printf("2. 删除学生\n");
        printf("3. 添加教师\n");
        printf("4. 删除教师\n");
        printf("5. 查看所有用户\n");
        printf("6. 查看所有成绩\n");
        printf("7. 退出登录\n");
        printf("请选择操作（1-7）：");
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 7) {
            clearBuffer();
            printf("输入非法，请输入1-7的数字：");
        }
        clearBuffer();
        switch (choice) {
        case 1:
            adminAddStudent();
            break;
        case 2:
            adminDeleteStudent();
            break;
        case 3:
            adminAddTeacher();
            break;
        case 4:
            adminDeleteTeacher();
            break;
        case 5:
            adminViewUsers();
            break;
        case 6:
            adminViewAllScores();
            break;
        case 7:
            printf("退出成功！\n");
            return;

        default:
            printf("输入错误，请重新选择！\n");
        }
    }
}

//main
int main() {
    UserType type;
    char id[20];
    initSystem();

    printf("===== 学生成绩管理系统（C语言版） =====\n");
    printf("系统初始化完成，数据加载成功！\n");
    printf("请进行登录操作\n");
    if (login(&type, id)) {
        printf("登录成功！欢迎使用系统！\n");
        switch (type) {
        case STUDENT:
            studentMenu(id);
            break;
        case TEACHER:
            teacherMenu(id);
            break;
        case ADMIN:
            adminMenu();
            break;
        }
    }
    else {
        printf("账号或密码错误，登录失败！\n");
    }

    printf("系统已退出！\n");

    return 0;

}

