#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/*******************************************************************/
/***************** INSERCION MULTIPLE; posible desborde de memoria */
/*******************************************************************/
  
TABBPoro a;

for(int i=1; i<=2; i++)
//for(int i=1; i<=100; i++)
{
  for( int num=1; num<=5; num++)
//  for( int num=1; num<=1000; num++)
  {
  	TPoro p1(1,2,(double) num,(char *) "rojo");
  	if(!a.Insertar(p1))
		cout << "Error NO INSERCION" << endl;
	p1.~TPoro();
  }
  a.~TABBPoro();
}

cout << "CORRECTA INSERCION MULTIPLE" << endl;

return 1;
}
