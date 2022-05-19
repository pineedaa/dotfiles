#include <iostream>

using namespace std;

#include "tlistaporo.h"

int
main(void)
{
  TPoro p(1, 1, 1, (char*)"rojo"), q(2, 2, 2, (char*)"verde");
  TListaPoro a;

  a.Insertar(p);

  a.Insertar(q);
  cout << a << endl;

  a.Borrar(p);
  cout << a << endl;

  a.Borrar(q);
  cout << a << endl;
}
