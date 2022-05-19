/************************************************************
** ALTURA, NODOS, NODOSHOJA CON 1 ELEMENTO
*************************************************************/
#include <iostream>
#include "tavlporo.h"

using namespace std;

int
main(void)
{
  TAVLPoro a;
  TPoro p1(1,2,1,(char *) "rojo");

  a.Insertar(p1);

  cout << "Altura: " << a.Altura() << endl;
  cout << "Nodos: " << a.Nodos() << endl;
  cout << "NodosHoja: " << a.NodosHoja() << endl;
 return 0;
}
