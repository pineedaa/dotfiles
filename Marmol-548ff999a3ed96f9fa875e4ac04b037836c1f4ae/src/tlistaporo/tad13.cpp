#include <iostream>

using namespace std;

#include "tlistaporo.h"

int
main(void)
{
  TPoro p(1, 1, 1, (char*)"rojo"), q(2, 2, 2, (char*)"verde"), r(3, 3, 3, (char*)"amarillo");
  TListaPoro a;

  a.Insertar(p); a.Insertar(q); a.Insertar(r);
  TListaPoro b(a);

  if(a == b) {
    cout << "CONSTRUCTOR DE COPIA CORRECTO" << endl;
  }
  else {
    cout << "FALLO EN CONSTRUCTOR DE COPIA" << endl;
  }

  TListaPoro c;
  c = a;

  if(a == c) {
    cout << "OPERADOR DE ASIGNACION CORRECTO" << endl;
  }
  else {
    cout << "FALLO EN OPERADOR DE ASIGNACION" << endl;
  }
  
  cout << a << endl;
  a.Borrar(q);
  cout << a << endl;

  a.~TListaPoro();
  b.~TListaPoro();
  c.~TListaPoro();

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
}
