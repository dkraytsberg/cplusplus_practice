#include <iostream>
#include <string>

using namespace std;

template <class T>
class holder{
public:
  T *ptr;
  int size = 0;
  int max = 10;

  holder(){
    ptr = new T[max];
  }
  ~holder(){
    delete[] ptr;
  }
  void add(T t){
    if(size < max)
      ptr[size++] = t;
  }
  T remove(){
    if(size > 0)
      return ptr[size--];
  }
  void print(){
    for(int i = 0; i < size; i++)
      cout << ptr[i] << endl;
  }
};

int main(){

  holder<int> h;

  string x;
  cout << x << endl;

}
