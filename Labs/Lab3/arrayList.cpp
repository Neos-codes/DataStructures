#include "arrayList.h"
#include <iostream>
using namespace std;

arrayList::arrayList(){
  start = new int[100];
  max = 100;
  top = 0;
}

void arrayList::push_back(int num){
  if(top < max){
    start[top] = num;
    top++;
  }
  else{

    int *aux = new int[2*max];

    max *= 2;
    
    for(int i = 0; i < top; i++)
      aux[i] = start[i];

    delete start;

    start = aux;
    start[top] = num;
    top++;
  }
};

int arrayList::at(int num){
  if(num < top)
  return start[num];

  else{
    cout << "No existe esa posicion\n";
    return -1;
  }
};

int arrayList::size(){
  return top;
};
