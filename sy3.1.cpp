#include <iostream>
using namespace std;

class Book
{
public:
    Book(int w);
    static int getsum();  // 声明静态成员函数
    static int sumnum;    // 声明静态数据成员

private:
    int num;
};

// 定义静态数据成员
int Book::sumnum = 120;

// 定义构造函数
Book::Book(int w)
{
    num = w;
    sumnum += w;  // 累加每个实例的 num 值
}

// 定义静态成员函数
int Book::getsum()
{
    return sumnum;
}

int main()
{
    Book b1(20);
    Book b2(70);

    // 调用静态成员函数输出 sumnum 的值
    cout << Book::getsum() << endl;

    return 0;
}