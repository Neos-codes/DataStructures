#include "mapADT.h"

using namespace std;

class mapg: public map{

 private:
  int index;
  int tam;                           //Tamaño actual de la tabla
  int elem;                         //Cantidad de elementos en la tabla
  pair<string,int> *hash;  //Puntero a la tabla hash

 public:

  mapg();
  void insert(pair<string,int>);
  void erase(string);
  int at(string);
  int size();
  bool empty();
  void rehash();
  void maprint();

};
