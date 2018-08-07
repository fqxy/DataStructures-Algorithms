#include <iostream>
#include "arrayQueue.h"

using namespace std;

int main(int argc, char const *argv[])
{
    arrayQueue<int> q(1);
    cout << q.empty() << endl;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.empty() << endl;
    cout << q.size() << endl;

    cout << "front: " << q.front()
         << "  back: " << q.back()
         << endl;

    q.pop();
    q.pop();

    cout << "front: " << q.front()
         << "  back: " << q.back()
         << endl;

    return 0;
}
