#include <iostream>
#include <functional>

// 通过使用 std::bind，可以灵活地创建新的函数对象，处理函数参数的绑定和适配，以及实现回调函数的自定义功能。

void add_sum(int a,int b, int c)
{
    std::cout<<a+b+c<<std::endl;;
}

// 非成员函数的绑定
void test01()
{
    auto func = std::bind(add_sum,1,2,std::placeholders::_1);
    func(3); // 调用 func，实际上调用 add_sum(1, 2, 3)
}

class MYClass
{
private:
    /* data */
public:
    void sum(int a,int b, int c)
    {
        std::cout<<a+b+c<<std::endl;;
    }

};

// 将对象的成员函数和对象本身绑定到一起，从而创建一个函数对象。这在需要将成员函数作为回调函数传递时非常有用
void test02()
{
    MYClass obj;
    auto func = std::bind(&MYClass::sum,&obj,1,2,std::placeholders::_1);
    func(4); // 调用 func，实际上调用 obj.sum(1, 2, 4)
}


int main(int argc, char *argv[])
{
    // test01();
    test02();
    
    return 0;
}
