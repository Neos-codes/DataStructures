#include "graph.h"
#include <stack>

using namespace std;

Graph::Graph(int n){

  m = 0;
  
  for(int i = 0; i < n; i++)       //Crear lista de adyacencia de para n nodos
  nodes.push_back(vector<int>());
  
}

bool Graph::areAdjacent(int a, int b){
  a--;
  b--;
  
  for(int i = 0; i < nodes[a].size(); i++)  //Se recorre lista de nodo a
    
    if(nodes[a][i] == b){                   //Si lo encuentra, retorna true
      cerr << "El nodo " << a+1 << " y " << b+1 << " si son adyacentes\n";
      return true;
    }

  cerr << "El nodo " << a+1 << " y " << b+1 << " no son adyacentes\n";
  return false;                             //Si no, false
  
}

void Graph::insertVertex(){
  
  nodes.push_back(vector<int>());            //Se agrega nuevo nodo enumerado
  cerr << "Ahora el vector tiene " << nodes.size() << "vertices\n";
  
}

void Graph::insertEdge(int a, int b){
  
  nodes[a].push_back(b);                 //Al nodo a se agrega adyacencia con b
  nodes[b].push_back(a);                 //Al nodo b se agrega adyacencia con a
  m++;
  
}

void Graph::printAdj(){

  cerr << "Adyacencia del grafo:\n";
  
  for(int i = 0; i < nodes.size(); i++){
    cerr << "Nodo " << i+1 << ": ";
    for(int j = 0; j < nodes[i].size(); j++){
      cerr << nodes[i][j]+1 << " ";
    }
    cerr << endl;
  }
  
}

int Graph::numVertices(){
  return nodes.size();
}

int Graph::numEdges(){
  return m;
}

void Graph::DFS(int v){
  
  stack<int> s;
  bool visited[nodes.size()];               //Arreglo de nodos visitados

  for(int i = 0; i < nodes.size(); i++)    //Setear todos los nodos como no visitados
    visited[i] = false;
  
  s.push(v-1);                             //Agregar el nodo a la cola
  
  while(!s.empty()){                       //Mientras se tengan nodos visitables
    int nodo = s.top();
    s.pop();

    if(!visited[nodo]){                    //Si el nodo no ha sido visitado
      visited[nodo] = true;
      
      cerr << "Voy al nodo " << nodo+1 << endl;

      for(int i = 0 ; i < nodes[nodo].size(); i++){
	//if(!visited[nodes[nodo][i]])
	s.push(nodes[nodo][i]);
      }
    }
    else{
      //cerr << "Nodo " << nodo+1 << " ya visitado\n";
    }
    cerr << endl;
  }//endwhile


}

