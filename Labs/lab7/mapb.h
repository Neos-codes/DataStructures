#include "mapADT.h"

using namespace std;

class mapb: public  map{

 private:
  int tam;                             //Guarda el tamaño de la tabla hash
  int elem;                           //Guarda la cantidad de elementos insertados en tabla hash
  pair<string,int> *hash;    //tabla hash, arreglo de pares

 public:

  mapb();
  void insert(pair<string,int>);
  void erase(string);
  int at(string);
  int size();
  bool empty();
  void rehash();
  void maprint();
  
};
