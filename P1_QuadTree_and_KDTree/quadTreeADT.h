#ifndef QUADTREE_H
#define QUADTREE_H
#include <vector>

using namespace std;

class quadTree{
	public:
		virtual void construir(vector<pair<int,int>> input) = 0;
		virtual vector<pair<int,int>> buscar(pair<int,int> searchTopRight, pair<int,int> searchBotLeft) = 0;
};

#endif
