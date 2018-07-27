#include <iostream>
#include "matrix.h"

using namespace std;

int main(int argc, char const *argv[])
{
    matrix<int> m(3, 3);
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            m(i, j) = i * j;
    cout << m << endl;

    matrix<int> m2;
    m2 = -m;
    cout << m2 << endl;

    matrix<int> m3 = m - m2;
    cout << m3 << endl;

    cout << m3 + m2 << endl;

    matrix<int> m4(3, 4);
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 4; j++)
            m4(i, j) = i * j;
    cout << m4 << endl;

    cout << m * m4 << endl;

    m += 1;
    cout << m << endl;

    return 0;
}
