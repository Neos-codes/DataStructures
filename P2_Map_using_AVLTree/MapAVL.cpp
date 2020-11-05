#include "MapAVL.h"

using namespace std;


MapAVL::MapAVL(){
	tam = 0;
	root = new Node();

}

void MapAVL::insert(pair<string,int> newPair){

	Node* aux = root;
	insertAux(newPair,aux);
	return;
	
}

void MapAVL::insertAux(pair<string,int> newPair, Node* aux){

	if (aux->data.first == "EMPTY"){
		aux->data = newPair;
		aux->left = new Node();		
		aux->right = new Node();	
		aux->height = 1;			//CAMBIOS
		cerr<<"Inserte "<<newPair.first<<endl;
		tam++;
		return;
	}

	if (aux->data.first == newPair.first){
		//Si la clave es igual no se inserta
		cerr<<"Son iguales, no se inserta\n";
		return;
	}
	/*if (aux->right == NULL && aux->left == NULL){
		cerr<<"Cree los hijos para nodo "<<aux->data.first<<endl;
		aux->left = new Node();
		aux->right = new Node();
	}*/

	if (newPair.first.compare(aux->data.first)<0){
		//Si es menor alfabeticamente, se inserta la izq
		cerr<<newPair.first<<" va en la izquierda\n";
		insertAux(newPair, aux->left);
		computeHeight(aux);			//CAMBIOS
	}
	else{
		//Si es mayor alfabeticamente, se inserta la der
		cerr<<newPair.first<<" va en la derecha\n";
		insertAux(newPair, aux->right);
		computeHeight(aux);			//CAMBIOS
	}
	cerr<<"Return final"<<endl;
	return;
}

void MapAVL::erase(string key){

	Node *aux = root;
	eraseAux(aux,key);
	return;
}

Node* MapAVL::eraseAux(Node *aux, string key){
	
	Node *res;
	//or aux ==NULL
	if(!aux -> data.first.compare("EMPTY"))     //Si esta vacio, retornar nada
		return root;

	else if(key.compare(aux->data.first) < 0){   //Si clave menor, borrar a la izq
		cerr << "Busco a la izquierda\n";
		aux -> left = eraseAux(aux -> left, key);
	}

	else if(key.compare(aux->data.first) > 0){   //Si clave mayor, borrar a la der
		cerr << "Busco a la derecha\n";
		aux -> right = eraseAux(aux->right, key);
	}	

	else{ //Cuando encontramos la clave

		cerr << "Encontre la clave: " << aux->data.first<<endl;
		if(aux -> left -> data.first == "EMPTY" && aux -> right -> data.first == "EMPTY"){  
			//No tiene hijos, entonces borramos
			cerr << "Entre a la hoja "<<aux->data.first<<endl;
			delete aux -> left;
			delete aux -> right;
			aux -> left = NULL;
			aux -> right = NULL;                                   
			aux -> data.first = "EMPTY";
			aux -> data.second = -1;
			aux -> height = 0;
		}

		else if(aux -> left -> data.first == "EMPTY"){
			//Tiene 1 hijo en la izquierda  
			cerr << "Borrado de " << aux -> data.first << " con hijo a la derecha\n";
			res = aux;
			aux = aux -> right;
			delete res;
		}

		else if(aux -> right -> data.first == "EMPTY"){
			//Tiene 1 hijo en la derecha
			cerr << "Borrado de " << aux -> data.first << " con hijo a la izquierda\n";
			res = aux;
			aux = aux -> left;
			delete res;

		}

		else{
			//Tiene 2 hijos
			cerr << "Borrado de " << aux -> data.first << " con 2 hijos\n";
			res = findMin(aux -> right);   //Busca minimo a la derecha, mantiene propiedad AVL
			aux -> data = res -> data;     //Copia el minimo en el nodo que se quiere borrar

			aux -> right = eraseAux(aux -> right, res -> data.first);

		}


 	}
 	computeHeight(aux);
	return aux;

}

int MapAVL::at(string key){
	Node* aux = root;

	while(1){
		//Si el nodo es vacio, termino
	
		if (aux->data.first == key){
			//Si la clave es igual, se retorna el entero asociado

			//cerr<<"Son iguales, este es\n";
			return aux->data.second;
		}		

		if (aux->data.first == "EMPTY"){
			//cerr<<"No encontre "<<key<<endl;
			return -1;	
		}

		if (aux->left == NULL || aux->right == NULL){
			return -1;
		}		

		if (key.compare(aux->data.first)<0){
			//Si es menor alfabeticamente, se inserta la izq
			//cerr<<key<<" va en la izquierda\n";
			aux = aux->left;
		}
		else{
			//Si es mayor alfabeticamente, se inserta la der
			//cerr<<key<<" va en la derecha\n";
			aux = aux->right;
		}
	}

	//cerr<<"Return final"<<endl;
	return -1;
}

int MapAVL::size(){
	return tam;
}

bool MapAVL::empty(){
	if (root->data.first != "EMPTY"){
		return false;
	}
	else{
		return true;
	}
}

Node* MapAVL::balance(Node *current){
	//te balanceai x weon

}

Node* MapAVL::Rrot(Node *current){
	Node* newRoot = current->left;
	current->left = newRoot->right;
	newRoot->right = current;
	computeHeight(current);
	computeHeight(newRoot);
	return newRoot;
}

Node* MapAVL::Lrot(Node *current){
	Node* newRoot = current->right;
	current->right = newRoot->left;
	newRoot->left = current;
	computeHeight(current);
	computeHeight(newRoot);
	return newRoot;
}

Node* MapAVL::LRrot(Node *current){
	current->left = Lrot(current->left);
	return Rrot(current);
}

Node* MapAVL::RLrot(Node *current){
	current->right = Rrot(current->right);
	return Lrot(current);
}

void MapAVL::computeHeight(Node* current){	//CAMBIOS
	int leftH = 0;
	int rightH = 0;
	/*
	calculamos la altura
	si no tiene hijos, la altura es 1
	si tiene hijos, se toma el max de la altura de los hijos +1
	*/

	if(current->hasChildren()){
		//Si tiene hijos revisamos la altura de los hijos y tomamos el max
		leftH = current->left->height;
		rightH = current->right->height;
	}

	current->height = 1 + max(leftH, rightH);
}

void MapAVL::printAVL(){
	//cerr<<"IN ORDER"<<endl;
	//inOrderPrint(root);
	cerr<<endl<<"PRE ORDER"<<endl;
	preOrderPrint(root);
	//cerr<<endl<<"POST ORDER"<<endl;
	//postOrderPrint(root);
}

void MapAVL::inOrderPrint(Node* n){
	if(n->left != NULL){
		inOrderPrint(n->left);
	}
	cerr<<n->data.first<<endl;
	if(n->right != NULL){
		inOrderPrint(n->right);
	}
}

void MapAVL::preOrderPrint(Node* n){



	cerr<<n->data.first<<" "<<n->height<<" "<<n->hasChildren()<<endl;	//CAMBIOS
	if(n->left != NULL){
		preOrderPrint(n->left);
	}
	if(n->right != NULL){
		preOrderPrint(n->right);
	}
}


void MapAVL::postOrderPrint(Node* n){

	if(n->left != NULL){
		postOrderPrint(n->left);
	}
	if(n->right != NULL){
		postOrderPrint(n->right);
	}
	cerr<<n->data.first<<endl;
}

//--------------NUEVO METODO CREADO---------------//

Node* MapAVL::findMin(Node *n){                // Retorna el par de menor clave en el sub-arbol dado
											   // Buscando de manera recursiva

	Node *min = n;                          //Seteamos hijo derecho como el menor

	if(n->left != NULL){                       //Buscamos el menor hacia la izq
		min = findMin(n -> left);
		if(min -> data.first.compare(n -> data.first) < 0)  //Si clave encontrada es menor a clave de n
			return min;
	}
	else
		return min;

}

