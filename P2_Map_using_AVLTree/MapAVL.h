#include "MapADT.h"

using namespace std;


struct Node{	//CAMBIOS
	Node* right;
	Node* left;
	int height;
	pair<string,int> data;
	Node(){
		right = NULL;
		left = NULL;
		data.first = "EMPTY";
		data.second = -1;
		height = 0;
	}
	bool hasChildren(){
		if (right == NULL && left == NULL){
			//Si no se han inicializado los hijos no hay hijos
			return false;
		}
		if (right->data.first == "EMPTY" && left->data.first == "EMPTY"){
			//Si los hijos se inicializaron, pero estan vacios
			return false;
		}
		//Sino tiene hijos
		return true;
	}
};

class MapAVL: public MapADT{
	private:
		Node* root;
		int tam;
		void insertAux(pair<string,int> newPair, Node* aux);
		Node* eraseAux(Node *aux, string key);
		Node* findMin(Node* n);
	public:
		MapAVL();
		void insert(pair<string,int> newPair);
		void erase(string key);
		int at(string key);
		int size();
		bool empty();

		Node* balance(Node *current);

		Node* Rrot(Node *current);
		Node* Lrot(Node *current);
		Node* LRrot(Node *current);
		Node* RLrot(Node *current);

		void computeHeight(Node *current);

		void inOrderPrint(Node* n);
		void preOrderPrint(Node* n);
		void postOrderPrint(Node* n);
		void printAVL();
};

