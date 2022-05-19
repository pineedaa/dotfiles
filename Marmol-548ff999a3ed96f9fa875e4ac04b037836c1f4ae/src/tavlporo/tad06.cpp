/************************************************************
** ALTURA, NODOS, NODOSHOJA, =, != 
*************************************************************/
#include <iostream>
#include "tavlporo.h"

using namespace std;

int
main()
{
  TAVLPoro arb1, arb2;

  TPoro bd(1,1,1,(char *)"rojo");
  TPoro bc(2,2,2,(char *)"rojo");
  TPoro be(3,3,3,(char *)"rojo");
  TPoro bn(4,4,4,(char *)"rojo");
  TPoro ba(5,5,5,(char *)"rojo");
  TPoro bm(6,6,6,(char *)"rojo");

  arb1.Insertar(ba);
  arb1.Insertar(bc);
  arb1.Insertar(bd);
  arb1.Insertar(be);
  arb1.Insertar(bm);
  

  arb2 = arb1;
  if(arb2 != arb1)
    cout << "No iguales" <<endl;
  else
    cout << "Iguales" << endl;

  cout << "Altura: " << arb2.Altura() << endl;
  cout << "Nodos: " << arb2.Nodos() << endl;
  cout << "NodosHoja: " << arb2.NodosHoja() << endl;

  return 0;
}
