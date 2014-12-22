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

int p(int x, int y){
  return (x > y ? x : y);
}

int main(){

  int x = 0, y = 10;

  (x > 0) ? x = 1 : x = x;
  // auto greater = [](int x, int y) -> int{
  //   if(y > x) return y; return x;
  // };
  cout << [](int x, int y){
    if(y > x) return y; return x;
  }(x,y) << endl;


}
