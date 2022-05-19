#include <iostream>
using namespace std;
#include "tporo.h"

/*CONSTRUCTOR DEF. / CONSTRUCTOR COPIA*/
int
main(void)
{
  TPoro a, b ;
  TPoro c(a), d(b) ;
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  cout << d << endl;

}
