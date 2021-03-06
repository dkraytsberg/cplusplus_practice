#include <iostream>

using namespace std;

template <class type> struct s{
  type t;
  s(type t):t(t){};
};


int main(){

  int array[5][5], count = 1;

  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      array[i][j] = count++;

  int * p = array[0];

  auto m_lambda = [](int *p, int nxn){
    for(int i = 0; i < nxn; i++){
      for(int j = 0; j < nxn; j++){
        cout << p[i*nxn + j] << "\t";
      }
      cout << "\n";
    }
  };

  m_lambda(p,5);

  {
    int x = 0, y = 10;

    // auto greater = [](int x, int y) -> int{
    //   if(y > x) return y; return x;
    // };
    cout << [](int x, int y){
      return (x > y ? x : y);
    }(x,y) << endl;
  }


}
