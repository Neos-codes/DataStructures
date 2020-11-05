#include "graph.h"

/*void dfs(int nodo, vector<vector<int>> adj){

  stack<int> s;
  q.push(nodo);

  while(!s.empty()){
    int nodo = s.top();
    s.pop();

    //Continuar rellenando

  }
  
}

void bfs(int nodo, vector<vector<int>> adj){
  queue<int> q;
  q.push(nodo);

  while(!q.empty()){
    int nodo = q.front();
    q.pop();
    //Continuar rellenando
  }

}
*/

int main(){
  
  int n,m;
  
  cin >> n;
  cin >> m;

  Graph g(n);

  for(int i = 0; i < m; i++){         //Insertar aristas
    int a,b;
    cin >> a >> b;
    g.insertEdge(a-1,b-1);
  }

  g.printAdj();

  
  cerr << "\nCantidad de vertices: " << g.numVertices() << endl;
  cerr << "\nCantidad de aristas: " << g.numEdges() << endl;

  g.DFS(1);
  
  
  return 0;
}
