#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/***************************************************/
/***************** SUMA,NIVELES 	           */
/***************************************************/
  TABBPoro a,b, suma;
  TVectorPoro vec;

  TPoro p1(1,2,1,(char *) "rojo");
  TPoro p2(1,2,2,(char *) "rojo");
  TPoro p3(1,2,3,(char *) "rojo");

  TPoro p4(1,2,4,(char *) "rojo");
  TPoro p5(1,2,5,(char *) "rojo");

  a.Insertar(p2);
  a.Insertar(p1);
  a.Insertar(p3);

  b.Insertar(p4);
  b.Insertar(p5);

  suma = a+b;

  vec = suma.Niveles();

  cout <<"Niveles Suma: "<< vec << endl;

  return 1; 

}
