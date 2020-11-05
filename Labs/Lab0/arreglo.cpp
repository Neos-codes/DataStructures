#include "arreglo.h"
#include <iostream>

using namespace std;

arreglo::arreglo(int _n){
  n = _n;
  myArray = new int[n];
  for(int i = 0; i < n; i++){   //Llenar arreglo con numeros aleatorios del 1 al 100
    myArray[i] = rand()%100+1;
    //  cout << myArray[i] << " " ;  // Imprimir numeros en arreglo
  }
  //cout << "\n";
}

int arreglo::suma(){          // Sumar numeros en el arreglo
  int aux = 0;
  for(int i = 0; i < n; i++)
    aux += myArray[i];
  return aux;
}

int arreglo::getn(){          // Dar tamaño del arreglo
  return n;
}
