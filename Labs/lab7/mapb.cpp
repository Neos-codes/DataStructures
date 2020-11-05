#include "mapb.h"

using namespace std;

int hashing(string str, int tam){
  // Numero ascii primera letra modulo tamaño de arreglo
  return (int)*str.begin()%tam;
}


mapb::mapb(){

  tam = 10;                                                                                        //Parte tamaño 10
  hash = (pair<string,int> *)malloc(tam*sizeof(pair<string,int>));  //Crear arreglo de pares
  elem = 0;                                                                                        //Inicia con 0 elementos

  for(int i = 0; i < tam; i++)   //Setea todas las claves iniciales con un "_" para distinguir nulos
    hash[i].first = "_";
  
}

void mapb::insert(pair<string,int> par){  // o(n)  (Lineal amortizado)

  if(tam == elem)                                   //Si tabla hash llena
    rehash();                                             // Rehash
  
  int a = hashing(par.first,tam);
  int p = 0;
  
  while(p < tam){

    if(!hash[a].first.compare(par.first)){   //Si la clave ya está insertada
      cout<<"Clave ya insertada, rechazado\n";
      return;
    }

    if(!hash[a].first.compare("_") || !hash[a].first.compare("*")){         //Si esa posicion esta vacia
      hash[a] = par;                                 // Insertar
      break;                                              // Salir de bucle
    }
    a = (a+1)%tam;                                //Avanzar posicion en arreglo circular
    p++;
    
  }//endwhile
  
  elem++;
  
  // cout << "Elementos: " << elem << endl;
  
}



void mapb::erase(string k){    // O(n)

  int a = hashing(k,tam);
  int p = 0;

  while(p<tam && hash[a].first.compare("_")){  //Mientras recorre arreglo y no pille "_"

    if(!hash[a].first.compare(k)){      // Si encuentra clave
      hash[a].first = "*";                     // Lo sustituye por un '*' como bandera
      elem--;
      cerr << "Elementos luego de borrar: " << elem << endl;
      return;
    }
    
    a = (a+1)%tam;                         //Recorrer arreglo circular
    p++;
    
  }
  
  // cerr <<"No se encontro la clave\n";
  
}

int mapb::at(string k){    //O(n)

  int a = hashing(k,tam);
  int p = 0;
  
  while(p < tam && hash[a].first.compare("_")){    //Mientras se recorre arreglo y no ecuentre "_"
    
    if(!hash[a].first.compare(k))                               //SI encuentra clave devuelve elemento
      return hash[a].second;
    
    a = (a+1)%tam;
    p++;
  }
  
  // cerr << "No esta guardada esta clave\n";          //Retorna -1 si no encuentra clave
  return -1;
}



int mapb::size(){   //O(1)
  cerr << "Elementos guardados: " << elem << endl;
  return elem;
}

bool mapb::empty(){  //O(1)
  if(elem == 0){
    return true;
  }
  return false;
}



void mapb::rehash(){  //Metodo auxiliar

  pair<string,int> *aux = (pair<string,int> *)malloc(tam*2*sizeof(pair<string,int>));
  for(int i = 0; i < 2*tam; i++)
    aux[i].first = "_";
  
  // cout<<"Rehashing B.....\n";

  for(int i = 0; i < tam; i++){
    
    int a = hashing(hash[i].first,tam*2);
    int p = 0;
    
    while(p < 2*tam){

      if(!aux[a].first.compare("_")){                //Si esa posicion esta vacia
	aux[a] = hash[i];                                  // Insertar
	break;                                                  // Salir de bucle
      }
      a = (a+1)%(2*tam);                              //Avanzar posicion en arreglo circular
      p++;
      
    }//endwhile
    
    
  }
  
  tam *= 2;
  free(hash);
  hash = aux;
  
}



void mapb::maprint(){  //Metodo auxiliar

  cerr << "Mapa actual:\n";
  for(int i = 0; i < tam; i++)
    cerr << "Pos "<<i<<": Clave: "<<hash[i].first << " elemento: "<<hash[i].second<<endl;

}



