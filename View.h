#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;


class View
{
  public:
    void showMenu(int&);
    void printStr(string);
    void printInt(int&);
    void readInt(int&);
    void readFloat(float&);
    void readStr(string&);
};

#endif
