#include <iostream>

using namespace std;

#include "tlistaporo.h"

int
main(void)
{
  TPoro p(1, 2, 3, (char*)"rojo");
  TListaPoro a, b;

  a.Insertar(p);
  b = a;

  cout << a << endl;
  cout << b << endl;
}
