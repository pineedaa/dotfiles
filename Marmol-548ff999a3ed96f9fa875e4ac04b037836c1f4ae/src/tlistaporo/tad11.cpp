#include <iostream>

using namespace std;

#include "tlistaporo.h"

int
main(void)
{
  TPoro p(1, 1, 1, (char*)"rojo"), q(2, 2, 2, (char*)"verde"), r(3, 3, 3, (char*)"amarillo");
  TListaPoro a;
  TListaPosicion pos;

  a.Insertar(p); a.Insertar(q); a.Insertar(r);

  pos = a.Primera();

  while(!pos.EsVacia())
  {
    cout << a.Obtener(pos) << endl;
    pos = pos.Siguiente();
  }
}
