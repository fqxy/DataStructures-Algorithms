#include <iostream>
#include "heap.h"

using namespace std;

int main(int argc, char const *argv[])
{
    heap<int> h;

    cout << h.empty() << endl;
    cout << h.size() << endl;

    h.push(1);
    h.push(3);
    h.push(2);
    h.push(4);

    cout << h.empty() << endl;
    cout << h.size() << endl;

    cout << h << endl;

    h.pop();
    cout << h << endl;

    return 0;
}
