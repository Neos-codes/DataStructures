#include <iostream>
#include <ctime>
#include "mapb.h"
#include "mapg.h"
#include "mapDH.h"


int main(){

  int n;
  map *b = new mapb();
  map *g = new mapg();
  map *dh = new mapDH();
  string aux;

  srand(time(NULL));

  clock_t t1 = clock();
  clock_t t2 = clock();

  cout<<"Ingrese la cantidad de elementos a generar\n";

  cin >> n;
  t1 = clock();
  t2 = clock();

  for(int i = 0; i<n; i++){
    for(int j = 0; j<8; j++){
      aux.push_back('A'+rand()%25);
      //cout << 'A'+rand()%25 << endl;
    }
    b->insert(make_pair(aux,rand()%100));
    aux.clear();
  }
  t2 = clock();
  double tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
  cout << "Tiempo insercion mapb: " << tiempo << endl;


  t1 = clock();
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 8; j++){
      aux.push_back('A'+rand()%25);
      //cout << 'A'+rand()%25 << endl;
    }
    g->insert(make_pair(aux,rand()%100));
    aux.clear();
  }
  t2 = clock();

  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
  cout<< "Tiempo insercion mapg: " << tiempo << endl;

  t1 = clock();
  for(int i = 0; i<n; i++){
    for(int j = 0; j < 8; j++){
      aux.push_back('A'+rand()%25);
      //cout << 'A'+rand()%25 << endl;
    }
    dh->insert(make_pair(aux,rand()%100));
    aux.clear();
  }
  t2 = clock();

  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
  cout << "Tiempo insercion mapDH: " << tiempo << endl;
  
  t1 = clock();
  for(int j = 0; j < 8; j++){
    aux.push_back('A'+rand()%25);
    //cout << 'A'+rand()%25 << endl;
  }
  b->at(aux);
  aux.clear();
  t2 = clock();

  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;

  cout << "Tiempo at mapb: " << tiempo <<endl;
  
  t1 = clock();
  for(int j = 0; j < 8; j++){
    aux.push_back('A'+rand()%25);
    //cout << 'A'+rand()%25 << endl;
  }
  g->at(aux);
  aux.clear();
  t2 = clock();
  
  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
  
  cout << "Tiempo at mapg: " << tiempo <<endl;
  
  t1 = clock();
  for(int j = 0; j < 8; j++){
    aux.push_back('A'+rand()%25);
    //cout << 'A'+rand()%25 << endl;
  }
  dh->at(aux);
  aux.clear();
  t2 = clock();
  
  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;

  cout << "Tiempo at mapDH: " << tiempo <<endl;

  t1 = clock();
  for(int j = 0; j < 8; j++){
    aux.push_back('A'+rand()%25);
    //cout << 'A'+rand()%25 << endl;
  }
  b->erase(aux);
  aux.clear();
  t2 = clock();

  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;
  
  cout << "Tiempo erase mapb: " << tiempo <<endl;

  t1 = clock();
  for(int j = 0; j < 8; j++){
    aux.push_back('A'+rand()%25);
    //cout << 'A'+rand()%25 << endl;
  }
  g->erase(aux);
  aux.clear();
  t2 = clock();

  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;

  cout << "Tiempo erase mapg: " << tiempo <<endl;

  t1 = clock();
  for(int j = 0; j < 8; j++){
    aux.push_back('A'+rand()%25);
    //cout << 'A'+rand()%25 << endl;
  }
  dh->erase(aux);
  aux.clear();
  t2 = clock();

  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;

  cout << "Tiempo erase mapDH: " << tiempo <<endl;

  
  return 0;
}
