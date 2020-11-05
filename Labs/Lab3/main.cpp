#include <iostream>
#include "ListADT.h"
#include "arrayList.h"


using namespace std;

int main(){
  
  List *a = new arrayList();
  a->push_back(19);
  a->push_back(10);
  a->push_back(9);

  cout << a->size() << " " << a->at(0) << endl;

  delete a;
  
  return 0;
}
