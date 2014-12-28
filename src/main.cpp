#include <iostream>
#include <string>

using namespace std;

struct person{
  int age;
  string name;
  person(){}
  person(int age, string name):age(age),name(name){}
  void print(){
    cout << name << "," << age << endl;
  }
};

struct people{
  person * ppl;
  int num_ppl;
  people(){
    ppl = new person[5];
    num_ppl = 0;
  }
  void add(person p){
    ppl[num_ppl++] = p;
  }
  person remove(){
    return ppl[--num_ppl];
  }
};

int main(){
  person dave(23,"dave");;
  person joe(20,"joe");
  people peeps;
  peeps.add(dave);
  peeps.add(joe);
  {
    person temp = peeps.remove();
    temp.print();
  }



}
