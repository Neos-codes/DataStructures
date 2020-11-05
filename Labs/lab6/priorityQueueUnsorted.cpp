#include "priorityQueueUnsorted.h"

priorityQueueUnsorted::priorityQueueUnsorted(){ }

int priorityQueueUnsorted::top(){       // O(n), recorre 1 vez el vector
  int min;

  if(!q.empty()){                                   //Si la cola no esta vacia
    min = q[0];                                      // el menor se asigna el primero de la cola
    
    for(int i = 1; i < q.size(); i++){       //se compara con todo el resto del vector
      if(min > q[i])                                 //si es mayor que el comparado
	min = q[i];                                  //cambiar min
    }
  }
  //  cout << "top: " << min << endl;
  return min;
  
}

void priorityQueueUnsorted::pop(){      // O(n), recorre una vez el vector
  int min,minPos;

  if(!q.empty()){                                      //Si no está vacio
      min = q[0];                                       //se deja min como la primera posicion
      minPos = 0;                                      //y minPos como el subindice de la primera posicion
      
      for(int i = 1; i < q.size()   ;i++){      //se recorre el arreglo
	if(min > q[i]){                                //si min es mayor que el elemento actual
	  min = q[i];                                   //se reasigna min
	  minPos = i;                                  // y se guarda su subindice
	}	  
      }
      q.erase(q.begin() + minPos);          //por ultimo se borra el elemento
    }
  
  /*
  cout << "despues de pop\n";
  for(int i = 0 ; i <q.size(); i++)
    cout << q[i] << " ";
  cout << endl;
  */
}

void priorityQueueUnsorted::push(int num){  // O(1), inserta al final del vector
  
  q.push_back(num);                             //Se inserta el numero al final de la cola
  /*
  cout << "despues de push\n";
  for(int i = 0 ; i <q.size(); i++)
    cout << q[i] << " ";
  cout << endl;
  */
}

int priorityQueueUnsorted::size(){      // O(1), devuelve el tamaño del vector
  
  return q.size();                                   //size de cola es igual a size del vector
}

bool priorityQueueUnsorted::empty(){ // O(1), devuelve true si vector esta vacio
  
  return q.empty();                               //empty de cola es igual a empty de vector
}
