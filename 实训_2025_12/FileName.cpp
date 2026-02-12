#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//替换#define为const（修复VCR101警告）
const int MAX_COURSE = 5;        //最大课程数（文档要求支持多门课程）
const int MAX_NAME = 20;         //姓名最大长度
const int MAX_ID = 15;           //学号/工号最大长度
const int MAX_PWD = 15;          //密码最大长度
const char* FILE_STUDENT = "student.dat";  //学生数据文件
const char* FILE_USER = "user.dat";        //用户登录信息文件

//课程
typedef struct Course {
    char name[20];  //课程名称
    float score;    //课程成绩
} Course;

//学生
typedef struct Student {
    char id[MAX_ID];     //学号（唯一标识）
    char name[MAX_NAME]; //姓名
    Course courses[MAX_COURSE]; //多门课程成绩
    float total;         //总分
    float avg;           //平均分
    int rank;            //班级排名
    struct Student* next;//链表节点指针
} Student;

//用户登录信息（区分人物）
typedef struct User {
    char username[MAX_ID];  //用户名（学生/教师/管理员ID）
    char password[MAX_PWD]; //密码
    int role;               //1-学生，2-教师，3-管理员
} User;

//全局变量：学生链表头节点、课程名称数组
Student* head = NULL;
char courseNames[MAX_COURSE][20] = { "高等数学", "C语言", "数据结构", "英语", "操作系统" };
int courseCount = MAX_COURSE; //实际课程数

//提前声明
void initSystem(void);                //初始化系统
void saveStudentData(void);           //保存学生数据到文件
void loadStudentData(void);           //从文件加载学生数据
void saveUserData(void);              //保存用户数据到文件
int loadUserData(User* users, int* userCount); //从文件加载用户数据（修正声明）
int login(void);                      //用户登录（返回：1-学生，2-教师，3-管理员，0-失败）
void studentMenu(char* userId);    //学生菜单
void teacherMenu(void);               //教师菜单
void adminMenu(void);                 //管理员菜单
Student* createStudent(void);         //创建学生节点
void addStudent(void);                //新增学生
void deleteStudent(void);             //删除学生
void modifyStudent(void);             //修改学生信息
void queryStudentByID(char* id);  //按学号查询学生（所有人）
void queryStudentByName(char* name); //按姓名查询学生（教师/管理员）
void inputScores(Student* stu);   //录入学生成绩（教师）
void modifyScore(void);               //修改学生成绩（教师）
void deleteScore(void);               //删除学生成绩（教师）
void calculateTotalAndAvg(Student* stu); //计算总分和平均分
void sortStudentsByAvg(void);         //按平均分快速排序
void statisticsScore(void);           //成绩统计分析
void printAllStudents(void);          //打印所有学生信息（教师/管理员）
void addUser(void);                   //新增用户（管理员）
void deleteUser(void);                //删除用户（管理员）
void viewUsers(void);                 //查看用户列表（管理员）
void changePassword(const char* username);  //修改密码（所有人）
void freeStudentList(void);           //释放学生链表内存

//安全的 swap：只交换数据字段，不动 next 指针
void swapStudent(Student* a, Student* b) {
    if (a == NULL || b == NULL || a == b) return;

    char tmpId[MAX_ID];
    char tmpName[MAX_NAME];
    memcpy(tmpId, a->id, sizeof(tmpId));
    memcpy(a->id, b->id, sizeof(tmpId));
    memcpy(b->id, tmpId, sizeof(tmpId));

    memcpy(tmpName, a->name, sizeof(tmpName));
    memcpy(a->name, b->name, sizeof(tmpName));
    memcpy(b->name, tmpName, sizeof(tmpName));

    //假设 Course 是可按值复制的
    Course tmpCourses[MAX_COURSE];
    memcpy(tmpCourses, a->courses, sizeof(tmpCourses));
    memcpy(a->courses, b->courses, sizeof(tmpCourses));
    memcpy(b->courses, tmpCourses, sizeof(tmpCourses));

    float tmpTotal = a->total;
    a->total = b->total;
    b->total = tmpTotal;

    float tmpAvg = a->avg;
    a->avg = b->avg;
    b->avg = tmpAvg;

    int tmpRank = a->rank;
    a->rank = b->rank;
    b->rank = tmpRank;
}

//使用哨兵节点修复分区，避免 low - 1
Student* quickSortPartition(Student* low, Student* high) {
    if (low == NULL || high == NULL || low == high) {
        return NULL;
    }

    float pivot = high->avg;
    Student dummy;
    dummy.next = low;
    Student* i = &dummy; //i 永远有效

    for (Student* j = low; j != NULL && j != high; j = j->next) {
        if (j->avg >= pivot) {
            i = i->next; //从 dummy 移到第一个有效节点
            swapStudent(i, j);
        }
    }

    if (i->next != NULL) {
        swapStudent(i->next, high);
    }
    return i->next;
}

//快速排序递归实现
void quickSort(Student* low, Student* high) {
    if (low != NULL && high != NULL && low != high) {
        Student* pivot = quickSortPartition(low, high);
        if (pivot != NULL) {
            quickSort(low, pivot->next == high ? pivot : NULL); //左半部分
            quickSort(pivot->next, high);                      //右半部分
        }
    }
}

//按平均分排序并更新排名
void sortStudentsByAvg(void) {
    if (head == NULL || head->next == NULL) return;

    //找到链表尾节点
    Student* tail = head;
    while (tail != NULL && tail->next != NULL) {
        tail = tail->next;
    }

    //快速排序（降序）
    quickSort(head, tail);

    //更新排名
    int rank = 1;
    Student* p = head;
    if (p != NULL) {
        p->rank = rank;
        while (p != NULL && p->next != NULL) {
            if (p->next->avg < p->avg) {
                rank = p->rank + 1;
            }
            else {
                rank = p->rank; //同分排名相同
            }
            p->next->rank = rank;
            p = p->next;
        }
    }

    printf("排序完成！已更新班级排名\n");
    saveStudentData(); //排序后保存数据
}

//计算学生总分和平均分
void calculateTotalAndAvg(Student* stu) {
    if (stu == NULL) return;

    stu->total = 0.0f;
    int validCourses = 0;

    for (int i = 0; i < courseCount; i++) {
        if (stu->courses[i].score != -1.0f) {
            stu->total += stu->courses[i].score;
            validCourses++;
        }
    }

    if (validCourses > 0) {
        stu->avg = stu->total / validCourses;
    }
    else {
        stu->avg = 0.0f;
    }
}

//创建学生节点
Student* createStudent(void) {
    Student* newStu = (Student*)malloc(sizeof(Student));
    if (newStu == NULL) {
        printf("内存分配失败！\n");
        exit(EXIT_FAILURE);
    }

    printf("请输入学号：");
    scanf_s("%s", newStu->id, (unsigned)_countof(newStu->id));
    printf("请输入姓名：");
    scanf_s("%s", newStu->name, (unsigned)_countof(newStu->name));

    //初始化成绩为-1（未录入）
    for (int i = 0; i < courseCount; i++) {
        strncpy(newStu->courses[i].name, courseNames[i], sizeof(newStu->courses[i].name) - 1);
        newStu->courses[i].name[sizeof(newStu->courses[i].name) - 1] = '\0';
        newStu->courses[i].score = -1.0f;
    }

    newStu->total = 0.0f;
    newStu->avg = 0.0f;
    newStu->rank = 0;
    newStu->next = NULL;

    return newStu;
}

//新增学生（管理员/教师）
void addStudent(void) {
    Student* newStu = createStudent();
    if (newStu == NULL) return;

    //检查学号是否重复
    Student* p = head;
    while (p != NULL) {
        if (strcmp(p->id, newStu->id) == 0) {
            printf("错误：学号已存在！\n");
            free(newStu);
            return;
        }
        p = p->next;
    }

    //插入链表头部
    newStu->next = head;
    head = newStu;

    printf("学生信息新增成功！\n");
    saveStudentData(); //保存到文件
}

//删除学生（管理员/教师）
void deleteStudent(void) {
    if (head == NULL) {
        printf("暂无学生数据！\n");
        return;
    }

    char id[MAX_ID];
    printf("请输入要删除的学生学号：");
    scanf_s("%s", id, (unsigned)_countof(id));

    Student* p = head;
    Student* pre = NULL;

    //查找学生节点
    while (p != NULL && strcmp(p->id, id) != 0) {
        pre = p;
        p = p->next;
    }

    if (p == NULL) {
        printf("未找到该学生！\n");
        return;
    }

    //删除节点
    if (pre == NULL) { //删除头节点
        head = head->next;
    }
    else { //删除中间或尾节点
        pre->next = p->next;
    }

    free(p);
    printf("学生信息删除成功！\n");
    saveStudentData(); //保存到文件
}

//修改学生基本信息（管理员/教师）
void modifyStudent(void) {
    if (head == NULL) {
        printf("暂无学生数据！\n");
        return;
    }

    char id[MAX_ID];
    printf("请输入要修改的学生学号：");
    scanf_s("%s", id, (unsigned)_countof(id));

    Student* p = head;
    while (p != NULL && strcmp(p->id, id) != 0) {
        p = p->next;
    }

    if (p == NULL) {
        printf("未找到该学生！\n");
        return;
    }

    printf("当前学生信息：\n");
    printf("学号：%s  姓名：%s\n", p->id, p->name);
    printf("请输入新姓名（原姓名：%s）：", p->name);
    scanf_s("%s", p->name, (unsigned)_countof(p->name));

    printf("学生信息修改成功！\n");
    saveStudentData(); //保存到文件
}

//录入学生成绩（教师）
void inputScores(Student* stu) {
    if (stu == NULL) return;

    printf("开始录入【%s】的成绩（输入-1表示未考）：\n", stu->name);
    for (int i = 0; i < courseCount; i++) {
        printf("%s：", courseNames[i]);
        scanf_s("%f", &stu->courses[i].score);
        //成绩合法性校验（0-100或-1）
        while (stu->courses[i].score != -1.0f && (stu->courses[i].score < 0.0f || stu->courses[i].score > 100.0f)) {
            printf("成绩无效！请输入0-100或-1：");
            scanf_s("%f", &stu->courses[i].score);
        }
    }

    calculateTotalAndAvg(stu); //计算总分和平均分
    sortStudentsByAvg();       //重新排序并更新排名
    printf("成绩录入成功！\n");
}

//修改学生成绩（教师）
void modifyScore(void) {
    if (head == NULL) {
        printf("暂无学生数据！\n");
        return;
    }

    char id[MAX_ID];
    printf("请输入要修改成绩的学生学号：");
    scanf_s("%s", id, (unsigned)_countof(id));

    Student* p = head;
    while (p != NULL && strcmp(p->id, id) != 0) {
        p = p->next;
    }

    if (p == NULL) {
        printf("未找到该学生！\n");
        return;
    }

    //显示当前成绩
    printf("【%s】当前成绩：\n", p->name);
    for (int i = 0; i < courseCount; i++) {
        if (p->courses[i].score == -1.0f) {
            printf("%s：未录入\n", courseNames[i]);
        }
        else {
            printf("%s：%.1f\n", courseNames[i], p->courses[i].score);
        }
    }

    //选择要修改的课程
    int choice = 0;
    printf("请选择要修改的课程（1-%d）：", courseCount);
    scanf_s("%d", &choice);
    while (choice < 1 || choice > courseCount) {
        printf("选择无效！请输入1-%d：", courseCount);
        scanf_s("%d", &choice);
    }

    //输入新成绩
    printf("请输入%s的新成绩（0-100或-1）：", courseNames[choice - 1]);
    scanf_s("%f", &p->courses[choice - 1].score);
    while (p->courses[choice - 1].score != -1.0f &&
        (p->courses[choice - 1].score < 0.0f || p->courses[choice - 1].score > 100.0f)) {
        printf("成绩无效！请输入0-100或-1：");
        scanf_s("%f", &p->courses[choice - 1].score);
    }

    calculateTotalAndAvg(p); //重新计算总分和平均分
    sortStudentsByAvg();     //重新排序排名
    printf("成绩修改成功！\n");
    saveStudentData();       //保存到文件
}

//删除学生成绩（教师）
void deleteScore(void) {
    if (head == NULL) {
        printf("暂无学生数据！\n");
        return;
    }

    char id[MAX_ID];
    printf("请输入要删除成绩的学生学号：");
    scanf_s("%s", id, (unsigned)_countof(id));

    Student* p = head;
    while (p != NULL && strcmp(p->id, id) != 0) {
        p = p->next;
    }

    if (p == NULL) {
        printf("未找到该学生！\n");
        return;
    }

    //选择要删除的课程成绩（置为-1）
    int choice = 0;
    printf("请选择要删除成绩的课程（1-%d）：", courseCount);
    scanf_s("%d", &choice);
    while (choice < 1 || choice > courseCount) {
        printf("选择无效！请输入1-%d：", courseCount);
        scanf_s("%d", &choice);
    }

    p->courses[choice - 1].score = -1.0f;
    calculateTotalAndAvg(p); //重新计算总分和平均分
    sortStudentsByAvg();     //重新排序排名
    printf("成绩删除成功（已置为未录入）！\n");
    saveStudentData();       //保存到文件
}

//按学号查询学生（所有人物）
void queryStudentByID(char* id) {
    if (id == NULL || head == NULL) {
        printf("暂无学生数据！\n");
        return;
    }

    Student* p = head;
    while (p != NULL && strcmp(p->id, id) != 0) {
        p = p->next;
    }

    if (p == NULL) {
        printf("未找到学号为【%s】的学生！\n", id);
        return;
    }

    //打印查询结果
    printf("\n==================== 学生成绩详情 ====================\n");
    printf("学号：%s\t姓名：%s\t班级排名：%d\n", p->id, p->name, p->rank);
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < courseCount; i++) {
        printf("%-8s：", courseNames[i]);
        if (p->courses[i].score == -1.0f) {
            printf("未录入\n");
        }
        else {
            printf("%.1f\n", p->courses[i].score);
        }
    }
    printf("-----------------------------------------------------\n");
    printf("总分：%.1f\t平均分：%.1f\n", p->total, p->avg);
    printf("=====================================================\n\n");
}

//按姓名查询学生（教师/管理员）
void queryStudentByName(char* name) {
    if (name == NULL || head == NULL) {
        printf("暂无学生数据！\n");
        return;
    }

    int count = 0;
    Student* p = head;
    printf("\n==================== 学生成绩查询结果 ====================\n");
    while (p != NULL) {
        if (strstr(p->name, name) != NULL) { //模糊查询
            count++;
            printf("第%d条结果：\n", count);
            printf("学号：%s\t姓名：%s\t班级排名：%d\n", p->id, p->name, p->rank);
            printf("-----------------------------------------------------\n");
            for (int i = 0; i < courseCount; i++) {
                printf("%-8s：", courseNames[i]);
                if (p->courses[i].score == -1.0f) {
                    printf("未录入\n");
                }
                else {
                    printf("%.1f\n", p->courses[i].score);
                }
            }
            printf("总分：%.1f\t平均分：%.1f\n\n", p->total, p->avg);
        }
        p = p->next;
    }

    if (count == 0) {
        printf("未找到姓名包含【%s】的学生！\n", name);
    }
    printf("=====================================================\n\n");
}

//成绩统计分析（分数段、平均分等）
void statisticsScore(void) {
    if (head == NULL) {
        printf("暂无学生数据！\n");
        return;
    }

    //统计变量初始化
    int totalStudents = 0;
    float classAvg = 0.0f;
    int scoreRange[5] = { 0 }; //0-59, 60-69, 70-79, 80-89, 90-100
    float courseAvg[MAX_COURSE] = { 0.0f }; //每门课程平均分
    int courseValidCount[MAX_COURSE] = { 0 }; //每门课程有效成绩数

    //遍历所有学生计算统计数据
    Student* p = head;
    while (p != NULL) {
        totalStudents++;
        classAvg += p->avg;

        //统计总分分数段
        if (p->avg >= 90.0f) {
            scoreRange[4]++;
        }
        else if (p->avg >= 80.0f) {
            scoreRange[3]++;
        }
        else if (p->avg >= 70.0f) {
            scoreRange[2]++;
        }
        else if (p->avg >= 60.0f) {
            scoreRange[1]++;
        }
        else if (p->avg >= 0.0f) {
            scoreRange[0]++;
        }

        //统计每门课程平均分
        for (int i = 0; i < courseCount; i++) {
            if (p->courses[i].score != -1.0f) {
                courseAvg[i] += p->courses[i].score;
                courseValidCount[i]++;
            }
        }

        p = p->next;
    }

    if (totalStudents > 0) {
        classAvg /= totalStudents;
    }

    for (int i = 0; i < courseCount; i++) {
        if (courseValidCount[i] > 0) {
            courseAvg[i] /= courseValidCount[i];
        }
        else {
            courseAvg[i] = -1.0f; //无有效成绩
        }
    }

    //打印统计结果
    printf("\n==================== 成绩统计分析 ====================\n");
    printf("班级总人数：%d\t班级平均分：%.1f\n", totalStudents, classAvg);
    printf("-----------------------------------------------------\n");
    printf("分数段分布：\n");
    printf("90-100分：%d人（%.1f%%）\n", scoreRange[4],
        (totalStudents > 0) ? (float)scoreRange[4] / totalStudents * 100 : 0.0f);
    printf("80-89分：%d人（%.1f%%）\n", scoreRange[3],
        (totalStudents > 0) ? (float)scoreRange[3] / totalStudents * 100 : 0.0f);
    printf("70-79分：%d人（%.1f%%）\n", scoreRange[2],
        (totalStudents > 0) ? (float)scoreRange[2] / totalStudents * 100 : 0.0f);
    printf("60-69分：%d人（%.1f%%）\n", scoreRange[1],
        (totalStudents > 0) ? (float)scoreRange[1] / totalStudents * 100 : 0.0f);
    printf("0-59分：%d人（%.1f%%）\n", scoreRange[0],
        (totalStudents > 0) ? (float)scoreRange[0] / totalStudents * 100 : 0.0f);
    printf("-----------------------------------------------------\n");
    printf("每门课程平均分：\n");
    for (int i = 0; i < courseCount; i++) {
        printf("%-8s：", courseNames[i]);
        if (courseAvg[i] == -1.0f) {
            printf("无有效成绩\n");
        }
        else {
            printf("%.1f\n", courseAvg[i]);
        }
    }
    printf("=====================================================\n\n");
}

//打印所有学生信息（教师/管理员）
void printAllStudents(void) {
    if (head == NULL) {
        printf("暂无学生数据！\n");
        return;
    }

    sortStudentsByAvg(); //排序后打印
    printf("\n==================== 所有学生成绩列表 ====================\n");
    printf("排名\t学号\t\t姓名\t");
    for (int i = 0; i < courseCount; i++) {
        printf("%-6s", courseNames[i]);
    }
    printf("总分\t平均分\n");
    printf("-----------------------------------------------------\n");

    Student* p = head;
    while (p != NULL) {
        printf("%d\t%s\t%s\t", p->rank, p->id, p->name);
        for (int i = 0; i < courseCount; i++) {
            if (p->courses[i].score == -1.0f) {
                printf("%-6s", "未录");
            }
            else {
                printf("%-6.1f", p->courses[i].score);
            }
        }
        printf("%.1f\t%.1f\n", p->total, p->avg);
        p = p->next;
    }
    printf("=====================================================\n\n");
}

//保存学生数据到文件（二进制存储）
void saveStudentData(void) {
    FILE* fp = fopen(FILE_STUDENT, "wb");
    if (fp == NULL) {
        printf("文件打开失败！无法保存数据\n");
        return;
    }

    Student* p = head;
    while (p != NULL) {
        fwrite(p, sizeof(Student), 1, fp);
        p = p->next;
    }

    fclose(fp);
}

//从文件加载学生数据
void loadStudentData(void) {
    FILE* fp = fopen(FILE_STUDENT, "rb");
    if (fp == NULL) {
        printf("学生数据文件不存在，将创建新文件\n");
        return;
    }

    //释放原有链表
    freeStudentList();

    Student temp;
    while (fread(&temp, sizeof(Student), 1, fp) == 1) {
        Student* newStu = (Student*)malloc(sizeof(Student));
        if (newStu != NULL) {
            *newStu = temp;
            newStu->next = head;
            head = newStu;
        }
    }

    fclose(fp);
    printf("学生数据加载成功！\n");
}

//保存用户数据到文件
void saveUserData(void) {
    FILE* fp = fopen(FILE_USER, "wb");
    if (fp == NULL) {
        printf("文件打开失败！无法保存用户数据\n");
        return;
    }

    //预设测试用户（实际使用时可由管理员添加）
    User users[] = {
        {"2023001", "123456", 1}, //学生：学号2023001，密码123456
        {"teacher01", "teacher123", 2}, //教师：账号teacher01，密码teacher123
        {"admin", "admin123", 3} //管理员：账号admin，密码admin123
    };
    int userCount = (int)(sizeof(users) / sizeof(users[0]));

    fwrite(&userCount, sizeof(int), 1, fp);
    fwrite(users, sizeof(User), userCount, fp);

    fclose(fp);
}

//从文件加载用户数据（修正后的定义）
int loadUserData(User* users, int* userCount) {
    if (users == NULL || userCount == NULL) {
        return 0;
    }

    FILE* fp = fopen(FILE_USER, "rb");
    if (fp == NULL) {
        printf("用户数据文件不存在，将创建默认用户\n");
        saveUserData(); //创建默认用户
        return 0;
    }

    if (fread(userCount, sizeof(int), 1, fp) != 1) {
        fclose(fp);
        return 0;
    }

    if (fread(users, sizeof(User), *userCount, fp) != *userCount) {
        fclose(fp);
        return 0;
    }

    fclose(fp);
    return 1;
}

//用户登录
int login(void) {
    User users[100]; //最多支持100个用户
    int userCount = 0;
    loadUserData(users, &userCount);

    char username[MAX_ID];
    char password[MAX_PWD];

    printf("==================== 学生成绩管理系统 ====================\n");
    printf("请输入用户名：");
    scanf_s("%s", username, (unsigned)_countof(username));
    printf("请输入密码：");
    scanf_s("%s", password, (unsigned)_countof(password));
    printf("=====================================================\n");

    //验证用户名和密码
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            printf("登录成功！欢迎【%s】\n", username);
            return users[i].role; //返回人物
        }
    }

    printf("登录失败！用户名或密码错误\n");
    return 0;
}

//修改密码功能
void changePassword(const char* username) {
    if (username == NULL) return;

    User users[100];
    int userCount = 0;
    if (!loadUserData(users, &userCount)) {
        printf("无法加载用户数据！\n");
        return;
    }

    //查找用户
    int userIndex = -1;
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        printf("未找到用户【%s】！\n", username);
        return;
    }

    char oldPassword[MAX_PWD];
    char newPassword[MAX_PWD];
    char confirmPassword[MAX_PWD];

    //验证原密码
    printf("请输入原密码：");
    scanf_s("%s", oldPassword, (unsigned)_countof(oldPassword));
    if (strcmp(users[userIndex].password, oldPassword) != 0) {
        printf("原密码错误！\n");
        return;
    }

    //输入新密码
    printf("请输入新密码：");
    scanf_s("%s", newPassword, (unsigned)_countof(newPassword));
    printf("请确认新密码：");
    scanf_s("%s", confirmPassword, (unsigned)_countof(confirmPassword));

    //验证新密码
    if (strcmp(newPassword, confirmPassword) != 0) {
        printf("两次输入的密码不一致！\n");
        return;
    }

    //更新密码
    strncpy(users[userIndex].password, newPassword, sizeof(users[userIndex].password) - 1);
    users[userIndex].password[sizeof(users[userIndex].password) - 1] = '\0';

    //保存更新后的用户数据
    FILE* fp = fopen(FILE_USER, "wb");
    if (fp == NULL) {
        printf("文件打开失败！无法保存用户数据\n");
        return;
    }

    fwrite(&userCount, sizeof(int), 1, fp);
    fwrite(users, sizeof(User), userCount, fp);
    fclose(fp);

    printf("密码修改成功！\n");
}

//学生菜单
void studentMenu(char* userId) {
    if (userId == NULL) return;

    int choice = 0;
    while (1) {
        printf("\n==================== 学生功能菜单 ====================\n");
        printf("1. 查询个人成绩\t2. 查看个人信息\t3. 修改密码\t4. 退出登录\n");
        printf("=====================================================\n");
        printf("请选择功能（1-4）：");
        scanf_s("%d", &choice);

        //修复C2360：变量移到switch外或加{}
        switch (choice) {
        case 1:
            queryStudentByID(userId); //学生只能查询自己的成绩
            break;
        case 2: { //加{}限制作用域，避免跳转跳过初始化
            //查看个人信息（简化实现：查询成绩时已包含基本信息）
            printf("\n==================== 个人信息 ====================\n");
            printf("学号：%s\n", userId);
            //查找姓名
            Student* p = head;
            while (p != NULL && strcmp(p->id, userId) != 0) {
                p = p->next;
            }
            if (p != NULL) {
                printf("姓名：%s\n", p->name);
            }
            printf("=====================================================\n\n");
            break;
        }
        case 3:
            changePassword(userId);
            break;
        case 4:
            printf("退出登录成功！\n");
            return;
        default:
            printf("选择无效！请输入1-4\n");
        }
    }
}

//教师菜单（修复C2360：变量移到switch外定义）
void teacherMenu(void) {
    int choice = 0;
    //把case内的变量移到switch外，避免初始化被跳过
    char id[MAX_ID] = { 0 };
    char name[MAX_NAME] = { 0 };
    Student* p = NULL;
    int subChoice = 0;

    while (1) {
        printf("\n==================== 教师功能菜单 ====================\n");
        printf("1. 录入学生成绩\t2. 修改学生成绩\t3. 删除学生成绩\n");
        printf("4. 按学号查询\t5. 按姓名查询\t6. 打印所有学生\n");
        printf("7. 成绩统计分析\t8. 新增学生\t9. 删除学生\n");
        printf("10. 修改学生信息\t11. 修改密码\t12. 退出登录\n");
        printf("=====================================================\n");
        printf("请选择功能（1-12）：");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            if (head == NULL) {
                printf("暂无学生数据，请先新增学生！\n");
                break;
            }
            printf("请输入要录入成绩的学生学号：");
            scanf_s("%s", id, (unsigned)_countof(id));
            p = head;
            while (p != NULL && strcmp(p->id, id) != 0) {
                p = p->next;
            }
            if (p == NULL) {
                printf("未找到该学生！\n");
                break;
            }
            inputScores(p);
            break;
        case 2:
            modifyScore();
            break;
        case 3:
            deleteScore();
            break;
        case 4:
            printf("请输入要查询的学生学号：");
            scanf_s("%s", id, (unsigned)_countof(id));
            queryStudentByID(id);
            break;
        case 5:
            printf("请输入要查询的学生姓名：");
            scanf_s("%s", name, (unsigned)_countof(name));
            queryStudentByName(name);
            break;
        case 6:
            printAllStudents();
            break;
        case 7:
            statisticsScore();
            break;
        case 8:
            addStudent();
            break;
        case 9:
            deleteStudent();
            break;
        case 10:
            modifyStudent();
            break;
        case 11: {
            //假设教师用户名是固定的
            char teacherUsername[MAX_ID] = "teacher01";
            changePassword(teacherUsername); //传递可修改的char数组
            break;
        }
        case 12:
            printf("退出登录成功！\n");
            return;
        default:
            printf("选择无效！请输入1-12\n");
        }
    }
}

//查看用户列表（管理员）
void viewUsers(void) {
    User users[100];
    int userCount = 0;
    if (!loadUserData(users, &userCount)) {
        printf("无法加载用户数据！\n");
        return;
    }

    if (userCount == 0) {
        printf("暂无用户数据！\n");
        return;
    }

    printf("\n==================== 用户列表 ====================\n");
    printf("序号\t用户名\t\t人物\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < userCount; i++) {
        printf("%d\t%s\t\t", i + 1, users[i].username);
        switch (users[i].role) {
        case 1:
            printf("学生\n");
            break;
        case 2:
            printf("教师\n");
            break;
        case 3:
            printf("管理员\n");
            break;
        default:
            printf("未知人物\n");
            break;
        }
    }

    printf("=====================================================\n\n");
}

//新增用户（管理员）
void addUser(void) {
    User users[100];
    int userCount = 0;
    loadUserData(users, &userCount);

    if (userCount >= 100) {
        printf("用户数量已达上限！\n");
        return;
    }

    User newUser;
    printf("请输入新用户名：");
    scanf_s("%s", newUser.username, (unsigned)_countof(newUser.username));

    //检查用户名是否已存在
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("用户名已存在！\n");
            return;
        }
    }

    printf("请输入密码：");
    scanf_s("%s", newUser.password, (unsigned)_countof(newUser.password));

    printf("请选择人物（1-学生，2-教师，3-管理员）：");
    scanf_s("%d", &newUser.role);
    while (newUser.role < 1 || newUser.role > 3) {
        printf("人物无效！请输入1-3：");
        scanf_s("%d", &newUser.role);
    }

    //添加新用户
    users[userCount] = newUser;
    userCount++;

    //保存更新后的用户数据
    FILE* fp = fopen(FILE_USER, "wb");
    if (fp == NULL) {
        printf("文件打开失败！无法保存用户数据\n");
        return;
    }

    fwrite(&userCount, sizeof(int), 1, fp);
    fwrite(users, sizeof(User), userCount, fp);
    fclose(fp);

    printf("用户新增成功！\n");
}

//删除用户（管理员）
void deleteUser(void) {
    User users[100];
    int userCount = 0;
    if (!loadUserData(users, &userCount)) {
        printf("无法加载用户数据！\n");
        return;
    }

    if (userCount == 0) {
        printf("暂无用户数据！\n");
        return;
    }

    //显示用户列表
    viewUsers();

    int choice;
    printf("请选择要删除的用户序号：");
    scanf_s("%d", &choice);
    while (choice < 1 || choice > userCount) {
        printf("选择无效！请输入1-%d：", userCount);
        scanf_s("%d", &choice);
    }

    //确认删除
    char confirm;
    printf("确定要删除用户【%s】吗？（y/n）：", users[choice - 1].username);
    scanf_s(" %c", &confirm, 1);
    if (confirm != 'y' && confirm != 'Y') {
        printf("删除操作已取消！\n");
        return;
    }

    //删除用户（将后面的用户向前移动）
    for (int i = choice - 1; i < userCount - 1; i++) {
        users[i] = users[i + 1];
    }
    userCount--;

    //保存更新后的用户数据
    FILE* fp = fopen(FILE_USER, "wb");
    if (fp == NULL) {
        printf("文件打开失败！无法保存用户数据\n");
        return;
    }

    fwrite(&userCount, sizeof(int), 1, fp);
    fwrite(users, sizeof(User), userCount, fp);
    fclose(fp);

    printf("用户删除成功！\n");
}

//管理员菜单（修复C2360：变量移到switch外+加{}）
void adminMenu(void) {
    int choice = 0;
    //变量移到switch外，避免初始化被跳过
    int subChoice = 0;
    char id[MAX_ID] = { 0 };
    Student* p = NULL;

    while (1) {
        printf("\n==================== 管理员功能菜单 ====================\n");
        printf("1. 学生信息管理\t2. 成绩管理\t3. 数据统计\t4. 用户管理\n");
        printf("5. 备份数据\t6. 修改密码\t7. 退出登录\n");
        printf("=====================================================\n");
        printf("请选择功能（1-7）：");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: { //加{}限制子switch作用域
            //学生信息管理子菜单
            printf("\n===== 学生信息管理 =====\n");
            printf("1. 新增学生\t2. 删除学生\t3. 修改学生信息\t4. 查看所有学生\n");
            printf("请选择（1-4）：");
            scanf_s("%d", &subChoice);
            switch (subChoice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: modifyStudent(); break;
            case 4: printAllStudents(); break;
            default: printf("选择无效！\n");
            }
            break;
        }
        case 2: { //加{}限制子switch作用域
            //成绩管理子菜单
            printf("\n===== 成绩管理 =====\n");
            printf("1. 录入成绩\t2. 修改成绩\t3. 删除成绩\t4. 成绩查询\n");
            printf("请选择（1-4）：");
            scanf_s("%d", &subChoice);
            switch (subChoice) {
            case 1:
                if (head == NULL) {
                    printf("暂无学生数据，请先新增学生！\n");
                    break;
                }
                printf("请输入学生学号：");
                scanf_s("%s", id, (unsigned)_countof(id));
                p = head;
                while (p != NULL && strcmp(p->id, id) != 0) {
                    p = p->next;
                }
                if (p == NULL) {
                    printf("未找到该学生！\n");
                    break;
                }
                inputScores(p);
                break;
            case 2: modifyScore(); break;
            case 3: deleteScore(); break;
            case 4:
                printf("1. 按学号查询\t2. 按姓名查询\t3. 查看所有成绩\n");
                printf("请选择：");
                scanf_s("%d", &subChoice);
                if (subChoice == 1) {
                    printf("输入学号：");
                    scanf_s("%s", id, (unsigned)_countof(id));
                    queryStudentByID(id);
                }
                else if (subChoice == 2) {
                    printf("输入姓名：");
                    scanf_s("%s", id, (unsigned)_countof(id));
                    queryStudentByName(id);
                }
                else if (subChoice == 3) {
                    printAllStudents();
                }
                break;
            default: printf("选择无效！\n");
            }
            break;
        }
        case 3:
            statisticsScore();
            break;
        case 4: { //加{}限制子switch作用域
            //用户管理
            printf("\n===== 用户管理 =====\n");
            printf("1. 新增用户\t2. 删除用户\t3. 查看用户列表\n");
            printf("请选择（1-3）：");
            scanf_s("%d", &subChoice);
            switch (subChoice) {
            case 1: addUser(); break;
            case 2: deleteUser(); break;
            case 3: viewUsers(); break;
            default: printf("选择无效！\n");
            }
            break;
        }
        case 5:
            saveStudentData();
            saveUserData();
            printf("数据备份成功！\n");
            break;
        case 6:
            changePassword("admin"); //假设管理员用户名是固定的
            break;
        case 7:
            printf("退出登录成功！\n");
            return;
        default:
            printf("选择无效！请输入1-7\n");
        }
    }
}

//释放学生链表内存
void freeStudentList(void) {
    Student* p = head;
    while (p != NULL) {
        Student* temp = p;
        p = p->next;
        free(temp);
    }
    head = NULL;
}

//初始化系统
void initSystem(void) {
    loadStudentData(); //加载学生数据
    //加载用户数据（在login函数中执行）
    printf("系统初始化完成！\n");
}

//主函数
int main(void) {
    initSystem();

    while (1) {
        int role = login();
        if (role == 0) {
            //登录失败，重试或退出
            char choice = 'n';
            printf("是否重新登录？（y/n）：");
            scanf_s(" %c", &choice, 1);
            if (choice != 'y' && choice != 'Y') {
                printf("退出系统，感谢使用！\n");
                break;
            }
            continue;
        }

        //根据人物进入对应菜单
        if (role == 1) {
            char userId[MAX_ID] = { 0 };
            printf("请输入你的学号以继续：");
            scanf_s("%s", userId, (unsigned)_countof(userId));
            studentMenu(userId);
        }
        else if (role == 2) {
            teacherMenu();
        }
        else if (role == 3) {
            adminMenu();
        }
    }

    freeStudentList(); //释放内存
    return 0;
}