#include "myswap_int.h"

myswap_int::myswap_int(int temp):temp_(temp)
{
}

myswap_int::~myswap_int()
{
}


int getTemp(myswap_int swap)
{
    return swap.temp_;
}