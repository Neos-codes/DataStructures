#include "stackqueue.h"
#include <iostream>
#include <stack>

using namespace std;

//-----METODOS PARA LA QUEUE-----//

stackqueue::stackqueue(){   //Constructor
  
}

void stackqueue::push(int num){   //PUSH
  s.push(num);
  //cout << "Pushed: " << s.top() << endl;
}

void stackqueue::pop(){    //POP
                           // Complejidad 2n

  while(!s.empty()){       // Copiar Stack en auxiliar
    aux.push(s.top());     // COPIAR CON TOP
    // cout << "Poped s: " << s.top() << endl;
    s.pop();
  }

  if(!aux.empty()){         // Quitar elemento final de aux
    //cout << "Poped aux: " << aux.top() << endl;;
    aux.pop();
  }

  while(!aux.empty()){     // Devolver al stack
    s.push(aux.top());
    aux.pop();
  }
  //cout << "Poped\n";
}

int stackqueue::front(){
                          //  Complejidad 2n+1
   int top;

   while(!s.empty()){     // Copiar stack en auxiliar
    aux.push(s.top());
    s.pop();
   }

  if(!aux.empty())       // Toma primer elemento
   top = aux.top();

  while(!aux.empty()){    // Devolver auxiliar a Stack
    s.push(aux.top());
    aux.pop();
  }

  //cout << "front: " << top << endl;
  return top;
}

int stackqueue::back(){
  //cout << "back: " << s.top() << endl;
  return s.top();
}

int stackqueue::size(){
  // cout << "size: " << s.size() << endl;
  return s.size();
}

bool stackqueue::isEmpty(){
  // cout << s.empty() << "\n";
  return s.empty();
}



//-----METODOS PARA EL ITERADOR-----//


StackIt::StackIt(stackqueue *q){   // Constructor StackIt
  count = 0;                  // Inicia contador de posicion
  aq = q;                      // Toma referencia a lista
}


bool StackIt::hasNext(){     
  int tam = aq -> s.size();     // Obtener tamaño del stack "lista"

  if(tam  > count){           // si el tamaño es mayor al contador, tiene
    cout << "Tiene next\n";
    return true;
  }
  else{
    cout << "No tiene next\n";
    return false;
  }
}

int StackIt::nextInt(){

  int i = 0;
  int next = -1;
  
  while(!aq -> s.empty()){       // Copiar Stack en auxiliar
    aq ->aux.push(aq -> s.top());
    //  cout << "Poped s: " << aq -> s.top() << endl;
    aq -> s.pop();
  }

  while(!aq -> aux.empty()){     // Devolver al stack

    aq -> s.push(aq -> aux.top());
    if(i == count)       // Si i = contador de iterador, retorna valor      
      next = aq -> aux.top();      // Caso contrario, retorna -1;

    aq -> aux.pop();
    i++;
  }
  count++;
  // cout << "nextInt: " << next << endl;
  return next;
}

void StackIt::reset(){
  cout << "Reseted\n";
  count = 0;

}
