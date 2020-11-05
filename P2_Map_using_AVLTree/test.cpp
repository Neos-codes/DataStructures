#include "MapAVL.h"

using namespace std;


int main(){

    
    string s1 = "aaa";
    string s2 = "aad";
    string s3 = "aac";
    string s4 = "aaf";
    string s5 = "aag";
    //string s6 = "aba";
    MapAVL ma;
    cerr<<"Intento insertar "<<s1<<endl;
    ma.insert(make_pair(s1,2));
    cerr<<endl;
    cerr<<"Intento insertar "<<s2<<endl;
    ma.insert(make_pair(s2,2));
    cerr<<endl;
    cerr<<"Intento insertar "<<s3<<endl;
    ma.insert(make_pair(s3,2));
    cerr<<endl;
    cerr<<"Intento insertar "<<s4<<endl;
    ma.insert(make_pair(s4,10));
    cerr<<endl; 
    cerr<<"Intento insertar "<<s5<<endl;
    ma.insert(make_pair(s5,2));
    cerr<<endl;
    //cerr<<"Intento insertar "<<s6<<endl;
    //ma.insert(make_pair(s6,-5));
    //cerr<<endl;

    cerr<<endl<<endl;

    ma.printAVL(); 

    cerr << "Escribir string a borrar: \n";

    string test;
    cin>>test;

    cerr<<"Buscar "<<test<<" es: "<<ma.at(test)<<endl;
    cerr<<ma.size()<<endl;
    cerr<<ma.empty()<<endl;

    cerr<<"Ahora borramos "<<test<<endl;
    ma.erase(test);

    ma.printAVL();

    goto end;
    end:
    return 0;
}
