#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/************************************************/
/***************** INORDEN, PREORDEN, POSTORDEN */
/************************************************/

	TABBPoro a;
      TVectorPoro vec1, vec2, vec3;

  	TPoro p1(1,2,1,(char *) "rojo");
  	TPoro p2(1,2,2,(char *) "rojo");
  	TPoro p3(1,2,3,(char *) "rojo");
  	TPoro p4(1,2,4,(char *) "rojo");
  	TPoro p5(1,2,5,(char *) "rojo");
  	TPoro p6(1,2,6,(char *) "rojo");


	a.Insertar(p5);
	a.Insertar(p2);
	a.Insertar(p1);
	a.Insertar(p3);
	a.Insertar(p6);

	vec1 = a.Inorden();
	vec2 = a.Preorden();
	vec3 = a.Postorden();

	cout << "Inorden: " << vec1 << endl;
	cout << "Preorden: " << vec2 << endl;
	cout << "Postorden: " << vec3 << endl;

  return 1; 
}
