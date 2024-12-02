#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
    // 构造函数（空）
    Student() = default;

    // 设置分数
    void setScore(float s) {
        score = s;
        // 注意：这里我们不直接更新total和count，因为它们是静态成员
        // 静态成员的更新应该在外部逻辑中处理，或者在工厂函数中处理
    }

    // 静态成员函数，返回总分
    static float sum() {
        return total;
    }

    // 静态成员函数，返回平均分
    static float average() {
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

int main() {
    int numStudents;
    float scoreInput;

    // 输入学生人数
    cout << "请输入学生人数: ";
    cin >> numStudents;

    // 使用vector来存储Student对象（比动态数组更安全、更方便）
    vector<Student> students(numStudents);

    // 输入每个学生的分数并更新静态成员
    for (int i = 0; i < numStudents; i++) {
        cout << "请输入第" << i + 1 << "个学生的分数: ";
        cin >> scoreInput;
        students[i].setScore(scoreInput);
        // 由于我们不在setScore中更新total和count，我们需要在外部手动处理
        // 但为了保持示例的简洁性，并展示如何正确地使用静态成员，
        // 我们假设这里每个Student对象的分数都是有效的，并且应该在创建对象时立即加到total上。
        // 然而，在实际应用中，更好的做法可能是使用一个单独的函数或方法来处理所有学生的分数输入，
        // 并在那里更新total和count。
        // 因此，下面的两行代码应该被看作是一个示例性的、简化的处理方式，用于展示如何更新静态成员。
        // 在实际代码中，这部分逻辑应该被整合到一个更合适的位置。
        Student::total += scoreInput; // 手动更新总分
        Student::count++; // 手动更新学生人数（注意：这通常不是最佳实践，因为它违反了封装原则）
    }

    // 注意：上面的手动更新总分和学生人数的做法并不是最佳实践，
    // 因为它在类的外部直接操作了静态成员，从而破坏了封装性。
    // 在实际应用中，应该通过类的方法（例如一个静态的工厂方法）来管理对象的创建和静态成员的更新。
    // 下面的代码展示了如何正确地调用静态成员函数来获取总分和平均分。

    // 计算并输出总分和平均分
    cout << "全班总分: " << Student::sum() << endl;
    cout << "全班平均分: " << Student::average() << endl;

    return 0;
}