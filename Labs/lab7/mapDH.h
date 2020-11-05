#include "mapADT.h"

using namespace std;

class mapDH: public map{

 private:
  int index;
  int tam;                          //Tamaño actual de la tabla
  int elem;                        // Cantidad de elementos no nulos en la tabla
  pair<string,int> *hash; // Puntero a arreglo de elementos

 public:
  mapDH();
  void insert(pair<string,int>);
  void erase(string);
  int at(string);
  int size();
  bool empty();
  void rehash();
  void maprint();
  
};
