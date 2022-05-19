/************************************************************
** INSERTAR, ALTURA, PREORDEN
*************************************************************/
#include <iostream>
#include "tavlporo.h"

using namespace std;

int
main(void)
{
  TAVLPoro a;
 
  TPoro p1(1,2,1,(char *) "rojo");
  TPoro p2(1,2,2,(char *) "rojo");
  TPoro p3(1,2,3,(char *) "rojo");
  TPoro p4(1,2,4,(char *) "rojo");

  a.Insertar(p1);
  a.Insertar(p2);
  a.Insertar(p3);
  if (a.Insertar(p4)) 
	cout<<"Insertado"<<endl;
  else cout<<"No insertado"<<endl; 
  
  if (a.Insertar(p3)) 
	cout<<"Insertado"<<endl;
  else cout<<"No insertado"<<endl;

  cout << "Altura: " << a.Altura() << endl;
  cout << a.Preorden() <<endl;
  return 0;
}
