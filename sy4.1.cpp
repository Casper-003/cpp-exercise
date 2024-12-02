#include <iostream>
#include <cmath>
using namespace std;

// 定义点类Point
class Point 
{
private:
    double x;
    double y;
public:
    Point(double a = 0, double b = 0) : x(a), y(b) {}
    // 声明友元函数
    friend double distance(Point p);
};

// 友元函数的定义，用于计算点到原点的距离
double distance(Point p)
{
    return sqrt(p.x * p.x + p.y * p.y);
}

int main() {
    Point P(10, 15);
    double dis = distance(P);
    std::cout << "点P距原点的距离为: " << dis << endl;
    return 0;
}