#include <bits/stdc++.h>
#include "arrayStack.h"
#include "linkedStack.h"

using namespace std;

int main(){
  int n;
  srand(time(NULL));
  Stack *as = new arrayStack();
  Stack *ls = new linkedStack();
  
  cout<<"Cantidad de numeros a insertar"<<endl;
  cin>>n;
  clock_t t1 = clock();
  for(int i = 0; i<n; i++){
    as -> push(rand()%100);
  }
  clock_t t2 = clock();
  double tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
  cout<<"Insercion ArrayStack: "<<tiempo<<endl;

  t1 = clock();
  for(int i = 0; i<n; i++){
    ls -> push(rand()%100);
  }
  t2 = clock();
  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
  cout<<"Insercion LinkedtStack: "<<tiempo<<endl;

  t1 = clock();
  while(!as -> isEmpty()){
    as -> pop();
  }
  t2 = clock();
  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
  cout<<"Pop ArrayStack: "<<tiempo<<endl;

  t1 = clock();
  while(!ls -> isEmpty()){
    ls -> pop();
  }
  t2 = clock();
  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
  cout<<"Pop ListStack: "<<tiempo<<endl;

  return 0;
}
