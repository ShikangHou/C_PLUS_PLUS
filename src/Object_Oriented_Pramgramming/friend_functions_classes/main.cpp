#include <iostream>
using namespace std;

// note: 友元函数/类 不会继承

class EquilateralTriangle
{
private:
    float a_;
    float circumference_;
    float area_;

public:
    EquilateralTriangle(float a)
    {
        a_ = a;
        circumference_ = 3 * a;
        area_ = 1.73 / 4 * a;
    }
    friend void get_info(EquilateralTriangle et);
    friend class Homework;
};

class Homework
{
private:
    /* data */
public:
    void get_info(EquilateralTriangle et)
    {
        cout << "area: " << et.area_ << " circumference: " << et.circumference_ << endl;
    }
};

void get_info(EquilateralTriangle et)
{
    cout << "area: " << et.area_ << " circumference: " << et.circumference_ << endl;
}

int main(int argc, char const *argv[])
{
    EquilateralTriangle et(3);
    get_info(et);
    Homework hw;
    hw.get_info(et);

    return 0;
}
