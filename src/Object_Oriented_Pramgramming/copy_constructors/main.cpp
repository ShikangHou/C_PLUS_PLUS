#include <iostream>

using namespace std;

// 编译器默认的拷贝构造函数为浅拷贝，如果类成员中含有指针类型，
// 原对象和新对象共享相同的内存地址，重复调用析构函数释放内存会有错误，
// 因此要手动实现深拷贝的拷贝构造函数


namespace Test01
{
    class Book
    {
    private:
        string title_;
        string author_;
        float* rates;
        int rateCounter;
    public:
        Book(string title,string author)
        {
            title_ = title;
            author_ = author;
            
            rateCounter = 2;
            rates = new float[rateCounter];
            rates[0] = 4;
            rates[1] = 5;
        }

        ~Book()
        {
            delete[] rates;
            rates = nullptr;
        }
    
    };

}

// 类中成员有指针类型，如果不自己实现拷贝构造函数，会使用编译器默认的，只能实现浅拷贝，
// 新对象的指针和老对象的指针指向同一块地址，调用析构函数时连续释放多次空间导致错误。
void test01()
{
    Test01::Book book1("math","lihua");
    Test01::Book book2(book1); 
    Test01::Book book3 = book1;

}

namespace Test02
{
    class Book
    {
    private:
        string title_;
        string author_;
        float* rates;
        int rateCounter;
    public:
        Book()
        {

        }

        Book(string title,string author)
        {
            title_ = title;
            author_ = author;
            
            rateCounter = 2;
            rates = new float[rateCounter];
            rates[0] = 4;
            rates[1] = 5;
        }

        Book(const Book& book)
        {
            this->author_ = book.author_;
            this->title_ = book.title_;
            this->rateCounter = book.rateCounter;
            this->rates = new float[this->rateCounter];
            this->rates[0] = book.rates[0];
            this->rates[1] = book.rates[1];
        }

        ~Book()
        {
            delete[] rates;
            rates = nullptr;
        }

        void operator= (const Book& book)
        {
            this->author_ = book.author_;
            this->title_ = book.title_;
            this->rateCounter = book.rateCounter;
            this->rates = new float[this->rateCounter];
            this->rates[0] = book.rates[0];
            this->rates[1] = book.rates[1];
        }
    
    };
}

void test02()
{
    Test02::Book book1("math","lihua");
    Test02::Book book2(book1);
    // 这种情况下使用拷贝构造 
    Test02::Book book3 = book1;
    // 这种情况下要重载 =
    Test02::Book book4;
    book4 = book1;

}

int main(int argc, char *argv[])
{
    // test01();
    test02();
    return 0;
}
