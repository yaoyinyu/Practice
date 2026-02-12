#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>

//常量管理（去冗余，统一规范）
constexpr int MAX_STU = 5;       //学生数量
constexpr int MAX_INFO = 20;     //通用字符串长度（学号/姓名）
constexpr int MAX_SUB = 5;       //考试科目数
constexpr char AGE_RANGE[] = "12-25"; //年龄范围（业务规则）

//科目名称（业务数据独立）
const std::vector<std::string> subjects = { "语文", "数学", "英语", "物理", "化学" };

//结构体封装（数据与逻辑分离）
struct Student {
    std::string code;  //学号
    std::string name;  //姓名
    int age;           //年龄（12-25岁）
    char sex;          //性别（M/F）
    std::vector<int> scores;  //各科成绩
    int total;         //总分
    float avg;         //平均分（浮点）
};

//函数声明（模块化设计）
void init_system();
void input_student(Student& stu, int idx);
bool validate_code(const std::string& code);
char input_sex();
void input_scores(Student& stu);
void print_table(const std::vector<Student>& stus);
void analyze_grades(const std::vector<Student>& stus);
void clear_input();
void print_divider(const std::string& title);

int main() {
    std::vector<Student> students(MAX_STU); //结构体数组初始化

    init_system(); //系统初始化（清屏+欢迎）

    //录入流程
    for (int i = 0; i < MAX_STU; i++)
    {
        std::cout << "\n? 正在录入第" << i + 1 << "/" << MAX_STU << "位学生\n";
        input_student(students[i], i + 1);
        input_scores(students[i]);
    }

    //输出结果
    print_table(students);
    analyze_grades(students);

    return 0;
}

//系统初始化（清屏+欢迎界面）
void init_system()
{
    system("cls||clear"); //跨平台清屏
    std::cout << R"(
 ██████╗ ██████╗ ███████╗██╗   ██╗    ██████╗ ███████╗██████╗ 
██╔════╝██╔═══██╗██╔════╝██║   ██║    ██╔══██╗██╔════╝██╔══██╗
██║     ██║   ██║███████╗██║   ██║    ██████╔╝█████╗  ██████╔╝
██║     ██║   ██║╚════██║██║   ██║    ██╔══██╗██╔══╝  ██╔══██╗
╚██████╗╚██████╔╝███████║╚██████╔╝    ██████╔╝███████╗██║  ██║
 ╚═════╝ ╚═════╝ ╚══════╝ ╚═════╝     ══════╝ ╚══════╝╚═╝  ╚═╝
    )";
    print_divider("学生信息管理系统 V2.0");
    std::cout << "? 本系统支持录入" << MAX_STU << "名学生，每生" << MAX_SUB << "科成绩（";
    for (size_t i = 0; i < subjects.size(); ++i)
    {
        std::cout << subjects[i];
        if (i != subjects.size() - 1) std::cout << "、";
    }
    std::cout << "）\n";
}

//学生信息录入（带业务规则校验）
void input_student(Student& stu, int idx)
{
    //学号校验（字母开头，6-12位，含数字/下划线）
    while (true)
    {
        std::cout << "\n[" << idx << "] 学号（字母开头，6-12位）: ";
        std::getline(std::cin, stu.code);
        if (validate_code(stu.code)) break;
        std::cout << "? 学号格式错误！示例：S_202401\n";
    }

    //姓名录入（2-8汉字，兼容全角）
    std::cout << "[" << idx << "] 姓名（2-8汉字）: ";
    while (true)
    {
        std::getline(std::cin, stu.name);
        if (stu.name.length() >= 2 && stu.name.length() <= 16) break;
        std::cout << "? 姓名长度不符！请重新输入: ";
    }

    //年龄校验（业务规则：12-25岁）
    std::cout << "[" << idx << "] 年龄（" << AGE_RANGE << "）: ";
    while (true)
    {
        if (std::cin >> stu.age && stu.age >= 12 && stu.age <= 25)
        {
            clear_input();
            break;
        }
        std::cout << "? 年龄超出范围！" << AGE_RANGE << ": ";
        clear_input();
    }

    //性别输入（独立函数）
    stu.sex = input_sex();
}

//性别输入（带可视化提示）
char input_sex()
{
    char c;
    std::cout << "[性别] ??(M) / ??(F): ";
    while (true)
    {
        c = std::toupper(std::cin.get());
        clear_input();
        if (c == 'M' || c == 'F') return c;
        std::cout << "? 请输入M/F: ";
    }
}

//成绩录入（带科目名称和趋势提示）
void input_scores(Student& stu)
{
    stu.total = 0;
    print_divider("?? 成绩录入 - " + stu.name);

    for (int i = 0; i < MAX_SUB; i++)
    {
        int score;
        while (true) {
            std::cout << "? " << subjects[i] << "成绩（0-100）: ";
            if (std::cin >> score && score >= 0 && score <= 100)
            {
                stu.scores.push_back(score);
                stu.total += score;
                clear_input();
                break;
            }
            std::cout << "? 无效成绩！请输入0-100的整数: ";
            clear_input();
        }
    }
    stu.avg = static_cast<float>(stu.total) / MAX_SUB; //浮点平均分
}

//数据展示（表格化输出）
void print_table(const std::vector<Student>& stus)
{
    print_divider("?? 学生信息总览");
    std::cout << "┌────┬──────────┬──────┬────┬────┐\n";
    std::cout << "│ ID │ 学号       │ 姓名   │ 年龄 │ 性别 │\n";
    std::cout << "├────┼──────────┼──────┼────┼────┤\n";
    for (size_t i = 0; i < stus.size(); i++)
    {
        std::cout << "│ " << i + 1 << " │ " << stus[i].code << " │ " << stus[i].name << " │ " << stus[i].age << " │ " << stus[i].sex << " │\n";
    }
    std::cout << "└────┴──────────┴──────┴────┴────┘\n";
}

//成绩分析（含统计图表）
void analyze_grades(const std::vector<Student>& stus)
{
    print_divider("?? 成绩分析报告");
    const std::vector<std::string> level = { "不及格", "及格", "中等", "良好", "优秀" };

    for (const auto& s : stus)
    {
        int level_idx = static_cast<int>(s.avg / 10) - 5;
        level_idx = std::clamp(level_idx, 0, 4);

        //带颜色的等级标识（ANSI转义）
        std::cout << "\n【" << s.name << "】学号:" << s.code << "\n";
        std::cout << "  总分: " << s.total << " │ 平均分: " << s.avg << " │ " << level[level_idx] << " ";
        std::cout << "[" << ANSI_COLOR(level_idx + 2) << level[level_idx] << ANSI_RESET << "]\n";

        //成绩雷达图（简化版）
        std::cout << "  各科成绩: ";
        for (size_t j = 0; j < subjects.size(); j++) 
        {
            std::cout << subjects[j] << ":" << s.scores[j] << (s.scores[j] > s.avg ? "(▲)" : s.scores[j] < s.avg ? "(▼)" : "(─)") << " ";
        }

        //进度条可视化
        int bar = static_cast<int>(s.avg / 2);
        std::cout << "\n  学习进度: ▏";
        for (int j = 0; j < 50; j++) std::cout << (j < bar ? "█" : " ");
        std::cout << "▕ " << s.avg << "%\n";
    }
}

//通用工具函数
void clear_input() { std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }
bool validate_code(const std::string& code)
{
    return code.length() >= 6 && code.length() <= 12
        && std::isalpha(code[0])
        && std::all_of(code.begin(), code.end(), [](char c) { return std::isalnum(c) || c == '_'; });
}
void print_divider(const std::string& title)
{
    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║  " << title << "  ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
}
