#include <iostream>

using namespace std;

#include "tlistaporo.h"

int
main(void)
{
  TPoro p(1, 2, 3);
  TListaPoro a, b;

  if(a == b)
    cout << "SI"  << endl;
  else
    cout << "NO" << endl;

  a.Insertar(p);

  if(a == b)
    cout << "SI"  << endl;
  else
    cout << "NO" << endl;
}
