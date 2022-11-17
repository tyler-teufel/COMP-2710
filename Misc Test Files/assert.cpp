//Class file

//#define NDEBUG
#include <iostream>
#include <assert.h>

using namespace std;

const int N_PRIMES = 7;
int primes[N_PRIMES] = {2,3,5,7, 11, 13, 17};

int main ()
{
   int index = -3;
   assert(index<N_PRIMES);
   assert(index>=0);
   cout << "THe tenth prime is " << primes[index] << endl;
   return 0;


}