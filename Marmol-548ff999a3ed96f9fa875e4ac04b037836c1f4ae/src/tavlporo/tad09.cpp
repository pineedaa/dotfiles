/************************************************************
** ESVACIO, BORRAR EN UN ARBOL DE 1 ELEMENTO
*************************************************************/
#include <iostream>
#include "tavlporo.h"

using namespace std;


int
main()
{
  TAVLPoro arb1;
  TVectorPoro vec;

  TPoro p1(1,2,1,(char *) "rojo");
 
  if (arb1.EsVacio())
	cout<<"Arbol vacio"<<endl;
  else cout<<"Arbol no vacio"<<endl;
 
  if (arb1.Borrar(p1))
  	cout<<"Elemento borrado"<<endl;
  else cout<<"Elemento no borrado"<<endl;

  arb1.Insertar(p1);
 
  if (arb1.EsVacio())
	cout<<"Arbol vacio"<<endl;
  else cout<<"Arbol no vacio"<<endl;

  if (arb1.Borrar(p1))
  	cout<<"Elemento borrado"<<endl;
  else cout<<"Elemento no borrado"<<endl;
    
  if (arb1.EsVacio())
	cout<<"Arbol vacio"<<endl;
  else cout<<"Arbol no vacio"<<endl;

  return 0; 
}
