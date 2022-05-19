#include <iostream>

using namespace std;

#include "tporo.h"
#include "tvectorporo.h"

int
main(void)
{
  TPoro a(1, 2, 3, (char*)"rojo");

  TVectorPoro v(5);
v[1]=a;

cout<<v[1];

}
