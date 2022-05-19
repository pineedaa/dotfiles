/************************************************************
** CONSTRUCTOR COPIA, =
*************************************************************/
#include <iostream>
#include "tavlporo.h"

using namespace std;

int
main(void)
{
  TAVLPoro a,b;

  TPoro p1(1,2,1,(char *) "rojo");
  TPoro p2(1,2,2,(char *) "rojo");
  TPoro p3(1,2,3,(char *) "rojo");
  TPoro p4(1,2,4,(char *) "rojo");
  TPoro p5(1,2,5,(char *) "rojo");

  a.Insertar(p1);
  a.Insertar(p2);
  a.Insertar(p3);
  a.Insertar(p4);

  TAVLPoro c(a);
  
  b.Insertar(p1);
  b.Insertar(p2);
  b.Insertar(p3);
  b.Insertar(p4);

  if ( a==c )
  	cout << "IGUALES" << endl;
  else 
	cout << "DISTINTOS" << endl;

  if ( c==b )
  	cout << "IGUALES" << endl;
  else 
	cout << "DISTINTOS" << endl;

  b = a;
  cout << b.Preorden() <<endl;
  a.Insertar(p5);
  if ( a==b )
  	cout << "IGUALES" << endl;
  else 
	cout << "DISTINTOS" << endl;

  cout << "Altura: " << b.Altura() << endl;
  cout << b.Preorden() <<endl;
 return 0;
}
