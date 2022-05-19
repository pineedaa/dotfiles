#include <iostream>

using namespace std;

#include "tlistaporo.h"

int
main(void)
{
  TPoro p(1, 2, 3, (char*)"rojo");
  TListaPoro a;

  cout << "Longitud: " << a.Longitud() << endl;

  a.Insertar(p);
  cout << "Longitud: " << a.Longitud() << endl;

  a.Insertar(p);
  cout << "Longitud: " << a.Longitud() << endl;

  a.~TListaPoro();
  cout << "Longitud: " << a.Longitud() << endl;
}
