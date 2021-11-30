#include <iostream>
using namespace std;
#include <cstdlib>
#include "Array.h"
template <class T>
class TwoDimArray
{
  public:
    TwoDimArray(int r, int c);
    ~TwoDimArray();
    Array<T>& operator[](int);

  private:
    int capacity;
    Array<T>**  arrs;
};


template <class T>
TwoDimArray<T>::TwoDimArray(int r, int c)
{
  capacity = r;
  arrs = new Array<T>*[r];
  for (int i = 0; i < r; i++) {
      arrs[i] = new Array<T>(c);
  }
}

template <class T>
TwoDimArray<T>::~TwoDimArray()
{
    for (int i = 0; i < capacity; i++)
        delete arrs[i];
  delete [] arrs;
}

template <class T>
Array<T>& TwoDimArray<T>::operator[](int s)
{
    /*
    cout <<"s: " << s << endl;
  if (s<0 || s >= capacity) {
    cerr<<"Overflow"<<endl;
    exit(1);
  }
     */
  return *arrs[s];
}

