#ifndef __myException__
#define __myException__
#include <iostream>
#include <string>

using namespace std;

class illegalIndex
{
  public:
    illegalIndex(string theMessage = "Illegal Index")
    {
        message = theMessage;
    }
    void outputMessage()
    {
        cout << message << endl;
    }

  private:
    string message;
};

class illegalParameterValues
{
  public:
    illegalParameterValues(string theMessage = "Illegal parameter value")
    {
        message = theMessage;
    }
    void outputMessage()
    {
        cout << message << endl;
    }

  private:
    string message;
};

#endif