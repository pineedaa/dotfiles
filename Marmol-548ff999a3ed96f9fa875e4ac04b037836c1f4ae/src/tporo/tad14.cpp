#include <iostream>

using namespace std;

#include "tporo.h"

int
main(void)
{
  TPoro a(4, 5, 6, (char*)"amarillo");

if(a.Volumen()==6) cout<<"Bien"<<endl;
if(strcmp(a.Color(),(char*)"amarillo")==0) cout<<"Bien"<<endl;
if(a.PosicionY()==5) cout<<"Bien"<<endl;
if(a.PosicionX()==4) cout<<"Bien"<<endl;

}
