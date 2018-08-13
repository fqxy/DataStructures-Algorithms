#ifndef __heap__
#define __heap__

#include <iterator>

#include "priorityQueue.h"
#include "../myExceptions.h"
#include "../changeLength1D.h"

using namespace std;

template <class T>
class heap : public priorityQueue<T>
{
    template <class E>
    friend ostream &operator<<(ostream &, const heap<E> &);

  public:
    heap(int initialCapacity = 10);
    ~heap() { delete[] heapArr; }

    bool empty() const { return heapSize == 0; }
    int size() const { return heapSize; }

    const T &top()
    {
        if (heapSize == 0)
            throw queueEmpty();
        return heapArr[1];
    }

    void push(const T &theElement);
    void pop();

  private:
    T *heapArr;
    int arrayLength;
    int heapSize;
};

template <class T>
heap<T>::heap(int initialCapacity)
{
    if (initialCapacity < 1)
        throw illegalParameterValues();
    arrayLength = initialCapacity + 1;
    heapArr = new T[arrayLength];
    heapSize = 0;
}

template <class T>
void heap<T>::push(const T &theElement)
{
    // full
    if (heapSize == arrayLength - 1)
    {
        changeLength1D(heapArr, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }

    int currentNode = ++heapSize;

    while (currentNode > 1 && theElement > heapArr[currentNode / 2])
    {
        heapArr[currentNode] = heapArr[currentNode / 2];
        currentNode /= 2;
    }

    heapArr[currentNode] = theElement;
}

template <class T>
void heap<T>::pop()
{
    if (this->empty())
        throw queueEmpty();

    heapArr[1].~T();

    T lastElement = heapArr[heapSize--];

    int currentNode = 1, child = 2;

    while (child <= heapSize)
    {
        if (child < heapSize && heapArr[child] < heapArr[child + 1])
            child++;

        if (lastElement >= heapArr[child])
            break;

        // move down
        heapArr[currentNode] = heapArr[child];
        currentNode = child;
        child *= 2;
    }
    heapArr[currentNode] = lastElement;
}

template <class T>
ostream &operator<<(ostream &out, const heap<T> &h)
{
    for (int i = 1; i <= h.heapSize; i++)
        out << h.heapArr[i] << "  ";
    return out;
}

#endif