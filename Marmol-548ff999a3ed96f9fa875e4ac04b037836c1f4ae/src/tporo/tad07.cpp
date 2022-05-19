#include <iostream>

using namespace std;

#include "tporo.h"

int
main(void)
{
  TPoro a(1, 2, 3, (char*)"rojo");

  if(a.PosicionX() == 1)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  if(a.PosicionY() == 2)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;
}
