#include <iostream>
using namespace std;
#include "tporo.h"

/*"TPoro(1,1,3,"rojo");cout << a << endl;" : debe sacar el Volumen como "... 3.00 ..."*/
/*"cout  << a.Volumen() << endl; " : debe sacar el Volumen como "3"*/

int
main(void)
{
  TPoro a(-10,-20,3,NULL);

  cout << "PosicionX: " << a.PosicionX() << endl;
  cout << "PosicionY: " << a.PosicionY() << endl;
  cout << "Volumen: " << a.Volumen() << endl;
  cout << a << endl;
}
