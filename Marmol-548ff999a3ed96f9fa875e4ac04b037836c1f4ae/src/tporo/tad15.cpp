#include <iostream>

using namespace std;

#include "tporo.h"

int
main(void)
{
  TPoro a(1,1,1,(char*)"amarillo"), b(1, 1, 1,(char*)"amarillo");

  if(a==b) cout<<"Esta prueba está bien"<<endl;

}
