#include "priorityQueueSorted.h"

priorityQueueSorted::priorityQueueSorted(){ }

int priorityQueueSorted::top(){   // O(1), retornar cabeza de la cola

  if(!q.empty())
    return q[0];
  
  //cout << "Queue vacia\n";
  return -1;
}

void priorityQueueSorted::pop(){  //O(1), borrar cabeza de la cola
  if(!q.empty())
    q.erase(q.begin());
  /* cout << "despues de borrar: " << endl;
  for(int i = 0; i < q.size(); i++)
    cout << q[i] << " ";
  cout << endl;
  */
}

void priorityQueueSorted::push(int num){  // O(n*n), por complejidad de Insertion Sort
  q.push_back(num);

  int i,pivote,j;
  
  //Busque muchas ideas de Selection Sort en internet
  // tome ideas de muchas, pero comento para demostrar que entiendo lo que hago                            
  for(i = 1; i < q.size(); i++){   //recorremos el arreglo
    
    pivote = q[i];                             //se asigna pivote como la posicion i del arreglo del for
    j = i-1;                                       // j esta una posicion a la izquierda de i
    
    while(j >= 0 && q[j] > pivote){  // mientras j este dentro del limite inferior del arreglo
      // y la posicion anterior sea menor que el pivote
      q[j+1] = q[j];                            // |
      j -= 1;
    }                                                 // |  swap con el pivote     
     q[j+1] = pivote;                        // |
  }
  /*cout << "j = " << j << endl;
  cout << "Se inserta: " << num << endl;
  for(int i = 0; i < q.size(); i++)
    cout << q[i] << " ";
  cout << endl;
  */
}

int priorityQueueSorted::size(){   // O(1), retorna tamaño del vector
  return q.size();
}

bool priorityQueueSorted::empty(){  // O(1), retorna si arreglo vacio o no
  return q.empty();
}
