#ifndef __linkedStack__
#define __linkedStack__

#include <iostream>
#include "stack.h"
#include "../myExceptions.h"

using namespace std;

template <class T>
struct chainNode
{
    T element;
    chainNode<T> *next;

    chainNode() {}
    chainNode(const T &theElement)
    {
        this->element = theElement;
    }
    chainNode(const T &theElement, chainNode<T> *next)
    {
        this->element = theElement;
        this->next = next;
    }
};

template <class T>
class linkedStack : public stack<T>
{
    template <class E>
    friend ostream &operator<<(ostream &, linkedStack<E> &);

  public:
    linkedStack(int initialCapacity = 10)
    {
        stackSize = 0;
        stackTop = NULL;
    }
    ~linkedStack();

    bool empty() const { return stackSize == 0; }
    int size() const { return stackSize; }

    T &top()
    {
        if (stackSize == 0)
            throw stackEmpty();
        return stackTop->element;
    }
    void push(const T &theElement)
    {
        stackTop = new chainNode<T>(theElement, stackTop);
        stackSize++;
    }
    void pop();

  private:
    int stackSize;
    chainNode<T> *stackTop;
};

template <class T>
linkedStack<T>::~linkedStack()
{
    chainNode<T> *cur = stackTop;
    while (cur != NULL)
    {
        delete stackTop;
        cur = cur->next;
        stackTop = cur;
    }
}

template <class T>
void linkedStack<T>::pop()
{
    if (stackTop == NULL)
    {
        throw stackEmpty();
    }
    chainNode<T> *nextNode = stackTop->next;
    delete stackTop;
    stackTop = nextNode;
    stackSize--;
}

template <class T>
ostream &operator<<(ostream &out, linkedStack<T> &s)
{
    chainNode<T> *cur = s.stackTop;
    while (cur != NULL)
    {
        out << cur->element << "  ";
        cur = cur->next;
    }
    return out;
}

#endif