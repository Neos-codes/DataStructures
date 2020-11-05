#include "kdT.h"
#include <algorithm>

using namespace std;


//Obtenido de https://www.quora.com/How-do-I-sort-array-of-pair-int-int-in-C++-according-to-the-first-and-the-second-element
bool pairCompareX(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.first < j.first;
}

bool pairCompareY(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
    
    //sort(myvector.begin(), myvector.end(), myCompFunction)
}


kdT::kdT(){

	isLeaf=false;
	rightKDT = NULL;
	leftKDT = NULL;

	point.first = -1;      
	point.second = -1;
	//El pto del padre se inicializa en -1,-1

}

kdT::kdT(vector<pair<int,int>> input){

	isLeaf=false;
	rightKDT = NULL;
	leftKDT = NULL;

	point.first = -1;      
	point.second = -1;
	this->construir(input);
	

	
}
void kdT::construir(vector<pair<int,int>> input){


	this->BuildKDT(input,0,input.size()-1,true);

}



kdT* kdT::BuildKDT(vector<pair<int,int>> input, int vStart, int vEnd, bool odd){


	if (odd){
	//	cerr<<"Ordenamos el vector segun X"<<endl;
		//Si es odd entonces el vector debe ser ordenado seugn X
		sort(input.begin()+vStart,input.begin()+vEnd+1,pairCompareX);
	}
	else{
	//	cerr<<"Ordenamos el vector segun Y"<<endl;
		//Si no es odd, etnonces se ordena por Y
		sort(input.begin()+vStart,input.begin()+vEnd+1,pairCompareY);
	}

	int med = (vStart+vEnd)/2;

	if (vStart == vEnd){
		//Implica que este es una hoja
	//	cerr << "El punto "<<input[med].first << " "<<input[med].second<< " insertado en hoja\n";
		point=input[med];
		isLeaf=true;

	}
	else{
		if(odd){
			//Entonces trabajamos con el x
		//	cerr <<"vector izq: \n";
		//	for(int i = vStart; i <= med; i++){
		//		cout << input[i].first<<" "<<input[i].second<< " | ";
		//	}
		//	cerr<<"\nvector der: \n";
		//	for(int i = med+1; i <= vEnd; i++){
		//		cout << input[i].first<<" "<<input[i].second<< " | ";
		//	}
			cerr <<endl;
			point.first=input[med].first;
			point.second=-1;
			isLeaf=false;
		}
		else{
			//Entonces trabajamos con el y
		//	cerr <<"vector izq: \n";
		//	for(int i = vStart; i <= med; i++){
		//		cout << input[i].first<<" "<<input[i].second<< " | ";
		//	}
		//	cerr <<"\nvector der: \n";
		//	for(int i = med+1; i <= vEnd; i++){
		//		cout << input[i].first<<" "<<input[i].second<< " | ";
		//	}
			cerr <<endl;
			point.first=-1;
			point.second=input[med].second;
			isLeaf=false;
		}
		leftKDT = new kdT();
		rightKDT = new kdT();
	//	cerr<<"VECTOR LEFT "<<vStart<<" "<<med<<" "<<!odd<<endl;
		leftKDT->BuildKDT(input,vStart,med,!odd);
	//	cerr<<"VECTOR RIGHT "<<med+1<<" "<<vEnd<<" "<<!odd<<endl;
		rightKDT->BuildKDT(input,med+1,vEnd,!odd);
	}
	return this;

}


vector<pair<int,int>> kdT::buscar(pair<int,int> searchTopRight, pair<int,int> searchBotLeft){
	vector<pair<int,int>> pointVec;
    vector<pair<int,int>> aux;

    if(point.second==-1 && point.first==-1){
        //No hay punto, return
        return  pointVec;        
    }

    if(isLeaf){	//Si es una hoja
        if(intersectPoint(point,searchTopRight,searchBotLeft)){
            pointVec.push_back(point);
            //Entonces el punto si esta contenido dentro del rectangulo de busqueda
            //se agrega al vector
        }
    }
    else{
        
        if(point.second==-1){	//Si estamos revisando por X
	    //	cerr<<"Revisamos por X"<<endl;
	    	if(searchTopRight.first >= point.first && searchBotLeft.first <= point.first){
	    //		cerr<<"Se revisa ambos"<<endl;
	        	aux = leftKDT->buscar(searchTopRight,searchBotLeft);
	        	pointVec.insert(pointVec.end(),aux.begin(),aux.end());

	        	aux = rightKDT->buscar(searchTopRight,searchBotLeft);
	        	pointVec.insert(pointVec.end(),aux.begin(),aux.end());
	        }
	        else if(searchBotLeft.first >= point.first){
	    //    	cerr<<"se revisa lado derecho\n";
	        	aux = rightKDT->buscar(searchTopRight,searchBotLeft);
	        	pointVec.insert(pointVec.end(),aux.begin(),aux.end());
	        }
	        else if(searchTopRight.first <= point.first){
	    //    	cerr<<"se revisa lado izquierdo\n";
	        	aux = leftKDT->buscar(searchTopRight,searchBotLeft);
	        	pointVec.insert(pointVec.end(),aux.begin(),aux.end());
	        }
	    }
	    else{	//Si estamos revisando por Y
	    //	cerr<<"Revisamos por Y"<<endl;
	    	if(searchTopRight.second >= point.second && searchBotLeft.second <= point.second){
	    //		cerr<<"Se revisa ambos"<<endl;
	        	aux = leftKDT->buscar(searchTopRight,searchBotLeft);
	        	pointVec.insert(pointVec.end(),aux.begin(),aux.end());

	        	aux = rightKDT->buscar(searchTopRight,searchBotLeft);
	        	pointVec.insert(pointVec.end(),aux.begin(),aux.end());
	        }
	        else if(searchBotLeft.second >= point.second){
	    //    	cerr<<"se revisa por arriba\n";
	        	aux = rightKDT->buscar(searchTopRight,searchBotLeft);
	        	pointVec.insert(pointVec.end(),aux.begin(),aux.end());
	        }
	        else if(searchTopRight.second <= point.second){
	    //    	cerr<<"se revisa por abajo\n";
	        	aux = leftKDT->buscar(searchTopRight,searchBotLeft);
	        	pointVec.insert(pointVec.end(),aux.begin(),aux.end());
	        }
	    }     
    }

    

    

    return pointVec;
  

}








bool kdT::intersectPoint(pair<int,int> givenPoint, pair<int,int> searchTopRight, pair<int,int> searchBotLeft){
    //revisamos si el nodo esta contenido en este rectangulo
    if((givenPoint.first >= searchBotLeft.first) && (givenPoint.first <= searchTopRight.first) && 
        (givenPoint.second >= searchBotLeft.second) && (givenPoint.second <= searchTopRight.second)){
        //esta contenido en el eje x e y
     //   cerr<<givenPoint.first<<" "<<givenPoint.second<<" esta contenido"<<endl;
        return true;
    }
    else{
    //    cerr<<givenPoint.first<<" "<<givenPoint.second<<" no esta contenido"<<endl;
    //    cerr<<"En el rectangulo de topR " << searchTopRight.first << " " << searchTopRight.second<<endl;
    //    cerr << searchBotLeft.first << " " << searchBotLeft.second << endl;
        return false;
    }
}

















/*
kdT::kdT(int a, int b,vector input ){

	rootSize.first = a;   //raiz del arbol guarda el tamaño
	rootSize.second = b;

	root = NULL;
	rightKDT = NULL;      //punteros a hijos nulos
	leftKDT = NULL;

	point.fist = -1;      //El pto del padre se inicializa en -1,-1
	point.second = -1;

	//Aqui se llama el constructor con el vector

}


*/