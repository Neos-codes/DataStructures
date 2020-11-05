#include "mapDH.h"

using namespace std;

//usaremos la funcion good_hash implementada en mapg.cpp como "Primer hash"

int good_hash_(string str,int tam){
  int a = 0;
  
  for(int i = 0; i < str.length(); i++)
    a +=(int)str[i]*(i+1);              //a cada letra del string, la multiplica por su posicion
  
  return a%tam;
}

int double_hash(string str,int tam){
  int a = 0;

  for(int i = 0; i < str.length(); i++)
    a+= (int)str[str.length()-1-i]*(i+1);   //a cada letra del string, la multiplica por su posicion
                                                             // inversa

  return a%tam;

}

static int primos [] = {53,97,193,389,769,1543,3079,6151,12289,24593,49157,98317,196613,393241,786433};    //Arreglo de numeros primos

mapDH::mapDH(){

  index = 0;                       //Esto lleva la posicion del arreglo de primos
  tam = primos[0];           //Asignar primer numero primo en el arreglo
  elem = 0;                       //Cantidad de elementos no nulos insertados

  hash = (pair<string,int> *)malloc(tam*sizeof(pair<string,int>));  // crear arreglo hash

  for(int i = 0; i < tam; i++)
    hash[i].first = "_";
  //Crear arreglo de pares
  
}

void mapDH::insert(pair<string,int> par){   //o(n)   Lineal amortizado
  
  if(tam == elem)              //Si tabla hash llena
    rehash();

  int a = good_hash_(par.first,tam);
  int dh = -1;
  int p = 0;
  //  cout << "Llego aca\n";
  while(p < tam){

    if(!hash[a].first.compare(par.first)){                    //Si la clave ha sido insertada
      cout << "Clave ya insertada, rechazado\n";     //Rechazar colocacion
      return;
    }

    if(!hash[a].first.compare("_") || !hash[a].first.compare("*")){   //Si no hay "nada"
      hash[a] = par;                                                                          //Asignar a esa posicion
      break;
    }

    //Si llega aqui, hubo colision
    
    if(dh == -1)                                      //Se calcula una vez el doble hash
      dh = double_hash(par.first,tam);
    
    a = (a+dh)%tam;
    p++;
    
  }//endwhile
  // cout << "Pero no llego aca\n";
  elem++;

  //cout << "Elementos: " << elem << endl;

}

void mapDH::erase(string str){  // O(n)

  int a = good_hash_(str,tam);
  int dh = -1;
  int p = 0;

  while(p < tam && hash[a].first.compare("_")){  //Mientras no se recorra arreglo y no
                                                                              //Encuentre un nulo

    if(!hash[a].first.compare(str)){
      hash[a].first = "*";
      elem--;
      cerr << "Elementos luego de borrar: " << elem << endl;

    }

    if(dh == -1)
      dh = double_hash(str,tam);

    a = (a+dh)%tam;
    p++;
    
  }

  // cerr << "No se encontro la clave\n";

    
}


int mapDH::at(string str){   //O(n)
  int a = good_hash_(str,tam);
  int dh = -1;
  int p = 0;

  while(p < tam && hash[a].first.compare("_")){  //Mientras recorre arreglo y no hay "_"

    if(!hash[a].first.compare(str))                           //SI encuentra clave, devuelve valor
      return hash[a].second;

    if(dh == -1)
      dh = double_hash(str,tam);                             //Calculamos hash doble si hay colision

    a = (a+dh)%tam;
    p++;

  }

  // cerr << "No esta guardada esta clave\n";
  return -1;
    
}

int mapDH::size(){   //O(1)
  return elem;
}

bool mapDH::empty(){  //O(1)
  if(elem == 0)
    return true;
  return false;
}

void mapDH::rehash(){  //Metodo auxiliar

  index++;

  if(index == 15){    //Si ocupamos todos los primos del arreglo
    cout << "Capacidad maxima alcanzada\nAgregar mas primos al arreglo\n";
    return;
  }

  pair<string,int> *aux = (pair<string,int> *)malloc(primos[index]*100*sizeof(pair<string,int>));  //Se multiplica por 100 porque a veces genera error en el bus, pero se controla
         //el desborde con las variables de tamaño del arreglo

  for(int i = 0; i < primos[index]; i++)
    aux[i].first = "_";

  //cout <<"Rehashing DH......\n";

  for(int i = 0; i < tam; i++){

    int a = good_hash_(hash[i].first,primos[index]);
    int dh = -1;
    int p = 0;

    while(p < primos[index]){

      if(!aux[a].first.compare("_")){
	aux[a] = hash[i];
	break;
      }
      if(dh == -1)
	dh = double_hash(hash[i].first,primos[index]);
      a = (a+dh+2)%primos[index];
      p++;
      
    }
  }

  tam = primos[index];
  free(hash);
  hash = aux;
  //cout << "Termino rehash\n";
}

void mapDH::maprint(){  //Metodo auxiliar

  cerr << "Mapa actual:\n";
  for(int i = 0; i < tam; i++)
    cerr << "Pos "<<i<<": Clave: "<<hash[i].first << " elemento: "<<hash[i].second<<endl;
  
}
