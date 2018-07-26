#ifndef __chain__
#define __chain__

#include <iostream>
#include <sstream>

#include "../myExceptions.h"

using namespace std;

template <class T>
struct chainNode
{
    T element;
    chainNode<T> *next;

    chainNode() {}
    chainNode(const T &element)
    {
        this->element = element;
    }
    chainNode(const T &element, chainNode<T> *next)
    {
        this->element = element;
        this->next = next;
    }
};

template <class T>
class chain
{
  public:
    chain(int initialCapacity = 10);
    chain(const chain<T> &);
    ~chain();
    // 判断
    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }
    // 查询
    T &get(int theIndex) const;
    int indexOf(const T &theElement) const;
    // 增删
    void erase(int theIndex);
    void insert(int theIndex, const T &theElement);
    // 输出
    void output(ostream &out) const;

  private:
    chainNode<T> *firstNode;
    int listSize;

    void checkIndex(int theIndex) const;
};

template <class T>
void chain<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex >= listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }
}

template <class T>
chain<T>::chain(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " must be > 0";
        throw illegalParameterValues(s.str());
    }

    firstNode = NULL;
    listSize = 0;
}

template <class T>
chain<T>::chain(const chain<T> &theList)
{
    listSize = theList.listSize;
    if (listSize == 0)
    {
        firstNode == NULL;
        return;
    }

    chainNode<T> *sourceNode = theList.firstNode;
    firstNode = new chainNode<T>(sourceNode->element);
    sourceNode = sourceNode->next;

    chainNode<T> *targetNode = firstNode;

    while (sourceNode != NULL)
    {
        targetNode = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = targetNode->next;
    }
    targetNode->next = NULL;
}

template <class T>
chain<T>::~chain()
{
    while (firstNode != NULL)
    {
        chainNode<T> *nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template <class T>
T &chain<T>::get(int theIndex) const
{
    checkIndex(theIndex); // const修饰的参数只能访问const函数
                          // 因此checkIndex()也要为const
    chainNode<T> *currentNode = firstNode;
    for (int i = 0; i < theIndex; i++)
        currentNode = currentNode->next;

    return currentNode->element;
}

template <class T>
int chain<T>::indexOf(const T &theElement) const
{
    chainNode<T> *currentNode = firstNode;
    int index = 0;
    while (currentNode != NULL &&
           currentNode->element != theElement)
    {
        currentNode = currentNode->next;
        index++;
    }
    if (currentNode == NULL)
        return -1;
    else
        return index;
}

template <class T>
void chain<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    chainNode<T> *deleteNode;

    if (theIndex == 0)
    {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    }
    else
    {
        chainNode<T> *p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;

        deleteNode = p->next;
        p->next = p->next->next;
    }
    delete deleteNode;
    listSize--;
}

template <class T>
void chain<T>::insert(int theIndex, const T &theElement)
{
    if (theIndex < 0 || theIndex > listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

    chainNode<T> *newNode = new chainNode<T>(theElement);

    if (theIndex == 0)
    {
        newNode->next = firstNode;
        firstNode = newNode;
    }
    else
    {
        chainNode<T> *p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;

        newNode->next = p->next;
        p->next = newNode;
    }

    listSize++;
}

template <class T>
void chain<T>::output(ostream &out) const
{
    chainNode<T> *p = firstNode;
    while (p != NULL)
    {
        cout << p->element << " ";
        p = p->next;
    }
}

template <class T>
ostream &operator<<(ostream &out, const chain<T> &c)
{
    c.output(out);
    return out;
}

#endif