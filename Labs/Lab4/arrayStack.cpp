#include "arrayStack.h"
#include <iostream>

using namespace std;

arrayStack::arrayStack(){
  start = new int [10000000];
  max = 10000000;
  top = 0;
}

void arrayStack::push(int num){
  if(top < max){
    start[top] = num;
    // cout << "array push: " << start[top] << endl;
    top++;
  }
  else
    cout << "Error: Stack lleno\n";

}

int arrayStack::pop(){
  if(top != 0){
    //    cout << "array pop :" << start[top-1] << endl;
    top--;
    return start[top];
  }
  else
    cout << "El Stack esta vacio\n";
  return -1;
}

bool arrayStack::isEmpty(){
  if(top != 0)
    return false;
  else
    return true;
}
