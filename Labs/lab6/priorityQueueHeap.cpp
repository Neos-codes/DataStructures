#include "priorityQueueHeap.h"

void swap(int *a, int *b){   //funcion auxiliar, O(1)
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

priorityQueueHeap::priorityQueueHeap(){  // O(1), inserta algo al inicio
  
  q.push_back(-1);           // Agregar cualquier cosa al inicio
                                       // arbol comienza en posicion q[1]
} 

int priorityQueueHeap::top(){   // O(1), retorna root de heap
  
  if(q.size() >= 2)           //Si cola no vacia, si tiene algo en q[1]
    return q[1];                //Retornar elemento frontal
}

void priorityQueueHeap::pop(){  // O(log(n)), se mueve por la altura del arbol
  int i = 1;

  swap(&q[1],&q[q.size() - 1]);        //Cambiar de posicion primero con ultimo
  

  q.erase(q.begin() + q.size()-1 );                       //Borrar ultimo elemento

  while(2*i <= q.size() -1 || (2*i +1) <= q.size() -1){   //Mientras se tengan hijos

    if((2*i +1) < q.size() ){               //Si tiene hijo derecho
      if(q[2*i + 1] >= q[2*i]){           //Si el hijo derecho es mayor o igual que el izquierdo
	swap(&q[i],&q[2*i]);               //Swap con hijo izquierdo
	i *= 2;                                     // Modificar i
      }
      
      else if(q[2*i+1] < q[2*i]){        //Si hijo derecho es menor que el izquierdo
	swap(&q[i],&q[2*i+1]);          //swap con hijo derecho
	i = 2*i +1;
      }
	else                                          // Si no es mayor que ninguno, salir del ciclo
	  break;     
    }
    //------------------------------------------------------------------------------------//
    
    else{                                          //Si tiene solo hijo izquierdo
      if(q[i] > q[2*i]){                       // SI el hijo izquierdo es menor
	swap(&q[i],&q[2*i]);              // swap
	i *= 2;
      }

      else                                          //SI no es menor que el hijo, salir del ciclo
	break;      
    }
  }
  
  /* 
  cout << "Arreglo Popeado:\n";               //Imprime heap (arreglo)
  for(int j = 1; j <q.size(); j++)
    cout << q[j] <<" ";
  cout << "\n";
  */

}

void priorityQueueHeap::push(int num){  // O(log(n)), inserta al final pero hace upheaps
  
  int i = q.size();                            // Posicion del elemento que se insertara
  int aux;
  q.push_back(num);                    //Push al final del vector, (insercion)
  while(i >=1){                            // Mientras i sea mayor que el limite inferior del tree
    
    if(q[i] < q[i/2])                         // Si el elemento es menor que su padre
      swap(&q[i],&q[i/2]);              // Swap (upheap)
      
    else                                        // Si es mayor o igual se mantiene
      break;
    i /= 2;                                     // i se modifica a la posicion del numero
  }
  
  /*
  cout << "Heap: " << endl;
  for(int j = 1; j <q.size(); j++)
    cout << q[j] << endl;
  cout << endl;
  */

}

int priorityQueueHeap::size(){            // O(1), retorna tamaño del arreglo
  // cout << "size: " << q.size() - 1 << endl;
  return q.size() - 1;
}

bool priorityQueueHeap::empty(){    // O(1), retorna si el arreglo esta vacio o no
  if(q.size() <= 1)
    return true;
  return false;

}
