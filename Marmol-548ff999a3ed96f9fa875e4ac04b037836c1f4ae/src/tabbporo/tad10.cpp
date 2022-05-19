#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/**********************************************/
/***************** Buscar()               */
/**********************************************/
  
  TABBPoro a;

  TPoro p1(1,2,1,(char *) "rojo");
  TPoro p2(1,2,2,(char *) "rojo");
  TPoro p3(1,2,3,(char *) "rojo");
  TPoro p4(1,2,4,(char *) "rojo");
  TPoro p5(1,2,5,(char *) "rojo");
  TPoro p6(1,2,6,(char *) "rojo");
  TPoro p7(1,2,7,(char *) "rojo");

  a.Insertar(p5);
  a.Insertar(p2);
  a.Insertar(p1);
  a.Insertar(p3);
  a.Insertar(p6);

  bool busc = a.Buscar(p7);
  cout <<"Encontrado = "<<busc<<endl;
  bool ins = a.Insertar(p7);
  cout <<"Insertado = "<<ins<<endl;
  busc = a.Buscar(p7);
  cout <<"Encontrado = "<<busc<<endl;


  bool busc2 = a.Buscar(p1);
  cout <<"Encontrado = "<<busc2<<endl;
  bool ins2 = a.Insertar(p1);
  cout <<"Insertado = "<<ins2<<endl;
  bool bor2 = a.Borrar(p1);
  cout <<"Borrado = "<<bor2<<endl;
  busc2 = a.Buscar(p1);
  cout <<"Encontrado = "<<busc2<<endl;

  return 1; 
}
