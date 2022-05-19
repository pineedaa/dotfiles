#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/************************************************/
/***************** CONSTRUCTOR DE COPIA, "="    */
/************************************************/
  TABBPoro a,c;

  TPoro p1(1,2,3,(char *) "rojo");
  a.Insertar(p1);

  TABBPoro b(a);
  c=b;

  cout << "No hace nada" << endl;

  return 1;
}
