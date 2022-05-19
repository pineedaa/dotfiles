#include <iostream>
using namespace std;
#include "tporo.h"

/* salida de TPoro vacio  */

int
main(void)
{
  TPoro a;
  TPoro b(0, 0, 0, NULL);

  cout << a << endl;
  cout << b << endl;
}
