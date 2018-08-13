#include <iostream>
#include "linkedBinaryTree.h"

using namespace std;

int main(int argc, char const *argv[])
{
    linkedBinaryTree<int> a, b, c, d;
    linkedBinaryTree<int> e, f, g, h;
    g.makeTree(1, h, h);
    f.makeTree(2, h, h);
    e.makeTree(3, f, g);
    d.makeTree(4, h, h);
    c.makeTree(5, d, e);
    b.makeTree(6, h, h);
    a.makeTree(7, b, c);

    cout << "a.size = " << a.size() << endl;
    cout << "a.height = " << a.height() << endl;
    a.preOrderOutput();
    a.inOrderOutput();
    a.postOrderOutput();

    //             7
    //            / \
    //           6   5
    //              / \
    //             4   3
    //                / \
    //               2   1
    return 0;
}
