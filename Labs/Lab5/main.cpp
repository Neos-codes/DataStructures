#include <iostream>
#include "stackqueue.h"

using namespace std;

int main(){
  /*  
  q -> push(1);
  q -> push(2);
  q -> push(3);
  q -> push(4);
  q -> push(5);
  q -> push(6);
  q -> push(7);
  q -> push(8);
  
  for(int i = 0; i < 9; i++){
    it.nextInt();
  }
  */
  
  int n;
  
  srand(time(NULL));
  
  Queue *q = new stackqueue();
  StackIt it((stackqueue *)q);

  cout<<"Cantidad de numeros a insertar"<<endl;
  
  cin>>n;
  
  clock_t t1 = clock();

  for(int i = 0; i<n; i++){
    q -> push(rand()%100);
  }
  
  clock_t t2 = clock();
  double tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
  cout<<"Push Queuestack: "<<tiempo<<endl;

  t1 = clock();
  q -> front();
  t2 = clock();
  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
  cout<<"Front Queuestack: "<<tiempo<<endl;


  t1 = clock();
  it.nextInt();
  t2 = clock();
  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
  cout<<"Iterador NextInt Queuestack: "<<tiempo<<endl;


  t1 = clock();
  for(int i=0;i<n;++i){
    q -> pop();
  }
  t2 = clock();
  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
  cout<<"Pop Queuestack: "<<tiempo<<endl;

  //cout<<q -> isEmpty()<<endl;

  
  return 0;
}
