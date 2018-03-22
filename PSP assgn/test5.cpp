#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void cast( void );

int main( void ) {

   cast();

   return 0;

}

void cast( void ) {

   int num;

   for ( int i = 0; i < 3; i++ ) {

   srand( time( NULL ) );  //  using the time seed from srand explanation
   num = rand();
   cout << num << endl;

   }

   return;

}
