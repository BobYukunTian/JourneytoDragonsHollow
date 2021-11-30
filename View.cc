#include <iostream>
using namespace std;
#include <string>

#include "View.h"

void View::showMenu(int& choice)
{
  cout << "Welcome to The Tortoise Chronicles: Journey to Dragon’s Hollow !";
  cout << endl << endl;
  cout << "Select an option:"<< endl;
  cout << "  (1) Run" << endl;
  cout << "  (2) Modify width and height" << endl;
  cout << "  (3) Print statistics" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 1 || choice > 3) {
    cout << "Enter your selection: ";
    cin >> choice;
  }

}

void View::printStr(string str)
{
  cout << str;
}

void View::printInt(int& n)
{
  cout << n;
}
void View::readInt(int& n)
{
  cin >> n;
}

void View::readFloat(float& f)
{
  cin >> f;
}

void View::readStr(string& str)
{
  cin >> str;
}
