#include <iostream>
using namespace std;
#include <cstdlib>

template <class T>
class Array
{
  template <class V>
  friend ostream& operator<<(ostream&, const Array<V>&);

  public:
    Array(int c);
    ~Array();
    T& operator[](int);

  private:
    int capacity;
    T*  elements;
};


template <class T>
Array<T>::Array(int c)
{
  if (c < 0) {
    cerr<<"Invalid capacity"<<endl;
    exit(1);
  }
  capacity = c;
  elements = new T[capacity];
}

template <class T>
Array<T>::~Array()
{
  delete [] elements;
}

template <class T>
T& Array<T>::operator[](int s)
{
  if (s<0 || s >= capacity) {
    cerr<<"Overflow"<<endl;
    exit(1);
  }
  return elements[s];
}

template <class T>
ostream& operator<<(ostream& output, const Array<T>& arr)
{ 
  for (int i=0; i<arr.capacity; ++i)
    output<<arr.elements[i]<<endl;

  return output;
}

