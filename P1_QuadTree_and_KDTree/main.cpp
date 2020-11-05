#include "PRQuad.h"
#include "kdT.h"
#include <algorithm>

using namespace std;



int main(){

    int N,M,P;
    int x,y;

    
    cout << "Ingresar tamaño del espacio"<<endl;    //Se lee tamaño y puntos
    cin >> N;
    cin >> M;
    cin >> P;

    vector<pair<int,int>> ptos;                     //Se crea vector de puntos
    vector<pair<int,int>> buscadoskd;
    vector<pair<int,int>> buscadosquad;
    
    for(int i = 0; i < P; i++){                     //Se leen puntos
        cin >> x;
        cin >> y;
        ptos.push_back(make_pair(x,y));             //Se insertan al vector
    }
    

    quadTree *PRQ = new PRQuad(N,M,ptos);           //Se crea QuadTree

    kdT *kd = new kdT(ptos);                         //Se crea kdTree


    buscadoskd = kd->buscar(make_pair(8,10),make_pair(6,6));     //Despues de insertar se busca en ambos
    buscadosquad = PRQ-> buscar(make_pair(8,10),make_pair(6,6));

    cout << "Buscados en kd\n";                                  //Imprimir encontrados por ambos trees
    for(int i = 0;i < buscadoskd.size();i++){
        cerr<<"El punto " << buscadoskd[i].first << " " <<buscadoskd[i].second << " esta dentro"<<endl;
    }
    cout <<"Buscado en Quad\n";
    for(int i = 0;i < buscadosquad.size();i++){
        cerr<<"El punto " << buscadosquad[i].first << " " <<buscadosquad[i].second << " esta dentro"<<endl;
    }


    goto reprobar;
    reprobar:
    if(!0)
    return 0;    
}
