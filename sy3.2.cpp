#include <iostream>
#include <vector>

using namespace std;

class Student 
{
public:
    Student() = default;
    // 设置分数
    void setScore(float s) 
    {
        score = s;
    }

    // 静态成员函数，返回总分
    static float sum()
    {
        return total;
    }

    // 静态成员函数，返回平均分
    static float average()
    {
        // 如果学生人数为0，返回0以避免除以0的错误
        return count == 0 ? 0.0f : total / count;
    }

    // 静态数据成员声明（在类内部声明为static，在类外部定义和初始化）
    static float total;
    static int count;

private:
    float score; // 数据成员，存储每个学生的分数
};

// 静态数据成员初始化（在类外部）
float Student::total = 0.0f;
int Student::count = 0;

int main() 
{
    int numStudents;
    float scoreInput;

    // 输入学生人数
    cout << "请输入学生人数: ";
    cin >> numStudents;

    // 使用vector来存储Student对象（比动态数组更安全、更方便）
    vector<Student> students(numStudents);

    // 输入每个学生的分数并更新静态成员
    for (int i = 0; i < numStudents; i++)
    {
        cout << "请输入第" << i + 1 << "个学生的分数: ";
        cin >> scoreInput;
        students[i].setScore(scoreInput);
        Student::total += scoreInput; // 手动更新总分
        Student::count++; // 手动更新学生人数（注意：这通常不是最佳实践，因为它违反了封装原则）
    }

    // 计算并输出总分和平均分
    cout << "全班总分: " << Student::sum() << endl;
    cout << "全班平均分: " << Student::average() << endl;

    return 0;
}
