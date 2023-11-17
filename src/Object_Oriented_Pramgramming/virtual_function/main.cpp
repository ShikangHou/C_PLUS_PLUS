#include <iostream>

using namespace std;

class Instrument
{
private:
public:
    void make_sound()
    {
        cout << "instrument is playing" << endl;
    }

    virtual void sound()
    {
        cout << "instrument is playing" << endl;
    }

    virtual void print_info() = 0; // 纯虚函数，派生类中必须要实现这个函数，用于统一接口
};

class Accordion : public Instrument

{
private:
public:
    void make_sound()
    {
        cout << "accordion is playing" << endl;
    }
    void sound()
    {
        cout << "accordion is playing" << endl;
    }
    void print_info()
    {
        cout << "accordion" << endl;
    }
};

void test01()
{
    Instrument *instrument = new Accordion();
    instrument->make_sound(); // make_sound 不是虚函数，编译器认为派生类和基类中的make_sound是多态--函数重载，因此将派生类转换成基类后，调用的是基类中的函数
    instrument->sound();      // sound 是虚函数，当派生类中重写后，调用派生类中的函数，否则调用基类中的函数
    instrument->print_info();
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
