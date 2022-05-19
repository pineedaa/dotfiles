#include <iostream>

using namespace std;

#include "tporo.h"
#include "tvectorporo.h"

int
main(void)
{
  TPoro a(1, 2, 3, (char*)"rojo");
  TVectorPoro v(5);
  TVectorPoro b;
v[1]=a;
v[2]=a;
v[3]=a;
v[4]=a;
v[5]=a;
cout<<v<<endl;
cout<<b<<endl;
b=v;
cout<<v<<endl;
cout<<b<<endl;

}
