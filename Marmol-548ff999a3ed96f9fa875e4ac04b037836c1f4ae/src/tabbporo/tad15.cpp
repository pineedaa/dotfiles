#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/****************************************************/
/***************** CONSTRUCTOR DE COPIA, "=", "==" */
/***************************************************/
  TABBPoro a,c;

  TPoro p1(1,2,3,(char *) "rojo");
  a.Insertar(p1);

  TABBPoro b(a);
  c=b;

  if ( a==b )
  	cout << "IGUALES" << endl;
  else 
	cout << "DISTINTOS" << endl;

  if ( c==b )
  	cout << "IGUALES" << endl;
  else 
	cout << "DISTINTOS" << endl;

  return 1;
}
