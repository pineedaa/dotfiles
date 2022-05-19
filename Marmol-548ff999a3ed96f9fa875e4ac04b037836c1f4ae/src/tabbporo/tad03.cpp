#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/*******************************************************************/
/***************** EsVacio() ; 					   */
/*******************************************************************/
  
  TABBPoro a ;

  if( a.EsVacio() )
        cout << "VACIO" << endl;
  else
	cout << "INCORRECTO EsVacio()" << endl;

  TPoro p1(1,2,1,(char *) "rojo");

  a.Insertar(p1);
  if( a.EsVacio() )
        cout << "INCORRECTO EsVacio()" << endl;
  else
	cout << "NO VACIO" << endl;

  a.Borrar(p1);
  if( a.EsVacio() )
        cout << "VACIO" << endl;
  else
	cout << "INCORRECTO Borrar()" << endl;


  return 1;
}
