#include <iostream>

using namespace std;

#include "tlistaporo.h"

int main(void)
{
	bool pruebas[11];
	for(int i = 0; i < 11; i++)
		pruebas[i] = false;
	TPoro p(1, 3, 0, (char*)"p");
	TPoro q(1, 4, 1, (char*)"q");
	TPoro r(1, 7, 4, (char*)"r");
	TPoro s(1, 6, 2, (char*)"s");
  	TListaPoro a, b, c, d, e, f, g;
  	TListaPoro b_sol, c_sol, d_sol, e_sol, f_sol, g_sol;

  	if(a.Longitud() == 0)
  	{
  		cout << "longitud 0 bien" << endl;
  		pruebas[0] = true;
  	}
  	else
  		cout << "longitud 0 mal" << endl;
  	a.Insertar(p);
  	if(a.Longitud() == 1)
  	{
  		cout << "longitud 1 bien" << endl;
  		pruebas[1] = true;
  	}
  	else
  		cout << "longitud 1 mal" << endl;
  	a.Insertar(q);
  	if(a.Longitud() == 2)
  	{
  		cout << "longitud 2 bien" << endl;
  		pruebas[2] = true;
  	}
  	else
  		cout << "longitud 2 mal" << endl;
  	a.Insertar(r);
  	if(a.Longitud() == 3)
  	{
  		cout << "longitud 3 bien" << endl;
  		pruebas[3] = true;
  	}
  	else
  		cout << "longitud 3 mal" << endl;
  	a.Insertar(s);
  	if(a.Longitud() == 4)
  	{
  		cout << "longitud 4 bien" << endl;
  		pruebas[4] = true;
  	}
  	else
  		cout << "longitud 4 mal" << endl;

    TListaPoro a_b;
  	b = a.ExtraerRango(1,2);
  	b_sol.Insertar(p);
  	b_sol.Insertar(q);
  	a_b.Insertar(r);
  	a_b.Insertar(s);
  	if(b == b_sol && a == a_b)
  	{
  		cout << "prueba b bien" << endl;
  		pruebas[5] = true;
  	}
  	else
  		cout << "prueba b mal" << endl;

    TListaPoro w;
  	w.Insertar(p);
  	w.Insertar(q);
  	w.Insertar(r);
  	w.Insertar(s);
  	TListaPoro z;
  	c_sol = w;
  	c = w.ExtraerRango(0, 10);
  	if(w == z && c == c_sol)
  	{
  		cout << "prueba c bien" << endl;
  		pruebas[6] = true;
  	}
  	else
  		cout << "prueba c mal" << endl;

    TListaPoro m;
  	m.Insertar(p);
  	m.Insertar(q);
  	m.Insertar(r);
  	m.Insertar(s);
  	d_sol = m;
  	d = m.ExtraerRango(1,20);
  	if(m == z && d == d_sol)
  	{
  		pruebas[7] = true;
  		cout << "prueba d bien" << endl;
  	}
  	else
  		cout << "prueba d mal" << endl;
  	
  	TListaPoro n;
  	n.Insertar(p);
  	n.Insertar(q);
  	n.Insertar(r);
  	n.Insertar(s);
  	e_sol = n;
  	e = n.ExtraerRango(1,4);
  	if(n == z && e == e_sol)
  	{
  		pruebas[8] = true;
  		cout << "prueba e bien" << endl;
  	}
  	else
  		cout << "prueba e mal" << endl;

  	TListaPoro v;
  	v.Insertar(p);
  	v.Insertar(q);
  	v.Insertar(r);
  	v.Insertar(s);
  	f_sol.Insertar(q);
  	TListaPoro x;
  	x.Insertar(p);
  	x.Insertar(s);
  	x.Insertar(r);
  	f = v.ExtraerRango(2,2);
  	if(v == x && f == f_sol)
  	{
  		pruebas[9] = true;
  		cout << "prueba f bien" << endl;
  	}
  	else
  		cout << "prueba f mal" << endl;
  	

  	TListaPoro h;
  	h.Insertar(p);
  	h.Insertar(q);
  	h.Insertar(r);
  	h.Insertar(s);
  	TListaPoro y;
  	y.Insertar(p);
  	y.Insertar(s);
  	y.Insertar(r);
  	y.Insertar(q);
  	g = h.ExtraerRango(5,2);
  	if(h == y && g == g_sol)
  	{
  		pruebas[10] = true;
  		cout << "prueba g bien" << endl;
  	}
  	else
  		cout << "prueba g mal" << endl;
  	
  	int cont = 0;
  	for(int i=0;i<11;i++)
  		if(pruebas[i] == true)
  			cont++;

  	cout << endl << endl << endl << endl;
  	cout << "Tienes " << cont << " pruebas bien y "
  		<< 11-cont << " mal" << endl;

}