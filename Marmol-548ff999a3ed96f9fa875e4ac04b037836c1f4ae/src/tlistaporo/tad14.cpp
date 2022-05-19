#include "tlistaporo.h"

int
main(void)
{
  TPoro a(1, 1, 1), b(2, 2, 2), c(3, 3, 3);
  TPoro d(4, 4, 1.5), e(5, 5, 2.5), f(10, 3, 1.5);
  TListaPoro lista, lista2;

  if((lista.Insertar(e)&&lista.Insertar(c)&&lista.Insertar(a)&&lista.Insertar(f)&&lista.Insertar(b)&&lista.Insertar(d)) == true) {
  	cout << lista << endl;
  }

  //No se deberian insertar los siguientes.
  if((lista.Insertar(a)||lista.Insertar(b)||lista.Insertar(c)||lista.Insertar(d)||lista.Insertar(e)||lista.Insertar(f)) == false) {
  	cout << "NO SE PUEDEN INSERTAR REPETIDOS" << endl;
  }

  TPoro x(11, 11, 1.5), y(13, 13, 1);
  lista2.Insertar(x);
  lista2.Insertar(y);
  lista2.Insertar(c);

  cout << lista + lista2 << endl;

  lista2.Insertar(a);
  cout << lista - lista2 << endl;

  cout << lista - lista << endl;
  cout << lista2 - lista2 << endl;

  //EXTRAER RANGOS
  TListaPoro lista3;
  lista3 = lista.ExtraerRango(1, 10);

  if(lista.Longitud() == 0 && lista3.Longitud() == 6) {
  	cout << "BIEN" << endl;
  	cout << lista3 << endl;
  }
  else {
  	cout << "FALLO AL EXTRAER RANGO" << endl;
  }

  TListaPoro lista4;
  lista4 = lista3.ExtraerRango(-5,1);

  if(lista3.Longitud() == 5 && lista4.Longitud() == 1) {
  	cout << "BIEN" << endl;
  	cout << lista4 << endl;
  }
  else {
  	cout << "FALLO AL EXTRAER RANGO" << endl;	
  }
}