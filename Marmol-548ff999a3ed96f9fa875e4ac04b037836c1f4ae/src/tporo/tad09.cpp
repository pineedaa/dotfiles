#include <iostream>

using namespace std;

#include "tporo.h"

int
main(void)
{
  TPoro a;

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  a.Color((char*)"rojo");

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  a.~TPoro();

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;
}
