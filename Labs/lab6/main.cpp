#include "priorityQueueHeap.h"
#include "priorityQueueUnsorted.h"
#include "priorityQueueSorted.h"

vector<int> heapSort(vector<int> q){       // O(n*log(n)), recorre la altura del arbol
  pQueue *qe = new priorityQueueHeap(); // n veces ordenando los datos

  for(int i = 0; !q.empty(); i++){                     //meter todo al heap
    qe -> push(q.front());                                 //push primer elemento del vector al heap
    q.erase(q.begin());                                     // borrar primer elemento del vector
  }

  while(!qe -> empty()){                                //Pasar del Heap al vector
    q.push_back(qe -> top());                          //Se pushea al vector la raiz del heap
    qe -> pop();                                               //se borra la raiz del heap
  }
  
  for(int i = 0; i < q.size(); i++)                     //Imprimir vector      
    cout << q[i] << " ";
  cout << endl;
  
  return q;
}

vector<int> selectionSort(vector<int> q){        // O(n*n), recorre el arreglo 1 vez buscando el menor 
  pQueue *qe = new priorityQueueUnsorted();   // y lo devuelve, repite el proceso n veces

  for(int i = 0; !q.empty(); i++){                          //Meter todo a la cola
    qe -> push(q.front());
    q.erase(q.begin());                                           //Despues de meter elemento, borrarlo del vector
  }

  while(!qe -> empty()){                                      // Mientras la cola no este vacia
    q.push_back(qe -> top());                                // se pasa de la cola al vector
    qe -> pop();                                                     // pop elemento de la cola
  }
  
  for(int i = 0; i < q.size(); i++)                            // Imprimir vector
    cout << q[i] << " ";
  cout << endl;

  return q;
}

vector<int> insertionSort(vector<int> q){  // O(n*n), recorre el arreglo n veces
  pQueue *qe = new priorityQueueSorted(); // desde tamaño 2 hasta n.

  for(int i = 0; !q.empty(); i++){                   // Meter todo a la cola
    qe -> push(q.front());
    q.erase(q.begin());                                    //despues de emeter elemento, borrarlo del vector
  }

  while(!qe -> empty()){                               //mientras la cola no este vacia
    q.push_back(qe -> top());                         //se pasa de la cola al vector
    qe -> pop();                                              //pop del elemento de la cola
  }

  for(int i = 0; i < q.size(); i++)                     // Imprimir vector
	cout << q[i] << " ";
      cout << endl;
      
      return q;
}

int main(){

  srand(time(NULL));
  pQueue *qe = new priorityQueueSorted();
  vector<int> aux;
  cout << "Se pushea al vector: ";
  for(int i = 0; i < 15; i++){
    int num = rand()%10 +1;
    cout << num << " ";
    aux.push_back(num);
  }
  cout << endl;
  /*
  cout << "Heapsort: \n";
  aux = heapSort(aux);
  */
  
  cout << "Selection Sort: \n";
  aux = selectionSort(aux);
  
  /*
  cout << "Insertion Sort: \n";
  aux = insertionSort(aux);
  */
  
  return 0;
}
