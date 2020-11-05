#include "mapg.h"

using namespace std;

int good_hash(string str,int tam){
  int a = 0;
  
  for(int i = 0; i < str.length(); i++)
    a +=(int)str[i]*(i+1);              //a cada letra del string, la multiplica por su posicion
  
  return a%tam;
}

static int primos [] = {53,97,193,389,769,1543,3079,6151,12289,24593,49157,98317,196613,393241,786433};

mapg::mapg(){
 
  index = 0;                       // Esto lleva la posicion del arreglo de primos
  tam = primos[0];            //Asignar primer numero primo en el arreglo
  elem = 0;

  hash = (pair<string,int> *)malloc(tam*sizeof(pair<string,int>));  // crear arreglo hash

  for(int i = 0; i < tam; i++)
    hash[i].first = "_";
  //Crear arreglo de pares
}

void mapg::insert(pair<string,int> par){  // o(n)   (Lineal amortizado)

  if(tam == elem)              //Si tabla hash llena
    rehash();                        // Rehash
  
  int a = good_hash(par.first,tam);
  int p = 0;

  while(p < tam){
    
    if(!hash[a].first.compare(par.first)){                 //Si la clave ha sido insertada
      cout << "Clave ya insertada, rechazado\n";   //Rechazar colocacion
      return;
    }
    
    if(!hash[a].first.compare("_") || !hash[a].first.compare("*")){   //Si no hay "nada"
      hash[a] = par;                                                //asignar a esa posicion
      break;
    }
    
    a = (a+1)%tam;                                               //Recorrer arreglo circular
    p++;
    
  }//endwhile
  
  elem++;
  //cout << "Llego aca\n";
  //  cout << "Elementos: " << elem << endl;
  
}

void mapg::erase(string str){    // O(n)

  int a = good_hash(str,tam);
  int p = 0;

  while(p < tam && hash[a].first.compare("_")){

    if(!hash[a].first.compare(str)){
      hash[a].first = "*";
      elem--;
      cerr << "Elementos luego de borrar: " << elem << endl;
      return;
    }

    a = (a+1)%tam;
    p++;

  }

  //  cerr << "No se encontro la clave\n";

}

int mapg::at(string str){    //O(n)

  int a = good_hash(str,tam);
  int p = 0;

  while(p < tam && hash[a].first.compare("_")){  //MIentras recorre arreglo y no hay "_"

    if(!hash[a].first.compare(str))                              //Si encuentra clave, devuelve valor
      return hash[a].second;

    a = (a+1)%tam;                                                //Recorrer arreglo
    p++;
    
  }

  //  cerr << "No esta guardada esta clave\n";           //retorna -1 si no encuentra clave
  return -1;

}

int mapg::size(){   // O(1)
  return elem;
}

bool mapg::empty(){   //O(1)
  if(elem == 0)
    return true;
  return false;
}

void mapg::rehash(){   //metodo auxiliar

  index++;
  
  if(index == 15){    //Si ocupamos todos los primos en arreglo
    cout << "Capacidad maxima alcanzada\nAgregar mas primos al arreglo\n";
    return;
  }
  //cout << "Siguiente tamaño: " << sizeof(pair<string,int>) << endl;

  pair<string,int> *aux = (pair<string,int> *)malloc(primos[index]*100*sizeof(pair<string,int>));
  //Se multiplica por 100, porque a veces provoca error en el bus, pero se controla
  //el desborde con las variable de tamaño de arreglo
  
  for(int i = 0; i < primos[index]; i++)
    aux[i].first = "_";               //Inicializar todas las claves en "_"

  //  cout<<"Rehashing G.....\n";

  for(int i = 0; i < tam; i++){

    int a = good_hash(hash[i].first,primos[index]);
    int p = 0;
    
    while(p < primos[index]){
      
      if(!aux[a].first.compare("_")){
	aux[a] = hash[i];
	break;
      }
      a = (a+1)%primos[index];
      p++;
      
    }//endwhile    
  }
  
  tam = primos[index];
  free(hash);
  hash = aux;
  
}

void mapg::maprint(){   //Metodo auxiliar

  cerr << "Mapa actual:\n";
  for(int i = 0; i < tam; i++)
    cerr << "Pos "<<i<<": Clave: "<<hash[i].first << " elemento: "<<hash[i].second<<endl;

}
