#include <iostream>
using namespace std;
#include "tporo.h"

/*CHEQUEO DE != */
int
main(void)
{
  TPoro a(2,2,0,NULL);
  TPoro b(2,2,20,(char*)"aZUL");

  a.Volumen(20);
  a.Color("Azul");

  if(a!=b)
    cout << "DISTINTOS" << endl;
  else
    cout << "IGUALES" << endl;
}
