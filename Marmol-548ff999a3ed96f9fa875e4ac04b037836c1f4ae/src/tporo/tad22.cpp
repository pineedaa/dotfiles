#include <iostream>
using namespace std;
#include "tporo.h"

/*CONSTR. POS+VOL ; CONSTR. POS+VOL+COLOR ; */

int
main(void)
{
  TPoro a(2, 2, 20);
  TPoro b(2, 2, 20, NULL);

  cout << a << endl;
  cout << b << endl;
}
