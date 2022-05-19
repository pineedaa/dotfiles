#include <iostream>

using namespace std;

#include "tlistaporo.h"

int
main(void)
{
  TPoro p(1, 2, 3, (char*)"rojo");
  TListaPoro a, b;

  cout << "Longitud: " << a.Longitud() << endl;
  cout << "Longitud: " << b.Longitud() << endl;

  a.Insertar(p);
  b = a;

  cout << "Longitud: " << a.Longitud() << endl;
  cout << "Longitud: " << b.Longitud() << endl;
}
