#include <iostream>
#include <vector>

using namespace std;


class Graph{

 public:
  Graph(int n);
  bool areAdjacent(int a, int b);
  void insertVertex();
  void insertEdge(int a, int b);
  void printAdj();
  int numVertices();
  int numEdges();
  void DFS(int v);
  
  
 private:
  vector<vector<int>> nodes;  //Lista de adyacencia
  int m;                      //Cantidad de aristas
  
};
