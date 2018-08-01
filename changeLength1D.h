#ifndef __changeLength1D__
#define __changeLength1D__

#include <algorithm>
#include "myExceptions.h"

using namespace std;

template <class T>
void changeLength1D(T *&a, int oldLen, int newLen)
{
    if (oldLen < 0)
        throw illegalParameterValues("new length must be >= 0");

    T *tem = new T[newLen];
    int num = min(oldLen, newLen);
    copy(a, a + num, tem);
    delete[] a;
    a = tem;
}

#endif