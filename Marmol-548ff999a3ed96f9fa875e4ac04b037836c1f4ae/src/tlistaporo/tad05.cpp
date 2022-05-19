#include <iostream>

using namespace std;

#include "tlistaporo.h"

int
main(void)
{
  TPoro p(1, 1, 1), q(2, 2, 2), r(3, 3, 3);
  TListaPoro a;

  a.Insertar(p); a.Insertar(q); a.Insertar(r);

  cout << a << endl;
}
