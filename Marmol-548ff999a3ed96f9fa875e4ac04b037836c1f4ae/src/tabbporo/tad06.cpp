#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/************************************************************************/
/***************** INSERCION MULTIPLE (2) ; posible desborde de memoria */
/************************************************************************/
  
TABBPoro a;

for(int i=1; i<=100; i++)
{
  int num;
  for(num=1; num<=10; num++)
//  for(num=1; num<=1000; num++)
  {
  	TPoro p1(1,2,(double) num,(char *) "rojo");
  	if(!a.Insertar(p1))
		cout << "Error NO INSERCION" << endl;
	p1.~TPoro();
  }
  for(num=1; num<=10; num++)
//  for(num=1; num<=1000; num++)
  {
  	TPoro p1(1,2,(double) num,(char *) "rojo");
  	if(!a.Borrar(p1))
		cout << "Error NO BORRADO" << endl;
	p1.~TPoro();
  }
}

cout << "CORRECTA INSERCION MULTIPLE" << endl;

return 1;
}
