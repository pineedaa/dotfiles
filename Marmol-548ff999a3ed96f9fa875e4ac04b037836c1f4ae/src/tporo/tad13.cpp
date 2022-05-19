#include <iostream>

using namespace std;

#include "tporo.h"

int
main(void)
{
  TPoro a(3,4,5,(char*)"amarillo"),b(0, 0, 6, (char*)"blue");
  
if(a!=b) cout<<"Esta prueba está bien"<<endl;

}
