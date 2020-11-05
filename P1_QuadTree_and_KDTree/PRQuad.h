#include "quadTreeADT.h"
#include <iostream>
#include <utility>

using namespace std;

class PRQuad: public quadTree{

    private:
        PRQuad *NW;                             //Punteros a subQuadtrees
        PRQuad *SW;
        PRQuad *SE;
        PRQuad *NE;

        pair <int,int> point;       // Punto a almacenar
        bool hasPoint;              // Usado para saber si tiene punto

        pair <int,int> topRight;    // Punto de limite
        pair <int,int> botLeft;     // Punto de limite

    public:
        PRQuad(int a, int b,vector<pair<int,int>> input);       //el constructor usado para cuando se recibe inicialmente los datos
        PRQuad(pair<int,int> newTopRight,pair<int,int> newBotLeft);    //Constructor
        void construir(vector<pair<int,int>> input);
        vector<pair<int,int>> buscar(pair<int,int> searchTopRight, pair<int,int> searchBotLeft);
        bool hasChild();
        bool isContained(pair<int,int> givenPoint);
        //bool canSubdivide();
        void Subdivide();
        bool Insert(pair<int,int> insertPoint);
        bool intersectRect(pair<int,int> searchTopRight, pair<int,int> searchBotLeft);
        bool intersectPoint(pair<int,int> givenPoint, pair<int,int> searchTopRight, pair<int,int> searchBotLeft);
};
