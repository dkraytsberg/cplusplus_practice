#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

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
    for(int i = 0; i < size; i++)
      if(t > ptr[i])
        swap(ptr[i],t);

    ptr[size++] = t;
  }
  T remove(){
    if(size > 0)
      return ptr[--size];
  }
  int contains(T t){
    for(int i = 0; i < size; i++){
      if(ptr[i] == t)
        return i+1;
      else if(ptr[i] < t)
        break;
    }
    return 0;
  }

  void modify(int i,T t){
    i--;
    T old = ptr[i];
    ptr[i] = t;
    if(ptr[i] < old){
      while(i < size-1 && ptr[i] < ptr[i+1]){
        swap(ptr[i],ptr[i+1]);
        i++;
      }
    }
  }
  int operator[](T t){
    return contains(t);
  }
  void swap(T& t1, T& t2){
    T temp = t1;
    t1 = t2;
    t2 = temp;
  }
  void print(){
    for(int i = 0; i < size; i++)
      ptr[i].print();//cout << ptr[i] << endl;
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

  void print(){ cout<<"x: "<<x<<" y: "<<y<<" f: "<<f<<endl; }

};



int main(){
  //priority_q<int> q;

  //IMPORTANT
  //array of pointers to object that must all be
  //allocated dynamically
  node ** node_ptr = new node *[5];
  for(int i = 0; i < 5; i++){
    node_ptr[i] = new node(i,i);
  }
  for(int i = 0; i < 5; i++){
    node_ptr[i]->print();
    delete node_ptr[i];
  }
  delete[] node_ptr;







}
