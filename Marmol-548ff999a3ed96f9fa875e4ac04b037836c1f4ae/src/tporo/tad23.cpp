#include <iostream>
using namespace std;
#include "tporo.h"

/*CHEQUEO TRADUCCION DEL COLOR*/
int
main(void)
{
  TPoro a(2, 2, 20,(char*)"rojo");
  TPoro b(2, 2, 20,(char*)"RoJo");

 if(a==b)
    cout << "IGUALES" << endl;
  else
    cout << "DISTINTOS" << endl;

}
