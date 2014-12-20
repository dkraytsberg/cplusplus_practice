#include <iostream>

using namespace std;



int main(){

  int y = 0;

  auto max = [=](int x){ x > y ? cout << x : cout << y; cout << endl; };

  max(5);


}
