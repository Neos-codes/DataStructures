#include <iostream>
#include "clase.h"
#include "arreglo.h"

using namespace std;

int main() {
  srand(time(NULL));
  clase c(5);
  clock_t t1 = clock();
  arreglo a(rand()%10000+2);  // Dar tamaño de arreglo del 2 al 10000
  cout << "La suma del arreglo es: " << a.suma() << endl;
  clock_t t2 = clock();
  cout << "Tiempo: " << (double)(t2-t1)/CLOCKS_PER_SEC << endl; // Imprime tiempo
  // Imprimir valores
  
  /* 
  
  c.incrementar();
  cout << "El numero incrementado en 1:  " << c.getMyInt() << endl;
  c._incrementar(10);
  cout << "El numero incrementado en n: " << c.getMyInt() << endl;
  */
}
