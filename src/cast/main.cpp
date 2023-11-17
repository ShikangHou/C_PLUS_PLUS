#include <iostream>

class Base
{
    public:
        virtual void dummy()
        {
            std::cout<<"base dummy"<<std::endl;
        }
};

class Derived : public Base
{
    public:
        int a_;

    public:
        virtual void dummy();
};

void Derived::dummy()
{
    std::cout<<"derived dummy"<<std::endl;
}


// static_cast
// 可以用于内置数据类型的转换，以及相关类之间的转换
void test01()
{
    int a = 97;
    char c = static_cast<char>(a);
    std::cout<<c<<std::endl;

    Base* base01 = new Base;
    Derived* derived = static_cast<Derived*>(base01);
    base01 = static_cast<Base*>(derived);

    Base base02;
    Derived &derived02 = static_cast<Derived&>(base02);
    Base& base03 = static_cast<Base&>(derived02);

}

// dynamic_cast 只能够用在指向类的指针或者引用上。会进行指针类型的检查，确保目标指针类型所指向的是一个有效且完整的对象。
// 派生类可以转换成基类，但基类不可以转换为派生类。派生类的空间较大，基类转换成派生类会操作基类以外的空间
void test02()
{
    // 不可用于内置数据类型之间的转换
    // int a = 97;
    // char c = dynamic_cast<char>(a);

    Base* base01 = new Base;
    Derived* derived01  = new Derived;

    Derived* derived02 = dynamic_cast<Derived*>(base01);//基类转换为派生类
    if(derived02 == nullptr) std::cout<<"can not transform father to son"<<std::endl; //返回空指针来表示转换失败

    base01 = dynamic_cast<Base*>(derived01);//派生类转换为基类
    if(base01 == nullptr) std::cout<<"can not transform son to father"<<std::endl;

}

// const_cast 设置或者移除指针所指向对象的const
void test03()
{
    int a = 10;
    int& b = a;
    int& c = const_cast<int&>(b);

    std::cout<<"c: "<<c<<std::endl;
}


typedef void(*FUNC1)(int,int);
typedef int(*FUNC2)(int,char);

// reinterpret_cast 任何类型强制转换
void test04()
{
    int a = 10;
    Base* base = reinterpret_cast<Base*>(a);

    //甚至函数指针转换
    FUNC1 func1;
    FUNC2 func2 = reinterpret_cast<FUNC2>(func2);
}

//虚函数
void test05()
{
    Base base;
    Derived derived;
    base.dummy();
    derived.dummy();
}

int main(int argc, char *argv[])
{
    test05();
    return 0;
}
