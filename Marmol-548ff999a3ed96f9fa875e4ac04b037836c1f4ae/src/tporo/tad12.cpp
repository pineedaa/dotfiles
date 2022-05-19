#include <iostream>

using namespace std;

#include "tporo.h"

int
main(void)
{
  TPoro a(4, 3, 6, (char*)"naranja");
cout<<a<<endl;
  a.Posicion(5,4);
  a.Volumen(7);
  a.Color((char*)"pepe");
cout<<a<<endl;
}
