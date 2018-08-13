#ifndef __linkedBinaryTree__
#define __linkedBinaryTree__

#include <iostream>
#include "../myExceptions.h"

using namespace std;

template <class T>
struct binaryTreeNode
{
    T element;
    binaryTreeNode<T> *leftChild;
    binaryTreeNode<T> *rightChild;

    binaryTreeNode() { leftChild = rightChild = NULL; }
    binaryTreeNode(const T &theElement) : element(theElement)
    {
        leftChild = rightChild = NULL;
    }
    binaryTreeNode(const T &theElement,
                   binaryTreeNode<T> *theLeftChild,
                   binaryTreeNode<T> *theRightChild)
        : element(theElement)
    {
        leftChild = theLeftChild;
        rightChild = theRightChild;
    }
};

template <class T>
class linkedBinaryTree
{
  public:
    linkedBinaryTree()
    {
        root = NULL;
        treeSize = 0;
    }
    ~linkedBinaryTree() { erase(); }

    bool empty() const { return treeSize == 0; }
    int size() const { return treeSize; }

    void makeTree(const T &,
                  linkedBinaryTree<T> &,
                  linkedBinaryTree<T> &);

    void preOrder(void (*theVisit)(binaryTreeNode<T> *))
    {
        visit = theVisit;
        preOrder(root);
    }
    void inOrder(void (*theVisit)(binaryTreeNode<T> *))
    {
        visit = theVisit;
        inOrder(root);
    }
    void postOrder(void (*theVisit)(binaryTreeNode<T> *))
    {
        visit = theVisit;
        postOrder(root);
    }

    // the interface
    void preOrderOutput()
    {
        preOrder(output);
        cout << endl;
    }
    void inOrderOutput()
    {
        inOrder(output);
        cout << endl;
    }
    void postOrderOutput()
    {
        postOrder(output);
        cout << endl;
    }
    void erase()
    {
        postOrder(dispose);
        root = NULL;
        treeSize = 0;
    }

    int height() const { return height(root); }

  protected:
    binaryTreeNode<T> *root;
    int treeSize;
    static void (*visit)(binaryTreeNode<T> *);
    static int count;

    static void preOrder(binaryTreeNode<T> *t);
    static void inOrder(binaryTreeNode<T> *t);
    static void postOrder(binaryTreeNode<T> *t);

    // visit as function pointer
    // manipulations for evernode
    static void output(binaryTreeNode<T> *t) { cout << t->element << ' '; }
    static void dispose(binaryTreeNode<T> *t) { delete t; }
    static void addToCount(binaryTreeNode<T> *t) { count++; }

    static int height(binaryTreeNode<T> *t);
};

template <class T>
void (*linkedBinaryTree<T>::visit)(binaryTreeNode<T> *);

template <class T>
void linkedBinaryTree<T>::preOrder(binaryTreeNode<T> *t)
{
    if (t != NULL)
    {
        linkedBinaryTree<T>::visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

template <class T>
void linkedBinaryTree<T>::inOrder(binaryTreeNode<T> *t)
{
    if (t != NULL)
    {
        inOrder(t->leftChild);
        linkedBinaryTree<T>::visit(t);
        inOrder(t->rightChild);
    }
}

template <class T>
void linkedBinaryTree<T>::postOrder(binaryTreeNode<T> *t)
{
    if (t != NULL)
    {
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        visit(t);
    }
}

template <class T>
int linkedBinaryTree<T>::height(binaryTreeNode<T> *t)
{
    if (t == NULL)
        return 0;
    int hl = height(t->leftChild);
    int hr = height(t->rightChild);
    if (hl > hr)
        return ++hl;
    else
        return ++hr;
}

template <class T>
void linkedBinaryTree<T>::makeTree(const T &theElement,
                                   linkedBinaryTree<T> &left,
                                   linkedBinaryTree<T> &right)
{
    root = new binaryTreeNode<T>(theElement, left.root, right.root);
    treeSize = left.treeSize + right.treeSize + 1;

    left.root = right.root = NULL;
    left.treeSize = right.treeSize = 0;
}

#endif