#include "DOM_Tree.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;
using std::list;
using std::string;

int main ()
{
DOM_Tree a;
string h;
getline(cin,h);
	//cout<<"es h"<<h<<endl;
a.convertirEnArbol(h);
a.imprimir(5);
  return 0;
}
