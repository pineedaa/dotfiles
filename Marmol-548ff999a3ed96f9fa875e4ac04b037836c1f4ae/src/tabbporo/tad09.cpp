#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/***************************************/
/***************** BORRADO CON 2 HIJOS */
/***************************************/
  
  TABBPoro a;

  TPoro p1(1,2,20,(char *) "rojo");
  TPoro p2(1,2,10,(char *) "rojo");
  TPoro p3(1,2,24,(char *) "rojo");
  TPoro p4(1,2,8,(char *) "rojo");
  TPoro p5(1,2,12,(char *) "rojo");
  TPoro p6(1,2,26,(char *) "rojo");
  TPoro p7(1,2,28,(char *) "rojo");
  TPoro p8(1,2,11,(char *) "rojo");

  a.Insertar(p1);
  a.Insertar(p2);
  a.Insertar(p3);
  a.Insertar(p4);
  a.Insertar(p5);
  a.Insertar(p6);
  a.Insertar(p7);

  //cout << a.Inorden() << endl;

  if(!a.Borrar(p1))
  	cout << "Error NO BORRADO" << endl;

  if(!a.Borrar(p5))
  	cout << "Error NO BORRADO" << endl;

  if(!a.Borrar(p8))
  	cout << "Error NO BORRADO" << endl;

  if(!a.Borrar(p2))
  	cout << "Error NO BORRADO" << endl;

  if(!a.Borrar(p4))
  	cout << "Error NO BORRADO" << endl;

  cout << a.Inorden() << endl;
  
  return 1;
}
