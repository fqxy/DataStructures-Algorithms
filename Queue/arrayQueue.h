#ifndef __arrayQueue__
#define __arrayQueue__

#include "queue.h"
#include "../myExceptions.h"
#include <sstream>

using namespace std;

template <class T>
class arrayQueue : public queue<T>
{
  public:
    arrayQueue(int initialCapacity = 10);
    ~arrayQueue() { delete[] queue; }

    bool empty() const { return theFront == theBack; }
    int size() const
    {
        return (theBack - theFront + arrayLength) % arrayLength;
    }

    T &front()
    {
        if (empty())
            throw queueEmpty();
        return queue[(theFront + 1) % arrayLength];
    }
    T &back()
    {
        if (empty())
            throw queueEmpty();
        return queue[theBack];
    }
    void pop()
    {
        if (empty())
            throw queueEmpty();
        theFront = (theFront + 1) % arrayLength;
        queue[theFront].~T();
    }
    void push(const T &theElement);

  private:
    int theFront;
    int theBack;
    int arrayLength;
    T *queue;
};

template <class T>
arrayQueue<T>::arrayQueue(int initialCapacity)
{
    if (initialCapacity < 1)
        throw illegalParameterValues();
    arrayLength = initialCapacity;
    queue = new T[arrayLength];
    theFront = 0;
    theBack = 0;
}

template <class T>
void arrayQueue<T>::push(const T &theElement)
{
    // full
    if ((theBack + 1) % arrayLength == theFront)
    {
        T *newQueue = new T[arrayLength * 2];
        int start = (theFront + 1) % arrayLength;
        if (start < 2)
            copy(queue + start, queue + start + arrayLength - 1, newQueue);
        else
        {
            copy(queue + start, queue + arrayLength, newQueue);
            copy(queue, queue + theBack + 1, newQueue + arrayLength - start);
        }
        theFront = 2 * arrayLength - 1;
        theBack = arrayLength - 2;
        arrayLength *= 2;
        queue = newQueue;
    }

    theBack = (theBack + 1) % arrayLength;
    queue[theBack] = theElement;
}

#endif