#include <iostream>
#include <sstream>

using namespace std;

main(int argc, char const *argv[])
{
    ostringstream s;
    s << "hello "
      << "world.";
    cout << s.str();
    return 0;
}
