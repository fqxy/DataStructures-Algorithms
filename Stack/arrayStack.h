#ifndef __arrayStack__
#define __arrayStack__

#include <iostream>
#include "stack.h"
#include "../changeLength1D.h"
#include "../myExceptions.h"

using namespace std;

template <class T>
class arrayStack : public stack<T>
{
    template <class E>
    friend ostream &operator<<(ostream &, arrayStack<E> &);

  public:
    arrayStack(int initialCapacity = 10);
    ~arrayStack() { delete[] stack; }

    bool empty() const { return stackTop == -1; }
    int size() const { return stackTop + 1; }

    T &top()
    {
        if (stackTop == -1)
            throw stackEmpty();
        return stack[stackTop];
    }
    void pop()
    {
        if (stackTop == -1)
            throw stackEmpty();
        stack[stackTop--].~T();
    }
    void push(const T &);

  private:
    int stackTop;
    int arrayLength;
    T *stack;
};

template <class T>
arrayStack<T>::arrayStack(int initialCapacity)
{
    if (initialCapacity < 1)
        throw illegalParameterValues();

    stackTop = -1;
    arrayLength = initialCapacity;
    stack = new T[arrayLength];
}

template <class T>
void arrayStack<T>::push(const T &theElement)
{
    if (stackTop == arrayLength - 1)
    {
        changeLength1D(stack, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }
    stack[++stackTop] = theElement;
}

template <class E>
ostream &operator<<(ostream &out, arrayStack<E> &s)
{
    if (s.empty())
        out << "The stack is empty";
    else
    {
        for (int i = 0; i <= s.stackTop; i++)
            out << s.stack[i] << "  ";
    }
    return out;
}

#endif