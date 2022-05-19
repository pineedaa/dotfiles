#include <iostream>
using namespace std;
#include "tporo.h"


int
main(void)
{
  TPoro a;
  TPoro b(0, 0, 0, NULL);

  a.Posicion(0,0);
  a.Volumen(0);
  a.Color(NULL);

 if(a==b)
    cout << "IGUALES" << endl;
  else
    cout << "DISTINTOS" << endl;

  a.Color((char*)"rojo");
  b.Color((char*)"ROJO");

 if(a==b)
    cout << "IGUALES" << endl;
  else
    cout << "DISTINTOS" << endl;



}
