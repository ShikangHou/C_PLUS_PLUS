#include <iostream>
#include <string.h>
#include <exception>
// throw 抛出异常
// try/catch，try中放置可能抛出异常的代码，称为保护代码。catch用于捕获异常。
// 如果try在不同的情境下抛出不同的异常，可以罗列多个catch语句，用于捕获不同类型的异常。


// 拷贝构造函数
// 如果在类中没有定义拷贝构造函数，编译器会自行定义一个，为浅构造，只进行赋值操作。如果类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数，实现深拷贝。
// 拷贝有两种：深拷贝，浅拷贝。
// 当出现类的等号赋值时，会调用拷贝函数，在未定义显示拷贝构造函数的情况下，系统会调用默认的拷贝函数——即浅拷贝，它能够完成成员的一一复制。当数据成员中没有指针时，浅拷贝是可行的。
// 但当数据成员中有指针时，如果采用简单的浅拷贝，则两类中的两个指针将指向同一个地址，当对象快结束时，会调用两次析构函数，而导致指针悬挂现象。所以，这时，必须采用深拷贝。

// 深拷贝与浅拷贝的区别就在于深拷贝会在堆内存中另外申请空间来储存数据，从而也就解决了指针悬挂的问题。简而言之，当数据成员中有指针时，必须要用深拷贝。
// 对象赋值 浅拷贝 深拷贝的区别 https://blog.csdn.net/weixin_43881014/article/details/120759413
class MyException : public std::exception
{
private:
    char* error;
public:
    MyException()
    {
        std::cout<<"构造函数"<<std::endl;
    };
    MyException(char* str)
    {
        error = new char[strlen(str) + 1]; // 加1因为字符串结尾有‘\0'
        strcpy(error,str);
        std::cout<<"构造函数 str"<<std::endl;
    }

    MyException(const MyException& excep)
    {
        this->error = new char[strlen(excep.error) + 1];
        strcpy(this->error,excep.error);
        std::cout<<"拷贝构造函数"<<std::endl;
    }
    MyException& operator=(const MyException& excep)
    {
        if(this->error != NULL)
        {
            delete[] this->error;
            this->error = NULL;
        }
        this->error = new char[strlen(excep.error) + 1];
        strcpy(this->error,excep.error);
    }

    ~MyException()
    {
        if(this->error != NULL)
        {
            delete[] this->error;
        }   
        std::cout<<"析构函数"<<std::endl;
    }

    char* what()
    {
        return this->error;
    }
};


void func02()
{
    throw MyException("my exception 02");
}

void test02()
{
    try
    {
        func02();
    }
    // catch(MyException e) //用抛出的MyException 对象初始化e,因为MyException 中含有指针变量，所以要实现拷贝构造函数。
    // {
    //     std::cerr << e.what() << '\n';
    // }
    catch(MyException& e) //std::exception& e //引用，不调用拷贝构造函数
    {
        std::cerr << e.what() << '\n';
    }

    
}

//异常接口声明
//该函数只能抛出类型为 int float char 类型的异常
void func01() throw(int,float)
{
    throw "a";
}

float devide(float a,float b)
{
    if(b == 0)
    {
        // throw "division by zero condition!";
        throw std::out_of_range("division by zero condition!");
    }
    return (a/b);
}

void test01()
{
    try
    {
        float z = devide(10,0);
    }
    // catch(const char* e)
    // {
    //     std::cerr <<e<< '\n';
    // }
    catch(const std::out_of_range& e)
    {
        std::cerr<<e.what()<<std::endl;
    }
}



int main(int argc, char *argv[])
{
    test01();

    return 0;
}
