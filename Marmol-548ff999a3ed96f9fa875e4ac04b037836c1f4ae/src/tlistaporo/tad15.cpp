#include <iostream>

using namespace std;

#include "tlistaporo.h"

void tad01(){
  TPoro a, b, c;
  TListaPoro d, e, f;

  cout << "No hace nada" << endl;
}

void tad02(){
  TPoro p(1, 1, 1), q(2, 2, 2), r(3, 3, 3);
  TListaPoro a, b, c;

  cout << a.Longitud() << endl;
  cout << b.Longitud() << endl;
  cout << c.Longitud() << endl;

  a.Insertar(p);
  b.Insertar(p); b.Insertar(q);
  c.Insertar(p); c.Insertar(q); c.Insertar(r);

  cout << a.Longitud() << endl;
  cout << b.Longitud() << endl;
  cout << c.Longitud() << endl;
}

void tad03(){
  TListaPoro a;

  cout << a << endl;
}

void tad04(){
  TPoro p(1, 2, 3);
  TListaPoro a, b;

  if(a == b)
    cout << "SI"  << endl;
  else
    cout << "NO" << endl;

  a.Insertar(p);

  if(a == b)
    cout << "SI"  << endl;
  else
    cout << "NO" << endl;
}

void tad05(){
  TPoro p(1, 1, 1), q(2, 2, 2), r(3, 3, 3);
  TListaPoro a;

  a.Insertar(p); a.Insertar(q); a.Insertar(r);

  cout << a << endl;
}

void tad06(){
  TPoro p(1, 2, 3, (char*)"rojo");
  TListaPoro a, b;

  a.Insertar(p);
  b = a;

  cout << a << endl;
  cout << b << endl;
}

void tad07(){
  TPoro p(1, 2, 3, (char*)"rojo");
  TListaPoro a;

  cout << "Longitud: " << a.Longitud() << endl;

  a.Insertar(p);
  cout << "Longitud: " << a.Longitud() << endl;

  a.Insertar(p);
  cout << "Longitud: " << a.Longitud() << endl;

  a.~TListaPoro();
  cout << "Longitud: " << a.Longitud() << endl;
}

void tad08(){
  TPoro p(1, 2, 3, (char*)"rojo");
  TListaPoro a, b;

  cout << "Longitud: " << a.Longitud() << endl;
  cout << "Longitud: " << b.Longitud() << endl;

  a.Insertar(p);
  b = a;

  cout << "Longitud: " << a.Longitud() << endl;
  cout << "Longitud: " << b.Longitud() << endl;
}

void tad09(){
  TPoro p(1, 1, 1, (char*)"rojo"), q(2, 2, 2, (char*)"verde");
  TListaPoro a;

  a.Insertar(p);
  a.Insertar(q);
  cout << a << endl;

  a.Borrar(p);
  cout << a << endl;

  a.Borrar(q);
  cout << a << endl;
}

void tad10(){
  TPoro p(1, 1, 1, (char*)"rojo"), q(2, 2, 2, (char*)"verde"), r(3, 3, 3, (char*)"amarillo");
  TListaPoro a;

  a.Insertar(p); a.Insertar(q);

  if(a.Buscar(p))
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  if(a.Buscar(q))
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  if(a.Buscar(r))
    cout << "SI" << endl;
  else
    cout << "NO" << endl;
}

void tad11(){
  TPoro p(1, 1, 1, (char*)"rojo"), q(2, 2, 2, (char*)"verde"), r(3, 3, 3, (char*)"amarillo");
  TListaPoro a;
  TListaPosicion pos;

  a.Insertar(p); a.Insertar(q); a.Insertar(r);

  pos = a.Primera();

  while(!pos.EsVacia())
  {
    cout << a.Obtener(pos) << endl;
    pos = pos.Siguiente();
  }
}

void tad12(){
  TPoro p(1, 1, 1, (char*)"rojo"), q(2, 2, 2, (char*)"verde"), r(3, 3, 3, (char*)"amarillo");
  TListaPoro a;
  TListaPosicion pos;

  a.Insertar(p); a.Insertar(q); a.Insertar(r);

  pos = a.Ultima();

  while(!pos.EsVacia())
  {
    cout << a.Obtener(pos) << endl;
    pos = pos.Anterior();
  }
}

void pruebasTad(){
	cout<<"EMPIEZA EL TAD01:\n";
	tad01();
	cout<<"EMPIEZA EL TAD02:\n";
	tad02();
	cout<<"EMPIEZA EL TAD03:\n";
	tad03();
	cout<<"EMPIEZA EL TAD04:\n";
	tad04();	
	cout<<"EMPIEZA EL TAD05:\n";
	tad05();	
	cout<<"EMPIEZA EL TAD06:\n";
	tad06();	
	cout<<"EMPIEZA EL TAD07:\n";
	tad07();	
	cout<<"EMPIEZA EL TAD08:\n";
	tad08();	
	cout<<"EMPIEZA EL TAD09:\n";
	tad09();	
	cout<<"EMPIEZA EL TAD10:\n";
	tad10();
	cout<<"EMPIEZA EL TAD11:\n";
	tad11();
	cout<<"EMPIEZA EL TAD12:\n";
	tad12();
}

void inicializarLista(TListaPoro &lista1, TPoro &a, TPoro &b, TPoro &c, TPoro &d, TPoro &e){
  lista1.Insertar(a);
  lista1.Insertar(b);
  lista1.Insertar(c);
  lista1.Insertar(d);
  lista1.Insertar(d);
  lista1.Insertar(e);
}

void pruebasMias(){

  cout<< endl <<"Empiezan las pruebas de Rai y Larry: " << endl <<endl;

  TPoro a(2, 3, 5), b(3, 5, 6), c(1, 1, 2), d(1, 1, 7), e(5, 5, 2);
  // c - e - a - b - d
  // 2 - 2 - 5 - 6 - 7
  TListaPoro lista1;
  
  inicializarLista(lista1, a, b ,c , d, e);

  cout << "Insertar da resultado:\n" << lista1 << endl;

  lista1.Borrar(c); //borramos el primero de la lista
  lista1.Borrar(a); //borramos uno de en medio de la lista
  lista1.Borrar(d); //borramos el ultimo de la lista

  cout << "Al borrar la lista se queda:\n" << lista1 << endl;

  inicializarLista(lista1, a, b ,c , d, e);

  cout << "Al insertar otra vez los mismos datos tiene que quedarse asi:\n" <<lista1<<endl;

  TListaPoro copia(lista1);

  lista1.Borrar(c);
  lista1.Borrar(a);
  lista1.Borrar(d);

  cout<< "El constructor de copia tiene que dar esta lista:\n" << copia << endl;


  TListaPoro lista2,listaRai;
  inicializarLista(listaRai, a, b ,c , d, e);

  inicializarLista(lista2, a, b ,c , d, e);

  if (!(listaRai == lista2 && lista2 == listaRai)){
    cout << "1ERROR!!!!!!, operador == no funka bien\n";
  }

  lista2.Borrar(a);
  if (listaRai == lista2 && lista2 == listaRai){
    cout << "2ERROR!!!!!!, operador == no funka bien\n";
  }


  inicializarLista(lista1, a, b ,c , d, e);

  TListaPoro copia2 = lista1;

  lista1.Borrar(c);
  lista1.Borrar(a);
  lista1.Borrar(d);

  cout<< "El operador= tiene que dar esta lista:\n" << copia << endl;

  inicializarLista(lista1, a, b ,c , d, e);

  TListaPoro operadorMas,lista3;

  operadorMas = lista1 + lista2;

  cout<< "El operador+ tiene que dar:\n"<< operadorMas << endl;


  TPoro xd(1,2,3);
  lista3.Insertar(xd);

  operadorMas = lista1 + lista3;

  cout<< "El operador+ tambien tiene que dar:\n"<< operadorMas << endl;


  operadorMas = operadorMas - lista1;

  cout<< "El operador- da:\n"<< operadorMas;


  TListaPoro extraer;

  inicializarLista(extraer, a, b ,c , d, e);
  TListaPoro resultado = extraer.ExtraerRango(-1,8);
  cout<<endl<<"Pruebas extraer:\n"<<extraer<<endl;
  cout<<resultado<<endl;
  
  inicializarLista(extraer, a, b ,c , d, e);
  resultado = extraer.ExtraerRango(2, 8);
  cout<<endl<<extraer<<endl;
  cout<<resultado<<endl;

  inicializarLista(extraer, a, b ,c , d, e);
  resultado = extraer.ExtraerRango(0, 4);
  cout<<endl<<extraer<<endl;
  cout<<resultado<<endl;

  inicializarLista(extraer, a, b ,c , d, e);
  resultado = extraer.ExtraerRango(2, 4);
  cout<<endl<<extraer<<endl;
  cout<<resultado<<endl;

  inicializarLista(extraer, a, b ,c , d, e);
  resultado = extraer.ExtraerRango(3, 3);
  cout<<endl<<extraer<<endl;
  cout<<resultado<<endl;
}


int main() {
	
	pruebasTad();

  pruebasMias();
}
