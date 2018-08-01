#include <iostream>
#include "arrayStack.h"
#include "linkedStack.h"

using namespace std;

int main(int argc, char const *argv[])
{
    arrayStack<int> s(5);
    cout << s.empty() << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.size() << endl;
    cout << s << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;
    cout << s << endl;

    linkedStack<int> s2;
    cout << s.empty() << endl;
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    s2.push(5);
    cout << s2.size() << endl;
    cout << s2 << endl;
    s2.pop();
    s2.pop();
    cout << s2.top() << endl;
    cout << s2 << endl;

    return 0;
}
