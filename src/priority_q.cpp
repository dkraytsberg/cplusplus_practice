#include <iostream>

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
    //sort
    for(int i = 0; i < size; i++){
      if(t > ptr[i]){
        T temp = ptr[i];
        ptr[i] = t;
        t = temp;
      }
    }

    ptr[size++] = t;
  }
  T remove(){
    if(size > 0)
      return ptr[--size];

  }
  bool contains(T t){
    for(int i = 0; i < size; i++){
      if(ptr[i] == t)
        return true;
      else if(ptr[i] < t)
        break;
    }
    return false;
  }
  void print(){
    for(int i = size - 1; i >= 0; i--)
      cout << ptr[i] << endl;
  }
};

struct node{
  enum {REG,BLK,STR,END};
  int type, x, y, f, g, h;
  node(int x, int y): x(x),y(y),type(REG) {}
  node(int x, int y, int type): x(x),y(y),type(type) {}
  
  bool operator> (node other){ return (f > other.f ? true : false); }
  bool operator< (node other){ return (f < other.f ? true : false); }
  bool operator== (node other){
    return ((other.x == x && other.y == y) ? true : false); }
  bool operator+ (int add){ return f+add; }
  bool operator- (int subt){ return f-subt; }

};




int main(){
  priority_q<int> q;







}
