#include <iostream>
#include "tabbporo.h"

using namespace std;

int main() {
	TABBPoro a;

	TPoro p8(1,2,8,(char *) "rojo");
	TPoro p3(1,2,3,(char *) "rojo");
	TPoro p10(1,2,10,(char *) "rojo");
	TPoro p1(1,2,1,(char *) "rojo");
	TPoro p6(1,2,6,(char *) "rojo");
	TPoro p14(1,2,14,(char *) "rojo");
	TPoro p4(1,2,4,(char *) "rojo");
	TPoro p7(1,2,7,(char *) "rojo");
	TPoro p13(1,2,13,(char *) "rojo");

	a.Insertar(p8);
	a.Insertar(p3);
	a.Insertar(p10);
	a.Insertar(p1);
	a.Insertar(p6);
	a.Insertar(p14);
	a.Insertar(p4);
	a.Insertar(p7);
	a.Insertar(p13);

	cout << a.Preorden() << endl;

	cout << a.Niveles() << endl;

	cout << a.Preorden() << endl;
}