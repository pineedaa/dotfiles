/************************************************************
** CONSTRUCTORES, = CON ARBOLES VACIOS
*************************************************************/
#include <iostream>
#include "tavlporo.h"

using namespace std;

int
main(void)
{
  TAVLPoro a,c;
  TAVLPoro b(a);

  c=b;
  
  cout << "No hace nada" << endl;
  return 0;
}
