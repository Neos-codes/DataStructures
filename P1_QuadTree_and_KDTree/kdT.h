#include "kdTreeADT.h"
#include <iostream>
#include <utility>

using namespace std;

class kdT: public kdTree{

	private:
		kdT *rightKDT;
		kdT *leftKDT;
		pair<int,int> point;
		pair<int,int> rootSize;
		bool isLeaf;
		//true si se revisa X
		//false si se revisa Y
		/*
		vector<pair<int,int>> Xr;
		vector<pair<int,int>> Yr;
		vector<pair<int,int>> Xl;
		vector<pair<int,int>> Yl;
		*/

	public:
		//kdT(int a, int b);
		kdT();
		kdT(vector<pair<int,int>> input);
		void construir(vector<pair<int,int>> input);
		vector<pair<int,int>> buscar(pair<int,int> searchTopRight, pair<int,int> searchBotLeft);
		kdT *BuildKDT(vector<pair<int,int>> input, int vStart, int vEnd, bool odd);
		bool intersectPoint(pair<int,int> givenPoint, pair<int,int> searchTopRight, pair<int,int> searchBotLeft);

};   