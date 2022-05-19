#include <iostream>
using namespace std;
#include "tporo.h"

/*CHEQUEO DE POSICION,VOLUMEN,COLOR*/

int
main(void)
{
//  TPoro a(1,1,0,NULL);
TPoro a(2,2,20,(char*)"azul");
  TPoro b(2,2,20,(char*)"azul");

  //a.Posicion(2,2);
  //a.Volumen(20);
  //a.Color((char*)"Azul");

  if(a!=b)
    cout << "DISTINTOS" << endl;
  else
    cout << "IGUALES" << endl;
}
