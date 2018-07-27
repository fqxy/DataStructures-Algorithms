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

class matrixSizeMismatch
{
  public:
    matrixSizeMismatch(string theMessage = "The size of the two matrics doesn't match")
    {
        messages = theMessage;
    }
    void outputMessage()
    {
        cout << messages << endl;
    }

  private:
    string messages;
};

class stackEmpty
{
  public:
    stackEmpty(string s = "The stack is empty")
    {
        messages = s;
    }
    void outputMessage()
    {
        cout << messages << endl;
    }

  private:
    string messages;
};

#endif