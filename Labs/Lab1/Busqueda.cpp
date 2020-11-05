#include <bits/stdc++.h>
#include "Busqueda.h"

using namespace std;

Busqueda::Busqueda(int n) {
  this->vec = new int[n];
    
  srand(time(NULL));

  for(int i=0;i<n;i++) {
    this->vec[i] = rand() % n + 1;
  }
  this->tam = n;
  sort(this->vec,this->vec + this->tam);
  
  //DESCOMENTAR ESTAS LINEAS PARA IMPRIMIR
  // for(int i=0;i<this->tam;i++) cout<<this->vec[i]<<" ";
  // puts("");
    
}

Busqueda::~Busqueda(){
  delete this->vec;
}
int Busqueda::size(){
  return this->tam;
}

int Busqueda::lineal(int num){
  int pos = -1;
  for(int i = 0; i < tam; i++){    // Busca desde inicio arreglo
    if(vec[i] == num){             // y se detiene al encontrar num
      pos = i;
      //  cout << "Lineal num: " << vec[i] << endl;
      return pos;
    }
  }
  return pos;
}

int Busqueda::binaria(int num){
  int inf = 0,mid,sup = tam - 1;
  int pos = -1;
  while(inf <= sup){
    mid = (inf + sup)/2;
    //  cout << "Inf: " << inf << " Sup: " << sup << " mid: " << mid << endl;
    //  cout << "Pos: " << pos << endl;

    if(num > vec[sup] || num < vec[inf])  // Si esta fuera de los limites menor o mayor
      break;                         // Del arreglo, retornar pos -1

    if(num == vec[mid]){                  // Si encontramos el numero, acotamos superiormente
      pos = mid;                          // Para buscar mas a la izquierda
      sup = mid - 1;
    }

    if(num > vec[mid])                    // Si es mayor a la mitad, acotamos inferiormente
      inf = mid + 1;
     
    else                                  // Si es menor a la mitad, acotamos superiormente
      sup = mid - 1;
 
  }
  return pos;
}

int Busqueda::testSTL(int num){
  //http://www.cplusplus.com/reference/algorithm/lower_bound/
  int *iter = lower_bound(this->vec,this->vec+this->tam,num);
  int pos = iter-vec;
  if(pos>=this->tam){
    return -1;
  }else if(vec[pos]!=num){
    return -1;
  }else{
    return pos;
  }
}

