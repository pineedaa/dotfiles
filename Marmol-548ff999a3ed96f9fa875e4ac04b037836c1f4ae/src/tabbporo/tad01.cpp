#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/*******************************************************************/
/***************** CONSTR. COPIA , "=" ; posible copia de punteros */
/*******************************************************************/
  
  TABBPoro a;

  TPoro p1(1,2,1,(char *) "rojo");
  TPoro p2(1,2,2,(char *) "verde");

  a.Insertar(p1);

  TABBPoro b(a), c;
  c=b;

  a.Insertar(p2);
  if( a.Inorden() == b.Inorden() )
        cout << "MAL! SE HAN COPIADO PUNTEROS" << endl;
  else
	cout << "CORRECTO CONSTRUCTOR DE COPIA" << endl;


  b.Insertar(p2);
  if( b.Inorden() == c.Inorden() )
        cout << "MAL! SE HAN COPIADO PUNTEROS" << endl;
  else
	cout << "CORRECTA ASIGNACION" << endl;

  return 1;
}
