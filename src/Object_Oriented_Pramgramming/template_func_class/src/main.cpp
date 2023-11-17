#include "myswap.hpp" //类模板一般写成hpp,即定义声明在同一文件内
#include "myswap_int.h"
#include <iostream>

myswap<float> MySwap;
myswap_int MySwap_int(10);

template <typename T, typename T1>
T1 add(T a, T1 b)
{
    return a + b;
}

int main(int argc, char *argv[])
{
    // int a = 10,b = 20;
    // std::string a = "hello",b = " world";
    int a = 10;
    float b = 2.5;
    std::cout << "a + b = " << add(a, b) << std::endl;

    float c = 1.5, d = 2.6;
    std::cout << "before swap"
              << "c: " << c << " d: " << d << std::endl;
    MySwap.swap(c, d);
    std::cout << "after swap"
              << "c: " << c << " d: " << d << std::endl;

    int e = 10, f = 20;
    std::cout << "before swap"
              << "e: " << e << " f: " << f << std::endl;
    MySwap_int.swap(e, f);
    std::cout << "after swap"
              << "e: " << e << " f: " << f << std::endl;

    std::cout << getTemp(MySwap_int) << std::endl; // 友元函数

    return 0;
}
