#include <iostream>

using namespace std;

#include "tporo.h"
#include "tvectorporo.h"

int
main(void)
{
	TPoro a(1, 2, 3, (char*)"rojo");
	TVectorPoro v;

	cout << v << endl;
	if(v.Longitud()==0) cout<<"Bien"<<endl;

	v.Redimensionar(3);

	cout << v << endl;
	if(v.Longitud()==3) cout<<"Bien"<<endl;
}
