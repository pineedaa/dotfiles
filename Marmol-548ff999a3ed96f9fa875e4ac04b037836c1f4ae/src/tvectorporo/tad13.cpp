#include <iostream>

using namespace std;

#include "tporo.h"
#include "tvectorporo.h"

int
main(void)
{
  TPoro a(1, 2, 3, (char*)"rojo");
  TPoro c(0,3,4,(char*)"rojo");
  TVectorPoro v(5);
  TVectorPoro b(5);
v[1]=a;
v[2]=a;
v[3]=a;
v[4]=a;
v[5]=a;
b[1]=c;
b[2]=c;
b[3]=c;
b[4]=c;
b[5]=c;
if(v!=b) cout<<"Bien"<<endl;
}
