#include <ctime>
#include "mapBST.h"
#include <vector>

void swap(pair<string,int> *a , pair<string,int> *b){
  
  pair<string,int> aux = *a;
  *a = *b;
  *b = aux;
   
}


int main(){

  int n;
  map *m1 = new mapBST();
  map *m2 = new mapBST();
  string name;
  vector<pair<string,int>> vec;

  srand(time(NULL));

  clock_t t1;
  clock_t t2;

  cout << "Ingrese la cantidad de elementos a generar\n";

  cin >> n;

  cout << "Creando BST ....\n";

    cout << endl << endl;

  for(int i = 0; i < n; i++){                                 //Crear vector de pares
    for(int j = 0; j < 12; j++)
      name.push_back('A'+rand()%25);
    int k = rand()%100;
    vec.push_back(make_pair(name,k));
    name.clear();
  }
  
  t1 = clock();

  for(int i = 0; i < vec.size(); i++)              //Insertar desordenado
  m1 -> insert(vec[i]);
  
  t2 = clock();

  double tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;

  cout << "Tiempo insercion en mapBST sin orden: " << tiempo << endl;
  
  for(int i = 0; i < vec.size(); i++){               //Selection sort simple
    for(int j = i+1; j < vec.size();j++){          // Para ordenar arreglo de pares
      if(vec[i].first.compare(vec[j].first) > 0){
	swap(&vec[i],&vec[j]);
      }
    }
  }
  
  /* cerr << "Arreglo ordenado\n";
  
  for(int i = 0; i < vec.size(); i++)
    cerr << "pos i: " << vec[i].first << " " << vec[i].second << endl;
  */
  
  t1 = clock();

  for(int i = 0; i < vec.size(); i++)
    m2 -> insert(vec[i]);
  
  t2 = clock();

  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;

  cout << "Tiempo de insercion en mapBST ordenado: " << tiempo << endl;

  cout << endl << endl;
  name.clear();                                                  //Limpiar string auxiliar

  name = vec[vec.size() -1].first;                       // Colocar clave en name para buscar

  // cerr << "Key para at: "  <<name << endl;

  t1 = clock();
  m1->at(name);
  t2 = clock();
  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;

  cout << "Tiempo busqueda en mapBST sin orden: " << tiempo << endl;


  t1 = clock();
  m2->at(name);
  t2 = clock();
  tiempo = (double)(t2-t1)/CLOCKS_PER_SEC;

  cout << "Tiempo busqueda en mapBST ordenado: " << tiempo << endl;

  

  // cout << "size m1: " << m1 -> size() << " size m2: " << m2 -> size() <<  endl;
  
  return 0;
}
