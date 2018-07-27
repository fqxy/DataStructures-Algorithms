#include <iostream>
#include "arrayStack.h"

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

    return 0;
}
