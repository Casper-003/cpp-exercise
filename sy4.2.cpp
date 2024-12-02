#include <iostream>

using namespace std;

class Book; // 前向声明，因为Ruler类需要访问Book类的totalWeight友元函数
class Ruler; // 同理，Book类也需要访问Ruler类的totalWeight友元函数

class Book {
public:
    Book(double w) : weight(w) {} // 构造函数，初始化weight

    // 声明友元函数，使其能够访问Book类的私有或受保护成员
    friend double totalWeight(const Book& b, const Ruler& r);

private:
    double weight; // 存储书的重量
};

class Ruler {
public:
    Ruler(double w) : weight(w) {} // 构造函数，初始化weight

    // 同样声明友元函数，使其能够访问Ruler类的私有或受保护成员
    friend double totalWeight(const Book& b, const Ruler& r);

private:
    double weight; // 存储尺子的重量
};

// 定义友元函数，计算Book和Ruler的重量和
double totalWeight(const Book& b, const Ruler& r) {
    return b.weight + r.weight;
}

int main() {
    // 创建Book和Ruler对象，并设置它们的重量
    Book book(4.5);
    Ruler ruler(0.2);

    // 调用友元函数计算总重量，并输出结果
    double total = totalWeight(book, ruler);
    cout << "总重量: " << total << endl;

    return 0;
}