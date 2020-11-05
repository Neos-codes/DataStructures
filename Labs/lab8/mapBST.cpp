#include "mapBST.h"

using namespace std;


mapBST::mapBST(){
  
  root = new node();   //Setear root como nodo vacio
  tam = 0;                   //Setear tamaño en 0
}

void mapBST::insert(pair<string,int> par){

  node *aux = root;    //Iniciar siempre por la raiz

  while(1){

    if(aux -> data.first == "EMPTY"){   //Si nodo vacio
      aux -> data = par;                        //Insertar dato
      aux -> right = new node();           //crear hijos
      aux -> left = new node();
      //cerr << "Inserte " << aux -> data.first << " " << aux -> data.second << endl;
      tam++;
      return;
    }
    
    else if(!aux -> data.first.compare(par.first)){   //Si claves iguales
      cerr << "Clave ya insertada, rechazada\n";      //Rechazar
      return;
    }

    else if(aux -> data.first.compare(par.first) < 0){  //Si clave insertada es mayor
      aux = aux -> right;
      //cerr << "Me fui a la derecha\n";
    }

    else{                                               //Si clave insetada es menor
      aux = aux -> left;
      //cerr << "Me fui a la izquierda\n";
    }
    
  }//endwhile
}

void mapBST::erase(string key){
  //No se llama
}

int mapBST::at(string key){

  node *aux = root;

  while(1){

    if(!aux -> data.first.compare(key)){   //Si clave es igual a la insertada
      // cerr << "Encontrado " << aux -> data.first << " dato: " << aux -> data.second <<endl;
      return aux -> data.second;                  //Retornar valor
    }

    else if(!aux -> data.first.compare("EMPTY")){  //Si clave nodo vacia
      cerr << "Clave no insertada\n";                      //Rechazar y salir
      return -1;
    }

    else if(aux -> data.first.compare(key) < 0){  //Si clave es mayor
      aux = aux -> right;                                        //Ir a la derecha
      //cerr << "Me fui a la derecha\n";
    }

    else{                                                 //Si la clave es menor
      aux = aux -> left;                           //Ir hacia la izquierda
      //cerr << "Me fui a la izquierda\n";
    }
    
  }//endwhile

  return -1;
}

int mapBST::size(){
  return tam;
}

bool mapBST::empty(){
  if(root -> data.first.compare("EMPTY"))  //Si primer elemento de la root vacio
    return true;                                            //return true
  return false;                                             //default return false
}
