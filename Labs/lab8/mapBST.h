#include "mapADT.h"

using namespace std;

typedef struct node{

  node *right;
  node *left;
  pair<string,int> data;
  node(){
    right = NULL;
    left = NULL;
    data.first = "EMPTY";
  }

}nodo;


class mapBST: public map{

 private:
  nodo *root;
  int tam;

 public:
  mapBST();
  void insert(pair<string,int> par);
  void erase(string key);
  int at(string key);
  int size();
  bool empty();
  

};


