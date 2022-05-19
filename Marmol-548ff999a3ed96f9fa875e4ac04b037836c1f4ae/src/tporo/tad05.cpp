#include <iostream>

using namespace std;

#include "tporo.h"

int
main(void)
{
  TPoro a(1, 2, 3, (char*)"rojo");
  TPoro b;

  b = a;

  cout << a << endl;
  cout << b << endl;
}
