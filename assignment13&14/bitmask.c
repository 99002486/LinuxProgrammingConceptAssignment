#include"bitmask.h"

int set(int num,int pos)
{
    return num |= (1<<pos);
}

int reset(int num,int pos)
{
    return num &= ~(1<<pos);
}

int flip(int num,int pos)
{
    return num ^= (1<<pos);
}

int query(int num,int pos)
{
    return num &= (1<<pos);
}