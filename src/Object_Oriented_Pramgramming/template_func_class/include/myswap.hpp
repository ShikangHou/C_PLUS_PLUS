#ifndef TEMPLATE_CLASS_MYSWAP_H__
#define TEMPLATE_CLASS_MYSWAP_H__

template <typename T>
class myswap
{
private:
    /* data */
public:
    void swap(T &a, T &b);
    myswap(/* args */);
    ~myswap();
};

template <typename T>
void myswap<T>::swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}


template <typename T>
myswap<T>::myswap()
{
}
template <typename T>
myswap<T>::~myswap()
{
}



#endif