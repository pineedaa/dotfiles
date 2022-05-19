#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/*******************************************************************/
/***************** Insertar(), Borrar() */
/*******************************************************************/
  
  TABBPoro a, b, c, d;


  TPoro p1(1,2,1,(char *) "rojo");
  TPoro p2(1,2,2,(char *) "rojo");
  TPoro p3(1,2,3,(char *) "rojo");
  TPoro p4(1,2,4,(char *) "rojo");
  TPoro p5(1,2,5,(char *) "rojo");
  TPoro p6(1,2,6,(char *) "rojo");
  TPoro p7(1,2,7,(char *) "rojo");

  a.Insertar(p5);
  a.Insertar(p2);

  b.Insertar(p1);
  b.Insertar(p3);

  a.Insertar(p6);
  a.Insertar(p7);

  cout << a.Inorden() << endl;

  cout << a.Niveles() << endl;
  cout << a << endl;

  c = a + b;      //c = 1,2,3,5,6,7

  cout << c.Niveles() << endl;

  d = c - a;      //d = 1,3


  if(d == b)
    cout << d.Inorden() << endl;

  c = a - a;      //c se queda vacío

  cout << c.Inorden() << endl;

  a = a - c;      //a se queda como está

  cout << a.Inorden() << endl;

  a = c - a;      //a se queda como está

  cout << a.Inorden() << endl;

  return 1;
}
