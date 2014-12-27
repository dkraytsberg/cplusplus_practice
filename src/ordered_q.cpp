#include <iostream>
#include "priority_q.cpp"

template <class T>
class ordered_q{
public:
  T ** q;
  int size = 0;
  int max = 10;

  ordered_q(){
    q = new T *[max];
  };

  ~ordered_q(){
    delete[] q;
  };

  void add(T *t);
  T *remove();
  bool contains(T t);
  int indexof(T t);
  bool modify(int index, T newT);
  bool modify(T oldT, T newT);
  void print();
private:
  void swap(T& t1, T& t2);
};

template<class T>void ordered_q<T>::add(T *t){
  q[size++] = t;
};
template<class T>T *ordered_q<T>::remove(){
  T *temp = q[size];
  //delete q[size];
  return temp;
}



int main(int argc, char ** argv){
  ordered_q<node> q;
  q.add(new node(0,0));
  q.add(new node(1,2));
  q.q[0]->print();
  q.q[1]->print();
  q.remove();
}
