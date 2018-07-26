
#include <iostream>
#include "chain.h"

using namespace std;

main(int argc, char const *argv[])
{
    // 测试异常处理
    try
    {
        chain<int> *a = new chain<int>(0);
    }
    catch (illegalParameterValues &ex)
    {
        ex.outputMessage();
    }

    chain<int> x;

    if (x.empty())
        cout << "x is empty" << endl;

    x.insert(0, 1);
    x.insert(1, 2);
    x.insert(2, 3);
    x.insert(0, 4);
    x.insert(1, 5);
    x.insert(2, 6);
    cout << x << endl;

    cout << x.get(5) << endl;
    cout << x.indexOf(4) << endl;

    x.erase(0);
    cout << x << endl;
    cout << "size of chain is " << x.size() << endl;

    return 0;
}
