#include "PRQuad.h"
#include <utility>             // Para usar Pair

using namespace std;

PRQuad::PRQuad(int a, int b,vector<pair<int,int>> input){
    //Constructor usado para cuando se recibe inicialmente los datos
    NW = NULL;
    SW = NULL;
    SE = NULL;
    NE = NULL;

    hasPoint = false;
    //point = NULL;
    point.first = -1;
    point.second = -1;

    topRight.first=a-1;
    topRight.second=b-1;
    botLeft.first=0;
    botLeft.second=0;

    construir(input);

    //construir(input);
    //cerr<<"Construido con int"<<endl;
}

PRQuad::PRQuad(pair<int,int> newTopRight, pair<int,int> newBotLeft){
    //Se reciben los bounds del punto, luego, se guardan dentro de esta clase
    //Se inicializan los hijos en null
    //falta insertar el nodo anterior al crear la wea
    NW = NULL;
    SW = NULL;
    SE = NULL;
    NE = NULL;

    hasPoint = false;
    //point = NULL;
    point.first = -1;
    point.second = -1;

    topRight = newTopRight;
    botLeft = newBotLeft;
  //  cerr<<"Construido con pairs"<<endl;
}



bool PRQuad::hasChild(){
    //Solo se encarga de revisar si el quad actual tiene algun hijo
    //retorna true si tiene hijo
    //retorna false si no tiene hijo
    if(NW!=NULL || SW!=NULL || SE!=NULL || NE!=NULL){
        //cerr<<"Tiene hijos"<<endl;
        return true;
    }
    else{
        /*cerr<<"No tiene hijos en cuadrante "<<botLeft.first<<" "<<botLeft.second<<" / "<<topRight.first<<" "<<topRight.second;
        if (hasPoint){
            cerr<<" pero tiene un punto"<<endl;
        }
        else{
            cerr<<" no hay punto"<<endl;
        }*/
        return false;
    }
}

bool PRQuad::isContained(pair<int,int> givenPoint){
    //revisamos si el nodo esta contenido en este quad
    if((givenPoint.first >= botLeft.first) && (givenPoint.first <= topRight.first) && 
        (givenPoint.second >= botLeft.second) && (givenPoint.second <= topRight.second)){
        //esta contenido en el eje x e y
        //cerr<<givenPoint.first<<" "<<givenPoint.second<<" esta contenido en "<<botLeft.first<<" "<<botLeft.second<<" / "<<topRight.first<<" "<<topRight.second<<endl;
        return true;
    }
    else{
        //cerr<<givenPoint.first<<" "<<givenPoint.second<<" no esta contenido en "<<botLeft.first<<" "<<botLeft.second<<" / "<<topRight.first<<" "<<topRight.second<<endl;
        return false;
    }
}



void PRQuad::Subdivide(){
    //Subdividimos el nodo y reubicamos nuestro punto anterior
    
    pair<int,int> NWT = make_pair((topRight.first+botLeft.first)/2,topRight.second);
    pair<int,int> NWB = make_pair(botLeft.first,(topRight.second+botLeft.second+1)/2);
    pair<int,int> NET = topRight;
    pair<int,int> NEB = make_pair((topRight.first+botLeft.first+1)/2,(topRight.second+botLeft.second+1)/2);
    pair<int,int> SET = make_pair(topRight.first,(topRight.second+botLeft.second)/2);
    pair<int,int> SEB = make_pair((topRight.first+botLeft.first+1)/2,botLeft.second);
    pair<int,int> SWT = make_pair((topRight.first+botLeft.first)/2,(topRight.second+botLeft.second)/2);
    pair<int,int> SWB = botLeft;

    //top right , bot left
    NW = new PRQuad(NWT,NWB);
    NE = new PRQuad(NET,NEB);
    SE = new PRQuad(SET,SEB);
    SW = new PRQuad(SWT,SWB);
    /*
    NW = new PRQuad(make_pair(topRight.first/2,topRight.second),make_pair(botLeft.first,topRight.second/2));    ///BUGS
    NE = new PRQuad(make_pair(topRight.first,topRight.second),make_pair(topRight.first/2,topRight.second/2));   ///BUGS
    SE = new PRQuad(make_pair(topRight.first,topRight.second/2),make_pair(topRight.first/2,botLeft.second));    ///BUGS
    SW = new PRQuad(make_pair(topRight.first/2,topRight.second/2),make_pair(botLeft.first,botLeft.second));     ///BUGS
    */

    //Aca se reubica el punto anterior en el cuadrante correspondiente

    if(NW->Insert(point)){
     //   cerr<<"Inserte el punto anterior en NW"<<endl;
        return;
    }

    if(NE->Insert(point)){
     //   cerr<<"Inserte el punto anterior en NE"<<endl;
        return;
    }

    if(SE->Insert(point)){
      //  cerr<<"Inserte el punto anterior en SE"<<endl;
        return;
    }

    if(SW->Insert(point)){
    //    cerr<<"Inserte el punto anterior en SW"<<endl;
        return;
    }



}


bool PRQuad::Insert(pair<int,int> insertPoint){
    //Al insertar, primero se revisa si dado punto esta contenido
    if(!isContained(insertPoint)){
        return false;
    }
    //cerr<<"Insertar en Cuadrante "<<botLeft.first<<" "<<botLeft.second<<" / "<<topRight.first<<" "<<topRight.second<<endl;
    if(point == insertPoint){
        //Si el punto q uno quiere insertar es igual al guardado return true
        //cerr<<"Ya insertaste ese punto dummy"<<endl;
        return true;
    }
    //si tiene un punto y no tiene hijos
    //entonces insertamos nuestro punto y marcamos que tiene un hijo
    if(!hasPoint && !hasChild()){   
       // cerr<<insertPoint.first<<" "<<insertPoint.second<<" insertado en una hoja"<<endl<<endl; 
        point = insertPoint;
        hasPoint = true;
        return true;
    }


    if(!hasChild()){
      //  cerr<<"SUBDIVIDIR"<<endl<<endl;
        //getchar();
        Subdivide();    
        //crea los 4 cuadrantes y revisa donde quedara el punto que teniamos antes
    }

    if(NW->Insert(insertPoint)){
      //  cerr<<insertPoint.first<<" "<<insertPoint.second<<" insertado en NW"<<endl;
        return true;
    }

    if(NE->Insert(insertPoint)){
     //   cerr<<insertPoint.first<<" "<<insertPoint.second<<" insertado en NE"<<endl;
        return true;
    }

    if(SE->Insert(insertPoint)){
      //  cerr<<insertPoint.first<<" "<<insertPoint.second<<" insertado en SE"<<endl;
        return true;
    }

    if(SW->Insert(insertPoint)){
     //   cerr<<insertPoint.first<<" "<<insertPoint.second<<" insertado en SW"<<endl;
        return true;
    }


    //Si llega aca es porque no se puede seguir subdiviediendo
  //  cerr<<"No se pudo seguir dividiendo"<<endl;
    return false;
}


void PRQuad::construir(vector<pair<int,int>> input){  //recibe un vector de pairs


    while(!input.empty()){           //mientras el vector de puntos no vacio
    //    cerr << "Construyo el punto "<< input[0].first<<" " <<input[0].second <<endl<<endl;

        Insert(input[0]);            //inserto en mi mismo la cabeza de vector        
      //  cerr << "Quito del vector el punto "<< input[0].first<<" " <<input[0].second <<endl<<endl;  
        input.erase(input.begin());  // borrar cabeza de vector luego de insertar
    }

}

vector<pair<int,int>> PRQuad::buscar(pair<int,int> searchTopRight, pair<int,int> searchBotLeft){   
    vector<pair<int,int>> pointVec;
    vector<pair<int,int>> aux;

    if(!intersectRect(searchTopRight,searchBotLeft)){
        //Si no se intersectan return 
        return  pointVec;
    }

    if(!hasChild()){
        if(intersectPoint(point,searchTopRight,searchBotLeft)){
            pointVec.push_back(point);
            //Entonces el punto si esta contenido dentro del rectangulo de busqueda
            //se agrega al vector
        }
    }
    else{
        
        aux = NW->buscar(searchTopRight,searchBotLeft);  //Guardamos el vector recibido recursivo
        pointVec.insert(pointVec.end(),aux.begin(),aux.end());

        aux = NE->buscar(searchTopRight,searchBotLeft);
        pointVec.insert(pointVec.end(),aux.begin(),aux.end());        


        aux = SE->buscar(searchTopRight,searchBotLeft);
        pointVec.insert(pointVec.end(),aux.begin(),aux.end());

        aux = SW->buscar(searchTopRight,searchBotLeft);
        pointVec.insert(pointVec.end(),aux.begin(),aux.end());
        /*
        pointVec.push_back(NE->buscar(searchTopRight,searchBotLeft));
        pointVec.push_back(SE->buscar(searchTopRight,searchBotLeft));
        pointVec.push_back(SW->buscar(searchTopRight,searchBotLeft));
        */
    }

    return pointVec;
  
}

bool PRQuad::intersectRect(pair<int,int> searchTopRight, pair<int,int> searchBotLeft){

    //Recibe 2 ptos del rectangulo

    //Si no se intersectan en X
    if(topRight.first < searchBotLeft.first || searchTopRight.first < botLeft.first){
      //  cerr << "No se intersectan por X\n";
        return false;
    }
    //Si no se intersectan en Y
    if(topRight.second < searchBotLeft.second || searchTopRight.second < botLeft.second){
      //  cerr << "No se intersectan por Y\n";
        return false;
    }

   // cerr << "Se intersectan los rectangulos\n";
    //Si no se cumple lo anterior, se intersectan
    return true;
}


bool PRQuad::intersectPoint(pair<int,int> givenPoint, pair<int,int> searchTopRight, pair<int,int> searchBotLeft){
    //revisamos si el nodo esta contenido en este rectangulo
    if((givenPoint.first >= searchBotLeft.first) && (givenPoint.first <= searchTopRight.first) && 
        (givenPoint.second >= searchBotLeft.second) && (givenPoint.second <= searchTopRight.second)){
        //esta contenido en el eje x e y
       // cerr<<givenPoint.first<<" "<<givenPoint.second<<" esta contenido"<<endl;
        return true;
    }
    else{
       // cerr<<givenPoint.first<<" "<<givenPoint.second<<" no esta contenido"<<endl;
       // cerr<<"En el rectangulo de topR " << searchTopRight.first << " " << searchTopRight.second<<endl;
       // cerr << searchBotLeft.first << " " << searchBotLeft.second << endl;
        return false;
    }
}

/*

//FUNCION DEPRECADA
//ya no se usa porque ahora sabemos que las matrices son cuadradas y de tamaño 2^n

bool PRQuad::canSubdivide(){
    //revisamos si se puede subdividir
    //para esto, restamos las coordenadas en x e y y vemos si es 1 o 0
    //si son 1 o 0, entonces no se va a poder subdividir mas
    if((abs(topRight.first - botLeft.first) <= 1) && (abs(topRight.second - botLeft.second) <= 1)){
        cerr<<"No se puede subdividir mas"<<endl;
        return false;
    }
    else{
        cerr<<"Se puede subdividir"<<endl;
        return true;
    }

}
*/
