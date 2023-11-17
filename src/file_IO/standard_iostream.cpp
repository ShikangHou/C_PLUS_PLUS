#include <iostream>

// 标准输入流
void test01()
{
    char ch;
    while((ch = std::cin.get()) != EOF)//回车之后才有输出，说明有缓冲区存在
    {
        std::cout<<ch<<std::endl;
    }
}

int main(int argc, char *argv[])
{
    // std::cout; // 标准输出流 有缓冲区
    // std::cin;  // 标准输入流 有缓冲区
    // std::cerr; // 标准错误流 无缓冲区
    // std::clog; // 标准日志流 有缓冲区

    test01();
    return 0;
}
