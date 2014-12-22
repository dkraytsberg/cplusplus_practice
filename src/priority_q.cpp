#include <iostream>
#include <string>


 #include "h/file.h"

using namespace std;

template <class T>
class priority_q{
public:
  T * ptr;
  int size = 0;
  int max = 10;

  priority_q(){
    ptr = new T[max];
  }
  ~priority_q(){
    delete[] ptr;
  }
  void add(T t){
    if(size >= max){  //expand
      T * tmp = new T[max*2];
      for(int i = 0; i < max; i++)
        tmp[i] = ptr[i];
      delete[] ptr;
      ptr = tmp;
      max *= 2;
    }

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
  // priority_q<int> q;
  // for(int i = 1; i < 22; i++){
  //   q.add(i*i);
  //   cout << q.max << " " << q.size << endl;
  // }
  // q.print();
  cout << x << endl;




}
