#ifndef TEMPLATE_CLASS_SWAP_INT__
#define TEMPLATE_CLASS_SWAP_INT__

#include "myswap.hpp"

class myswap_int:public myswap<int>
{
public:
    int temp_;
public:
    friend int getTemp(myswap_int);
    myswap_int(int temp);
    ~myswap_int();
};

int getTemp(myswap_int swap);
#endif