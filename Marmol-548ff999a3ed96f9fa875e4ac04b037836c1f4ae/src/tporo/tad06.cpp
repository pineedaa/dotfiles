#include <iostream>

using namespace std;

#include "tporo.h"

int
main(void)
{
  TPoro a(1, 2, 3, (char*)"rojo");

  cout << "PosicionX: " << a.PosicionX() << endl;
  cout << "PosicionY: " << a.PosicionY() << endl;
  cout << "Volumen: " << a.Volumen() << endl;
}
