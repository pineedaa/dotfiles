/************************************************************
** INORDEN, PREORDEN Y POSTORDEN
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

  TVectorPoro v;

  a.Insertar(p4);
  a.Insertar(p3);
  a.Insertar(p2);
  a.Insertar(p1);

  v = a.Inorden();
  cout << "Inorden: " << v << endl;

  v = a.Preorden();
  cout << "Preorden: " << v << endl;

  v = a.Postorden();
  cout << "Postorden: " << v << endl;
  return 0;
}
