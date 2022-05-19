/************************************************************
** BORRAR CON ROTACION IDº
*************************************************************/
#include <iostream>
#include "tavlporo.h"

using namespace std;

int
main()
{
  TAVLPoro arb1, arb2;
  TVectorPoro vec, vec2;

  TPoro p1(1,2,20,(char *) "rojo");
  TPoro p2(1,2,7,(char *) "rojo");
  TPoro p3(1,2,40,(char *) "rojo");
  TPoro p4(1,2,1,(char *) "rojo");
  TPoro p5(1,2,35,(char *) "rojo");
  TPoro p6(1,2,50,(char *) "rojo");
  TPoro p7(1,2,25,(char *) "rojo");
  TPoro p8(1,2,37,(char *) "rojo");

  arb1.Insertar(p1);
  arb1.Insertar(p2);
  arb1.Insertar(p3);
  arb1.Insertar(p4);
  arb1.Insertar(p5);
  arb1.Insertar(p6);
  arb1.Insertar(p7);
  arb1.Insertar(p8);

 cout<<arb1.Preorden()<<endl;



 if (arb1.Borrar(p4))
  	cout<<"Elemento borrado"<<endl;
 else cout<<"Elemento no borrado"<<endl;
 
 /*if (arb1.Borrar(p6))
  	cout<<"Elemento borrado"<<endl;
  else cout<<"Elemento no borrado"<<endl;*/
 
 cout<<arb1.Raiz()<<endl;
 cout<<arb1.Preorden()<<endl;
 cout<<arb1.Inorden()<<endl;
 cout<<arb1.Postorden()<<endl;
  
  return 0;
}
