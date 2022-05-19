#include <iostream>

using namespace std;

#include "tporo.h"

int
main(void)
{
  TPoro a, b(0, 0, 0, NULL);
  TPoro c(a), d(b);

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  if(b.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  if(c.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  if(d.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;
}
