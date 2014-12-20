#include <iostream>

using namespace std;

namespace FOO{
  void foo(){
    cout << "foo\n";
  }
  void bar(void (*fp)()){
    fp();
  }
}

int main(){
  //pointers to above functions
  void (*foo_ptr)() = &FOO::foo;
  void (*bar_ptr)(void (*)()) = &FOO::bar;
  bar_ptr(foo_ptr);

  //struct with overloaded '()', acting like function
  struct foo_struct{
    void operator()(){cout << "i know kung fu\n";}
    void operator()(foo_struct f){f(); cout << "show me\n";}
  }foo,bar;

  bar(foo);

}
