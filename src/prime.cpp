#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv){
  int x = 0;
  int * primes, count = 0;

  if(argc > 1)
    x = atoi(*(argv+1));

  primes = new (nothrow) int[x];

  for(int i = 2; i < x; i++){
    bool isPrime = true;
    for(int j = 2; j < i-1; j++){
      if(i%j == 0 && !(isPrime = false))
        break;
    }
    if(isPrime)
      primes[count++] = i;
  }

  {
    int * temp = new (nothrow) int[count];
    for(int i = 0; i < count; i++)
      temp[i] = primes[i];
    delete[] primes;
    primes = temp;
    temp = NULL;
  }

  for(int i = 0; i < count; i++)
    cout << primes[i] << "\n";

  delete[] primes;

  string abc;
  cout << "type something\n";
  while(true){
    string temp;
    cin >> temp;
    abc+=temp;
    cout << "abc = \"" <<abc<<"\"\n";
  }



}
