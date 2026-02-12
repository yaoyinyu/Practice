#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "请输入数组的长度 N：";
    cin >> n;

    // 动态分配数组内存
    int* arr = new int[n];

    // 输入数组元素
    cout << "请输入 " << n << " 个整数：" << endl;
    for (int i = 0; i < n; i++) {
        cout << "请输入第 " << i + 1 << " 个元素：";
        cin >> arr[i];
    }

    // 初始化最大值、最小值和总和
    int max = arr[0];
    int min = arr[0];
    int sum = 0;

    // 遍历数组计算最大值、最小值和总和
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
        sum += arr[i];
    }

    // 计算平均值
    double average = static_cast<double>(sum) / n;

    // 输出结果
    cout << "\n统计结果：" << endl;
    cout << "最大值：" << max << endl;
    cout << "最小值：" << min << endl;
    cout << "总和：" << sum << endl;
    cout << "平均值：" << average << endl;

    // 释放动态分配的内存
    delete[] arr;

    return 0;
}